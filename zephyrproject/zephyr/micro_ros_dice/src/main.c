#include <version.h>

#if ZEPHYR_VERSION_CODE >= ZEPHYR_VERSION(3,1,0)
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/posix/time.h>
#else
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <posix/time.h>
#endif

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <std_msgs/msg/int32.h>

#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <rmw_microros/rmw_microros.h>
#include <microros_transports.h>

#include "hash/hash.h"
#include "dice/dice.h"

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc);for(;;){};}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}

rcl_publisher_t publisher;
std_msgs__msg__Int32 msg;

void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
	RCLC_UNUSED(last_call_time);
	if (timer != NULL) {
		RCSOFTCHECK(rcl_publish(&publisher, &msg, NULL));
		msg.data++;
	}
}

int main(void)
{
	rmw_uros_set_custom_transport(
		MICRO_ROS_FRAMING_REQUIRED,
		(void *) &default_params,
		zephyr_transport_open,
		zephyr_transport_close,
		zephyr_transport_write,
		zephyr_transport_read
	);

	rcl_allocator_t allocator = rcl_get_default_allocator();
	rclc_support_t support;

	// uint8_t hash_result[32];

    // printk("Start calculating firmware SHA-256...\n");

    // if (hash_firmware(hash_result)) {
    //     printk("SHA-256 hash:\n");
    //     for (int i = 0; i < 32; ++i) {
    //         printk("%02x", hash_result[i]);
    //     }
	// 	printk("\n");
    // } else {
    //     printk("Firmware hash failed.\n");
    // }

    // uint8_t cdi_buffer[DICE_CDI_SIZE];
    // uint8_t cert_buffer[2048];
    // size_t cert_size;
    // DiceInputValues input_values = {0};
	// DiceResult result;

	// result = DiceMainFlow(NULL, cdi_buffer, cdi_buffer,
    //             &input_values, sizeof(cert_buffer), cert_buffer,
    //             &cert_size, cdi_buffer, cdi_buffer);

	// if (result == kDiceResultOk) {
    //     printk("Cdi_buffer:\n");
    //     for (int i = 0; i < 2048; ++i) {
    //             printk("%02x", cdi_buffer[i]);
    //         }
    //         printk("\n");
    // } else {
    //     printk("DICE failed.\n");
    // }


	// create init_options
	RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

	// create node
	rcl_node_t node;
	RCCHECK(rclc_node_init_default(&node, "zephyr_int32_publisher", "", &support));

	// create publisher
	RCCHECK(rclc_publisher_init_default(
		&publisher,
		&node,
		ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
		"zephyr_int32_publisher"));

	// create timer,
	rcl_timer_t timer;
	const unsigned int timer_timeout = 1000;
	RCCHECK(rclc_timer_init_default(
		&timer,
		&support,
		RCL_MS_TO_NS(timer_timeout),
		timer_callback));

	// create executor
	rclc_executor_t executor;
	RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
	RCCHECK(rclc_executor_add_timer(&executor, &timer));

	msg.data = 0;

	while(1){
		rclc_executor_spin_some(&executor, 100);
		usleep(100000);
	}

	// free resources
	RCCHECK(rcl_publisher_fini(&publisher, &node))
	RCCHECK(rcl_node_fini(&node))
  return 0;    
}
