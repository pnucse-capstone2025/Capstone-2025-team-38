# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/micro-CDR"
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr"
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr/ucdr-prefix"
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr/ucdr-prefix/tmp"
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr/ucdr-prefix/src/ucdr-stamp"
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr/ucdr-prefix/src"
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr/ucdr-prefix/src/ucdr-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr/ucdr-prefix/src/ucdr-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/microcdr/ucdr-prefix/src/ucdr-stamp${cfgdir}") # cfgdir has leading slash
endif()
