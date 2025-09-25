/*
 * Copyright (c) 2024 Arm Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file host_css_memory_map.h
 * \brief This file contains addresses that are defined in the compute
 *        subsystem (CSS) memory map.
 */

#ifndef __HOST_CSS_MEMORY_MAP_H__
#define __HOST_CSS_MEMORY_MAP_H__

#include "host_css_io_block_memory_map.h"

/* AP Shared (ARSM) SRAM base address */
#define HOST_AP_SHARED_SRAM_PHYS_BASE               0x000000000ULL
/* AP Shared (ARSM) SRAM end address */
#define HOST_AP_SHARED_SRAM_PHYS_LIMIT              0x0000FFFFFULL

/* AP Memory Expansion region 1 base address */
#define HOST_AP_MEM_EXP_1_PHYS_BASE                 0x008000000ULL
/* AP Memory Expansion region 1 end address */
#define HOST_AP_MEM_EXP_1_PHYS_LIMIT                0x00FFFFFFFULL

/* System Control block NI-Tower base address */
#define HOST_SYSCTRL_NI_TOWER_PHYS_BASE             0x020000000ULL
/* System Control block NI-Tower end address */
#define HOST_SYSCTRL_NI_TOWER_PHYS_LIMIT            0x020FFFFFFULL
/* IO Block NI-Tower base address */
#define HOST_IO_MACRO_NI_TOWER_PHYS_BASE            0x021000000ULL
/* IO Block NI-Tower end address */
#define HOST_IO_MACRO_NI_TOWER_PHYS_LIMIT           0x021FFFFFFULL
/* Peripheral block NI-Tower base address */
#define HOST_PERIPH_NI_TOWER_PHYS_BASE              0x022000000ULL
/* Peripheral block NI-Tower end address */
#define HOST_PERIPH_NI_TOWER_PHYS_LIMIT             0x022FFFFFFULL
/* System Fabric NI-Tower base address */
#define HOST_FABRIC_NI_TOWER_PHYS_BASE              0x023000000ULL
/* System Fabric NI-Tower end address */
#define HOST_FABRIC_NI_TOWER_PHYS_LIMIT             0x023FFFFFFULL

/* Non-secure Uart peripheral base address */
#define HOST_NS_UART_PHYS_BASE                      0x02A400000ULL
/* Non-secure Uart peripheral end address */
#define HOST_NS_UART_PHYS_LIMIT                     0x02A40FFFFULL
/* Secure Uart peripheral base address */
#define HOST_S_UART_PHYS_BASE                       0x02A410000ULL
/* Secure Uart peripheral end address */
#define HOST_S_UART_PHYS_LIMIT                      0x02A41FFFFULL
/* RMM Uart peripheral base address */
#define HOST_RMM_NS_UART_PHYS_BASE                  0x02A420000ULL
/* RMM Uart peripheral end address */
#define HOST_RMM_NS_UART_PHYS_LIMIT                 0x02A42FFFFULL

/* Generic refclk cntcontrol register base address */
#define HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_BASE    0x02A430000ULL
/* Generic refclk cntcontrol register end address */
#define HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_LIMIT   0x02A43FFFFULL
/* Non-secure AP watchdog base address */
#define HOST_AP_NS_WDOG_PHYS_BASE                   0x02A440000ULL
/* Non-secure AP watchdog end address */
#define HOST_AP_NS_WDOG_PHYS_LIMIT                  0x02A45FFFFULL
/* Root AP watchdog base address */
#define HOST_AP_RT_WDOG_PHYS_BASE                   0x02A460000ULL
/* Root AP watchdog end address */
#define HOST_AP_RT_WDOG_PHYS_LIMIT                  0x02A47FFFFULL
/* Secure AP watchdog base address */
#define HOST_AP_S_WDOG_PHYS_BASE                    0x02A480000ULL
/* Secure AP watchdog end address */
#define HOST_AP_S_WDOG_PHYS_LIMIT                   0x02A49FFFFULL
/* SID register base address */
#define HOST_SID_PHYS_BASE                          0x02A4A0000ULL
/* SID register end address */
#define HOST_SID_PHYS_LIMIT                         0x02A4AFFFFULL

/* Secure AP ECC error record register base address */
#define HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_BASE        0x02A4B0000ULL
/* Secure AP ECC error record register end address */
#define HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT       0x02A4BFFFFULL
/* Non-Secure AP ECC error record register base address */
#define HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_BASE       0x02A4C0000ULL
/* Non-Secure AP ECC error record register end address */
#define HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x02A4CFFFFULL
/* Root AP ECC error record register base address */
#define HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_BASE       0x02A4D0000ULL
/* Root AP ECC error record register end address */
#define HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x02A4DFFFFULL
/* Realm AP ECC error record register base address */
#define HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_BASE       0x02A4E0000ULL
/* Realm AP ECC error record register end address */
#define HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x02A4EFFFFULL
/* Secure SCP ECC error record register base address */
#define HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_BASE       0x02A4F0000ULL
/* Secure SCP ECC error record register end address */
#define HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x02A4FFFFFULL
/* Non-secure SCP ECC error record register base address */
#define HOST_SCP_NS_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A500000ULL
/* Non-secure SCP ECC error record register end address */
#define HOST_SCP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A50FFFFULL
/* Root SCP ECC error record register base address */
#define HOST_SCP_RT_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A510000ULL
/* Root SCP ECC error record register end address */
#define HOST_SCP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A51FFFFULL
/* Realm SCP ECC error record register base address */
#define HOST_SCP_RL_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A520000ULL
/* Realm SCP ECC error record register end address */
#define HOST_SCP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A52FFFFULL
/* Secure MCP ECC error record register base address */
#define HOST_MCP_S_ARSM_RAM_ECC_REC_PHYS_BASE       0x02A530000ULL
/* Secure MCP ECC error record register end address */
#define HOST_MCP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x02A53FFFFULL
/* Non-secure MCP ECC error record register base address */
#define HOST_MCP_NS_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A540000ULL
/* Non-secure MCP ECC error record register end address */
#define HOST_MCP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A54FFFFULL
/* Root MCP ECC error record register base address */
#define HOST_MCP_RT_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A550000ULL
/* Root MCP ECC error record register end address */
#define HOST_MCP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A55FFFFULL
/* Realm MCP ECC error record register base address */
#define HOST_MCP_RL_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A560000ULL
/* Realm MCP ECC error record register end address */
#define HOST_MCP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A56FFFFULL
/* Secure RSE ECC error record register base address */
#define HOST_RSE_S_ARSM_RAM_ECC_REC_PHYS_BASE       0x02A570000ULL
/* Secure RSE ECC error record register end address */
#define HOST_RSE_S_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x02A57FFFFULL
/* Non-secure RSE ECC error record register base address */
#define HOST_RSE_NS_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A580000ULL
/* Non-secure RSE ECC error record register end address */
#define HOST_RSE_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A58FFFFULL
/* Root RSE ECC error record register base address */
#define HOST_RSE_RT_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A590000ULL
/* Root RSE ECC error record register end address */
#define HOST_RSE_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A59FFFFULL
/* Realm RSE ECC error record register base address */
#define HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_BASE      0x02A5A0000ULL
/* Realm RSE ECC error record register end address */
#define HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x02A5AFFFFULL

/* Secure RSE ECC error record register for RSM base address */
#define HOST_RSE_S_RSM_RAM_ECC_REC_PHYS_BASE        0x02A5B0000ULL
/* Secure RSE ECC error record register for RSM end address */
#define HOST_RSE_S_RSM_RAM_ECC_REC_PHYS_LIMIT       0x02A5BFFFFULL
/* Non-secure RSE ECC error record register for RSM base address */
#define HOST_RSE_NS_RSM_RAM_ECC_REC_PHYS_BASE       0x02A5C0000ULL
/* Non-secure RSE ECC error record register for RSM end address */
#define HOST_RSE_NS_RSM_RAM_ECC_REC_PHYS_LIMIT      0x02A5CFFFFULL
/* Secure SCP ECC error record register for RSM base address */
#define HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_BASE        0x02A5D0000ULL
/* Secure SCP ECC error record register for RSM end address */
#define HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_LIMIT       0x02A5DFFFFULL
/* Non-secure SCP ECC error record register for RSM base address */
#define HOST_SCP_NS_RSM_RAM_ECC_REC_PHYS_BASE       0x02A5E0000ULL
/* Non-secure SCP ECC error record register for RSM end address */
#define HOST_SCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT      0x02A5EFFFFULL
/* Secure MCP ECC error record register for RSM base address */
#define HOST_MCP_S_RSM_RAM_ECC_REC_PHYS_BASE        0x02A5F0000ULL
/* Secure MCP ECC error record register for RSM end address */
#define HOST_MCP_S_RSM_RAM_ECC_REC_PHYS_LIMIT       0x02A5FFFFFULL
/* Non-secure MCP ECC error record register for RSM base address */
#define HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_BASE       0x02A600000ULL
/* Non-secure MCP ECC error record register for RSM end address */
#define HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT      0x02A60FFFFULL

/* Generic refclk cntread register base address */
#define HOST_GENERIC_REFCLK_CNTREAD_PHYS_BASE       0x02A800000ULL
/* Generic refclk cntread register end address */
#define HOST_GENERIC_REFCLK_CNTREAD_PHYS_LIMIT      0x02A80FFFFULL
/* AP refclk cntctl register base address */
#define HOST_AP_REFCLK_CNTCTL_PHYS_BASE             0x02A810000ULL
/* AP refclk cntctl register end address */
#define HOST_AP_REFCLK_CNTCTL_PHYS_LIMIT            0x02A81FFFFULL
/* AP refclk cntbase0 register base address */
#define HOST_AP_S_REFCLK_CNTBASE0_PHYS_BASE         0x02A820000ULL
/* AP refclk cntbase0 register end address */
#define HOST_AP_S_REFCLK_CNTBASE0_PHYS_LIMIT        0x02A82FFFFULL
/* AP refclk cntbase1 register base address */
#define HOST_AP_NS_REFCLK_CNTBASE1_PHYS_BASE        0x02A830000ULL
/* AP refclk cntbase1 register end address */
#define HOST_AP_NS_REFCLK_CNTBASE1_PHYS_LIMIT       0x02A83FFFFULL

/* Non-secure AP<->SCP MHUv3 Send and recieve registers base address */
#define HOST_AP_NS_SCP_MHUV3_PHYS_BASE              0x02A900000ULL
/* Non-secure AP<->SCP MHUv3 Send and recieve registers end address */
#define HOST_AP_NS_SCP_MHUV3_PHYS_LIMIT             0x02A91FFFFULL
/* Secure AP<->SCP MHUv3 Send and recieve registers base address */
#define HOST_AP_S_SCP_MHUV3_PHYS_BASE               0x02A920000ULL
/* Secure AP<->SCP MHUv3 Send and recieve registers end address */
#define HOST_AP_S_SCP_MHUV3_PHYS_LIMIT              0x02A93FFFFULL
/* Root AP<->SCP MHUv3 Send and recieve registers base address */
#define HOST_AP_RT_SCP_MHUV3_PHYS_BASE              0x02A940000ULL
/* Root AP<->SCP MHUv3 Send and recieve registers end address */
#define HOST_AP_RT_SCP_MHUV3_PHYS_LIMIT             0x02A95FFFFULL

/* Non-secure AP<->MCP MHUv3 Send and recieve registers base address */
#define HOST_AP_NS_MCP_MHUV3_SEND_BASE              0x02AA00000ULL
/* Non-secure AP<->MCP MHUv3 Send and recieve registers end address */
#define HOST_AP_NS_MCP_MHUV3_SEND_LIMIT             0x02AA1FFFFULL
/* Secure AP<->MCP MHUv3 Send and recieve registers base address */
#define HOST_AP_S_MCP_MHUV3_PHYS_BASE               0x02AA20000ULL
/* Secure AP<->MCP MHUv3 Send and recieve registers end address */
#define HOST_AP_S_MCP_MHUV3_PHYS_LIMIT              0x02AA3FFFFULL
/* Root AP<->MCP MHUv3 Send and recieve registers base address */
#define HOST_AP_RT_MCP_MHUV3_PHYS_BASE              0x02AA40000ULL
/* Root AP<->MCP MHUv3 Send and recieve registers end address */
#define HOST_AP_RT_MCP_MHUV3_PHYS_LIMIT             0x02AA5FFFFULL

/* Non-secure AP<->RSE MHUv3 Send and recieve registers base address */
#define HOST_AP_NS_RSE_MHUV3_PHYS_BASE              0x02AB00000ULL
/* Non-secure AP<->RSE MHUv3 Send and recieve registers end address */
#define HOST_AP_NS_RSE_MHUV3_PHYS_LIMIT             0x02AB1FFFFULL
/* Secure AP<->RSE MHUv3 Send and recieve registers base address */
#define HOST_AP_S_RSE_MHUV3_PHYS_BASE               0x02AB20000ULL
/* Secure AP<->RSE MHUv3 Send and recieve registers end address */
#define HOST_AP_S_RSE_MHUV3_PHYS_LIMIT              0x02AB3FFFFULL
/* Root AP<->RSE MHUv3 Send and recieve registers base address */
#define HOST_AP_RT_RSE_MHUV3_PHYS_BASE              0x02AB40000ULL
/* Root AP<->RSE MHUv3 Send and recieve registers end address */
#define HOST_AP_RT_RSE_MHUV3_PHYS_LIMIT             0x02AB5FFFFULL
/* Realm AP<->RSE MHUv3 Send and recieve registers base address */
#define HOST_AP_RL_RSE_MHUV3_PHYS_BASE              0x02AB60000ULL
/* Realm AP<->RSE MHUv3 Send and recieve registers end address */
#define HOST_AP_RL_RSE_MHUV3_PHYS_LIMIT             0x02AB7FFFFULL

/* SCP<->SCP MHU Send registers base address */
#define HOST_SCP_TO_SCP_MHU_PHYS_BASE               0x02AC00000ULL
/* SCP<->SCP MHU Send registers end address */
#define HOST_SCP_TO_SCP_MHU_PHYS_LIMIT              0x02AC2FFFFULL
/* MCP<->MCP MHU Send registers base address */
#define HOST_MCP_TO_MCP_MHU_PHYS_BASE               0x02AC60000ULL
/* MCP<->MCP MHU Send registers end address */
#define HOST_MCP_TO_MCP_MHU_PHYS_LIMIT              0x02AC8FFFFULL
/* RSE<->RSE MHU Send registers base address */
#define HOST_RSE_TO_RSE_MHU_PHYS_BASE               0x02ACC0000ULL
/* RSE<->RSE MHU Send registers end address */
#define HOST_RSE_TO_RSE_MHU_PHYS_LIMIT              0x02ACEFFFFULL

/* Macro wrappers for MHU physical address for cross chip send frames */
#define HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(chip_id_a, chip_id_b)     \
        HOST_RSE_##chip_id_a##_TO_RSE_##chip_id_b##_MHU_FRAME_PHYS_BASE
#define HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(chip_id_a, chip_id_b)    \
        HOST_RSE_##chip_id_a##_TO_RSE_##chip_id_b##_MHU_FRAME_PHYS_LIMIT
#define HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(chip_id_a, chip_id_b)     \
        HOST_SCP_##chip_id_a##_TO_SCP_##chip_id_b##_MHU_FRAME_PHYS_BASE
#define HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(chip_id_a, chip_id_b)    \
        HOST_SCP_##chip_id_a##_TO_SCP_##chip_id_b##_MHU_FRAME_PHYS_LIMIT
#define HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(chip_id_a, chip_id_b)     \
        HOST_MCP_##chip_id_a##_TO_MCP_##chip_id_b##_MHU_FRAME_PHYS_BASE
#define HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(chip_id_a, chip_id_b)    \
        HOST_MCP_##chip_id_a##_TO_MCP_##chip_id_b##_MHU_FRAME_PHYS_LIMIT

#define HOST_RSE_0_TO_RSE_1_MHU_FRAME_PHYS_BASE     0x102ACC0000ULL
#define HOST_RSE_0_TO_RSE_1_MHU_FRAME_PHYS_LIMIT    0x102ACCFFFFULL
#define HOST_RSE_0_TO_RSE_2_MHU_FRAME_PHYS_BASE     0x202ACC0000ULL
#define HOST_RSE_0_TO_RSE_2_MHU_FRAME_PHYS_LIMIT    0x202ACCFFFFULL
#define HOST_RSE_0_TO_RSE_3_MHU_FRAME_PHYS_BASE     0x302ACC0000ULL
#define HOST_RSE_0_TO_RSE_3_MHU_FRAME_PHYS_LIMIT    0x302ACCFFFFULL
#define HOST_RSE_1_TO_RSE_0_MHU_FRAME_PHYS_BASE     0x002ACC0000ULL
#define HOST_RSE_1_TO_RSE_0_MHU_FRAME_PHYS_LIMIT    0x002ACCFFFFULL
#define HOST_RSE_1_TO_RSE_2_MHU_FRAME_PHYS_BASE     0x202ACD0000ULL
#define HOST_RSE_1_TO_RSE_2_MHU_FRAME_PHYS_LIMIT    0x202ACDFFFFULL
#define HOST_RSE_1_TO_RSE_3_MHU_FRAME_PHYS_BASE     0x302ACD0000ULL
#define HOST_RSE_1_TO_RSE_3_MHU_FRAME_PHYS_LIMIT    0x302ACDFFFFULL
#define HOST_RSE_2_TO_RSE_0_MHU_FRAME_PHYS_BASE     0x002ACD0000ULL
#define HOST_RSE_2_TO_RSE_0_MHU_FRAME_PHYS_LIMIT    0x002ACDFFFFULL
#define HOST_RSE_2_TO_RSE_1_MHU_FRAME_PHYS_BASE     0x102ACD0000ULL
#define HOST_RSE_2_TO_RSE_1_MHU_FRAME_PHYS_LIMIT    0x102ACDFFFFULL
#define HOST_RSE_2_TO_RSE_3_MHU_FRAME_PHYS_BASE     0x302ACE0000ULL
#define HOST_RSE_2_TO_RSE_3_MHU_FRAME_PHYS_LIMIT    0x302ACEFFFFULL
#define HOST_RSE_3_TO_RSE_0_MHU_FRAME_PHYS_BASE     0x002ACE0000ULL
#define HOST_RSE_3_TO_RSE_0_MHU_FRAME_PHYS_LIMIT    0x002ACEFFFFULL
#define HOST_RSE_3_TO_RSE_1_MHU_FRAME_PHYS_BASE     0x102ACE0000ULL
#define HOST_RSE_3_TO_RSE_1_MHU_FRAME_PHYS_LIMIT    0x102ACEFFFFULL
#define HOST_RSE_3_TO_RSE_2_MHU_FRAME_PHYS_BASE     0x202ACE0000ULL
#define HOST_RSE_3_TO_RSE_2_MHU_FRAME_PHYS_LIMIT    0x202ACEFFFFULL
#define HOST_SCP_0_TO_SCP_1_MHU_FRAME_PHYS_BASE     0x102AC00000ULL
#define HOST_SCP_0_TO_SCP_1_MHU_FRAME_PHYS_LIMIT    0x102AC0FFFFULL
#define HOST_SCP_0_TO_SCP_2_MHU_FRAME_PHYS_BASE     0x202AC00000ULL
#define HOST_SCP_0_TO_SCP_2_MHU_FRAME_PHYS_LIMIT    0x202AC0FFFFULL
#define HOST_SCP_0_TO_SCP_3_MHU_FRAME_PHYS_BASE     0x302AC00000ULL
#define HOST_SCP_0_TO_SCP_3_MHU_FRAME_PHYS_LIMIT    0x302AC0FFFFULL
#define HOST_SCP_1_TO_SCP_0_MHU_FRAME_PHYS_BASE     0x002AC00000ULL
#define HOST_SCP_1_TO_SCP_0_MHU_FRAME_PHYS_LIMIT    0x002AC0FFFFULL
#define HOST_SCP_1_TO_SCP_2_MHU_FRAME_PHYS_BASE     0x202AC10000ULL
#define HOST_SCP_1_TO_SCP_2_MHU_FRAME_PHYS_LIMIT    0x202AC1FFFFULL
#define HOST_SCP_1_TO_SCP_3_MHU_FRAME_PHYS_BASE     0x302AC10000ULL
#define HOST_SCP_1_TO_SCP_3_MHU_FRAME_PHYS_LIMIT    0x302AC1FFFFULL
#define HOST_SCP_2_TO_SCP_0_MHU_FRAME_PHYS_BASE     0x002AC10000ULL
#define HOST_SCP_2_TO_SCP_0_MHU_FRAME_PHYS_LIMIT    0x002AC1FFFFULL
#define HOST_SCP_2_TO_SCP_1_MHU_FRAME_PHYS_BASE     0x102AC10000ULL
#define HOST_SCP_2_TO_SCP_1_MHU_FRAME_PHYS_LIMIT    0x102AC1FFFFULL
#define HOST_SCP_2_TO_SCP_3_MHU_FRAME_PHYS_BASE     0x302AC20000ULL
#define HOST_SCP_2_TO_SCP_3_MHU_FRAME_PHYS_LIMIT    0x302AC2FFFFULL
#define HOST_SCP_3_TO_SCP_0_MHU_FRAME_PHYS_BASE     0x002AC20000ULL
#define HOST_SCP_3_TO_SCP_0_MHU_FRAME_PHYS_LIMIT    0x002AC2FFFFULL
#define HOST_SCP_3_TO_SCP_1_MHU_FRAME_PHYS_BASE     0x102AC20000ULL
#define HOST_SCP_3_TO_SCP_1_MHU_FRAME_PHYS_LIMIT    0x102AC2FFFFULL
#define HOST_SCP_3_TO_SCP_2_MHU_FRAME_PHYS_BASE     0x202AC20000ULL
#define HOST_SCP_3_TO_SCP_2_MHU_FRAME_PHYS_LIMIT    0x202AC2FFFFULL
#define HOST_MCP_0_TO_MCP_1_MHU_FRAME_PHYS_BASE     0x102AC60000ULL
#define HOST_MCP_0_TO_MCP_1_MHU_FRAME_PHYS_LIMIT    0x102AC6FFFFULL
#define HOST_MCP_0_TO_MCP_2_MHU_FRAME_PHYS_BASE     0x202AC60000ULL
#define HOST_MCP_0_TO_MCP_2_MHU_FRAME_PHYS_LIMIT    0x202AC6FFFFULL
#define HOST_MCP_0_TO_MCP_3_MHU_FRAME_PHYS_BASE     0x302AC60000ULL
#define HOST_MCP_0_TO_MCP_3_MHU_FRAME_PHYS_LIMIT    0x302AC6FFFFULL
#define HOST_MCP_1_TO_MCP_0_MHU_FRAME_PHYS_BASE     0x002AC60000ULL
#define HOST_MCP_1_TO_MCP_0_MHU_FRAME_PHYS_LIMIT    0x002AC6FFFFULL
#define HOST_MCP_1_TO_MCP_2_MHU_FRAME_PHYS_BASE     0x202AC70000ULL
#define HOST_MCP_1_TO_MCP_2_MHU_FRAME_PHYS_LIMIT    0x202AC7FFFFULL
#define HOST_MCP_1_TO_MCP_3_MHU_FRAME_PHYS_BASE     0x302AC70000ULL
#define HOST_MCP_1_TO_MCP_3_MHU_FRAME_PHYS_LIMIT    0x302AC7FFFFULL
#define HOST_MCP_2_TO_MCP_0_MHU_FRAME_PHYS_BASE     0x002AC70000ULL
#define HOST_MCP_2_TO_MCP_0_MHU_FRAME_PHYS_LIMIT    0x002AC7FFFFULL
#define HOST_MCP_2_TO_MCP_1_MHU_FRAME_PHYS_BASE     0x102AC70000ULL
#define HOST_MCP_2_TO_MCP_1_MHU_FRAME_PHYS_LIMIT    0x102AC7FFFFULL
#define HOST_MCP_2_TO_MCP_3_MHU_FRAME_PHYS_BASE     0x302AC80000ULL
#define HOST_MCP_2_TO_MCP_3_MHU_FRAME_PHYS_LIMIT    0x302AC8FFFFULL
#define HOST_MCP_3_TO_MCP_0_MHU_FRAME_PHYS_BASE     0x002AC80000ULL
#define HOST_MCP_3_TO_MCP_0_MHU_FRAME_PHYS_LIMIT    0x002AC8FFFFULL
#define HOST_MCP_3_TO_MCP_1_MHU_FRAME_PHYS_BASE     0x102AC80000ULL
#define HOST_MCP_3_TO_MCP_1_MHU_FRAME_PHYS_LIMIT    0x102AC8FFFFULL
#define HOST_MCP_3_TO_MCP_2_MHU_FRAME_PHYS_BASE     0x202AC80000ULL
#define HOST_MCP_3_TO_MCP_2_MHU_FRAME_PHYS_LIMIT    0x202AC8FFFFULL

/* Timer synchronization register base address */
#define HOST_SYNCNT_MSTUPDTVAL_ADDR_PHYS_BASE       0x02B100000ULL
/* Timer synchronization register end address */
#define HOST_SYNCNT_MSTUPDTVAL_ADDR_PHYS_LIMIT      0x02B12FFFFULL

/* STM base address */
#define HOST_STM_PHYS_BASE                          0x02E000000ULL
/* STM end address */
#define HOST_STM_PHYS_LIMIT                         0x02EFFFFFFULL

/* Shared SRAM for RSM base address */
#define HOST_RSM_SRAM_PHYS_BASE                     0x02F000000ULL
/* Shared SRAM for RSM end address */
#define HOST_RSM_SRAM_PHYS_LIMIT                    0x02F3FFFFFULL

/* GIC-700 base address */
#define HOST_GIC_700_PHYS_BASE                      0x030000000ULL
/* GIC-700 end address */
#define HOST_GIC_700_PHYS_LIMIT                     0x037FFFFFFULL

/* PCIe NCI Memory space 1 base address */
#define HOST_PCIE_NCI_1_PHYS_BASE                   0x060000000ULL
/* PCIe NCI Memory space 1 end address */
#define HOST_PCIE_NCI_1_PHYS_LIMIT                  0x07FFFFFFFULL

/* DRAM base address */
#define HOST_DRAM_PHYS_BASE                         0x080000000ULL
/* DRAM end address */
#define HOST_DRAM_PHYS_LIMIT                        0x0FFFFFFFFULL

/* CMN GPV base address */
#define HOST_CMN_GPV_PHYS_BASE                      0x100000000ULL
/* CMN GPV end address */
#define HOST_CMN_GPV_PHYS_LIMIT                     0x13FFFFFFFULL

/* Memory controller + MPE register region base address */
#define HOST_MPE_PHYS_BASE                          0x180000000ULL
/* Memory controller + MPE register region end address */
#define HOST_MPE_PHYS_LIMIT                         0x1BFFFFFFFULL

/* LCP peripherals + Cluster utility memory region base address */
#define HOST_CLUST_UTIL_PHYS_BASE                   0x200000000ULL
/* LCP peripherals + Cluster utility memory region end address */
#define HOST_CLUST_UTIL_PHYS_LIMIT                  0x23FFFFFFFULL

/* Base address for IO Block memory region */
#define HOST_IO_BLOCK_PHYS_BASE             HOST_IO_TCU_PHYS_BASE(0)
/* End address for IO Block memory region */
#define HOST_IO_BLOCK_PHYS_LIMIT            HOST_IO_PCIE_CTRL_EXP_PHYS_LIMIT(11)

/* SYSCTRL SMMU base address */
#define HOST_SYSCTRL_SMMU_PHYS_BASE                 0x300000000ULL
/* SYSCTRL SMMU end address */
#define HOST_SYSCTRL_SMMU_PHYS_LIMIT                0x307FFFFFFULL

/* Debug Memory map base address */
#define HOST_DEBUG_MMAP_PHYS_BASE                   0x400000000ULL
/* Debug Memory map end address */
#define HOST_DEBUG_MMAP_PHYS_LIMIT                  0x5FFFFFFFFULL
/* AP Memory Expansion region 2 base address */
#define HOST_AP_MEM_EXP_2_PHYS_BASE                 0x600000000ULL
/* AP Memory Expansion region 2 end address */
#define HOST_AP_MEM_EXP_2_PHYS_LIMIT                0x7FFFFFFFFULL

/* Address offset of AP region of different chips */
#define HOST_AP_CHIP_OFFSET                         0x1000000000ULL
/* Base address of the AP region of the nth chip */
#define HOST_AP_CHIP_N_PHYS_BASE(n)                 (0x0ULL  +                \
                                                     HOST_AP_CHIP_OFFSET * (n))
/* End address of the AP region of the nth chip */
#define HOST_AP_CHIP_N_PHYS_LIMIT(n)                (0xFFFFFFFFFULL +         \
                                                     HOST_AP_CHIP_OFFSET * (n))

/* PCIe NCI Memory space 2 base address */
#define HOST_PCIE_NCI_2_PHYS_BASE                   0x4000000000ULL
/* PCIe NCI Memory space 2 end address */
#define HOST_PCIE_NCI_2_PHYS_LIMIT                  0x403FFFFFFFULL
/* PCIe NCI Memory space 3 base address */
#define HOST_PCIE_NCI_3_PHYS_BASE                   0x4040000000ULL
/* PCIe NCI Memory space 3 end address */
#define HOST_PCIE_NCI_3_PHYS_LIMIT                  0x807FFFFFFFULL

/* AP Memory Expansion region 3 base address */
#define HOST_AP_MEM_EXP_3_PHYS_BASE                 0xC00000000000ULL
/* AP Memory Expansion region 3 end address */
#define HOST_AP_MEM_EXP_3_PHYS_LIMIT                0xFFFFFFFFFFFFULL

#endif /* __HOST_CSS_MEMORY_MAP_H__ */
