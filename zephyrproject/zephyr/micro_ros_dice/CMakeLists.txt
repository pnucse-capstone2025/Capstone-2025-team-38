# SPDX-License-Identifier: Apache-2.0
#[[
cmake_minimum_required(VERSION 3.13.1)

list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/modules/libmicroros)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(microros_sample_app)

target_sources(app PRIVATE src/main.c)
]]

# CMakeLists.txt (프로젝트 루트)

cmake_minimum_required(VERSION 3.13.1)

list(APPEND ZEPHYR_EXTRA_MODULES
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/libmicroros
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/mpu
)



find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(microros_sample_app)

target_sources(app PRIVATE
  src/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/hash/src/hash.c
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/open-dice/src/dice.c
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/open-dice/src/clear_memory.c
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/open-dice/src/mbedtls_ops.c
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/open-dice/src/utils.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/asn1write.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/asn1parse.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/bignum.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/bignum_core.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/constant_time.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/ecdsa.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/ecp.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/ecp_curves.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/hkdf.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/hmac_drbg.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/md.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/md5.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/oid.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/pk.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/pk_wrap.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/pkwrite.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/platform_util.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/ripemd160.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/rsa.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/rsa_alt_helpers.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/sha1.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/sha256.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/sha3.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/sha512.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/x509write_crt.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/library/x509_create.c
)

target_include_directories(app PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/hash/include
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/open-dice/include
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/open-dice/include/dice/config/boringssl_multialg
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/open-dice/include/dice/config/default
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../../modules/crypto/mbedtls/include
)
