/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_provisioning.h"

#include "log.h"
#include "corstone315_provisioning_bundle.h"
#include "tfm_plat_otp.h"
#include "platform_s_device_definition.h"
#include "tfm_hal_platform.h"
#include <string.h>
#include "platform_regs.h"


static const volatile struct cm_provisioning_bundle *cm_bundle =
(const struct cm_provisioning_bundle *)CM_PROVISIONING_BUNDLE_START;

static const volatile struct dm_provisioning_bundle *dm_bundle =
(const struct dm_provisioning_bundle *)DM_PROVISIONING_BUNDLE_START;


void tfm_plat_provisioning_check_for_dummy_keys(void)
{
}

int tfm_plat_provisioning_is_required(void)
{
    enum lcm_error_t err;
    enum lcm_lcs_t lcs;
    bool provisioning_required;

    err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (err != LCM_ERROR_NONE) {
        return 1;
    }

    provisioning_required = (lcs == LCM_LCS_CM || lcs == LCM_LCS_DM);

    return provisioning_required;
}

static enum tfm_plat_err_t enable_sp_mode(void)
{
    enum lcm_bool_t sp_enabled;
    enum lcm_error_t lcm_err;

    lcm_err = lcm_get_sp_enabled(&LCM_DEV_S, &sp_enabled);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (sp_enabled != LCM_TRUE) {
        BL1_LOG("[INF] Enabling secure provisioning mode, system will now reset.\r\n");
        lcm_set_sp_enabled(&LCM_DEV_S);
    }

    /* We'll never get here */
    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t provision_assembly_and_test(void)
{
    enum tfm_plat_err_t err;

    err = enable_sp_mode();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* TODO replace this with decrypt and auth */
    memcpy((void*)PROVISIONING_BUNDLE_CODE_START,
           (void *)cm_bundle->code,
           PROVISIONING_BUNDLE_CODE_SIZE);
    memcpy((void*)PROVISIONING_BUNDLE_VALUES_START,
           (void *)&cm_bundle->values,
           PROVISIONING_BUNDLE_VALUES_SIZE + PROVISIONING_BUNDLE_DATA_SIZE);

    BL1_LOG("[INF] Running CM provisioning bundle\r\n");
    err = ((enum tfm_plat_err_t (*)(void))(PROVISIONING_BUNDLE_CODE_START | 0b1))();

    memset((void *)PROVISIONING_BUNDLE_CODE_START, 0,
           PROVISIONING_BUNDLE_CODE_SIZE);
    memset((void *)PROVISIONING_BUNDLE_VALUES_START, 0,
           PROVISIONING_BUNDLE_VALUES_SIZE + PROVISIONING_BUNDLE_DATA_SIZE);

    return err;
}

static enum tfm_plat_err_t provision_psa_rot(void)
{
    enum tfm_plat_err_t err;

    err = enable_sp_mode();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* TODO replace this with decrypt and auth */
    memcpy((void *)PROVISIONING_BUNDLE_CODE_START,
           (void *)dm_bundle->code,
           PROVISIONING_BUNDLE_CODE_SIZE);
    memcpy((void *)PROVISIONING_BUNDLE_VALUES_START,
           (void *)&dm_bundle->values,
           PROVISIONING_BUNDLE_VALUES_SIZE + PROVISIONING_BUNDLE_DATA_SIZE);

    BL1_LOG("[INF] Running DM provisioning bundle\r\n");
    err = ((enum tfm_plat_err_t (*)(void))(PROVISIONING_BUNDLE_CODE_START | 0b1))();

    memset((void *)PROVISIONING_BUNDLE_CODE_START, 0,
           PROVISIONING_BUNDLE_CODE_SIZE);
    memset((void *)PROVISIONING_BUNDLE_VALUES_START, 0,
           PROVISIONING_BUNDLE_VALUES_SIZE + PROVISIONING_BUNDLE_DATA_SIZE);

    return err;
}

static enum tfm_plat_err_t set_tp_mode(void)
{
    volatile enum lcm_tp_mode_t tp_mode = LCM_TP_MODE_VIRGIN;
    enum lcm_error_t lcm_err;

    tp_mode = LCM_TP_MODE_TCI;

    lcm_err = lcm_set_tp_mode(&LCM_DEV_S, tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    BL1_LOG("[INF] TP mode set complete, system will now reset.\r\n");
    tfm_hal_system_reset();

    /* Should not reach this point */
    return TFM_PLAT_ERR_SYSTEM_ERR;
}

enum tfm_plat_err_t tfm_plat_provisioning_perform(void)
{
    enum tfm_plat_err_t err;
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;
    enum lcm_tp_mode_t tp_mode;

    BL1_LOG("[INF] Beginning provisioning\r\n");

    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
    if (tp_mode == LCM_TP_MODE_VIRGIN) {
        err = set_tp_mode();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    } else if (!(tp_mode == LCM_TP_MODE_TCI || tp_mode == LCM_TP_MODE_PCI)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (lcs == LCM_LCS_CM) {
        BL1_LOG("[INF] Waiting for CM provisioning bundle\r\n");
        while (cm_bundle->magic != CM_BUNDLE_MAGIC ||
               cm_bundle->magic2 != CM_BUNDLE_MAGIC) {
        }

        err = provision_assembly_and_test();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
    if (lcs == LCM_LCS_DM) {

        BL1_LOG("[INF] Waiting for DM provisioning bundle\r\n");
        while (dm_bundle->magic != DM_BUNDLE_MAGIC ||
               dm_bundle->magic2 != DM_BUNDLE_MAGIC) {
        }

        err = provision_psa_rot();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}
