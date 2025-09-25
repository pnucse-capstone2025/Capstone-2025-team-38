# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/Micro-XRCE-DDS-Agent"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/uagent-prefix"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/uagent-prefix/tmp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/uagent-prefix/src/uagent-stamp"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/uagent-prefix/src"
  "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/uagent-prefix/src/uagent-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/uagent-prefix/src/uagent-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/Micro-XRCE-DDS-Agent/build/uagent-prefix/src/uagent-stamp${cfgdir}") # cfgdir has leading slash
endif()
