/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @brief Header containing command specific declarations for the
 * FMAC IF Layer of the Wi-Fi driver.
 */

#ifndef __FMAC_CMD_H__
#define __FMAC_CMD_H__

#include "fmac_structs_common.h"

#define NRF_WIFI_FMAC_STATS_RECV_TIMEOUT 50 /* ms */
#define NRF_WIFI_FMAC_PS_CONF_EVNT_RECV_TIMEOUT 50 /* ms */
#ifdef NRF70_RADIO_TEST
#define NRF_WIFI_FMAC_RF_TEST_EVNT_TIMEOUT 50 /* 5s */
#endif /* NRF_WIFI_LOW_POWER */
#define NRF_WIFI_FMAC_REG_SET_TIMEOUT_MS 2000 /* 2s */

struct host_rpu_msg *umac_cmd_alloc(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
				    int type,
				    int size);

enum nrf_wifi_status umac_cmd_cfg(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
				  void *params,
				  int len);

enum nrf_wifi_status umac_cmd_init(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
				   struct nrf_wifi_phy_rf_params *rf_params,
				   bool rf_params_valid,
#if !defined(NRF70_RADIO_TEST) && !defined(NRF70_OFFLOADED_RAW_TX)
				   struct nrf_wifi_data_config_params *config,
#endif /* !NRF70_RADIO_TEST && !NRF70_OFFLOADED_RAW_TX */
#ifdef NRF_WIFI_LOW_POWER
				   int sleep_type,
#endif /* NRF_WIFI_LOW_POWER */
				   unsigned int phy_calib,
				   enum op_band op_band,
				   bool beamforming,
				   struct nrf_wifi_tx_pwr_ctrl_params *tx_pwr_ctrl_params,
				   struct nrf_wifi_board_params *board_params,
				   unsigned char *country_code);

enum nrf_wifi_status umac_cmd_deinit(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx);

enum nrf_wifi_status umac_cmd_srcoex(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
	void *cmd, unsigned int cmd_len);
#ifndef NRF70_OFFLOADED_RAW_TX
enum nrf_wifi_status umac_cmd_he_ltf_gi(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
					unsigned char he_ltf,
					unsigned char he_gi,
					unsigned char enabled);

#ifdef NRF70_RADIO_TEST
enum nrf_wifi_status umac_cmd_prog_init(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
					struct nrf_wifi_radio_test_init_info *init_params);

enum nrf_wifi_status umac_cmd_prog_tx(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
				      struct rpu_conf_params *params);

enum nrf_wifi_status umac_cmd_prog_rx(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
				      struct rpu_conf_rx_radio_test_params *rx_params);

enum nrf_wifi_status umac_cmd_prog_rf_test(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
					   void *rf_test_params,
					   unsigned int rf_test_params_sz);
#endif /* NRF70_RADIO_TEST */
#endif /* NRF70_OFFLOADED_RAW_TX */

enum nrf_wifi_status umac_cmd_prog_stats_get(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
#ifdef NRF70_RADIO_TEST
					     int op_mode,
#endif /* NRF70_RADIO_TEST */
					     int stat_type);

#ifndef NRF70_OFFLOADED_RAW_TX
enum nrf_wifi_status umac_cmd_prog_stats_reset(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx);
#endif /* !NRF70_OFFLOADED_RAW_TX */

#ifdef NRF70_OFFLOADED_RAW_TX
enum nrf_wifi_status umac_cmd_off_raw_tx_conf(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
					struct nrf_wifi_offload_ctrl_params *offloaded_tx_params,
					struct nrf_wifi_offload_tx_ctrl *offload_tx_ctr);

enum nrf_wifi_status umac_cmd_off_raw_tx_ctrl(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
					unsigned char ctrl_type);
#endif /* NRF70_OFFLOADED_RAW_TX */

enum nrf_wifi_status umac_cmd_set_ps_exit_strategy(struct nrf_wifi_fmac_dev_ctx *fmac_dev_ctx,
					enum ps_exit_strategy ps_exit_strategy);
#endif /* __FMAC_CMD_H__ */
