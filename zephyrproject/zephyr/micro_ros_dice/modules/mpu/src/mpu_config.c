#include <zephyr/kernel.h>
#include <mpu_config.h>
// #include <zephyr/syscall_handler.h>
#include <zephyr/internal/syscall_handler.h>

void MPU_Disable(void)
{
    CLEAR_BIT(MPU_CTRL, MPU_CTRL_ENABLE_Msk);
}

void MPU_Enable(void)
{
    // MPU Enable
    uint32_t ctrl_value = 0;
    ctrl_value |= MPU_CTRL_ENABLE_Msk;      
    ctrl_value |= MPU_CTRL_PRIVDEFENA_Msk;  
    WRITE_REG(MPU_CTRL, ctrl_value);
}

void MPU_Config(void) 
{
    // MPU Disable
    MPU_Disable();

    // Configure Flash Region
    // Memory Attribute 0 
    MPU_MAIR0 &= ~(0xFFUL << 8);  // 비트 [15:8] 클리어
    MPU_MAIR0 |= (0xAAUL << 8);   // Normal memory, Write-through, Read allocate
    
    // Memory Region 0 
    WRITE_REG(MPU_RNR, 0);
    
    // Flash Base Address 
    uint32_t rbar_value = 0;
    rbar_value |= (0x08000000UL & MPU_RBAR_BASE_Msk);  // 베이스 주소
    rbar_value |= (0x0UL << MPU_RBAR_SH_Pos);          // Non-shareable
    rbar_value |= (0x1UL << MPU_RBAR_AP_Pos);          // 읽기/쓰기 권한
    rbar_value &= ~MPU_RBAR_XN_Msk;                    // 실행 가능
    WRITE_REG(MPU_RBAR, rbar_value);
    
    // Flash Limit Address 
    uint32_t rlar_value = 0;
    rlar_value |= (0x0807FFFFUL & MPU_RLAR_LIMIT_Msk); // 리미트 주소
    rlar_value |= (0x0UL << MPU_RLAR_AttrIndx_Pos);    // 속성 인덱스 1
    rlar_value |= MPU_RLAR_EN_Msk;                     // 영역 활성화
    WRITE_REG(MPU_RLAR, rlar_value);

    // MPU Enable
    MPU_Enable();
}


int z_impl_MPU_Enable_syscall(void)
{
    // MPU_Enable();
    volatile uint32_t *MPU_CTRL_REG = (volatile uint32_t *)0xE000ED94;
    *MPU_CTRL_REG &= 0xFFFFFFFEUL;
    *MPU_CTRL_REG |= 0x1UL;
    return 0;
}

int z_impl_MPU_Disable_syscall(void)
{
    // MPU_Disable();
    volatile uint32_t *MPU_CTRL_REG = (volatile uint32_t *)0xE000ED94;
    *MPU_CTRL_REG &= 0xFFFFFFFEUL;
    // *MPU_CTRL_REG |= 0x1UL;
    return 0;
}

int z_vrfy_MPU_Disable_syscall(void)
{
    return z_impl_MPU_Disable_syscall();
}

int z_vrfy_MPU_Enable_syscall(void)
{
    return z_impl_MPU_Enable_syscall();
}

uintptr_t z_mrsh_MPU_Disable_syscall(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
    uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
_current->syscall_frame = ssf;
(void) arg0;	/* unused */
(void) arg1;	/* unused */
(void) arg2;	/* unused */
(void) arg3;	/* unused */
(void) arg4;	/* unused */
(void) arg5;	/* unused */
int ret = z_vrfy_MPU_Disable_syscall();
_current->syscall_frame = NULL;
return (uintptr_t) ret;
}

uintptr_t z_mrsh_MPU_Enable_syscall(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
    uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
_current->syscall_frame = ssf;
(void) arg0;	/* unused */
(void) arg1;	/* unused */
(void) arg2;	/* unused */
(void) arg3;	/* unused */
(void) arg4;	/* unused */
(void) arg5;	/* unused */
int ret = z_vrfy_MPU_Enable_syscall();
_current->syscall_frame = NULL;
return (uintptr_t) ret;
}
