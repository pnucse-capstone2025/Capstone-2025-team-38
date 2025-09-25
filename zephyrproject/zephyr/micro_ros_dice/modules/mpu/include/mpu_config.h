#ifndef MPU_CONFIG_H
#define MPU_CONFIG_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <zephyr/syscall.h>

// MPU Register Pointer
#define MPU_BASE    0xE000ED90UL

#define MPU_TYPE    (*(volatile uint32_t *)(MPU_BASE + 0x00))
#define MPU_CTRL    (*(volatile uint32_t *)(MPU_BASE + 0x04))
#define MPU_RNR     (*(volatile uint32_t *)(MPU_BASE + 0x08))
#define MPU_RBAR    (*(volatile uint32_t *)(MPU_BASE + 0x0C))
#define MPU_RLAR    (*(volatile uint32_t *)(MPU_BASE + 0x10))
#define MPU_MAIR0   (*(volatile uint32_t *)(MPU_BASE + 0x30))
#define MPU_MAIR1   (*(volatile uint32_t *)(MPU_BASE + 0x34))

// Set Bit
#define SET_BIT(REG, BIT)       ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)     ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)      ((REG) & (BIT))
#define CLEAR_REG(REG)          ((REG) = 0x0)
#define WRITE_REG(REG, VAL)     ((REG) = (VAL))
#define READ_REG(REG)           ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  \
    WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

// CTRL Register
#define MPU_CTRL_ENABLE_Pos     0U
#define MPU_CTRL_ENABLE_Msk     (0x1UL << MPU_CTRL_ENABLE_Pos)
#define MPU_CTRL_HFNMIENA_Pos   1U
#define MPU_CTRL_HFNMIENA_Msk   (0x1UL << MPU_CTRL_HFNMIENA_Pos)
#define MPU_CTRL_PRIVDEFENA_Pos 2U
#define MPU_CTRL_PRIVDEFENA_Msk (0x1UL << MPU_CTRL_PRIVDEFENA_Pos)

// RBAR Register
#define MPU_RBAR_BASE_Pos       5U
#define MPU_RBAR_BASE_Msk       (0x7FFFFFFUL << MPU_RBAR_BASE_Pos)
#define MPU_RBAR_SH_Pos         3U
#define MPU_RBAR_SH_Msk         (0x3UL << MPU_RBAR_SH_Pos)
#define MPU_RBAR_AP_Pos         1U
#define MPU_RBAR_AP_Msk         (0x3UL << MPU_RBAR_AP_Pos)
#define MPU_RBAR_XN_Pos         0U
#define MPU_RBAR_XN_Msk         (0x1UL << MPU_RBAR_XN_Pos)

// RLAR Register
#define MPU_RLAR_LIMIT_Pos      5U
#define MPU_RLAR_LIMIT_Msk      (0x7FFFFFFUL << MPU_RLAR_LIMIT_Pos)
#define MPU_RLAR_AttrIndx_Pos   1U
#define MPU_RLAR_AttrIndx_Msk   (0x7UL << MPU_RLAR_AttrIndx_Pos)
#define MPU_RLAR_EN_Pos         0U
#define MPU_RLAR_EN_Msk         (0x1UL << MPU_RLAR_EN_Pos)

// MPU functions
void MPU_Disable(void);
void MPU_Enable(void);
void MPU_Config(void);

/*
 * @brief MPU Enable 시스템 콜
 */
__syscall int MPU_Enable_syscall(void);

/*
 * @brief MPU Disable 시스템 콜
 */
__syscall  int MPU_Disable_syscall(void);

uintptr_t z_mrsh_MPU_Enable_syscall(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
    uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
;
uintptr_t z_mrsh_MPU_Disable_syscall(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
    uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
;

#ifdef __cplusplus
 }
#endif

// #include <zephyr/syscalls/mpu_config.h>

#endif // MPU_CONFIG_H
