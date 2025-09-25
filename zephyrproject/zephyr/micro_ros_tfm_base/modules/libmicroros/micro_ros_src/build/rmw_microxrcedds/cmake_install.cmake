# Install script for directory: /home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rmw-microxrcedds/rmw_microxrcedds_c

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "1")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/tmdals010126/zephyr-sdk-0.17.0/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_dev/install/ament_package/lib/python3.10/site-packages/ament_package/template/environment_hook/library_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/library_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rmw_typesupport_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_index/share/ament_index/resource_index/rmw_typesupport_c/rmw_microxrcedds")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rmw_typesupport" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_index/share/ament_index/resource_index/rmw_typesupport/rmw_microxrcedds")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/rmw_microxrcedds")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/rmw_microxrcedds")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_index/share/ament_index/resource_index/packages/rmw_microxrcedds")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds/cmake" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_core/rmw_microxrceddsConfig.cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/ament_cmake_core/rmw_microxrceddsConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rmw_microxrcedds" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rmw-microxrcedds/rmw_microxrcedds_c/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rmw-microxrcedds/rmw_microxrcedds_c/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rmw_microxrcedds_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/include/rmw_microxrcedds_c/config.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/librmw_microxrcedds.a")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rmw_microxrcedds/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
