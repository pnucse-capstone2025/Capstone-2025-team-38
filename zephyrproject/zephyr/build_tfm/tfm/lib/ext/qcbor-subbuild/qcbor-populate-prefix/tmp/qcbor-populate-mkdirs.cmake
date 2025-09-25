# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-src"
  "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-build"
  "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-subbuild/qcbor-populate-prefix"
  "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-subbuild/qcbor-populate-prefix/tmp"
  "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-subbuild/qcbor-populate-prefix/src/qcbor-populate-stamp"
  "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-subbuild/qcbor-populate-prefix/src"
  "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-subbuild/qcbor-populate-prefix/src/qcbor-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-subbuild/qcbor-populate-prefix/src/qcbor-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tmdals010126/zephyrproject/zephyr/build_tfm/tfm/lib/ext/qcbor-subbuild/qcbor-populate-prefix/src/qcbor-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
