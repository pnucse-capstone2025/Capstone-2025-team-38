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

// #include <mpu_config.h>
#include <zephyr/syscalls/mpu_config.h>

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

void app_main(void *p1, void *p2, void *p3)
{
	MPU_Disable_syscall();
	rmw_uros_set_custom_transport(
		MICRO_ROS_FRAMING_REQUIRED,
		(void *) &default_params,
		zephyr_transport_open,
		zephyr_transport_close,
		zephyr_transport_write,
		zephyr_transport_read
	);
	MPU_Enable_syscall();

	MPU_Disable_syscall();
	rcl_allocator_t allocator = rcl_get_default_allocator();
	rclc_support_t support;
	MPU_Enable_syscall();

	MPU_Disable_syscall();
	// create init_options
	RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
	MPU_Enable_syscall();

	MPU_Disable_syscall();
	// create node
	rcl_node_t node;
	RCCHECK(rclc_node_init_default(&node, "zephyr_int32_publisher", "", &support));
	MPU_Enable_syscall();

	MPU_Disable_syscall();
	// create publisher
	RCCHECK(rclc_publisher_init_default(
		&publisher,
		&node,
		ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
		"zephyr_int32_publisher"));
	MPU_Enable_syscall();

	MPU_Disable_syscall();
	// create timer,
	rcl_timer_t timer;
	const unsigned int timer_timeout = 1000;
	RCCHECK(rclc_timer_init_default(
		&timer,
		&support,
		RCL_MS_TO_NS(timer_timeout),
		timer_callback));
	MPU_Enable_syscall();

	MPU_Disable_syscall();
	// create executor
	rclc_executor_t executor;
	RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
	RCCHECK(rclc_executor_add_timer(&executor, &timer));
	MPU_Enable_syscall();

	msg.data = 0;

	while(1){
		MPU_Disable_syscall();
		rclc_executor_spin_some(&executor, 100);
		MPU_Enable_syscall();
		usleep(100000);
	}

	// free resources
	MPU_Disable_syscall();
	RCCHECK(rcl_publisher_fini(&publisher, &node))
	RCCHECK(rcl_node_fini(&node))
	MPU_Enable_syscall();
}

#define APP_STACK_SIZE 16384
#define APP_PRIORITY 7

K_THREAD_STACK_DEFINE(app_stack_area, APP_STACK_SIZE);
struct k_thread app_thread_data;

int main(void)
{
	const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));

	k_tid_t tid = k_thread_create(&app_thread_data, app_stack_area,
			K_THREAD_STACK_SIZEOF(app_stack_area),
			app_main, NULL, NULL, NULL,
			APP_PRIORITY, K_USER, K_NO_WAIT);

	k_object_access_grant(uart_dev, tid);

	return 0;
}
