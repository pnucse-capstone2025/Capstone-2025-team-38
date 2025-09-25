# Install script for directory: /home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_introspection_c

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.10/site-packages/rosidl_typesupport_introspection_c-3.1.7-py3.10.egg-info" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_python/rosidl_typesupport_introspection_c/rosidl_typesupport_introspection_c.egg-info/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.10/site-packages/rosidl_typesupport_introspection_c" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_introspection_c/rosidl_typesupport_introspection_c/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/home/tmdals010126/zephyrproject/.venv/bin/python3" "-m" "compileall"
        "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/install/lib/python3.10/site-packages/rosidl_typesupport_introspection_c"
      )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_dev/install/ament_package/lib/python3.10/site-packages/ament_package/template/environment_hook/library_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/library_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_typesupport_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_index/share/ament_index/resource_index/rosidl_typesupport_c/rosidl_typesupport_introspection_c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_runtime_packages" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_index/share/ament_index/resource_index/rosidl_runtime_packages/rosidl_typesupport_introspection_c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/rosidl_typesupport_introspection_c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/rosidl_typesupport_introspection_c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_dev/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/environment" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_index/share/ament_index/resource_index/packages/rosidl_typesupport_introspection_c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake/rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake/rosidl_typesupport_introspection_cExport.cmake"
         "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/CMakeFiles/Export/e311f381a5497150eae046bcea56c8e3/rosidl_typesupport_introspection_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake/rosidl_typesupport_introspection_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake/rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/CMakeFiles/Export/e311f381a5497150eae046bcea56c8e3/rosidl_typesupport_introspection_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/CMakeFiles/Export/e311f381a5497150eae046bcea56c8e3/rosidl_typesupport_introspection_cExport-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_core/rosidl_typesupport_introspection_c-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c/cmake" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_core/rosidl_typesupport_introspection_cConfig.cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/ament_cmake_core/rosidl_typesupport_introspection_cConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_introspection_c/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rosidl_typesupport_introspection_c" TYPE PROGRAM FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_introspection_c/bin/rosidl_typesupport_introspection_c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosidl_typesupport_introspection_c" TYPE DIRECTORY FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_introspection_c/cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_introspection_c/resource"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rosidl_typesupport_introspection_c" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/rosidl/rosidl_typesupport_introspection_c/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/librosidl_typesupport_introspection_c.a")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/rosidl_typesupport_introspection_c/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
