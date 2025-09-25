# Install script for directory: /home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/install")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/msg" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/Arrays.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/BasicTypes.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/BoundedPlainSequences.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/BoundedSequences.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/Constants.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/Defaults.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/Empty.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/MultiNested.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/Nested.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/Strings.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/UnboundedSequences.msg"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/msg/WStrings.msg"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/srv" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/srv/Arrays.srv"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/srv/BasicTypes.srv"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/srv/Empty.srv"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/action" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/action/Fibonacci.action")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/test_interface_files")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/test_interface_files")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_index/share/ament_index/resource_index/packages/test_interface_files")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_core/test_interface_files-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files/cmake" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_core/test_interface_filesConfig.cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/ament_cmake_core/test_interface_filesConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/test_interface_files" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/test_interface_files/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/test_interface_files/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
