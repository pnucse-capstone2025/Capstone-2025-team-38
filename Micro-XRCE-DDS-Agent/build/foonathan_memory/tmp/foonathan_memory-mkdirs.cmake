# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/src/foonathan_memory"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/src/foonathan_memory-build"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/temp_install/foonathan_memory"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/tmp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/src/foonathan_memory-stamp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/src"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/src/foonathan_memory-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/src/foonathan_memory-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/foonathan_memory/src/foonathan_memory-stamp${cfgdir}") # cfgdir has leading slash
endif()
