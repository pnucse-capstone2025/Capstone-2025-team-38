#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <rmw_microros/rmw_microros.h>
#include <microros_transports.h>

#include <std_msgs/msg/header.h>

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include <zephyr.h>

//#include "../lib/hash/include/hash/hash.h"
#include <hash/hash.h>
#include <dice/dice.h>

#define STRING_BUFFER_LEN 50

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printk("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc); return 1;}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}


#undef RMW_UROS_TRACE_MESSAGE
#define RMW_UROS_TRACE_MESSAGE(msg) printk("[RMW TRACE] %s\n", msg)

rcl_publisher_t ping_publisher;
rcl_publisher_t pong_publisher;
rcl_subscription_t ping_subscriber;
rcl_subscription_t pong_subscriber;

std_msgs__msg__Header incoming_ping;
std_msgs__msg__Header outcoming_ping;
std_msgs__msg__Header incoming_pong;

int device_id;
int seq_no;
int pong_count;

uint8_t hash_result[32];
uint32_t nonce = 0;


void ping_timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
	(void) last_call_time;

	if (timer != NULL) {

		seq_no = rand();
		sprintf(outcoming_ping.frame_id.data, "%d_%d", seq_no, device_id);
		outcoming_ping.frame_id.size = strlen(outcoming_ping.frame_id.data);

		// Fill the message timestamp
		struct timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		outcoming_ping.stamp.sec = ts.tv_sec;
		outcoming_ping.stamp.nanosec = ts.tv_nsec;

		// Reset the pong count and publish the ping message
		pong_count = 0;
		rcl_publish(&ping_publisher, (const void*)&outcoming_ping, NULL);
		printf("Ping send seq %s\n", outcoming_ping.frame_id.data);
	}
}

void ping_subscription_callback(const void * msgin)
{
	const std_msgs__msg__Header * msg = (const std_msgs__msg__Header *)msgin;

	// Dont pong my own pings
	if(strcmp(outcoming_ping.frame_id.data, msg->frame_id.data) != 0){
		printf("Ping received with seq %s. Answering.\n", msg->frame_id.data);
		rcl_publish(&pong_publisher, (const void*)msg, NULL);
	}
}


void pong_subscription_callback(const void * msgin)
{
	const std_msgs__msg__Header * msg = (const std_msgs__msg__Header *)msgin;

	if(strcmp(outcoming_ping.frame_id.data, msg->frame_id.data) == 0) {
			pong_count++;
			printf("Pong for seq %s (%d)\n", msg->frame_id.data, pong_count);
	}
}


void main(void)
{
	// Set custom transports
	rmw_uros_set_custom_transport(
		MICRO_ROS_FRAMING_REQUIRED,
		(void *) &default_params,
		zephyr_transport_open,
		zephyr_transport_close,
		zephyr_transport_write,
		zephyr_transport_read
	);

	// Init micro-ROS
	rcl_allocator_t allocator = rcl_get_default_allocator();
	rclc_support_t support;

	// printk("Set transport!\n");


	

    // printk("Calculating firmware SHA-256...\n");

	
    // if (hash_firmware(hash_result)) {
    //     printk("SHA-256 hash:\n");
    //     for (int i = 0; i < 32; ++i) {
    //             printk("%02x", hash_result[i]);
    //         }
    //         printk("\n");
    // } else {
    //     printk("Firmware hash failed.\n");
    // }
    if (!hash_firmware(hash_result)) {
        printk("Firmware hash failed.\n");
    }

    // uint8_t cdi_buffer[DICE_CDI_SIZE] = {0,};
    // uint8_t cert_buffer[2048];
    // size_t cert_size;
    // DiceInputValues input_values = {1};
	// DiceResult result;

	// result = DiceMainFlow(NULL, cdi_buffer, cdi_buffer,
    //             &input_values, sizeof(cert_buffer), cert_buffer,
    //             &cert_size, cdi_buffer, cdi_buffer);

	// if (result == kDiceResultOk) {
    //     printk("cdi_buffer:\n");
    //     for (int i = 0; i < DICE_CDI_SIZE; ++i) {
    //             printk("%02x ", cdi_buffer[i]);
    //         }
    //         printk("\n");
	// 	printk("cert_buffer:\n");
	// 	for (int i = 0; i < cert_size; ++i) {
	// 			printk("%02x ", cert_buffer[i]);
	// 		}
	// 		printk("\n");
    // } else {
    //     printk("DICE failed.\n");
    // }
	


	// create init_options
	RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
	// printk("Initialized!!\n");

	// create node
	rcl_node_t node;
	RCCHECK(rclc_node_init_default(&node, "dice_node", "", &support));

	// Create a reliable ping publisher
	RCCHECK(rclc_publisher_init_default(&ping_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Header), "/microROS/ping"));

	// Create a best effort pong publisher
	RCCHECK(rclc_publisher_init_best_effort(&pong_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Header), "/microROS/pong"));

	// Create a best effort ping subscriber
	RCCHECK(rclc_subscription_init_best_effort(&ping_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Header), "/microROS/ping"));

	// Create a best effort  pong subscriber
	RCCHECK(rclc_subscription_init_best_effort(&pong_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Header), "/microROS/pong"));


	// Create a 3 seconds ping timer timer,
	rcl_timer_t timer;
	RCCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(2000), ping_timer_callback));


	// Create executor
	rclc_executor_t executor;
	RCCHECK(rclc_executor_init(&executor, &support.context, 3, &allocator));
	RCCHECK(rclc_executor_add_timer(&executor, &timer));
	RCCHECK(rclc_executor_add_subscription(&executor, &ping_subscriber, &incoming_ping, &ping_subscription_callback, ON_NEW_DATA));
	RCCHECK(rclc_executor_add_subscription(&executor, &pong_subscriber, &incoming_pong, &pong_subscription_callback, ON_NEW_DATA));

	// Create and allocate the pingpong messages

	char outcoming_ping_buffer[STRING_BUFFER_LEN];
	outcoming_ping.frame_id.data = outcoming_ping_buffer;
	outcoming_ping.frame_id.capacity = STRING_BUFFER_LEN;

	char incoming_ping_buffer[STRING_BUFFER_LEN];
	incoming_ping.frame_id.data = incoming_ping_buffer;
	incoming_ping.frame_id.capacity = STRING_BUFFER_LEN;

	char incoming_pong_buffer[STRING_BUFFER_LEN];
	incoming_pong.frame_id.data = incoming_pong_buffer;
	incoming_pong.frame_id.capacity = STRING_BUFFER_LEN;

	device_id = rand();

	while(1){
		rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
		usleep(100000);
	}

	RCCHECK(rcl_publisher_fini(&ping_publisher, &node));
	RCCHECK(rcl_publisher_fini(&pong_publisher, &node));
	RCCHECK(rcl_subscription_fini(&ping_subscriber, &node));
	RCCHECK(rcl_subscription_fini(&pong_subscriber, &node));
	RCCHECK(rcl_node_fini(&node));

}
