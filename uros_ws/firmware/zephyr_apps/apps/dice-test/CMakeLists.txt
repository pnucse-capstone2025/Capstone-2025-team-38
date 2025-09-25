# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
add_definitions(-DRMW_UXRCE_LOG=1)

set(COMPATIBLE_BOARDS disco_l475_iot1 olimex_stm32_e407 native_posix nucleo_h743zi nucleo_f746zg blackpill_f411ce blackpill_f401ce nucleo_l552ze_q)
if(NOT ${BOARD} IN_LIST COMPATIBLE_BOARDS)
    message(FATAL_ERROR "App $ENV{UROS_APP} not compatible with board ${BOARD}")
endif()

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(microrosapp C CXX)
#[[
add_subdirectory(lib/hash)

target_link_libraries(app PRIVATE
    hash
)
]]
set(microros_src_dir   ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/microros_extensions)
set(microros_build_dir ${MICRO_ROS_FIRMWARE_DIR}/build/microros_extensions)

if(${MICRO_ROS_TRANSPORT} STREQUAL "serial")
    add_compile_definitions(MICRO_ROS_TRANSPORT_SERIAL)
elseif(${MICRO_ROS_TRANSPORT} STREQUAL "udp")
    add_compile_definitions(MICRO_ROS_TRANSPORT_UDP)
elseif(${MICRO_ROS_TRANSPORT} STREQUAL "serial-usb")
    add_compile_definitions(MICRO_ROS_TRANSPORT_SERIALUSB)
endif()

FILE(GLOB app_sources
    src/*.c
    ${microros_src_dir}/microros_transports.c)

include_directories(${microros_src_dir})

target_sources(app PRIVATE ${app_sources})


#[[
add_subdirectory(lib/hash)
add_subdirectory(lib/open-dice)
target_include_directories(app PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/hash/include
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/open-dice/include
)

target_include_directories(
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/include
)
]]

# add_subdirectory(${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/hash)
# target_link_libraries(app PUBLIC hash)

target_include_directories(app PRIVATE 
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/hash/include
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/tinycrypt/lib/include
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/include
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/include/dice/config/boringssl_multialg
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/include/dice/config/default
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/include/dice/ops
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/include
)
target_sources(app PRIVATE 
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/hash/src/hash.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/src/dice.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/src/clear_memory.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/src/mbedtls_ops.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/apps/dice-test/lib/open-dice/src/utils.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/x509write_crt.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/x509_create.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/asn1write.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/asn1parse.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/hmac_drbg.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/ecp.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/ecdsa.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/ecp_curves.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/hkdf.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/pkwrite.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/pem.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/oid.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/base64.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/des.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/aes.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/platform_util.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/bignum.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/md.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/rsa.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/rsa_internal.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/md5.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/sha1.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/sha256.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/sha512.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/pk.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/pk_wrap.c
    ${MICRO_ROS_FIRMWARE_DIR}/zephyrproject/modules/crypto/mbedtls/mbedtls/library/ripemd160.c

)

zephyr_get_include_directories_for_lang_as_string(       C includes)
zephyr_get_system_include_directories_for_lang_as_string(C system_includes)
zephyr_get_compile_definitions_for_lang_as_string(       C definitions)
zephyr_get_compile_options_for_lang_as_string(           C options)

zephyr_get_include_directories_for_lang_as_string(       CXX includes_cxx)
zephyr_get_system_include_directories_for_lang_as_string(CXX system_includes_cxx)
zephyr_get_compile_definitions_for_lang_as_string(       CXX definitions_cxx)
zephyr_get_compile_options_for_lang_as_string(           CXX options_cxx)


set(external_project_cflags
    "${includes} ${definitions} ${options} ${system_includes}"
    )

set(external_project_cxxflags
    "${includes_cxx} ${definitions_cxx} ${options_cxx} ${system_includes_cxx}"
    )

include(ExternalProject)

set(microros_src_dir   ${MICRO_ROS_FIRMWARE_DIR}/zephyr_apps/microros_extensions)
set(microros_build_dir ${MICRO_ROS_FIRMWARE_DIR}/build/microros_extensions)

if(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
    set(submake "$(MAKE)")
else()
    set(submake "make")
endif()

ExternalProject_Add(
    microroslib_project                 # Name for custom target
    PREFIX     ${microros_build_dir}    # Root dir for entire project
    SOURCE_DIR ${microros_src_dir}
    BINARY_DIR ${microros_src_dir}      # This particular build system is invoked from the root
    CONFIGURE_COMMAND ""                # Skip configuring the project, e.g. with autoconf
    BUILD_COMMAND
        ${submake}
            PREFIX=${microros_src_dir}
            CC=${CMAKE_C_COMPILER}
            AR=${CMAKE_AR}
            CFLAGS=${external_project_cflags}
            CXX=${CMAKE_CXX_COMPILER}
            CXXFLAGS=${external_project_cxxflags}
            APP_META=$ENV{UROS_APP_FOLDER}/app-colcon.meta

    INSTALL_COMMAND ""      # This particular build system has no install command
    BUILD_BYPRODUCTS ${MICROROS_LIB_DIR}/libmicroros.a
    )

file(MAKE_DIRECTORY ${MICRO_ROS_FIRMWARE_DIR}/mcu_ws/install)
file(MAKE_DIRECTORY ${MICRO_ROS_FIRMWARE_DIR}/mcu_ws/install/include)

set(MICROROS_LIB_DIR     ${MICRO_ROS_FIRMWARE_DIR}/mcu_ws/install)
set(MICROROS_INCLUDE_DIR ${MICRO_ROS_FIRMWARE_DIR}/mcu_ws/install/include)

add_library(microroslib STATIC IMPORTED GLOBAL)
add_dependencies(
    microroslib
    microroslib_project
)

add_dependencies(microroslib_project offsets_h)

set_target_properties(microroslib PROPERTIES IMPORTED_LOCATION             ${MICROROS_LIB_DIR}/libmicroros.a)
set_target_properties(microroslib PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${MICROROS_INCLUDE_DIR})

execute_process(
    COMMAND
        make get_package_names
    WORKING_DIRECTORY
        ${microros_src_dir}
    OUTPUT_VARIABLE
        INCLUDE_ROS2_PACKAGES
    )

foreach(pkg ${INCLUDE_ROS2_PACKAGES})
    file(MAKE_DIRECTORY ${MICROROS_INCLUDE_DIR}/${pkg})
    target_include_directories(microroslib INTERFACE ${MICROROS_INCLUDE_DIR}/${pkg})
endforeach()

target_link_libraries(app PUBLIC microroslib)
