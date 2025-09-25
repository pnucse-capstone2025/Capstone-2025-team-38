# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/src/fastcdr"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/src/fastcdr-build"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/temp_install/fastcdr-1.1.1"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/tmp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/src/fastcdr-stamp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/src"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/src/fastcdr-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/src/fastcdr-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/fastcdr/src/fastcdr-stamp${cfgdir}") # cfgdir has leading slash
endif()
