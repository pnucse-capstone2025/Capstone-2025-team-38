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

#include <stdio.h>
#include <stdlib.h>

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

#define DEMCR (*(volatile uint32_t *) 0xE000EDFC)
#define DWT_CTRL (*(volatile uint32_t *) 0xE0001000)
#define DWT_CYCCNT (*(volatile uint32_t *) 0xE0001004)

typedef uint64_t uint64;
typedef int64_t int64;

void enable_dwt(){
    if(DWT_CTRL != 0){ 
        DEMCR |= (1 << 24);
        DWT_CYCCNT = 0;
        DWT_CTRL |= 1;
    }   
}

uint64_t start_time;
uint64_t end_time;
uint64_t duration;

int main(void)
{

	enable_dwt();

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


	start_time = k_cycle_get_64();

	// create init_options
	RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

	// create node
	rcl_node_t node;
	RCCHECK(rclc_node_init_default(&node, "zephyr_int32_publisher", "", &support));

	// k_sleep(K_SECONDS(10));

	// end_time = k_cycle_get_64();
	// duration = end_time - start_time;
	// // k_sleep(K_SECONDS(10));

	// for(int i = 0; i < 10; i++){
	// 	printf("rclc_support_init time: %llu us\n", duration);
	// 	k_sleep(K_SECONDS(1));
	// }


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
