# Install script for directory: /home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_interface

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/rosidl_typesupport_interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/rosidl_typesupport_interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_index/share/ament_index/resource_index/packages/rosidl_typesupport_interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake/rosidl_typesupport_interfaceExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake/rosidl_typesupport_interfaceExport.cmake"
         "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/CMakeFiles/Export/8db5830afd50b0a27d8e6849db66d8ab/rosidl_typesupport_interfaceExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake/rosidl_typesupport_interfaceExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake/rosidl_typesupport_interfaceExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/CMakeFiles/Export/8db5830afd50b0a27d8e6849db66d8ab/rosidl_typesupport_interfaceExport.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface/cmake" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_core/rosidl_typesupport_interfaceConfig.cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/ament_cmake_core/rosidl_typesupport_interfaceConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_interface" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_interface/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rosidl_typesupport_interface" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_interface/include/")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tmdals010126/zephyrproject/zephyr/micro_ros_dice/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_interface/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
