# Install script for directory: /home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/src/ament_cmake/ament_cmake_export_link_flags

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/install/ament_cmake_export_link_flags")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/ament_cmake_export_link_flags")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/ament_cmake_export_link_flags")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_index/share/ament_index/resource_index/packages/ament_cmake_export_link_flags")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/src/ament_cmake/ament_cmake_export_link_flags/ament_cmake_export_link_flags-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags/cmake" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_core/ament_cmake_export_link_flagsConfig.cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/ament_cmake_core/ament_cmake_export_link_flagsConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/src/ament_cmake/ament_cmake_export_link_flags/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_cmake_export_link_flags" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/src/ament_cmake/ament_cmake_export_link_flags/cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/build/ament_cmake_export_link_flags/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
