#ifndef _VTSS_JAGUAR2_REGS_VAUI_CHANNEL_H_
#define _VTSS_JAGUAR2_REGS_VAUI_CHANNEL_H_

/*
 *
 * VCore-III Register Definitions
 *
 * Copyright (C) 2012 Vitesse Semiconductor Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "vtss_jaguar2_regs_common.h"

#define VTSS_VAUI_CHANNEL_VAUI_CHANNEL_CFG_VAUI_CHANNEL_CFG(target,ri)  VTSS_IOREG(target,0x0 + (ri))
#define  VTSS_F_VAUI_CHANNEL_VAUI_CHANNEL_CFG_VAUI_CHANNEL_CFG_LANE_SYNC_ENA(x)  VTSS_ENCODE_BITFIELD(x,4,4)
#define  VTSS_M_VAUI_CHANNEL_VAUI_CHANNEL_CFG_VAUI_CHANNEL_CFG_LANE_SYNC_ENA     VTSS_ENCODE_BITMASK(4,4)
#define  VTSS_X_VAUI_CHANNEL_VAUI_CHANNEL_CFG_VAUI_CHANNEL_CFG_LANE_SYNC_ENA(x)  VTSS_EXTRACT_BITFIELD(x,4,4)
#define  VTSS_F_VAUI_CHANNEL_VAUI_CHANNEL_CFG_VAUI_CHANNEL_CFG_SIGDET_MODE_R  VTSS_BIT(1)
#define  VTSS_F_VAUI_CHANNEL_VAUI_CHANNEL_CFG_VAUI_CHANNEL_CFG_SIGDET_MODE  VTSS_BIT(0)

#define VTSS_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG(gi)  VTSS_IOREG_IX(target,0x2,gi,5,0,0)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_ANEG_RESET_ONE_SHOT  VTSS_BIT(31)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_TXBYP_TESTMODE  VTSS_BIT(23)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_ATE_TESTMODE  VTSS_BIT(22)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_RX_TESTMODE  VTSS_BIT(21)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_ARB_TESTMODE  VTSS_BIT(20)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_ANEG_OB_CTRL_DIS  VTSS_BIT(16)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_ANEG_FREQSEL_DIS  VTSS_BIT(15)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_ANEG_PWDN_DIS  VTSS_BIT(14)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_10GKX4(x)  VTSS_ENCODE_BITFIELD(x,12,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_10GKX4     VTSS_ENCODE_BITMASK(12,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_10GKX4(x)  VTSS_EXTRACT_BITFIELD(x,12,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_1GKX(x)  VTSS_ENCODE_BITFIELD(x,10,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_1GKX     VTSS_ENCODE_BITMASK(10,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_1GKX(x)  VTSS_EXTRACT_BITFIELD(x,10,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_2G5(x)  VTSS_ENCODE_BITFIELD(x,8,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_2G5     VTSS_ENCODE_BITMASK(8,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_PD_TIMER_2G5(x)  VTSS_EXTRACT_BITFIELD(x,8,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_BLTD_ENA  VTSS_BIT(7)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_RESTART_ANEG_ONE_SHOT  VTSS_BIT(1)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_CFG_ANEG_ENA  VTSS_BIT(0)

#define VTSS_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0(gi)  VTSS_IOREG_IX(target,0x2,gi,5,0,1)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_ADV_ABIL_LSB(x)  VTSS_ENCODE_BITFIELD(x,24,8)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_ADV_ABIL_LSB     VTSS_ENCODE_BITMASK(24,8)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_ADV_ABIL_LSB(x)  VTSS_EXTRACT_BITFIELD(x,24,8)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_CAP_10GKR  VTSS_BIT(23)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_CAP_10GKX4  VTSS_BIT(22)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_CAP_1GKX  VTSS_BIT(21)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_TX_NONCE(x)  VTSS_ENCODE_BITFIELD(x,16,5)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_TX_NONCE     VTSS_ENCODE_BITMASK(16,5)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_TX_NONCE(x)  VTSS_EXTRACT_BITFIELD(x,16,5)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_NP  VTSS_BIT(15)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_ACKN  VTSS_BIT(14)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_RF  VTSS_BIT(13)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_PAUSE(x)  VTSS_ENCODE_BITFIELD(x,10,3)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_PAUSE     VTSS_ENCODE_BITMASK(10,3)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_PAUSE(x)  VTSS_EXTRACT_BITFIELD(x,10,3)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_ECHOED_NONCE(x)  VTSS_ENCODE_BITFIELD(x,5,5)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_ECHOED_NONCE     VTSS_ENCODE_BITMASK(5,5)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_ECHOED_NONCE(x)  VTSS_EXTRACT_BITFIELD(x,5,5)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_SEL_FIELD(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_SEL_FIELD     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_0_SEL_FIELD(x)  VTSS_EXTRACT_BITFIELD(x,0,5)

#define VTSS_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_1(gi)  VTSS_IOREG_IX(target,0x2,gi,5,0,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_1_FEC(x)  VTSS_ENCODE_BITFIELD(x,14,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_1_FEC     VTSS_ENCODE_BITMASK(14,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_1_FEC(x)  VTSS_EXTRACT_BITFIELD(x,14,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_1_ADV_ABIL_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,14)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_1_ADV_ABIL_MSB     VTSS_ENCODE_BITMASK(0,14)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_ADV_ABILITY_1_ADV_ABIL_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,14)

#define VTSS_VAUI_CHANNEL_ANEG_CFG_ANEG_NEXT_PAGE_0(gi)  VTSS_IOREG_IX(target,0x2,gi,5,0,3)

#define VTSS_VAUI_CHANNEL_ANEG_CFG_ANEG_NEXT_PAGE_1(gi)  VTSS_IOREG_IX(target,0x2,gi,5,0,4)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_NEXT_PAGE_1_NEXT_PAGE_LOADED_ONE_SHOT  VTSS_BIT(31)
#define  VTSS_F_VAUI_CHANNEL_ANEG_CFG_ANEG_NEXT_PAGE_1_NP_TX_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_VAUI_CHANNEL_ANEG_CFG_ANEG_NEXT_PAGE_1_NP_TX_MSB     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_VAUI_CHANNEL_ANEG_CFG_ANEG_NEXT_PAGE_1_NP_TX_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0(gi)  VTSS_IOREG_IX(target,0x2a,gi,3,0,0)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_LP_ADV_ABIL_LSB(x)  VTSS_ENCODE_BITFIELD(x,24,8)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_LP_ADV_ABIL_LSB     VTSS_ENCODE_BITMASK(24,8)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_LP_ADV_ABIL_LSB(x)  VTSS_EXTRACT_BITFIELD(x,24,8)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_CAP_10GKR  VTSS_BIT(23)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_CAP_10GKX4  VTSS_BIT(22)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_CAP_1GKX  VTSS_BIT(21)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_TX_NONCE(x)  VTSS_ENCODE_BITFIELD(x,16,5)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_TX_NONCE     VTSS_ENCODE_BITMASK(16,5)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_TX_NONCE(x)  VTSS_EXTRACT_BITFIELD(x,16,5)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_NP  VTSS_BIT(15)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_ACKN  VTSS_BIT(14)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_RF  VTSS_BIT(13)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_PAUSE(x)  VTSS_ENCODE_BITFIELD(x,10,3)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_PAUSE     VTSS_ENCODE_BITMASK(10,3)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_PAUSE(x)  VTSS_EXTRACT_BITFIELD(x,10,3)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_ECHOED_NONCE(x)  VTSS_ENCODE_BITFIELD(x,5,5)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_ECHOED_NONCE     VTSS_ENCODE_BITMASK(5,5)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_ECHOED_NONCE(x)  VTSS_EXTRACT_BITFIELD(x,5,5)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_SEL_FIELD(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_SEL_FIELD     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_0_SEL_FIELD(x)  VTSS_EXTRACT_BITFIELD(x,0,5)

#define VTSS_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_1(gi)  VTSS_IOREG_IX(target,0x2a,gi,3,0,1)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_1_FEC(x)  VTSS_ENCODE_BITFIELD(x,14,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_1_FEC     VTSS_ENCODE_BITMASK(14,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_1_FEC(x)  VTSS_EXTRACT_BITFIELD(x,14,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_1_LP_ADV_ABIL_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,14)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_1_LP_ADV_ABIL_MSB     VTSS_ENCODE_BITMASK(0,14)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_LP_ADV_ABILITY_1_LP_ADV_ABIL_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,14)

#define VTSS_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS(gi)  VTSS_IOREG_IX(target,0x2a,gi,3,0,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_10GKX4(x)  VTSS_ENCODE_BITFIELD(x,28,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_10GKX4     VTSS_ENCODE_BITMASK(28,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_10GKX4(x)  VTSS_EXTRACT_BITFIELD(x,28,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_1GKX(x)  VTSS_ENCODE_BITFIELD(x,26,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_1GKX     VTSS_ENCODE_BITMASK(26,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_1GKX(x)  VTSS_EXTRACT_BITFIELD(x,26,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_2G5(x)  VTSS_ENCODE_BITFIELD(x,24,2)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_2G5     VTSS_ENCODE_BITMASK(24,2)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LINK_CTRL_2G5(x)  VTSS_EXTRACT_BITFIELD(x,24,2)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_ANEG_ARB_FSM_ERR_STICKY  VTSS_BIT(20)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_ANEG_RX_FSM_ERR_STICKY  VTSS_BIT(19)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_ANEG_TX_FSM_ERR_STICKY  VTSS_BIT(18)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_INCOMPATIBLE_LINK  VTSS_BIT(17)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_PAR_DETECT_FAULT_STICKY  VTSS_BIT(16)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_ARBITER_STATE(x)  VTSS_ENCODE_BITFIELD(x,8,4)
#define  VTSS_M_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_ARBITER_STATE     VTSS_ENCODE_BITMASK(8,4)
#define  VTSS_X_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_ARBITER_STATE(x)  VTSS_EXTRACT_BITFIELD(x,8,4)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_PAGE_RX  VTSS_BIT(3)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_LP_ANEG_ABLE  VTSS_BIT(1)
#define  VTSS_F_VAUI_CHANNEL_ANEG_STATUS_ANEG_STATUS_ANEG_COMPLETE  VTSS_BIT(0)


#endif /* _VTSS_JAGUAR2_REGS_VAUI_CHANNEL_H_ */
