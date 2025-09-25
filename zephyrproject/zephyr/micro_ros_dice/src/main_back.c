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

#include <zephyr/kernel.h>
#include "mpu_config.h"

#define STACK_SIZE 1024

K_THREAD_STACK_DEFINE(priv_stack1, STACK_SIZE);
K_THREAD_STACK_DEFINE(user_stack1, STACK_SIZE);
K_THREAD_STACK_DEFINE(user_stack2, STACK_SIZE);

struct k_thread priv_thread1;
struct k_thread user_thread1;
struct k_thread user_thread2;

// 동기화를 위한 세마포어들
K_SEM_DEFINE(priv1_done, 0, 1);
K_SEM_DEFINE(user1_done, 0, 1);
K_SEM_DEFINE(user2_done, 0, 1);

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc);for(;;){};}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}

rcl_allocator_t allocator;
rclc_support_t support;

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

void privileged_task_1(void* p1, void* p2, void* p3)
{
	printk("priv task 1\n");

	// create init_options
	RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
    
	k_sem_give(&priv1_done);
}

void user_task_1(void* p1, void* p2, void* p3)
{
	printk("user task 1\n");

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

	k_sem_give(&user1_done);
}

void user_task_2(void* p1, void* p2, void* p3)
{
	printk("user task 2\n");

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

	k_sem_give(&user2_done);
}

int main(void)
{
	/*
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
	*/

    MPU_Config();
    printk("MPU CONFIGURED\n");

	k_tid_t tid = k_thread_create(&user_thread1,
                    user_stack1,
                    K_THREAD_STACK_SIZEOF(user_stack1),
                    user_task_1,
                    NULL, NULL, NULL,
                    5, K_USER,  // privileged (K_USER 플래그 없음)
                    K_NO_WAIT);
    
	k_object_access_grant(&user1_done, tid);

    k_sem_take(&user1_done, K_FOREVER);  // 완료 대기

	k_thread_create(&priv_thread1,
                    priv_stack1,
                    K_THREAD_STACK_SIZEOF(priv_stack1),
                    privileged_task_1,
                    NULL, NULL, NULL,
                    5, 0,  // privileged (K_USER 플래그 없음)
                    K_NO_WAIT);
    
    k_sem_take(&priv1_done, K_FOREVER);  // 완료 대기


	tid = k_thread_create(&user_thread2,
                    user_stack2,
                    K_THREAD_STACK_SIZEOF(user_stack2),
                    user_task_2,
                    NULL, NULL, NULL,
                    5, K_USER,  // privileged (K_USER 플래그 없음)
                    K_NO_WAIT);


	k_object_access_grant(&user2_done, tid);
    
    k_sem_take(&user2_done, K_FOREVER);  // 완료 대기


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


	/*
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
	*/
  return 0;    
}
