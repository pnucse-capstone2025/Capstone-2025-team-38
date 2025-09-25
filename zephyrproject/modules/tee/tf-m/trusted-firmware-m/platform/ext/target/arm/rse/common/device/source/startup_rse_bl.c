/*
 * Copyright (c) 2022-2024 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM55.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */

#include "tfm_hal_device_header.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exception handler that blocks execution. */
__NO_RETURN void exception_handler(void)
{
    while (1);
}

/* No IRQs are enabled at boot, so this handler should be unreachable. In case
 * it is ever reached, disable the IRQ that was triggered and return. In debug
 * builds, block execution to catch the bug.
 */
void invalid_irq_handler(void)
{
#ifndef NDEBUG
    while (1);
#else
    NVIC_DisableIRQ((IRQn_Type)((int32_t)__get_IPSR() - 16));
#endif
}

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
       const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP), /*     Initial Stack Pointer */
  Reset_Handler,                     /*      Reset Handler */
  exception_handler,                 /* -14: NMI Handler */
  exception_handler,                 /* -13: Hard Fault Handler */
  exception_handler,                 /* -12: MPU Fault Handler */
  exception_handler,                 /* -11: Bus Fault Handler */
  exception_handler,                 /* -10: Usage Fault Handler */
  exception_handler,                 /*  -9: Secure Fault Handler */
  0,                                 /*      Reserved */
  0,                                 /*      Reserved */
  0,                                 /*      Reserved */
  exception_handler,                 /*  -5: SVCall Handler */
  exception_handler,                 /*  -4: Debug Monitor Handler */
  0,                                 /*      Reserved */
  exception_handler,                 /*  -2: PendSV Handler */
  exception_handler,                 /*  -1: SysTick Handler */

  invalid_irq_handler,               /*   0: Non-Secure Watchdog Reset Request Handler */
  invalid_irq_handler,               /*   1: Non-Secure Watchdog Handler */
  invalid_irq_handler,               /*   2: SLOWCLK Timer Handler */
  invalid_irq_handler,               /*   3: TIMER 0 Handler */
  invalid_irq_handler,               /*   4: TIMER 1 Handler */
  invalid_irq_handler,               /*   5: TIMER 2 Handler */
  0,                                 /*   6: Reserved */
  0,                                 /*   7: Reserved */
  0,                                 /*   8: Reserved */
  invalid_irq_handler,               /*   9: MPC Combined (Secure) Handler */
  invalid_irq_handler,               /*  10: PPC Combined (Secure) Handler */
  invalid_irq_handler,               /*  11: MSC Combined (Secure) Handler */
  invalid_irq_handler,               /*  12: Bridge Error (Secure) Handler */
  0,                                 /*  13: Reserved */
  invalid_irq_handler,               /*  14: PPU Combined (Secure) Handler */
  0,                                 /*  15: Reserved */
  invalid_irq_handler,               /*  16: NPU0 Handler */
  invalid_irq_handler,               /*  17: NPU1 Handler */
  invalid_irq_handler,               /*  18: NPU2 Handler */
  invalid_irq_handler,               /*  19: NPU3 Handler */
  invalid_irq_handler,               /*  20: KMU (Secure) Handler */
  0,                                 /*  21: Reserved */
  0,                                 /*  22: Reserved */
  0,                                 /*  23: Reserved */
  invalid_irq_handler,               /*  24: DMA350 Combined (Secure) Handler */
  invalid_irq_handler,               /*  25: DMA350 Combined (Non-Secure) Handler */
  invalid_irq_handler,               /*  26: DMA350 Security Violation Handler */
  invalid_irq_handler,               /*  27: TIMER 3 AON Handler */
  invalid_irq_handler,               /*  28: CPU0 CTI IRQ 0 Handler */
  invalid_irq_handler,               /*  29: CPU0 CTI IRQ 1 Handler */
  0,                                 /*  30: Reserved */
  0,                                 /*  31: Reserved */

  /* External interrupts */
  invalid_irq_handler,               /*  32: SAM Critical Security Fault (Secure) Handler */
  invalid_irq_handler,               /*  33: SAM Security Fault (Secure) Handler */
  invalid_irq_handler,               /*  34: GPIO Combined (Secure) Handler */
  invalid_irq_handler,               /*  35: Secure Debug Channel Handler */
  invalid_irq_handler,               /*  36: FPU Exception Handler */
  invalid_irq_handler,               /*  37: SRAM or TRAM Corrected ECC Error (Secure) Handler */
  invalid_irq_handler,               /*  38: Secure I-Cache (Secure) Handler */
  invalid_irq_handler,               /*  39: ATU (Secure) Handler */
  invalid_irq_handler,               /*  40: CMU MHU 0 Sender Handler */
  invalid_irq_handler,               /*  41: CMU MHU 0 Receiver Handler */
  invalid_irq_handler,               /*  42: CMU MHU 1 Sender Handler */
  invalid_irq_handler,               /*  43: CMU MHU 1 Receiver Handler */
  invalid_irq_handler,               /*  44: CMU MHU 2 Sender Handler */
  invalid_irq_handler,               /*  45: CMU MHU 2 Receiver Handler */
  invalid_irq_handler,               /*  46: CMU MHU 3 Sender Handler */
  invalid_irq_handler,               /*  47: CMU MHU 3 Receiver Handler */
  invalid_irq_handler,               /*  48: CMU MHU 4 Sender Handler */
  invalid_irq_handler,               /*  49: CMU MHU 4 Receiver Handler */
  invalid_irq_handler,               /*  50: CMU MHU 5 Sender Handler */
  invalid_irq_handler,               /*  51: CMU MHU 5 Receiver Handler */
  invalid_irq_handler,               /*  52: CMU MHU 6 Sender Handler */
  invalid_irq_handler,               /*  53: CMU MHU 6 Receiver Handler */
  invalid_irq_handler,               /*  54: CMU MHU 7 Sender Handler */
  invalid_irq_handler,               /*  55: CMU MHU 7 Receiver Handler */
  invalid_irq_handler,               /*  56: CMU MHU 8 Sender Handler */
  invalid_irq_handler,               /*  57: CMU MHU 8 Receiver Handler */
  invalid_irq_handler,               /*  58: Crypto Engine (Secure) Handler */
  invalid_irq_handler,               /*  59: SoC System Timer 0 AON Handler */
  invalid_irq_handler,               /*  60: SoC System Timer 1 AON Handler */
  invalid_irq_handler,               /*  61: SRAM ECC Detected Partial Write (Secure) Handler */
  invalid_irq_handler,               /*  62: Integrity Checker Handler */
  0,                                 /*  63: Reserved */
  0,                                 /*  64: Reserved */
  0,                                 /*  65: Reserved */
  0,                                 /*  66: Reserved */
  0,                                 /*  67: Reserved */
  0,                                 /*  68: Reserved */
  0,                                 /*  69: Reserved */
  0,                                 /*  70: Reserved */
  0,                                 /*  71: Reserved */
  0,                                 /*  72: Reserved */
  0,                                 /*  73: Reserved */
  0,                                 /*  74: Reserved */
  0,                                 /*  75: Reserved */
  0,                                 /*  76: Reserved */
  0,                                 /*  77: Reserved */
  0,                                 /*  78: Reserved */
  0,                                 /*  79: Reserved */
  0,                                 /*  80: Reserved */
  0,                                 /*  81: Reserved */
  0,                                 /*  82: Reserved */
  0,                                 /*  83: Reserved */
  0,                                 /*  84: Reserved */
  0,                                 /*  85: Reserved */
  0,                                 /*  86: Reserved */
  0,                                 /*  87: Reserved */
  0,                                 /*  88: Reserved */
  0,                                 /*  89: Reserved */
  0,                                 /*  90: Reserved */
  0,                                 /*  91: Reserved */
  0,                                 /*  92: Reserved */
  0,                                 /*  93: Reserved */
  0,                                 /*  94: Reserved */
  0,                                 /*  95: Reserved */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));

    SystemInit();                    /* CMSIS System Initialization */
    __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}
