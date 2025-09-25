# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m"
  "/home/tmdals010126/zephyrproject/zephyr/build/tfm"
  "/home/tmdals010126/zephyrproject/zephyr/build/modules/trusted-firmware-m/tfm-prefix"
  "/home/tmdals010126/zephyrproject/zephyr/build/modules/trusted-firmware-m/tfm-prefix/tmp"
  "/home/tmdals010126/zephyrproject/zephyr/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp"
  "/home/tmdals010126/zephyrproject/zephyr/build/modules/trusted-firmware-m/tfm-prefix/src"
  "/home/tmdals010126/zephyrproject/zephyr/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/build/modules/trusted-firmware-m/tfm-prefix/src/tfm-stamp${cfgdir}") # cfgdir has leading slash
endif()
