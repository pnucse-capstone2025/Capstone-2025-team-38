# Install script for directory: /home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/micro-CDR

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/libmicrocdr.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ucdr" TYPE DIRECTORY FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/src/micro-CDR/include/ucdr/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ucdr" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/include/ucdr/config.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/microcdr/cmake/microcdrTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/microcdr/cmake/microcdrTargets.cmake"
         "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/CMakeFiles/Export/7dbace54a6f331dd3fb26f3c05b88776/microcdrTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/microcdr/cmake/microcdrTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/microcdr/cmake/microcdrTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/microcdr/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/CMakeFiles/Export/7dbace54a6f331dd3fb26f3c05b88776/microcdrTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/microcdr/cmake" TYPE FILE FILES "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/CMakeFiles/Export/7dbace54a6f331dd3fb26f3c05b88776/microcdrTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/microcdr/cmake" TYPE FILE FILES
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/cmake/config/microcdrConfig.cmake"
    "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/cmake/config/microcdrConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tmdals010126/zephyrproject/zephyr/micro_ros_tfm_base/modules/libmicroros/micro_ros_src/build/microcdr/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
