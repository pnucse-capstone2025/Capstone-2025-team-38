# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/src/fastdds"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/src/fastdds-build"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/temp_install/fastrtps-2.12"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/tmp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/src/fastdds-stamp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/src"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/src/fastdds-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/src/fastdds-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastdds/src/fastdds-stamp${cfgdir}") # cfgdir has leading slash
endif()
