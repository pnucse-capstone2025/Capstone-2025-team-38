# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros"
  "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros"
  "/home/tmdals010126/zephyrproject/zephyr/build_dice/libmicroros-prefix"
  "/home/tmdals010126/zephyrproject/zephyr/build_dice/libmicroros-prefix/tmp"
  "/home/tmdals010126/zephyrproject/zephyr/build_dice/libmicroros-prefix/src/libmicroros_project-stamp"
  "/home/tmdals010126/zephyrproject/zephyr/build_dice/libmicroros-prefix/src"
  "/home/tmdals010126/zephyrproject/zephyr/build_dice/libmicroros-prefix/src/libmicroros_project-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/build_dice/libmicroros-prefix/src/libmicroros_project-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/build_dice/libmicroros-prefix/src/libmicroros_project-stamp${cfgdir}") # cfgdir has leading slash
endif()
