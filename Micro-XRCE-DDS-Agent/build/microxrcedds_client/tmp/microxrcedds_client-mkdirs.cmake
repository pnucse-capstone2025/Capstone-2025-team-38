# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/src/microxrcedds_client"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/src/microxrcedds_client-build"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/temp_install"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/tmp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/src/microxrcedds_client-stamp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/src"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/src/microxrcedds_client-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/src/microxrcedds_client-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/microxrcedds_client/src/microxrcedds_client-stamp${cfgdir}") # cfgdir has leading slash
endif()
