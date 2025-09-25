/*
 * Copyright 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <device_mec5.h>
#include "mec_pcfg.h"
#include "mec_defs.h"
#include "mec_ecia_api.h"
#include "mec_pcr_api.h"
#include "mec_qspi_api.h"
#include "mec_retval.h"

#define MEC_QSPI_GIRQ                  18
#define MEC_QSPI0_GIRQ_POS             1
#define MEC_QSPI0_AGGR_NVIC            10
#define MEC_QSPI0_NVIC                 91

#define MEC_QSPI0_ECIA_INFO            \
    MEC5_ECIA_INFO(MEC_QSPI_GIRQ, MEC_QSPI0_GIRQ_POS, MEC_QSPI0_AGGR_NVIC, MEC_QSPI0_NVIC)

#define MEC_QSPI_M_FDIV_MAX            0x10000
#define MEC_QSPI_SOFT_RESET_WAIT_LOOPS 16
#define MEC_QSPI_CLR_FIFOS_WAIT_LOOPS  16
#define MEC_QSPI_FORCE_STOP_WAIT_LOOPS 1000
#define MEC_QSPI_DESCR_NU_MAX          0x7fffu

#define MEC_QSPI_STATUS_ERRORS (MEC_BIT(MEC_QSPI_STATUS_TXBERR_Pos) \
                                | MEC_BIT(MEC_QSPI_STATUS_RXBERR_Pos) \
                                | MEC_BIT(MEC_QSPI_STATUS_PROGERR_Pos) \
                                | MEC_BIT(MEC_QSPI_STATUS_LDRXERR_Pos) \
                                | MEC_BIT(MEC_QSPI_STATUS_LDTXERR_Pos))

#define MEC_QSPI_SIG_MODE_POS MEC_QSPI_MODE_CPOL_Pos
#define MEC_QSPI_SIG_MODE_MSK \
    (MEC_QSPI_MODE_CPOL_Msk | MEC_QSPI_MODE_CPHA_MOSI_Msk | MEC_QSPI_MODE_CPHA_MISO_Msk)

#define MEC5_QSPI_START_DESCR_MSK0 ((uint32_t)MEC_QSPI_CTRL_DPTR_Msk >> MEC_QSPI_CTRL_DPTR_Pos)
#define MEC5_QSPI_NEXT_DESCR_MSK0  ((uint32_t)MEC_QSPI_DESCR_NEXT_Msk >> MEC_QSPI_DESCR_NEXT_Pos)

/* QSPI SPI frequencies less than or equal to this value use
 * normal CPHA and CPOL settings. For frequencies above this
 * value we must transmit and sample on the same edge.
 */
#define MEC_QSPI_SIGNAL_NORM_FREQ 24000000u

struct mec_qspi_info {
    uintptr_t base_addr;
    uint32_t devi;
    uint16_t pcr_id;
};

const struct mec_qspi_info qspi_instances[MEC5_QSPI_INSTANCES] = {
    {MEC_QSPI0_BASE, MEC_QSPI0_ECIA_INFO, MEC_PCR_QSPI0},
};

static struct mec_qspi_info const *qspi_get_info(struct mec_qspi_regs *base)
{
    for (size_t n = 0u; n < MEC5_QSPI_INSTANCES; n++) {
        const struct mec_qspi_info *p = &qspi_instances[n];

        if (p->base_addr == (uintptr_t)base) {
            return p;
        }
    }

    return NULL;
}

/* Return the QSPI controller clock source frequency in Hz. */
static uint32_t qspi_max_spi_clock(void)
{
    /* QMSPI uses the same PLL output clock as the CPU domain */
    return mec_hal_pcr_cpu_max_freq();
}

static uint32_t qspi_get_freq(struct mec_qspi_regs *base)
{
    uint32_t srcfreq = qspi_max_spi_clock();
    uint32_t fdiv = (base->MODE & MEC_QSPI_MODE_CLKDIV_Msk) >> MEC_QSPI_MODE_CLKDIV_Pos;

    if (fdiv == 0u) { /* zero is maximum clock divider */
        fdiv = MEC_QSPI_M_FDIV_MAX;
    }

    return (srcfreq / fdiv);
}

uint32_t mec_hal_qspi_get_freq(struct mec_qspi_regs *base)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    return qspi_get_freq(base);
}

uint32_t mec_hal_qspi_freq_div(struct mec_qspi_regs *base)
{
    uint32_t fdiv = 0;

    if ((uintptr_t)base == (uintptr_t)(MEC_QSPI0_BASE)) {
        fdiv = (base->MODE & MEC_QSPI_MODE_CLKDIV_Msk) >> MEC_QSPI_MODE_CLKDIV_Pos;
    }

    if (fdiv == 0) {
        fdiv = 0x10000u;
    }

    return fdiv;
}

/* Return the raw 16-bit clock divider field from QSPI Mode register.
 * 0 = divide by maximum (0x10000)
 * 1 - 0xffff is divide by this value
 */
uint16_t mec_hal_qspi_freq_div_raw(struct mec_qspi_regs *base)
{
    if ((uintptr_t)base != (uintptr_t)(MEC_QSPI0_BASE)) {
        return 0;
    }

    return (uint16_t)((base->MODE & MEC_QSPI_MODE_CLKDIV_Msk) >> MEC_QSPI_MODE_CLKDIV_Pos);
}

bool mec_hal_qspi_is_enabled(struct mec_qspi_regs *regs)
{
    if ((uintptr_t)regs != (uintptr_t)MEC_QSPI0_BASE) {
        return false;
    }

    return (regs->MODE & MEC_BIT(MEC_QSPI_MODE_ACTV_Pos)) ? true : false;
}

/* Compute an estimate of time in nanoseconds to clock in/out one byte.
 * Maximum: F = 96 MHz, T = 10.42 ns
 * Single: 83.3 ns
 * Dual = 41.7 ns
 * Quad = 20.8 ns
 * Minimum: F = 48 MHz / 65536 = 732.4 Hz, T = 1.365 ms
 * Single: 10922667 (0x00a6_aaab) ns
 * Dual: 5461333 ns
 * Quad = 2730666 ns
 *
 * Maximum clock divider Fin = 96MHz
 * Tsingle = 1e9 * ((65536 / 96,000,000) * 8) = 5461333.33333 ns
 * Tdual = 1e9 * ((65536 / 96,000,000) * 4) =   2730666.66666 ns
 * Tquad = 1e9 * ((65536 / 96,000,000) * 2) =   1365333.33333 ns
 *
 * Fin = 48MHz
 * Tsingle = 1e9 * ((65536 / 48,000,000) * 8) = 10922666.66666
 *
 */
static uint32_t qspi_byte_time_ns(struct mec_qspi_regs *base)
{
    uint32_t clkdiv = (base->MODE & MEC_QSPI_MODE_CLKDIV_Msk) >> MEC_QSPI_MODE_CLKDIV_Pos;
    uint32_t iom = (base->CTRL & MEC_QSPI_CTRL_IFM_Msk) >> MEC_QSPI_CTRL_IFM_Pos;
    uint32_t byte_time_ns = 10922667u; /* 8-bits full duplex 48MHz clock source, max clock divider */

    if (mec_hal_pcr_is_turbo_clock()) { /* 96MHz clock source? */
        byte_time_ns = 5461333u; /* max clock divider */
    }

    /* adjust for IO mode */
    if (iom == MEC_QSPI_CTRL_IFM_QUAD) {
        byte_time_ns >>= 2u;
    } else if (iom == MEC_QSPI_CTRL_IFM_DUAL) {
        byte_time_ns >>= 1u;
    }

    /* HW clkdiv == 0 special value is maximum divider = 65536 */
    if (!clkdiv) {
        clkdiv = 65536u;
    }

    /* adjust for clock divider */
    byte_time_ns = byte_time_ns / (65536u / clkdiv);

    return byte_time_ns;
}

int mec_hal_qspi_byte_time_ns(struct mec_qspi_regs *base, uint32_t *btime_ns)
{
    if ((!base) || (!btime_ns)) {
        return MEC_RET_ERR_INVAL;
    }

    *btime_ns = qspi_byte_time_ns(base);

    return MEC_RET_OK;
}

/* Computer QSPI frequency divider given desired SPI clock in Hz.
 * Hardware fdiv = 1 to pow(2, fdiv_field_bit_length) - 1 is Source_Freq / n
 * Hardware fdiv = 0 is Source_Freq / pow(2, fdiv_field_bit_length)
 * fdiv_field_bit_length = 8 for MEC152x and 16 for MEC172x
 * NOTE: Truncation from integer division may result in an actual frequency
 * lower than requested.
 */
static uint32_t compute_freq_divisor(uint32_t freq_hz)
{
    uint32_t src_freq = qspi_max_spi_clock();
    uint32_t fdiv;

    if (freq_hz < (src_freq / MEC_QSPI_M_FDIV_MAX)) {
        fdiv = 0u; /* HW divider of 0 is divide by MEC_QSPI_M_FDIV_MAX */
    } else if (freq_hz > src_freq) {
        fdiv = 1u;
    } else {
        fdiv = src_freq / freq_hz;
    }

    return fdiv;
}

static void qspi_set_freq(struct mec_qspi_regs *base, uint32_t freqhz)
{
    uint32_t fdiv = compute_freq_divisor(freqhz);

    base->MODE = ((base->MODE & (uint32_t)~MEC_QSPI_MODE_CLKDIV_Msk)
                  | (fdiv << MEC_QSPI_MODE_CLKDIV_Pos));
}

int mec_hal_qspi_set_freq(struct mec_qspi_regs *base, uint32_t freqhz)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    qspi_set_freq(base, freqhz);

    return MEC_RET_OK;
}

static void qspi_intr_clr_dis(struct mec_qspi_regs *base)
{
    const struct mec_qspi_info *info = qspi_get_info(base);

    if (!info) {
        return;
    }

    base->INTR_CTRL = 0;
    base->STATUS = UINT32_MAX;
    mec_hal_girq_ctrl(info->devi, 0);
    mec_hal_girq_clr_src(info->devi);
}

static void qspi_reset(struct mec_qspi_regs *base)
{
    /* Self clearing soft reset bit (write-only) */
    base->MODE |= MEC_BIT(MEC_QSPI_MODE_SRST_Pos);

    qspi_intr_clr_dis(base);
}

/* Clear GIRQ source status. Current SoC's have one QSPI instance */
void mec_hal_qspi_girq_clr(struct mec_qspi_regs *base)
{
    mec_hal_girq_clr_src(MEC_QSPI0_ECIA_INFO);
}

void mec_hal_qspi_girq_ctrl(struct mec_qspi_regs *base, uint8_t enable)
{
    mec_hal_girq_ctrl(MEC_QSPI0_ECIA_INFO, enable);
}

/* Returns non-zero if QSPI0 GIRQ result bit is set else 0 */
uint32_t mec_hal_qspi_girq_is_result(struct mec_qspi_regs *base)
{
    return mec_hal_girq_result(MEC_QSPI0_ECIA_INFO);
}

int mec_hal_qspi_reset(struct mec_qspi_regs *base)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    qspi_reset(base);

    return MEC_RET_OK;
}

int mec_hal_qspi_reset_sr(struct mec_qspi_regs *base)
{
    uint32_t saved[5];

    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    mec_hal_girq_ctrl(MEC_QSPI0_ECIA_INFO, 0);

    saved[0] = base->MODE & (MEC_QSPI_MODE_CPOL_Msk | MEC_QSPI_MODE_CPHA_MOSI_Msk
                             | MEC_QSPI_MODE_CPHA_MISO_Msk | MEC_QSPI_MODE_CLKDIV_Msk);
    saved[1] = base->CSTM;
    saved[2] = base->TAPSS;
    saved[3] = base->TAPSA;
    saved[4] = base->TAPSC;

    qspi_reset(base);
    mec_hal_girq_clr_src(MEC_QSPI0_ECIA_INFO);

    base->MODE = saved[0];
    base->CSTM = saved[1];
    base->TAPSS = saved[2];
    base->TAPSA = saved[3];
    base->TAPSC = saved[4];

    return MEC_RET_OK;
}

/* Set frequency for chip select 1.
 * param regs = QSPI instance register base address
 * param freq = frequency use for CS1. Zero indicates use same as CS0.
 */
static void qspi_cs1_freq(struct mec_qspi_regs *base, uint32_t freq)
{
    uint32_t fdiv;

    if (freq) {
        fdiv = compute_freq_divisor(freq);
        base->ALT1_MODE = (fdiv << MEC_QSPI_MODE_CLKDIV_Pos) & MEC_QSPI_MODE_CLKDIV_Msk;
        base->ALT1_MODE |= MEC_BIT(MEC_QSPI_ALT1_MODE_CS1_ALTEN_Pos);
    } else {
        base->ALT1_MODE = 0u;
    }
}

int mec_hal_qspi_cs1_freq(struct mec_qspi_regs *base, uint32_t freq)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    qspi_cs1_freq(base, freq);

    return MEC_RET_OK;
}

static uint32_t qspi_compute_byte_time_ns(struct mec_qspi_regs *base)
{
    uint32_t freq = qspi_max_spi_clock();
    uint32_t fdiv = (base->MODE & MEC_QSPI_MODE_CLKDIV_Msk) >> MEC_QSPI_MODE_CLKDIV_Pos;
    uint32_t btime_ns;

    /* Not CS0 and alternate frequency divider enabled */
    if ((base->MODE & MEC_QSPI_MODE_CS_Msk) &&
        (base->ALT1_MODE & MEC_BIT(MEC_QSPI_ALT1_MODE_CS1_ALTEN_Pos))) {
        fdiv = ((base->ALT1_MODE & MEC_QSPI_ALT1_MODE_CS1_ALT_CLKDIV_Msk)
                >> MEC_QSPI_ALT1_MODE_CS1_ALT_CLKDIV_Pos);
    }

    if (!fdiv) { /* divider reg field = 0 is maximum divider */
        fdiv = MEC_QSPI_M_FDIV_MAX;
    }

    freq /= fdiv;

    /* Pad to two byte times */
    btime_ns = (uint32_t)(16000000000ULL / freq);

    return btime_ns;
}

static void qspi_cs_select(struct mec_qspi_regs *base, enum mec_qspi_cs cs)
{
    uint32_t mode = base->MODE & (uint32_t)~MEC_QSPI_MODE_CS_Msk;

    mode |= (((uint32_t)cs << MEC_QSPI_MODE_CS_Pos) & MEC_QSPI_MODE_CS_Msk);
    base->MODE = mode;
}

int mec_hal_qspi_cs_select(struct mec_qspi_regs *base, enum mec_qspi_cs cs)
{
    if (!base || (cs >= MEC_QSPI_CS_MAX)) {
        return MEC_RET_ERR_INVAL;
    }

    qspi_cs_select(base, cs);

    return MEC_RET_OK;
}

static const uint8_t qspi_smode[MEC_SPI_SIGNAL_MODE_MAX] = { 0x0, 0x6, 0x1, 0x7, };
static const uint8_t qspi_smode_hi[MEC_SPI_SIGNAL_MODE_MAX] = { 0x4, 0x2, 0x5, 0x3, };

static void qspi_spi_signal_mode(struct mec_qspi_regs *base, enum mec_qspi_signal_mode spi_mode)
{
    uint32_t freq = qspi_get_freq(base);
    uint32_t hwsm = 0;

    if (freq > MEC_QSPI_SIGNAL_NORM_FREQ) {
        hwsm = (uint32_t)qspi_smode_hi[spi_mode];
    } else {
        hwsm = (uint32_t)qspi_smode[spi_mode];
    }

    base->MODE = (base->MODE & ~0x700u) | (hwsm << MEC_QSPI_MODE_CPOL_Pos);
}

/* Requires frequency programmed first */
int mec_hal_qspi_spi_signal_mode(struct mec_qspi_regs *base, enum mec_qspi_signal_mode spi_mode)
{
    if ((base == NULL) || (spi_mode >= MEC_SPI_SIGNAL_MODE_MAX)) {
        return MEC_RET_ERR_INVAL;
    }

    qspi_spi_signal_mode(base, spi_mode);

    return MEC_RET_OK;
}

int mec_hal_qspi_sampling_phase_pol(struct mec_qspi_regs *base, uint8_t phpol)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    base->MODE = (base->MODE & ~0x700u) | ((uint32_t)(phpol & 0x7u) << 8);

    return MEC_RET_OK;
}

static uint32_t qspi_ifm(enum mec_qspi_io iom)
{
    uint32_t ifm;

    if (iom == MEC_QSPI_IO_QUAD) {
        ifm = (uint32_t)MEC_QSPI_CTRL_IFM_QUAD;
    } else if (iom == MEC_QSPI_IO_DUAL) {
        ifm = (uint32_t)MEC_QSPI_CTRL_IFM_DUAL;
    } else {
        ifm = (uint32_t)MEC_QSPI_CTRL_IFM_FD;
    }

    return (ifm << MEC_QSPI_CTRL_IFM_Pos);
}

static void qspi_io(struct mec_qspi_regs *base, enum mec_qspi_io io)
{
    base->CTRL = (base->CTRL & (uint32_t)~MEC_QSPI_CTRL_IFM_Msk) | qspi_ifm(io);
}

int mec_hal_qspi_io(struct mec_qspi_regs *base, enum mec_qspi_io io)
{
    if (!base || (io >= MEC_QSPI_IO_MAX)) {
        return MEC_RET_ERR_INVAL;
    }

    qspi_io(base, io);

    return MEC_RET_OK;
}

struct qspi_cstm_info {
    uint8_t pos;
    uint8_t msk0;
};

const struct qspi_cstm_info cstm_tbl[MEC_QSPI_CSTM_MAX] = {
    {0, 0xfu},
    {8, 0xfu},
    {16, 0xfu},
    {24, 0xffu},
};

int mec_hal_qspi_cs_timing_adjust(struct mec_qspi_regs *base, enum mec_qspi_cstm field,
                                  uint8_t val)
{
    if ((!base) || (field >= MEC_QSPI_CSTM_MAX)) {
        return MEC_RET_ERR_INVAL;
    }

    uint32_t pos = cstm_tbl[field].pos;
    uint32_t msk0 = cstm_tbl[field].msk0;

    base->CSTM = (base->CSTM & ~(msk0 << pos)) | ((val & msk0) << pos);

    return MEC_RET_OK;
}

int mec_hal_qspi_cs_timing(struct mec_qspi_regs *base, uint32_t cs_timing)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    base->CSTM = cs_timing;

    return MEC_RET_OK;
}

int mec_hal_qspi_tap_select(struct mec_qspi_regs *base, uint8_t sel_sck_tap, uint8_t sel_ctrl_tap)
{
    uint32_t tapss = sel_sck_tap | ((uint32_t)sel_ctrl_tap << 8);

    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    tapss = ((uint32_t)sel_sck_tap << MEC_QSPI_TAPSS_TSCK_Pos) & MEC_QSPI_TAPSS_TSCK_Msk;
    tapss |= (((uint32_t)sel_ctrl_tap << MEC_QSPI_TAPSS_TCTRL_Pos) & MEC_QSPI_TAPSS_TCTRL_Msk);
    base->TAPSS = (base->TAPSS & (uint32_t)~(MEC_QSPI_TAPSS_TSCK_Msk | MEC_QSPI_TAPSS_TSCK_Msk)) | tapss;

    return MEC_RET_OK;
}

/* Initialize QMSPI controller using local DMA. */
int mec_hal_qspi_init(struct mec_qspi_regs *base,
                      uint32_t freq_hz,
                      enum mec_qspi_signal_mode spi_signal_mode,
                      enum mec_qspi_io iom,
                      enum mec_qspi_cs chip_sel)
{
    const struct mec_qspi_info *info = qspi_get_info(base);

    if (!info) {
        return MEC_RET_ERR_INVAL;
    }

    mec_hal_pcr_clr_blk_slp_en(info->pcr_id); /* clocks gated ON */
    mec_hal_qspi_reset_sr(base);
    qspi_set_freq(base, freq_hz);
    qspi_spi_signal_mode(base, spi_signal_mode);
    qspi_io(base, iom);
    qspi_cs_select(base, chip_sel);

    base->MODE |= MEC_BIT(MEC_QSPI_MODE_ACTV_Pos);

    /* Enable QSPI interrupt signal to propagate to NVIC */
    mec_hal_girq_ctrl(info->devi, 1);

    return MEC_RET_OK;
}

int mec_hal_qspi_options(struct mec_qspi_regs *regs, uint8_t en, uint32_t options)
{
    uint32_t val = 0, msk = 0;

    if (!regs) {
        return MEC_RET_ERR_INVAL;
    }

    if (options & MEC_BIT(MEC_QSPI_OPT_ACTV_EN_POS)) {
        msk |= MEC_BIT(MEC_QSPI_MODE_ACTV_Pos);
        if (en) {
            val |= MEC_BIT(MEC_QSPI_MODE_ACTV_Pos);
        }
    }
    if (options & MEC_BIT(MEC_QSPI_OPT_TAF_DMA_EN_POS)) {
        msk |= MEC_BIT(MEC_QSPI_MODE_TAFDMA_Pos);
        if (en) {
            val |= MEC_BIT(MEC_QSPI_MODE_TAFDMA_Pos);
        }
    }
    if (options & MEC_BIT(MEC_QSPI_OPT_RX_LDMA_EN_POS)) {
        msk |= MEC_BIT(MEC_QSPI_MODE_RX_LDMA_Pos);
        if (en) {
            val |= MEC_BIT(MEC_QSPI_MODE_RX_LDMA_Pos);
        }
    }
    if (options & MEC_BIT(MEC_QSPI_OPT_TX_LDMA_EN_POS)) {
        msk |= MEC_BIT(MEC_QSPI_MODE_TX_LDMA_Pos);
        if (en) {
            val |= MEC_BIT(MEC_QSPI_MODE_TX_LDMA_Pos);
        }
    }

    regs->MODE = (regs->MODE & ~msk) | (val & msk);

    return MEC_RET_OK;
}

/* Force QSPI to stop an on-going transaction.
 * If QSPI is generating clocks, it will stop at the next byte boundary
 * and de-assert chip select.
 */
int mec_hal_qspi_force_stop(struct mec_qspi_regs *base)
{
    uint32_t btime_ns;

    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    base->EXE = MEC_BIT(MEC_QSPI_EXE_STOP_Pos);

    /* computation uses up some of the time */
    btime_ns = qspi_compute_byte_time_ns(base);

    /* Timeout period, doesn't have to be accurate.
     * EC running at 96MHz (~10 ns) or slower.
     */
    while (base->STATUS & MEC_BIT(MEC_QSPI_STATUS_ACTIVE_Pos)) {
        if (!btime_ns) {
            return MEC_RET_ERR_TIMEOUT;
        }
        btime_ns--;
    }

    return MEC_RET_OK;
}

int mec_hal_qspi_done(struct mec_qspi_regs *base)
{
    uint32_t qsts;

    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    qsts = base->STATUS;

    if (qsts & MEC_QSPI_STATUS_ERRORS) {
        return MEC_RET_ERR_HW;
    }

    if (qsts & MEC_BIT(MEC_QSPI_STATUS_DONE_Pos)) {
        return MEC_RET_OK;
    }

    return MEC_RET_ERR_BUSY;
}

uint32_t mec_hal_qspi_hw_status(struct mec_qspi_regs *base)
{
    if (!base) {
        return 0;
    }

    return base->STATUS;
}

int mec_hal_qspi_hw_status_clr(struct mec_qspi_regs *base, uint32_t msk)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    base->STATUS = msk;

    return MEC_RET_OK;
}

static void qspi_intr_ctrl(struct mec_qspi_regs *base, int enable)
{
    uint32_t qien = 0u;

    if (enable) {
        qien = (MEC_BIT(MEC_QSPI_INTR_CTRL_DONE_Pos)
                | MEC_BIT(MEC_QSPI_INTR_CTRL_TXBERR_Pos)
                | MEC_BIT(MEC_QSPI_INTR_CTRL_PROGERR_Pos)
                | MEC_BIT(MEC_QSPI_INTR_CTRL_LDRXERR_Pos)
                | MEC_BIT(MEC_QSPI_INTR_CTRL_LDTXERR_Pos));
    }

    base->INTR_CTRL = qien;
}

int mec_hal_qspi_intr_ctrl(struct mec_qspi_regs *base, int enable)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    qspi_intr_ctrl(base, enable);

    return MEC_RET_OK;
}

int mec_hal_qspi_intr_ctrl_msk(struct mec_qspi_regs *base, int enable, uint32_t msk)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    if (enable) {
        base->INTR_CTRL |= msk;
    } else {
        base->INTR_CTRL &= (uint32_t)~msk;
    }

    return MEC_RET_OK;
}

int mec_hal_qspi_tx_fifo_is_empty(struct mec_qspi_regs *base)
{
    if (base) {
        if (base->STATUS & MEC_BIT(MEC_QSPI_STATUS_TXBE_Pos)) {
            return 1;
        }
    }

    return 0;
}

int mec_hal_qspi_tx_fifo_is_full(struct mec_qspi_regs *base)
{
    if (base) {
        if (base->STATUS & MEC_BIT(MEC_QSPI_STATUS_TXBF_Pos)) {
            return 1;
        }
    }

    return 0;
}

int mec_hal_qspi_rx_fifo_is_empty(struct mec_qspi_regs *base)
{
    if (base) {
        if (base->STATUS & MEC_BIT(MEC_QSPI_STATUS_RXBE_Pos)) {
            return 1;
        }
    }

    return 0;
}

int mec_hal_qspi_rx_fifo_is_full(struct mec_qspi_regs *base)
{
    if (base) {
        if (base->STATUS & MEC_BIT(MEC_QSPI_STATUS_RXBF_Pos)) {
            return 1;
        }
    }

    return 0;
}

int mec_hal_qspi_start(struct mec_qspi_regs *base, uint32_t ien_mask)
{
    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    base->STATUS = UINT32_MAX;
    base->INTR_CTRL = ien_mask;
    base->EXE = MEC_BIT(MEC_QSPI_EXE_START_Pos);

    return MEC_RET_OK;
}

/* Write up to smaller of bufsz or space available in TX FIFO bytes.
 * If pointer nloaded not NULL set to number of bytes written to TX FIFO.
 */
int mec_hal_qspi_wr_tx_fifo(struct mec_qspi_regs *regs, const uint8_t *buf, uint32_t bufsz,
                            uint32_t *nwr)
{
    uint32_t loaded = 0;
    volatile uint8_t *tx_fifo = (volatile uint8_t *)&regs->TX_FIFO;

    if (!regs || (!buf && bufsz)) {
        return MEC_RET_ERR_INVAL;
    }

    while (bufsz--) {
        if (regs->STATUS & MEC_BIT(MEC_QSPI_STATUS_TXBF_Pos)) {
            break;
        }
        *tx_fifo = *buf++;
        loaded++;
    }

    if (nwr) {
        *nwr = loaded;
    }

    return MEC_RET_OK;
}

/* If data is available in QSPI RX FIFO read it and store into buffer data unless
 * buf is NULL then discard the data.
 * Stops reading when RX FIFO becomes empty.
 * Stores number of bytes read in nrd if not NULL.
 */
int mec_hal_qspi_rd_rx_fifo(struct mec_qspi_regs *regs, uint8_t *buf, uint32_t bufsz,
                            uint32_t *nrd)
{
    volatile uint8_t *rx_fifo = (volatile uint8_t *)&regs->RX_FIFO;
    uint32_t nr = 0;
    uint8_t db = 0;

    if (!regs) {
        return MEC_RET_ERR_INVAL;
    }

    while (bufsz--) {
        if (regs->STATUS & MEC_BIT(MEC_QSPI_STATUS_RXBE_Pos)) {
            break;
        }
        db = *rx_fifo;
        if (buf) {
            *buf++ = db;
        }
        nr++;
    }

    if (nrd) {
        *nrd = nr;
    }

    return MEC_RET_OK;
}

static void qspi_ldma_init(struct mec_qspi_regs *base)
{
    base->MODE &= ~(MEC_BIT(MEC_QSPI_MODE_RX_LDMA_Pos) | MEC_BIT(MEC_QSPI_MODE_TX_LDMA_Pos));
    base->LDMA_RXEN = 0u;
    base->LDMA_TXEN = 0u;
    base->RX_LDMA_CHAN[0].CTRL = 0;
    base->RX_LDMA_CHAN[1].CTRL = 0;
    base->RX_LDMA_CHAN[2].CTRL = 0;
    base->TX_LDMA_CHAN[0].CTRL = 0;
    base->TX_LDMA_CHAN[1].CTRL = 0;
    base->TX_LDMA_CHAN[2].CTRL = 0;
}

/* Configure QSPI LDMA RX channel 0 and LDMA TX channel 0 for rx/tx of lenb
 * bytes. If RX buffer is NULL use read-only QSPI buffer count register
 * as the target destination and do not set address increment.
 * If TX buffer is NULL read the write-only QSPI Execute register as
 * the data source to be written.
 */
static void qspi_ldma_cfg1(struct mec_qspi_regs *base, const uint8_t *txb,
                           uint8_t *rxb, size_t lenb)
{
    uint32_t rctrl = MEC_BIT(MEC_QSPI_LDMA_CHAN_CTRL_EN_Pos);
    uint32_t wctrl = MEC_BIT(MEC_QSPI_LDMA_CHAN_CTRL_EN_Pos);
    uint32_t temp = (uint32_t)MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_1B;

    if ((((uintptr_t)rxb | (uintptr_t)lenb) & 0x03u) == 0u) {
        temp = (uint32_t)MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_4B;
    }
    rctrl |= (temp << MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_Pos);

    temp = (uint32_t)MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_1B;
    if ((((uintptr_t)txb | (uintptr_t)lenb) & 0x03u) == 0u) {
        temp = (uint32_t)MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_4B;
    }
    wctrl |= (temp << MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_Pos);

    base->RX_LDMA_CHAN[0].LEN = lenb;
    if (rxb) {
        base->RX_LDMA_CHAN[0].MEM_START = (uintptr_t)rxb;
        rctrl |= MEC_BIT(MEC_QSPI_LDMA_CHAN_CTRL_INCRA_Pos);
    } else {
        base->RX_LDMA_CHAN[0].MEM_START = (uintptr_t)&base->BCNT_STS;
    }
    base->RX_LDMA_CHAN[0].CTRL = rctrl;

    if (txb) {
        base->TX_LDMA_CHAN[0].LEN = lenb;
        base->TX_LDMA_CHAN[0].MEM_START = (uintptr_t)txb;
        base->TX_LDMA_CHAN[0].CTRL = wctrl | MEC_BIT(MEC_QSPI_LDMA_CHAN_CTRL_INCRA_Pos);
    }
}

/* Build the intitial value used for all descriptors.
 * param txb pointer to transmit buffer
 * param interface mode field value (full-duplex, dual, or quad)
 * return initial/constant descriptor field values.
 * note Use RX LDMA channel 0 and TX LDMA channel 0.
 * If transmit buffer is NULL make use of QSPI HW feature to
 * transmit all 0's.
 */
static uint32_t descr_ldma_init(const uint8_t *txb, uint32_t ifm)
{
    uint32_t d = ifm;

    if (txb) {
        d |= (((uint32_t)MEC_QSPI_DESCR_TXEN_EN << MEC_QSPI_DESCR_TXEN_Pos)
             | ((uint32_t)MEC_QSPI_DESCR_TXDMA_1B_LDMA_CH0 << MEC_QSPI_DESCR_TXDMA_Pos));
    }

    /* always enable receive LDMA for full duplex */
    d |= (((uint32_t)MEC_QSPI_DESCR_RXEN_EN << MEC_QSPI_DESCR_RXEN_Pos)
          | ((uint32_t)MEC_QSPI_DESCR_RXDMA_1B_LDMA_CH0 << MEC_QSPI_DESCR_RXDMA_Pos));

    return d;
}

#ifdef MEC5_QSPI_LDMA_TX_NULL_LEN_ARE_CLOCKS
/*
 * FD 1 bit = 1 clock
 * Dual 2 bits = 1 clock
 * Quad 4 bits = 1 clock
 */
static uint32_t qspi_clocks_to_bits(uint32_t ctrl, uint32_t nclocks)
{
    uint32_t ifm = (ctrl & MEC_QSPI_CTRL_IFM_Msk) >> MEC_QSPI_CTRL_IFM_Pos;

    if (ifm == MEC_QSPI_CTRL_IFM_QUAD) {
        return (nclocks * 4u);
    } else if (ifm == MEC_QSPI_CTRL_IFM_DUAL) {
        return (nclocks * 2u);
    } else {
        return nclocks;
    }
}

static int qspi_gen_ts_clocks(struct mec_qspi_regs *base, uint32_t nclocks, uint32_t flags)
{
    uint32_t descr = qspi_clocks_to_bits(base->CTRL, nclocks);
    int ien = 0;

    descr <<= MEC_QSPI_DESCR_QNUNITS_Pos;
    descr &= MEC_QSPI_DESCR_QNUNITS_Msk;
    descr |= (base->CTRL & MEC_QSPI_CTRL_IFM_Msk);
    descr |= (1u << MEC_QSPI_DESCR_NEXT_Pos);
    descr |= MEC_BIT(MEC_QSPI_DESCR_LAST_Pos);

    if (flags & MEC_BIT(MEC_QSPI_XFR_FLAG_CLOSE_POS)) {
        descr |= MEC_BIT(MEC_QSPI_DESCR_CLOSE_Pos);
    }
    base->DESCR[0] = descr;

    if (flags & MEC_BIT(MEC_QSPI_XFR_FLAG_IEN_POS)) {
        ien = 1;
    }

    qspi_intr_ctrl(base, ien);

    /* start HW */
    if (flags & MEC_QSPI_XFR_FLAG_START_POS) {
        base->EXE = MEC_BIT(MEC_QSPI_EXE_START_Pos);
    }

    return MEC_RET_OK;
}
#endif

/* Configure and start/continue a SPI transaction
 * base is a pointer to the QSPI control instance hardware registers.
 * txb is a pointer to a constant buffer containing bytes to transmit.
 * rxb is a pointer to a r/w buffer to hold data received as each byte is
 * transmitted. If rxb is NULL the received data is discarded. lenb is the size
 * in bytes of each buffer. flags contains bits to enable interrupts before the
 * transfer starts.
 */
int mec_hal_qspi_ldma(struct mec_qspi_regs *base, const uint8_t *txb,
                      uint8_t *rxb, size_t lenb, uint32_t flags)
{
    uint32_t nbytes = lenb;
    uint32_t shift = 0, nu = 0, descr = 0, descr_init = 0, didx = 0;
    int ien = 0;

    if (!base) {
        return MEC_RET_ERR_INVAL;
    }

    if (!lenb) {
        return 0;
    }

    qspi_ldma_init(base);

    if (flags & MEC_BIT(MEC_QSPI_XFR_FLAG_CLR_FIFOS_POS)) {
        base->EXE = MEC_BIT(MEC_QSPI_EXE_CLRF_Pos);
    } else if (base->BCNT_STS) { /* data left in TX and/or RX FIFO */
        return MEC_RET_ERR_HW;
    }

    base->STATUS = UINT32_MAX;
    /* descriptor mode starting at descriptor 0 */
    base->CTRL |= MEC_BIT(MEC_QSPI_CTRL_DESCR_MODE_Pos);

#ifdef MEC5_QSPI_LDMA_TX_NULL_LEN_ARE_CLOCKS
    if (!txb && !rxb && lenb) {
        return qspi_gen_ts_clocks(base, lenb, flags);
    } else {
        descr_init = descr_ldma_init(txb, base->CTRL & MEC_QSPI_CTRL_IFM_Msk);
    }
#else
    descr_init = descr_ldma_init(txb, base->CTRL & MEC_QSPI_CTRL_IFM_Msk);
#endif

    while (nbytes && (didx < MEC5_QSPI_NUM_DESCRS)) {
        descr = descr_init;
        nu = nbytes;
        shift = 0;
        if (nu > MEC_QSPI_DESCR_NU_MAX) {
            shift = 4;
            nu >>= 4;
            descr |= ((uint32_t)MEC_QSPI_DESCR_QUNITS_16B << MEC_QSPI_DESCR_QUNITS_Pos);
        } else {
            descr |= ((uint32_t)MEC_QSPI_DESCR_QUNITS_1B << MEC_QSPI_DESCR_QUNITS_Pos);
        }

        descr |= (nu << MEC_QSPI_DESCR_QNUNITS_Pos);
        descr |= (((didx + 1u) << MEC_QSPI_DESCR_NEXT_Pos) & MEC_QSPI_DESCR_NEXT_Msk);
        base->DESCR[didx] = descr;
        base->LDMA_RXEN |= MEC_BIT(didx);
        if (txb) {
            base->LDMA_TXEN |= MEC_BIT(didx);
        }
        nbytes -= (nu << shift);
        didx++;
    }

    descr = base->DESCR[didx - 1u] | MEC_BIT(MEC_QSPI_DESCR_LAST_Pos);
    if (flags & MEC_BIT(MEC_QSPI_XFR_FLAG_CLOSE_POS)) {
        descr |= MEC_BIT(MEC_QSPI_DESCR_CLOSE_Pos);
    }
    base->DESCR[didx - 1u] = descr;

    if (nbytes) {
        return MEC_RET_ERR_DATA_LEN;
    }

    qspi_ldma_cfg1(base, txb, rxb, lenb);

    base->MODE |= (MEC_BIT(MEC_QSPI_MODE_RX_LDMA_Pos) | MEC_BIT(MEC_QSPI_MODE_TX_LDMA_Pos));

    if (flags & MEC_BIT(MEC_QSPI_XFR_FLAG_IEN_POS)) {
        ien = 1;
    }

    qspi_intr_ctrl(base, ien);

    /* start HW */
    if (flags & MEC_BIT(MEC_QSPI_XFR_FLAG_START_POS)) {
        base->EXE = MEC_BIT(MEC_QSPI_EXE_START_Pos);
    }

    return 0;
}

/* -------- 2024-02-24 -------- */

void mec_hal_qspi_context_init(struct mec_qspi_context *ctx)
{
    ctx->ndescrs = 0;
    ctx->ntxdma = 0;
    ctx->nrxdma = 0;
    ctx->xflags = 0;
    for (size_t n = 0; n < MEC5_QSPI_NUM_DESCRS; n++) {
        ctx->descrs[n] = 0;
    }
}

uint8_t mec_hal_qspi_ctx_alloc_ldma_chan(struct mec_qspi_context *ctx, uint8_t is_tx)
{
    if (!ctx) {
        return 0;
    }

    if (is_tx) {
        if (ctx->ntxdma < MEC5_QSPI_LDMA_CHANNELS) {
            return ++ctx->ntxdma;
        }
    } else {
        if (ctx->nrxdma < MEC5_QSPI_LDMA_CHANNELS) {
            return ++ctx->nrxdma;
        }
    }

    return 0;
}

static uint32_t qspi_nio_pins_to_ifm(uint8_t nio_pins)
{
    uint8_t ifm_val;

    if (nio_pins == 4) {
        ifm_val = MEC_QSPI_DESCR_IFM_QUAD;
    } else if (nio_pins == 2) {
        ifm_val = MEC_QSPI_DESCR_IFM_DUAL;
    } else {
        ifm_val = MEC_QSPI_DESCR_IFM_FD;
    }

    return ((uint32_t)ifm_val << MEC_QSPI_DESCR_IFM_Pos);
}

int mec_hal_qspi_cfg_gen_ts_clocks(struct mec_qspi_context *ctx, uint32_t nclocks,
                                   uint8_t nio_pins)
{
    uint32_t didx = 0, descr = 0;

    if (!((nio_pins == 1) || (nio_pins == 2) || (nio_pins == 4))) {
        return MEC_RET_ERR_INVAL;
    }

    if (!nclocks) {
        return MEC_RET_ERR_NOP;
    }

    didx = ctx->ndescrs;
    if (didx >= MEC5_QSPI_NUM_DESCRS) {
        return MEC_RET_ERR_NO_RES;
    }

    descr |= qspi_nio_pins_to_ifm(nio_pins);
    if (!(nclocks & 0x7u)) { /* multiple of 8 bits? */
        descr |= (MEC_QSPI_DESCR_QUNITS_1B << MEC_QSPI_DESCR_QUNITS_Pos);
        descr |= ((((nclocks >> 3) * nio_pins) << MEC_QSPI_DESCR_QNUNITS_Pos)
                  & MEC_QSPI_DESCR_QNUNITS_Msk);
    } else {
        descr |= (MEC_QSPI_DESCR_QUNITS_BITS << MEC_QSPI_DESCR_QUNITS_Pos);
        descr |= (((nclocks * nio_pins) << MEC_QSPI_DESCR_QNUNITS_Pos) & MEC_QSPI_DESCR_QNUNITS_Msk);
    }
    ctx->descrs[didx] = descr;
    ctx->ndescrs++;

    return MEC_RET_OK;
}

/* Configure the specified QSPI Local-DMA channel.
 * regs - pointer to QSPI hardware registers
 * buf_addr - address of source or destination buffer in memory
 * nbytes - requested number of bytes to transfer
 * chan_dir
 *    b[3:0] = 1-based channel (1, 2, or 3)
 *    b[4] = direction: 0(RX), 1(TX)
 * return 0 success
 *        < 0 error
 *
 * Program the specified QSPI RX or TX LDMA channel with memory address
 * of source/destination buffer and transfer length in bytes.
 * If buffer address is 0 then source/destination memory address is set
 * to the QSPI buffer status count read-only register and LDMA channel
 * increment address is disabled.
 */
int mec_hal_qspi_ldma_cfg1(struct mec_qspi_regs *regs, uintptr_t buf_addr, uint32_t nbytes,
                           uint32_t ldflags)
{
    volatile struct mec_qspi_ldma_chan_regs *ldma_regs = NULL;
    uint32_t ctrl = 0;
    uint8_t chanrx = 0, chantx = 0;

    if (!regs) {
        return MEC_RET_ERR_INVAL;
    }

    if (!nbytes) {
        return MEC_RET_OK;
    }

    ctrl = ((uint32_t)MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_1B << MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_Pos);
    chanrx = (ldflags >> MEC5_QSPI_DCFG1_FLAG_DMA_RX_POS) & MEC5_QSPI_DCFG1_FLAG_DMA_MSK0;
    chantx = (ldflags >> MEC5_QSPI_DCFG1_FLAG_DMA_TX_POS) & MEC5_QSPI_DCFG1_FLAG_DMA_MSK0;

    if ((ldflags & MEC5_QSPI_DCFG1_FLAG_DIR_TX) && chantx) {
        ldma_regs = &regs->TX_LDMA_CHAN[chantx - 1u];
    } else if ((ldflags & MEC5_QSPI_DCFG1_FLAG_DIR_RX) && chanrx) {
        ldma_regs = &regs->RX_LDMA_CHAN[chanrx - 1u];
    } else {
        return MEC_RET_ERR_INVAL;
    }

    ldma_regs->CTRL = 0;
    ldma_regs->MEM_START = (uint32_t)buf_addr;
    ldma_regs->LEN = nbytes;

    if (buf_addr) {
        ctrl |= MEC_BIT(MEC_QSPI_LDMA_CHAN_CTRL_INCRA_Pos);
    } else {
        ldma_regs->MEM_START = (uint32_t)((uintptr_t)&regs->BCNT_STS & UINT32_MAX);
    }

    if (!((buf_addr | nbytes) & 0x3u)) {
        ctrl &= (uint32_t)~MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_Msk;
        ctrl |= ((uint32_t)MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_4B << MEC_QSPI_LDMA_CHAN_CTRL_ACCSZ_Pos);
    }

    ldma_regs->CTRL = ctrl | MEC_BIT(MEC_QSPI_LDMA_CHAN_CTRL_EN_Pos);

    return 0;
}

/* Configures descriptor(s):
 *   IFM (full-duplex, dual, or quad)
 *   xfr count unit size
 *   number of units
 *   TX enable (TX-Data only)
 *   TX-LDMA channel select (disable or channel id)
 *   RX enable
 *   RX-LDMA channel select (disable or channel id)
 */
uint32_t mec_hal_qspi_descrs_cfg1(struct mec_qspi_context *ctx, uint32_t nbytes, uint32_t flags)
{
    uint32_t dbase;
    uint32_t nb;
    uint32_t nu;
    uint8_t didx;

    if (!ctx) {
        return UINT32_MAX;
    }

    dbase = qspi_nio_pins_to_ifm(flags & MEC5_QSPI_DCFG1_FLAG_IFM_MSK);

    if (flags & MEC5_QSPI_DCFG1_FLAG_DIR_TX) {
        dbase |= (MEC_QSPI_DESCR_TXEN_EN << MEC_QSPI_DESCR_TXEN_Pos);
        /* b[5:4] = TX-DMA: 0=disabled, 1-2 specify LDMA channel */
        dbase |= ((flags >> MEC5_QSPI_DCFG1_FLAG_DMA_TX_POS)
                  & MEC5_QSPI_DCFG1_FLAG_DMA_MSK0) << MEC_QSPI_DESCR_TXDMA_Pos;
    }
    if (flags & MEC5_QSPI_DCFG1_FLAG_DIR_RX) {
        dbase |= MEC_BIT(MEC_QSPI_DESCR_RXEN_Pos);
        /* b[8:7] = RX-DMA: 0=disabled, 1-2 specify LDMA channel */
        dbase |= ((flags >> MEC5_QSPI_DCFG1_FLAG_DMA_RX_POS)
                  & MEC5_QSPI_DCFG1_FLAG_DMA_MSK0) << MEC_QSPI_DESCR_RXDMA_Pos;
    }

    didx = ctx->ndescrs;
    nb = nbytes;
    while (nb) {
        if (didx >= MEC5_QSPI_NUM_DESCRS) {
            break;
        }

        /* b[11:10] = 01b 1-byte units
         *            11b 16-byte units
         * b[31:17] = number of units
         */
        if (nb > MEC_QSPI_DESCR_NU_MAX) {
            nu = (nb >> 4);
            if (nu > MEC_QSPI_DESCR_NU_MAX) {
                nu = MEC_QSPI_DESCR_NU_MAX;
            }
            ctx->descrs[didx] = (((nu << MEC_QSPI_DESCR_QNUNITS_Pos) & MEC_QSPI_DESCR_QNUNITS_Msk)
                                 | (MEC_QSPI_DESCR_QUNITS_16B << MEC_QSPI_DESCR_QUNITS_Pos)
                                 | dbase);
            nb -= (nu << 4);
        } else {
            ctx->descrs[didx] = (((nb << MEC_QSPI_DESCR_QNUNITS_Pos) & MEC_QSPI_DESCR_QNUNITS_Msk)
                                 | (MEC_QSPI_DESCR_QUNITS_1B << MEC_QSPI_DESCR_QUNITS_Pos)
                                 | dbase);
            nb = 0;
        }
        didx++;
    }

    ctx->ndescrs = didx;

    return nb;
}

int mec_hal_qspi_load_descrs(struct mec_qspi_regs *regs, struct mec_qspi_context *ctx,
                             uint32_t flags)
{
    size_t didx, max_ndescr;
    uint32_t descr, ldchan, mode;

    if (!regs || !ctx) {
        return MEC_RET_ERR_INVAL;
    }

    if (!ctx->ndescrs) {
        return MEC_RET_ERR_NOP;
    }

    mode = 0;
    max_ndescr = (size_t)ctx->ndescrs;

    if (max_ndescr > MEC5_QSPI_NUM_DESCRS) {
        max_ndescr = MEC5_QSPI_NUM_DESCRS;
    }

    for (didx = 0; didx < max_ndescr; didx++) {
        descr = ctx->descrs[didx];
        descr &= (uint32_t)~(MEC_QSPI_DESCR_NEXT_Msk);
        descr |= ((((uint32_t)didx + 1u) << MEC_QSPI_DESCR_NEXT_Pos) & MEC_QSPI_DESCR_NEXT_Msk);
        regs->DESCR[didx] = descr;

        if ((descr & MEC_QSPI_DESCR_TXEN_Msk) == (MEC_QSPI_DESCR_TXEN_EN << MEC_QSPI_DESCR_TXEN_Pos)) {
            /* TX-Data enabled? */
            ldchan = (descr & MEC_QSPI_DESCR_TXDMA_Msk) >> MEC_QSPI_DESCR_TXDMA_Pos;
            if (ldchan) {
                regs->LDMA_TXEN |= MEC_BIT(didx);
                mode |= MEC_BIT(MEC_QSPI_MODE_TX_LDMA_Pos);
            } else {
                regs->LDMA_TXEN &= (uint32_t)~MEC_BIT(didx);
            }
        }

        if (descr & MEC_BIT(MEC_QSPI_DESCR_RXEN_Pos)) {
            ldchan = (descr & MEC_QSPI_DESCR_RXDMA_Msk) >> MEC_QSPI_DESCR_RXDMA_Pos;
            if (ldchan) {
                regs->LDMA_RXEN |= MEC_BIT(didx);
                mode |= MEC_BIT(MEC_QSPI_MODE_RX_LDMA_Pos);
            } else {
                regs->LDMA_RXEN &= (uint32_t)~MEC_BIT(didx);
            }
        }
    }

    regs->MODE = (regs->MODE & ~(MEC_BIT(MEC_QSPI_MODE_TX_LDMA_Pos)
                                 | MEC_BIT(MEC_QSPI_MODE_RX_LDMA_Pos))) | mode;

    didx = max_ndescr - 1u;
    if (flags & MEC_BIT(MEC5_QSPI_LD_FLAGS_LAST_POS)) {
        regs->DESCR[didx] |= MEC_BIT(MEC_QSPI_DESCR_LAST_Pos);
    }

    if (flags & MEC_BIT(MEC5_QSPI_LD_FLAGS_CLOSE_ON_LAST_POS)) {
        regs->DESCR[didx] |= MEC_BIT(MEC_QSPI_DESCR_CLOSE_Pos);
    }

    /* Enable descriptor mode with start descriptor = Descr[0] */
    regs->CTRL = MEC_BIT(MEC_QSPI_CTRL_DESCR_MODE_Pos);

    return 0;
}

/* Load descriptors register only. Does not touch other QSPI registers */
int mec_hal_qspi_load_descrs_at(struct mec_qspi_regs *regs, const uint32_t *descrs, uint8_t ndescr,
                                uint8_t start_descr_idx)
{
    uint32_t didx, didx_lim, n;

    if (!regs || !descrs || !ndescr || (start_descr_idx >= MEC5_QSPI_NUM_DESCRS)) {
        return MEC_RET_ERR_INVAL;
    }

    if (mec_hal_qspi_done(regs) == MEC_RET_ERR_BUSY) {
        return MEC_RET_ERR_BUSY;
    }

    didx = start_descr_idx;
    didx_lim = didx + ndescr;
    if (didx_lim > MEC5_QSPI_NUM_DESCRS) {
        didx_lim = MEC5_QSPI_NUM_DESCRS;
    }

    n = 0;
    while (didx < didx_lim) {
        regs->DESCR[didx++] = descrs[n++];
    }

    return MEC_RET_OK;
}

/* end mec_qspi.c */
