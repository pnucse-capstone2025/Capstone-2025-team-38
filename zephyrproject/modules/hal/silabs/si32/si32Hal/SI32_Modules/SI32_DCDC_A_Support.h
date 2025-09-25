//------------------------------------------------------------------------------
// Copyright 2012 (c) Silicon Laboratories Inc.
//
// SPDX-License-Identifier: Zlib
//
// This siHAL software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//------------------------------------------------------------------------------

// Version: 1

#ifndef __SI32_DCDC_A_SUPPORT_H__
#define __SI32_DCDC_A_SUPPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define Minimum PulseWidth Type

typedef enum SI32_DCDC_MIN_PULSE_WIDTH_Enum
{
   SI32_DCDC_MIN_PULSE_WIDTH_DISABLED = 0,
   SI32_DCDC_MIN_PULSE_WIDTH_10NS     = 1,
   SI32_DCDC_MIN_PULSE_WIDTH_20NS     = 2,
   SI32_DCDC_MIN_PULSE_WIDTH_40NS     = 3
} SI32_DCDC_MIN_PULSE_WIDTH_Enum_Type;

//-----------------------------------------------------------------------------
// Define Interrupt Mode

typedef enum SI32_DCDC_INTERRUPT_MODE_Enum
{
   SI32_DCDC_INTERRUPT_MODE_LOW        = 0,
   SI32_DCDC_INTERRUPT_MODE_NOT_LOW    = 1,
   SI32_DCDC_INTERRUPT_MODE_NOT_IN_REG = 2,
   SI32_DCDC_INTERRUPT_MODE_IN_REG     = 3
} SI32_DCDC_INTERRUPT_MODE_Enum_Type;

//-----------------------------------------------------------------------------
// Define Interrupt Mode

typedef enum SI32_DCDC_READY_LOW_THRESHOLD_Enum
{
   SI32_DCDC_READY_LOW_THRESHOLD_95 = 0,
   SI32_DCDC_READY_LOW_THRESHOLD_90 = 1,
   SI32_DCDC_READY_LOW_THRESHOLD_85 = 2,
   SI32_DCDC_READY_LOW_THRESHOLD_80 = 3
} SI32_DCDC_READY_LOW_THRESHOLD_Enum_Type;


#ifdef __cplusplus
}
#endif

#endif // __SI32_DCDC_A_SUPPORT_H__

//-eof--------------------------------------------------------------------------
