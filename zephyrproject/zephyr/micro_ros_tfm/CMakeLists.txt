# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/modules/libmicroros)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(microros_tfm_app)

message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/psa_attestation.c)
target_sources(app PRIVATE src/psa_crypto.c)
target_sources(app PRIVATE src/shell.c)
target_sources(app PRIVATE src/util_app_cfg.c)
target_sources(app PRIVATE src/util_app_log.c)
target_sources(app PRIVATE src/util_sformat.c)

target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/configs
)


target_include_directories(app PRIVATE
  $<TARGET_PROPERTY:tfm,TFM_BINARY_DIR>/api_ns/interface/include
)

set_property(TARGET zephyr_property_target
             APPEND PROPERTY TFM_CMAKE_OPTIONS
             -DPROJECT_CONFIG_HEADER_FILE=${CMAKE_CURRENT_SOURCE_DIR}/src/configs/config_tfm.h
)

zephyr_include_directories(${APPLICATION_SOURCE_DIR}/src/configs)
zephyr_include_directories(${APPLICATION_SOURCE_DIR}/src)