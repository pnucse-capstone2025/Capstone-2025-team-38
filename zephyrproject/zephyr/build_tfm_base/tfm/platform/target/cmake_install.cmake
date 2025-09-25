# Install script for directory: /home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "MinSizeRel")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/tmdals010126/zephyr-sdk-0.17.0/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/linker_scripts/appli_ns.icf;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/linker_scripts/appli_ns.ld;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/linker_scripts/appli_ns.sct")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/linker_scripts" TYPE FILE MESSAGE_NEVER FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/hal/template/iar/appli_ns.icf"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/hal/template/gcc/appli_ns.ld"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/hal/template/armclang/appli_ns.sct"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/Device/Include")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/Device" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/Device/Include")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/test_interrupt.h;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/Driver_USART.h;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/Driver_Common.h;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/tfm_plat_defs.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include" TYPE FILE MESSAGE_NEVER FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/common/test_interrupt.h"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_USART.h"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_Common.h"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/include/tfm_plat_defs.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Inc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Inc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/CMSIS_Driver/low_level_com.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/CMSIS_Driver" TYPE FILE MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/hal/CMSIS_Driver/low_level_com.c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/Device/Source/system_stm32l5xx.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/Device/Source" TYPE FILE MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/Device/Source/Templates/system_stm32l5xx.c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/cmsis.h;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/target_cfg.h;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/tfm_peripherals_def.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include" TYPE FILE MESSAGE_NEVER FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/boards/cmsis.h"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/boards/target_cfg.h"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/boards/tfm_peripherals_def.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_dma.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_pwr.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_pwr_ex.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_rcc.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_gpio.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_uart.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_uart_ex.c;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src/stm32l5xx_hal_cortex.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/hal/Src" TYPE FILE MESSAGE_NEVER FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_dma.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_pwr.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_pwr_ex.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_rcc.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_gpio.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_uart.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_uart_ex.c"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/hal/Src/stm32l5xx_hal_cortex.c"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/scripts/stm_tool.py;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/scripts/bin2hex.py;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/scripts/macro_parser.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/scripts" TYPE FILE MESSAGE_NEVER FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/scripts/stm_tool.py"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/scripts/bin2hex.py"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/common/stm32l5xx/../../../../../../bl2/ext/mcuboot/scripts/macro_parser.py"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/regression.sh;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/preprocess.sh;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/TFM_UPDATE.sh;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/TFM_BIN2HEX.sh;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/postbuild.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns" TYPE FILE MESSAGE_NEVER PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/scripts/regression.sh"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/scripts/gcc/preprocess.sh"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/scripts/TFM_UPDATE.sh"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/scripts/TFM_BIN2HEX.sh"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/scripts/postbuild.sh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/cpuarch.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform" TYPE FILE MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/cpuarch.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/Device/Source/startup_stm32l5xx_ns.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/Device/Source" TYPE FILE MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/stm32l5xx/Device/Source/startup_stm32l5xx_ns.c")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/ns/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/include")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/crypto_accelerator_config.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include" TYPE FILE MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/accelerator/crypto_accelerator_config.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/include" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/stm/nucleo_l552ze_q/../common/hal/accelerator/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/partition/flash_layout.h;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/partition/region_defs.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/platform/partition" TYPE FILE MESSAGE_NEVER FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/partition/flash_layout.h"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/partition/region_defs.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/flash_layout.h;/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/region_defs.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns" TYPE FILE MESSAGE_NEVER FILES
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/partition/flash_layout.h"
    "/home/tmdals010126/zephyrproject/modules/tee/tf-m/trusted-firmware-m/config/../platform/ext/target/stm/nucleo_l552ze_q/partition/region_defs.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns/image_macros_to_preprocess_bl2.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/api_ns" TYPE FILE MESSAGE_NEVER FILES "/home/tmdals010126/zephyrproject/zephyr/build_tfm_base/tfm/platform/target/image_macros_to_preprocess_bl2.c")
endif()

