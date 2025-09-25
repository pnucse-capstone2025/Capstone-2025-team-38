# Install script for directory: /home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_parser

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.10/site-packages/rosidl_parser-3.1.7-py3.10.egg-info" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_python/rosidl_parser/rosidl_parser.egg-info/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.10/site-packages/rosidl_parser" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_parser/rosidl_parser/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/home/tmdals010126/zephyrproject/.venv/bin/python3" "-m" "compileall"
        "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/install/lib/python3.10/site-packages/rosidl_parser"
      )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/rosidl_parser")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/rosidl_parser")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_index/share/ament_index/resource_index/packages/rosidl_parser")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser/cmake" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_core/rosidl_parserConfig.cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/ament_cmake_core/rosidl_parserConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_parser" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_parser/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rosidl_parser" TYPE PROGRAM FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_parser/bin/idl2png")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm/modules/libmicroros/micro_ros_src/build/rosidl_parser/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
