import sys
if sys.prefix == '/home/tmdals010126/zephyrproject/.venv':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_dev/install/domain_coordinator'
