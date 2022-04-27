#ifndef _VTSS_JAGUAR2_REGS_REW_H_
#define _VTSS_JAGUAR2_REGS_REW_H_

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

#define VTSS_REW_COMMON_COMMON_CTRL          VTSS_IOREG(VTSS_TO_REW,0x10750)
#define  VTSS_F_REW_COMMON_COMMON_CTRL_L3_CLR_VSTAX_DST_RSV  VTSS_BIT(7)
#define  VTSS_F_REW_COMMON_COMMON_CTRL_OWN_UPSID(x)  VTSS_ENCODE_BITFIELD(x,2,5)
#define  VTSS_M_REW_COMMON_COMMON_CTRL_OWN_UPSID     VTSS_ENCODE_BITMASK(2,5)
#define  VTSS_X_REW_COMMON_COMMON_CTRL_OWN_UPSID(x)  VTSS_EXTRACT_BITFIELD(x,2,5)
#define  VTSS_F_REW_COMMON_COMMON_CTRL_INVLD_W16_POP_CNT_FRM_ABORT  VTSS_BIT(1)
#define  VTSS_F_REW_COMMON_COMMON_CTRL_FRM_CLR_PAD_ENA  VTSS_BIT(0)

#define VTSS_REW_COMMON_PORT_CTRL(ri)        VTSS_IOREG(VTSS_TO_REW,0x10751 + (ri))
#define  VTSS_F_REW_COMMON_PORT_CTRL_ES0_LPORT_NUM(x)  VTSS_ENCODE_BITFIELD(x,17,6)
#define  VTSS_M_REW_COMMON_PORT_CTRL_ES0_LPORT_NUM     VTSS_ENCODE_BITMASK(17,6)
#define  VTSS_X_REW_COMMON_PORT_CTRL_ES0_LPORT_NUM(x)  VTSS_EXTRACT_BITFIELD(x,17,6)
#define  VTSS_F_REW_COMMON_PORT_CTRL_VSTAX2_MISC_ISDX_ENA  VTSS_BIT(15)
#define  VTSS_F_REW_COMMON_PORT_CTRL_PORT_VOE_TPID_AWARE_DIS(x)  VTSS_ENCODE_BITFIELD(x,10,5)
#define  VTSS_M_REW_COMMON_PORT_CTRL_PORT_VOE_TPID_AWARE_DIS     VTSS_ENCODE_BITMASK(10,5)
#define  VTSS_X_REW_COMMON_PORT_CTRL_PORT_VOE_TPID_AWARE_DIS(x)  VTSS_EXTRACT_BITFIELD(x,10,5)
#define  VTSS_F_REW_COMMON_PORT_CTRL_PORT_VOE_DEFAULT_PCP(x)  VTSS_ENCODE_BITFIELD(x,7,3)
#define  VTSS_M_REW_COMMON_PORT_CTRL_PORT_VOE_DEFAULT_PCP     VTSS_ENCODE_BITMASK(7,3)
#define  VTSS_X_REW_COMMON_PORT_CTRL_PORT_VOE_DEFAULT_PCP(x)  VTSS_EXTRACT_BITFIELD(x,7,3)
#define  VTSS_F_REW_COMMON_PORT_CTRL_PORT_VOE_DEFAULT_DEI  VTSS_BIT(6)
#define  VTSS_F_REW_COMMON_PORT_CTRL_KEEP_IFH_SEL(x)  VTSS_ENCODE_BITFIELD(x,4,2)
#define  VTSS_M_REW_COMMON_PORT_CTRL_KEEP_IFH_SEL     VTSS_ENCODE_BITMASK(4,2)
#define  VTSS_X_REW_COMMON_PORT_CTRL_KEEP_IFH_SEL(x)  VTSS_EXTRACT_BITFIELD(x,4,2)
#define  VTSS_F_REW_COMMON_PORT_CTRL_VSTAX2_MIRROR_OBEY_WAS_TAGGED  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_PORT_CTRL_VSTAX_PAD_ENA  VTSS_BIT(2)
#define  VTSS_F_REW_COMMON_PORT_CTRL_VSTAX_HDR_ENA  VTSS_BIT(1)
#define  VTSS_F_REW_COMMON_PORT_CTRL_VSTAX_STACK_GRP_SEL  VTSS_BIT(0)

#define VTSS_REW_COMMON_TPID_CFG(ri)         VTSS_IOREG(VTSS_TO_REW,0x10786 + (ri))
#define  VTSS_F_REW_COMMON_TPID_CFG_TPID_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_COMMON_TPID_CFG_TPID_VAL     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_COMMON_TPID_CFG_TPID_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_COMMON_ES0_CTRL             VTSS_IOREG(VTSS_TO_REW,0x10789)
#define  VTSS_F_REW_COMMON_ES0_CTRL_ES0_FRM_LBK_CFG  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_ES0_CTRL_ES0_BY_RT_FWD  VTSS_BIT(2)
#define  VTSS_F_REW_COMMON_ES0_CTRL_ES0_BY_RLEG  VTSS_BIT(1)
#define  VTSS_F_REW_COMMON_ES0_CTRL_ES0_LU_ENA  VTSS_BIT(0)

#define VTSS_REW_COMMON_MIRROR_PROBE_CFG(ri)  VTSS_IOREG(VTSS_TO_REW,0x1078a + (ri))
#define  VTSS_F_REW_COMMON_MIRROR_PROBE_CFG_MIRROR_TX_PORT(x)  VTSS_ENCODE_BITFIELD(x,12,6)
#define  VTSS_M_REW_COMMON_MIRROR_PROBE_CFG_MIRROR_TX_PORT     VTSS_ENCODE_BITMASK(12,6)
#define  VTSS_X_REW_COMMON_MIRROR_PROBE_CFG_MIRROR_TX_PORT(x)  VTSS_EXTRACT_BITFIELD(x,12,6)
#define  VTSS_F_REW_COMMON_MIRROR_PROBE_CFG_REMOTE_ENCAP_ID(x)  VTSS_ENCODE_BITFIELD(x,2,10)
#define  VTSS_M_REW_COMMON_MIRROR_PROBE_CFG_REMOTE_ENCAP_ID     VTSS_ENCODE_BITMASK(2,10)
#define  VTSS_X_REW_COMMON_MIRROR_PROBE_CFG_REMOTE_ENCAP_ID(x)  VTSS_EXTRACT_BITFIELD(x,2,10)
#define  VTSS_F_REW_COMMON_MIRROR_PROBE_CFG_REMOTE_MIRROR_CFG(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_COMMON_MIRROR_PROBE_CFG_REMOTE_MIRROR_CFG     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_COMMON_MIRROR_PROBE_CFG_REMOTE_MIRROR_CFG(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_REW_COMMON_MIRROR_TAG_A_CFG(ri)  VTSS_IOREG(VTSS_TO_REW,0x1078d + (ri))
#define  VTSS_F_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_TPID_SEL(x)  VTSS_ENCODE_BITFIELD(x,17,3)
#define  VTSS_M_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_TPID_SEL     VTSS_ENCODE_BITMASK(17,3)
#define  VTSS_X_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_TPID_SEL(x)  VTSS_EXTRACT_BITFIELD(x,17,3)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_VID_VAL(x)  VTSS_ENCODE_BITFIELD(x,5,12)
#define  VTSS_M_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_VID_VAL     VTSS_ENCODE_BITMASK(5,12)
#define  VTSS_X_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_VID_VAL(x)  VTSS_EXTRACT_BITFIELD(x,5,12)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_DEI_VAL  VTSS_BIT(4)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_PCP_SEL  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_PCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_PCP_VAL     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_COMMON_MIRROR_TAG_A_CFG_TAG_A_PCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_COMMON_MIRROR_TAG_B_CFG(ri)  VTSS_IOREG(VTSS_TO_REW,0x10790 + (ri))
#define  VTSS_F_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_TPID_SEL(x)  VTSS_ENCODE_BITFIELD(x,17,3)
#define  VTSS_M_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_TPID_SEL     VTSS_ENCODE_BITMASK(17,3)
#define  VTSS_X_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_TPID_SEL(x)  VTSS_EXTRACT_BITFIELD(x,17,3)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_VID_VAL(x)  VTSS_ENCODE_BITFIELD(x,5,12)
#define  VTSS_M_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_VID_VAL     VTSS_ENCODE_BITMASK(5,12)
#define  VTSS_X_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_VID_VAL(x)  VTSS_EXTRACT_BITFIELD(x,5,12)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_DEI_VAL  VTSS_BIT(4)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_PCP_SEL  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_PCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_PCP_VAL     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_COMMON_MIRROR_TAG_B_CFG_TAG_B_PCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_COMMON_DP_MAP               VTSS_IOREG(VTSS_TO_REW,0x10793)
#define  VTSS_F_REW_COMMON_DP_MAP_DP(x)       VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_REW_COMMON_DP_MAP_DP          VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_REW_COMMON_DP_MAP_DP(x)       VTSS_EXTRACT_BITFIELD(x,0,4)

#define VTSS_REW_COMMON_DSCP_REMAP(ri)       VTSS_IOREG(VTSS_TO_REW,0x10794 + (ri))
#define  VTSS_F_REW_COMMON_DSCP_REMAP_DSCP_REMAP(x)  VTSS_ENCODE_BITFIELD(x,0,6)
#define  VTSS_M_REW_COMMON_DSCP_REMAP_DSCP_REMAP     VTSS_ENCODE_BITMASK(0,6)
#define  VTSS_X_REW_COMMON_DSCP_REMAP_DSCP_REMAP(x)  VTSS_EXTRACT_BITFIELD(x,0,6)

#define VTSS_REW_COMMON_RLEG_CFG_0           VTSS_IOREG(VTSS_TO_REW,0x107d4)
#define  VTSS_F_REW_COMMON_RLEG_CFG_0_RLEG_MAC_LSB(x)  VTSS_ENCODE_BITFIELD(x,0,24)
#define  VTSS_M_REW_COMMON_RLEG_CFG_0_RLEG_MAC_LSB     VTSS_ENCODE_BITMASK(0,24)
#define  VTSS_X_REW_COMMON_RLEG_CFG_0_RLEG_MAC_LSB(x)  VTSS_EXTRACT_BITFIELD(x,0,24)

#define VTSS_REW_COMMON_RLEG_CFG_1           VTSS_IOREG(VTSS_TO_REW,0x107d5)
#define  VTSS_F_REW_COMMON_RLEG_CFG_1_RLEG_MAC_TYPE_SEL(x)  VTSS_ENCODE_BITFIELD(x,24,2)
#define  VTSS_M_REW_COMMON_RLEG_CFG_1_RLEG_MAC_TYPE_SEL     VTSS_ENCODE_BITMASK(24,2)
#define  VTSS_X_REW_COMMON_RLEG_CFG_1_RLEG_MAC_TYPE_SEL(x)  VTSS_EXTRACT_BITFIELD(x,24,2)
#define  VTSS_F_REW_COMMON_RLEG_CFG_1_RLEG_MAC_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,24)
#define  VTSS_M_REW_COMMON_RLEG_CFG_1_RLEG_MAC_MSB     VTSS_ENCODE_BITMASK(0,24)
#define  VTSS_X_REW_COMMON_RLEG_CFG_1_RLEG_MAC_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,24)

#define VTSS_REW_COMMON_CNT_CTRL             VTSS_IOREG(VTSS_TO_REW,0x107d6)
#define  VTSS_F_REW_COMMON_CNT_CTRL_EVENT_CNT_PORT(x)  VTSS_ENCODE_BITFIELD(x,5,6)
#define  VTSS_M_REW_COMMON_CNT_CTRL_EVENT_CNT_PORT     VTSS_ENCODE_BITMASK(5,6)
#define  VTSS_X_REW_COMMON_CNT_CTRL_EVENT_CNT_PORT(x)  VTSS_EXTRACT_BITFIELD(x,5,6)
#define  VTSS_F_REW_COMMON_CNT_CTRL_EVENT_CNT_ALL  VTSS_BIT(4)
#define  VTSS_F_REW_COMMON_CNT_CTRL_VSTAX_STAT_ESDX_DIS  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_CNT_CTRL_STAT_CNT_FRM_ABORT_ENA  VTSS_BIT(2)
#define  VTSS_F_REW_COMMON_CNT_CTRL_STAT_MODE(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_COMMON_CNT_CTRL_STAT_MODE     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_COMMON_CNT_CTRL_STAT_MODE(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_REW_COMMON_STICKY_EVENT_COUNT   VTSS_IOREG(VTSS_TO_REW,0x107d7)

#define VTSS_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG  VTSS_IOREG(VTSS_TO_REW,0x107d8)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_INVLD_W16_POP_CNT_STICKY_MASK  VTSS_BIT(16)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_INVLD_POP_CNT_STICKY_MASK  VTSS_BIT(15)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_REWRITE_OVERFLOW_STICKY_MASK  VTSS_BIT(14)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_VLAN_UNTAGGED_VID0_STICKY_MASK  VTSS_BIT(13)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_VLAN_PRIO_TAGGED_STICKY_MASK  VTSS_BIT(12)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_IP6_MC_STICKY_MASK  VTSS_BIT(11)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_IP4_MC_STICKY_MASK  VTSS_BIT(10)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_IP6_UC_STICKY_MASK  VTSS_BIT(9)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_IP4_UC_STICKY_MASK  VTSS_BIT(8)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_DSCP_REMAP_STICKY_MASK  VTSS_BIT(7)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_DSCP_REPLACE_STICKY_MASK  VTSS_BIT(6)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_INVLD_IFH_FOR_PTP_FRM_STICKY_MASK  VTSS_BIT(5)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_LINK_LAYER_ERROR_STICKY_MASK  VTSS_BIT(4)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_LINK_LAYER_ADDED_STICKY_MASK  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_VLAN_TAG_STICKY_MASK  VTSS_BIT(2)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_VLAN_UNTAG_STICKY_MASK  VTSS_BIT(1)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_CNT_MASK_CFG_VLAN_POP_CNT_STICKY_MASK  VTSS_BIT(0)

#define VTSS_REW_COMMON_STICKY_EVENT         VTSS_IOREG(VTSS_TO_REW,0x107d9)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_INVLD_W16_POP_CNT_STICKY  VTSS_BIT(16)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_INVLD_POP_CNT_STICKY  VTSS_BIT(15)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_REWRITE_OVERFLOW_STICKY  VTSS_BIT(14)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_VLAN_UNTAGGED_VID0_STICKY  VTSS_BIT(13)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_VLAN_PRIO_TAGGED_STICKY  VTSS_BIT(12)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_IP6_MC_STICKY  VTSS_BIT(11)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_IP4_MC_STICKY  VTSS_BIT(10)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_IP6_UC_STICKY  VTSS_BIT(9)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_IP4_UC_STICKY  VTSS_BIT(8)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_DSCP_REMAP_STICKY  VTSS_BIT(7)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_DSCP_REPLACE_STICKY  VTSS_BIT(6)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_INVLD_IFH_FOR_PTP_FRM_STICKY  VTSS_BIT(5)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_LINK_LAYER_ERROR_STICKY  VTSS_BIT(4)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_LINK_LAYER_ADDED_STICKY  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_VLAN_TAG_STICKY  VTSS_BIT(2)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_VLAN_UNTAG_STICKY  VTSS_BIT(1)
#define  VTSS_F_REW_COMMON_STICKY_EVENT_VLAN_POP_CNT_STICKY  VTSS_BIT(0)

#define VTSS_REW_COMMON_GCPU_CFG(ri)         VTSS_IOREG(VTSS_TO_REW,0x107da + (ri))
#define  VTSS_F_REW_COMMON_GCPU_CFG_GCPU_KEEP_IFH(x)  VTSS_ENCODE_BITFIELD(x,20,2)
#define  VTSS_M_REW_COMMON_GCPU_CFG_GCPU_KEEP_IFH     VTSS_ENCODE_BITMASK(20,2)
#define  VTSS_X_REW_COMMON_GCPU_CFG_GCPU_KEEP_IFH(x)  VTSS_EXTRACT_BITFIELD(x,20,2)
#define  VTSS_F_REW_COMMON_GCPU_CFG_GCPU_DO_NOT_REW  VTSS_BIT(19)
#define  VTSS_F_REW_COMMON_GCPU_CFG_GCPU_TAG_SEL(x)  VTSS_ENCODE_BITFIELD(x,17,2)
#define  VTSS_M_REW_COMMON_GCPU_CFG_GCPU_TAG_SEL     VTSS_ENCODE_BITMASK(17,2)
#define  VTSS_X_REW_COMMON_GCPU_CFG_GCPU_TAG_SEL(x)  VTSS_EXTRACT_BITFIELD(x,17,2)
#define  VTSS_F_REW_COMMON_GCPU_CFG_GCPU_FWD_MODE  VTSS_BIT(16)
#define  VTSS_F_REW_COMMON_GCPU_CFG_GCPU_UPSPN(x)  VTSS_ENCODE_BITFIELD(x,8,5)
#define  VTSS_M_REW_COMMON_GCPU_CFG_GCPU_UPSPN     VTSS_ENCODE_BITMASK(8,5)
#define  VTSS_X_REW_COMMON_GCPU_CFG_GCPU_UPSPN(x)  VTSS_EXTRACT_BITFIELD(x,8,5)
#define  VTSS_F_REW_COMMON_GCPU_CFG_GCPU_UPSID(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_REW_COMMON_GCPU_CFG_GCPU_UPSID     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_REW_COMMON_GCPU_CFG_GCPU_UPSID(x)  VTSS_EXTRACT_BITFIELD(x,0,5)

#define VTSS_REW_COMMON_VSTAX_PORT_GRP_CFG(ri)  VTSS_IOREG(VTSS_TO_REW,0x107e2 + (ri))
#define  VTSS_F_REW_COMMON_VSTAX_PORT_GRP_CFG_VSTAX_TTL(x)  VTSS_ENCODE_BITFIELD(x,4,5)
#define  VTSS_M_REW_COMMON_VSTAX_PORT_GRP_CFG_VSTAX_TTL     VTSS_ENCODE_BITMASK(4,5)
#define  VTSS_X_REW_COMMON_VSTAX_PORT_GRP_CFG_VSTAX_TTL(x)  VTSS_EXTRACT_BITFIELD(x,4,5)
#define  VTSS_F_REW_COMMON_VSTAX_PORT_GRP_CFG_VSTAX_LRN_ALL_HP_ENA  VTSS_BIT(1)
#define  VTSS_F_REW_COMMON_VSTAX_PORT_GRP_CFG_VSTAX_MODE  VTSS_BIT(0)

#define VTSS_REW_COMMON_GCPU_TAG_CFG(ri)     VTSS_IOREG(VTSS_TO_REW,0x107e4 + (ri))
#define  VTSS_F_REW_COMMON_GCPU_TAG_CFG_TAG_TPID_SEL(x)  VTSS_ENCODE_BITFIELD(x,17,3)
#define  VTSS_M_REW_COMMON_GCPU_TAG_CFG_TAG_TPID_SEL     VTSS_ENCODE_BITMASK(17,3)
#define  VTSS_X_REW_COMMON_GCPU_TAG_CFG_TAG_TPID_SEL(x)  VTSS_EXTRACT_BITFIELD(x,17,3)
#define  VTSS_F_REW_COMMON_GCPU_TAG_CFG_TAG_VID_VAL(x)  VTSS_ENCODE_BITFIELD(x,5,12)
#define  VTSS_M_REW_COMMON_GCPU_TAG_CFG_TAG_VID_VAL     VTSS_ENCODE_BITMASK(5,12)
#define  VTSS_X_REW_COMMON_GCPU_TAG_CFG_TAG_VID_VAL(x)  VTSS_EXTRACT_BITFIELD(x,5,12)
#define  VTSS_F_REW_COMMON_GCPU_TAG_CFG_TAG_DEI_VAL  VTSS_BIT(4)
#define  VTSS_F_REW_COMMON_GCPU_TAG_CFG_TAG_PCP_SEL  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_GCPU_TAG_CFG_TAG_PCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_COMMON_GCPU_TAG_CFG_TAG_PCP_VAL     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_COMMON_GCPU_TAG_CFG_TAG_PCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_COMMON_HIH_DEV10G_CFG(ri)   VTSS_IOREG(VTSS_TO_REW,0x107e6 + (ri))
#define  VTSS_F_REW_COMMON_HIH_DEV10G_CFG_HIH_LOCATION  VTSS_BIT(0)

#define VTSS_REW_COMMON_HIH_DEF_CFG          VTSS_IOREG(VTSS_TO_REW,0x107ea)
#define  VTSS_F_REW_COMMON_HIH_DEF_CFG_HIH_DEF_LPID(x)  VTSS_ENCODE_BITFIELD(x,24,8)
#define  VTSS_M_REW_COMMON_HIH_DEF_CFG_HIH_DEF_LPID     VTSS_ENCODE_BITMASK(24,8)
#define  VTSS_X_REW_COMMON_HIH_DEF_CFG_HIH_DEF_LPID(x)  VTSS_EXTRACT_BITFIELD(x,24,8)
#define  VTSS_F_REW_COMMON_HIH_DEF_CFG_HIH_DEF_CL(x)  VTSS_ENCODE_BITFIELD(x,8,16)
#define  VTSS_M_REW_COMMON_HIH_DEF_CFG_HIH_DEF_CL     VTSS_ENCODE_BITMASK(8,16)
#define  VTSS_X_REW_COMMON_HIH_DEF_CFG_HIH_DEF_CL(x)  VTSS_EXTRACT_BITFIELD(x,8,16)
#define  VTSS_F_REW_COMMON_HIH_DEF_CFG_HIH_DEF_FLAGS(x)  VTSS_ENCODE_BITFIELD(x,4,4)
#define  VTSS_M_REW_COMMON_HIH_DEF_CFG_HIH_DEF_FLAGS     VTSS_ENCODE_BITMASK(4,4)
#define  VTSS_X_REW_COMMON_HIH_DEF_CFG_HIH_DEF_FLAGS(x)  VTSS_EXTRACT_BITFIELD(x,4,4)
#define  VTSS_F_REW_COMMON_HIH_DEF_CFG_HIH_DEF_CKSM(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_REW_COMMON_HIH_DEF_CFG_HIH_DEF_CKSM     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_REW_COMMON_HIH_DEF_CFG_HIH_DEF_CKSM(x)  VTSS_EXTRACT_BITFIELD(x,0,4)

#define VTSS_REW_COMMON_MIP_STICKY_EVENT     VTSS_IOREG(VTSS_TO_REW,0x107eb)
#define  VTSS_F_REW_COMMON_MIP_STICKY_EVENT_MIP_CCM_COPY_STICKY  VTSS_BIT(6)
#define  VTSS_F_REW_COMMON_MIP_STICKY_EVENT_MIP_LBM_REDIR_STICKY  VTSS_BIT(5)
#define  VTSS_F_REW_COMMON_MIP_STICKY_EVENT_MIP_LTM_REDIR_STICKY  VTSS_BIT(4)
#define  VTSS_F_REW_COMMON_MIP_STICKY_EVENT_MIP_RAPS_STICKY  VTSS_BIT(3)
#define  VTSS_F_REW_COMMON_MIP_STICKY_EVENT_MIP_GENERIC_STICKY  VTSS_BIT(2)
#define  VTSS_F_REW_COMMON_MIP_STICKY_EVENT_MIP_LBM_DA_CHK_FAIl_STICKY  VTSS_BIT(1)
#define  VTSS_F_REW_COMMON_MIP_STICKY_EVENT_MIP_MEL_CHK_FAIL_STICKY  VTSS_BIT(0)

#define VTSS_REW_MAP_RES_A_MAP_VAL_A(gi)     VTSS_IOREG_IX(VTSS_TO_REW,0x8000,gi,2,0,0)
#define  VTSS_F_REW_MAP_RES_A_MAP_VAL_A_OAM_COLOR  VTSS_BIT(16)
#define  VTSS_F_REW_MAP_RES_A_MAP_VAL_A_OAM_COSID(x)  VTSS_ENCODE_BITFIELD(x,13,3)
#define  VTSS_M_REW_MAP_RES_A_MAP_VAL_A_OAM_COSID     VTSS_ENCODE_BITMASK(13,3)
#define  VTSS_X_REW_MAP_RES_A_MAP_VAL_A_OAM_COSID(x)  VTSS_EXTRACT_BITFIELD(x,13,3)
#define  VTSS_F_REW_MAP_RES_A_MAP_VAL_A_TC_VAL(x)  VTSS_ENCODE_BITFIELD(x,10,3)
#define  VTSS_M_REW_MAP_RES_A_MAP_VAL_A_TC_VAL     VTSS_ENCODE_BITMASK(10,3)
#define  VTSS_X_REW_MAP_RES_A_MAP_VAL_A_TC_VAL(x)  VTSS_EXTRACT_BITFIELD(x,10,3)
#define  VTSS_F_REW_MAP_RES_A_MAP_VAL_A_DSCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,4,6)
#define  VTSS_M_REW_MAP_RES_A_MAP_VAL_A_DSCP_VAL     VTSS_ENCODE_BITMASK(4,6)
#define  VTSS_X_REW_MAP_RES_A_MAP_VAL_A_DSCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,4,6)
#define  VTSS_F_REW_MAP_RES_A_MAP_VAL_A_DEI_VAL  VTSS_BIT(3)
#define  VTSS_F_REW_MAP_RES_A_MAP_VAL_A_PCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_MAP_RES_A_MAP_VAL_A_PCP_VAL     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_MAP_RES_A_MAP_VAL_A_PCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_MAP_RES_A_MAP_LBL_A(gi)     VTSS_IOREG_IX(VTSS_TO_REW,0x8000,gi,2,0,1)
#define  VTSS_F_REW_MAP_RES_A_MAP_LBL_A_LABEL_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,20)
#define  VTSS_M_REW_MAP_RES_A_MAP_LBL_A_LABEL_VAL     VTSS_ENCODE_BITMASK(0,20)
#define  VTSS_X_REW_MAP_RES_A_MAP_LBL_A_LABEL_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,20)

#define VTSS_REW_MAP_RES_B_MAP_VAL_B(gi)     VTSS_IOREG_IX(VTSS_TO_REW,0xa000,gi,2,0,0)
#define  VTSS_F_REW_MAP_RES_B_MAP_VAL_B_OAM_COLOR  VTSS_BIT(16)
#define  VTSS_F_REW_MAP_RES_B_MAP_VAL_B_OAM_COSID(x)  VTSS_ENCODE_BITFIELD(x,13,3)
#define  VTSS_M_REW_MAP_RES_B_MAP_VAL_B_OAM_COSID     VTSS_ENCODE_BITMASK(13,3)
#define  VTSS_X_REW_MAP_RES_B_MAP_VAL_B_OAM_COSID(x)  VTSS_EXTRACT_BITFIELD(x,13,3)
#define  VTSS_F_REW_MAP_RES_B_MAP_VAL_B_TC_VAL(x)  VTSS_ENCODE_BITFIELD(x,10,3)
#define  VTSS_M_REW_MAP_RES_B_MAP_VAL_B_TC_VAL     VTSS_ENCODE_BITMASK(10,3)
#define  VTSS_X_REW_MAP_RES_B_MAP_VAL_B_TC_VAL(x)  VTSS_EXTRACT_BITFIELD(x,10,3)
#define  VTSS_F_REW_MAP_RES_B_MAP_VAL_B_DSCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,4,6)
#define  VTSS_M_REW_MAP_RES_B_MAP_VAL_B_DSCP_VAL     VTSS_ENCODE_BITMASK(4,6)
#define  VTSS_X_REW_MAP_RES_B_MAP_VAL_B_DSCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,4,6)
#define  VTSS_F_REW_MAP_RES_B_MAP_VAL_B_DEI_VAL  VTSS_BIT(3)
#define  VTSS_F_REW_MAP_RES_B_MAP_VAL_B_PCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_MAP_RES_B_MAP_VAL_B_PCP_VAL     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_MAP_RES_B_MAP_VAL_B_PCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_MAP_RES_B_MAP_LBL_B(gi)     VTSS_IOREG_IX(VTSS_TO_REW,0xa000,gi,2,0,1)
#define  VTSS_F_REW_MAP_RES_B_MAP_LBL_B_LABEL_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,20)
#define  VTSS_M_REW_MAP_RES_B_MAP_LBL_B_LABEL_VAL     VTSS_ENCODE_BITMASK(0,20)
#define  VTSS_X_REW_MAP_RES_B_MAP_LBL_B_LABEL_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,20)

#define VTSS_REW_PORT_PORT_VLAN_CFG(gi)      VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,0)
#define  VTSS_F_REW_PORT_PORT_VLAN_CFG_PORT_PCP(x)  VTSS_ENCODE_BITFIELD(x,13,3)
#define  VTSS_M_REW_PORT_PORT_VLAN_CFG_PORT_PCP     VTSS_ENCODE_BITMASK(13,3)
#define  VTSS_X_REW_PORT_PORT_VLAN_CFG_PORT_PCP(x)  VTSS_EXTRACT_BITFIELD(x,13,3)
#define  VTSS_F_REW_PORT_PORT_VLAN_CFG_PORT_DEI  VTSS_BIT(12)
#define  VTSS_F_REW_PORT_PORT_VLAN_CFG_PORT_VID(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_REW_PORT_PORT_VLAN_CFG_PORT_VID     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_REW_PORT_PORT_VLAN_CFG_PORT_VID(x)  VTSS_EXTRACT_BITFIELD(x,0,12)

#define VTSS_REW_PORT_PCP_MAP_DE0(gi,ri)     VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,ri,1)
#define  VTSS_F_REW_PORT_PCP_MAP_DE0_PCP_DE0(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_PORT_PCP_MAP_DE0_PCP_DE0     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_PORT_PCP_MAP_DE0_PCP_DE0(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_PORT_PCP_MAP_DE1(gi,ri)     VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,ri,9)
#define  VTSS_F_REW_PORT_PCP_MAP_DE1_PCP_DE1(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_PORT_PCP_MAP_DE1_PCP_DE1     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_PORT_PCP_MAP_DE1_PCP_DE1(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_PORT_DEI_MAP_DE0(gi,ri)     VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,ri,17)
#define  VTSS_F_REW_PORT_DEI_MAP_DE0_DEI_DE0  VTSS_BIT(0)

#define VTSS_REW_PORT_DEI_MAP_DE1(gi,ri)     VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,ri,25)
#define  VTSS_F_REW_PORT_DEI_MAP_DE1_DEI_DE1  VTSS_BIT(0)

#define VTSS_REW_PORT_TAG_CTRL(gi)           VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,33)
#define  VTSS_F_REW_PORT_TAG_CTRL_TAG_CFG_OBEY_WAS_TAGGED  VTSS_BIT(12)
#define  VTSS_F_REW_PORT_TAG_CTRL_TAG_CFG(x)  VTSS_ENCODE_BITFIELD(x,10,2)
#define  VTSS_M_REW_PORT_TAG_CTRL_TAG_CFG     VTSS_ENCODE_BITMASK(10,2)
#define  VTSS_X_REW_PORT_TAG_CTRL_TAG_CFG(x)  VTSS_EXTRACT_BITFIELD(x,10,2)
#define  VTSS_F_REW_PORT_TAG_CTRL_TAG_TPID_CFG(x)  VTSS_ENCODE_BITFIELD(x,7,3)
#define  VTSS_M_REW_PORT_TAG_CTRL_TAG_TPID_CFG     VTSS_ENCODE_BITMASK(7,3)
#define  VTSS_X_REW_PORT_TAG_CTRL_TAG_TPID_CFG(x)  VTSS_EXTRACT_BITFIELD(x,7,3)
#define  VTSS_F_REW_PORT_TAG_CTRL_TAG_VID_CFG  VTSS_BIT(6)
#define  VTSS_F_REW_PORT_TAG_CTRL_TAG_PCP_CFG(x)  VTSS_ENCODE_BITFIELD(x,3,3)
#define  VTSS_M_REW_PORT_TAG_CTRL_TAG_PCP_CFG     VTSS_ENCODE_BITMASK(3,3)
#define  VTSS_X_REW_PORT_TAG_CTRL_TAG_PCP_CFG(x)  VTSS_EXTRACT_BITFIELD(x,3,3)
#define  VTSS_F_REW_PORT_TAG_CTRL_TAG_DEI_CFG(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_REW_PORT_TAG_CTRL_TAG_DEI_CFG     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_REW_PORT_TAG_CTRL_TAG_DEI_CFG(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_REW_PORT_DSCP_MAP(gi)           VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,34)
#define  VTSS_F_REW_PORT_DSCP_MAP_DSCP_UPDATE_ENA  VTSS_BIT(1)
#define  VTSS_F_REW_PORT_DSCP_MAP_DSCP_REMAP_ENA  VTSS_BIT(0)

#define VTSS_REW_PORT_PTP_MODE_CFG(gi,ri)    VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,ri,35)
#define  VTSS_F_REW_PORT_PTP_MODE_CFG_PTP_MODE_VAL(x)  VTSS_ENCODE_BITFIELD(x,2,3)
#define  VTSS_M_REW_PORT_PTP_MODE_CFG_PTP_MODE_VAL     VTSS_ENCODE_BITMASK(2,3)
#define  VTSS_X_REW_PORT_PTP_MODE_CFG_PTP_MODE_VAL(x)  VTSS_EXTRACT_BITFIELD(x,2,3)
#define  VTSS_F_REW_PORT_PTP_MODE_CFG_PTP_DOM_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_PORT_PTP_MODE_CFG_PTP_DOM_VAL     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_PORT_PTP_MODE_CFG_PTP_DOM_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_REW_PORT_PTP_MISC_CFG(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,37)
#define  VTSS_F_REW_PORT_PTP_MISC_CFG_PTP_UDP6_CSUM_DIS  VTSS_BIT(1)
#define  VTSS_F_REW_PORT_PTP_MISC_CFG_PTP_UDP4_CSUM_DIS  VTSS_BIT(0)

#define VTSS_REW_PORT_PTP_EDLY_CFG(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,38)

#define VTSS_REW_PORT_PTP_IDLY1_CFG(gi)      VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,39)

#define VTSS_REW_PORT_PTP_IDLY2_CFG(gi)      VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,40)

#define VTSS_REW_PORT_PTP_SMAC_LOW(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,41)

#define VTSS_REW_PORT_PTP_SMAC_HIGH(gi)      VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,42)
#define  VTSS_F_REW_PORT_PTP_SMAC_HIGH_PTP_SMAC_HIGH(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_PORT_PTP_SMAC_HIGH_PTP_SMAC_HIGH     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_PORT_PTP_SMAC_HIGH_PTP_SMAC_HIGH(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_PORT_HIH_CTRL(gi)           VTSS_IOREG_IX(VTSS_TO_REW,0xf000,gi,64,0,43)
#define  VTSS_F_REW_PORT_HIH_CTRL_HIH_LPID_MODE  VTSS_BIT(7)
#define  VTSS_F_REW_PORT_HIH_CTRL_HIH_ENA     VTSS_BIT(6)
#define  VTSS_F_REW_PORT_HIH_CTRL_HIH_FRM_LPID  VTSS_BIT(5)
#define  VTSS_F_REW_PORT_HIH_CTRL_HIH_FRM_CL(x)  VTSS_ENCODE_BITFIELD(x,3,2)
#define  VTSS_M_REW_PORT_HIH_CTRL_HIH_FRM_CL     VTSS_ENCODE_BITMASK(3,2)
#define  VTSS_X_REW_PORT_HIH_CTRL_HIH_FRM_CL(x)  VTSS_EXTRACT_BITFIELD(x,3,2)
#define  VTSS_F_REW_PORT_HIH_CTRL_HIH_FRM_FLAGS(x)  VTSS_ENCODE_BITFIELD(x,1,2)
#define  VTSS_M_REW_PORT_HIH_CTRL_HIH_FRM_FLAGS     VTSS_ENCODE_BITMASK(1,2)
#define  VTSS_X_REW_PORT_HIH_CTRL_HIH_FRM_FLAGS(x)  VTSS_EXTRACT_BITFIELD(x,1,2)
#define  VTSS_F_REW_PORT_HIH_CTRL_HIH_AUTO_CKSM  VTSS_BIT(0)

#define VTSS_REW_MIP_TBL_MIP_CFG(gi)         VTSS_IOREG_IX(VTSS_TO_REW,0xe000,gi,4,0,0)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_MEL_VAL(x)  VTSS_ENCODE_BITFIELD(x,19,3)
#define  VTSS_M_REW_MIP_TBL_MIP_CFG_MEL_VAL     VTSS_ENCODE_BITMASK(19,3)
#define  VTSS_X_REW_MIP_TBL_MIP_CFG_MEL_VAL(x)  VTSS_EXTRACT_BITFIELD(x,19,3)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_CCM_COPY_ENA  VTSS_BIT(18)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_LBM_REDIR_ENA  VTSS_BIT(17)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_LTM_REDIR_ENA  VTSS_BIT(16)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_RAPS_CFG(x)  VTSS_ENCODE_BITFIELD(x,14,2)
#define  VTSS_M_REW_MIP_TBL_MIP_CFG_RAPS_CFG     VTSS_ENCODE_BITMASK(14,2)
#define  VTSS_X_REW_MIP_TBL_MIP_CFG_RAPS_CFG(x)  VTSS_EXTRACT_BITFIELD(x,14,2)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_GENERIC_OPCODE_VAL(x)  VTSS_ENCODE_BITFIELD(x,6,8)
#define  VTSS_M_REW_MIP_TBL_MIP_CFG_GENERIC_OPCODE_VAL     VTSS_ENCODE_BITMASK(6,8)
#define  VTSS_X_REW_MIP_TBL_MIP_CFG_GENERIC_OPCODE_VAL(x)  VTSS_EXTRACT_BITFIELD(x,6,8)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_GENERIC_OPCODE_CFG(x)  VTSS_ENCODE_BITFIELD(x,4,2)
#define  VTSS_M_REW_MIP_TBL_MIP_CFG_GENERIC_OPCODE_CFG     VTSS_ENCODE_BITMASK(4,2)
#define  VTSS_X_REW_MIP_TBL_MIP_CFG_GENERIC_OPCODE_CFG(x)  VTSS_EXTRACT_BITFIELD(x,4,2)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_CPU_MIP_QU(x)  VTSS_ENCODE_BITFIELD(x,1,3)
#define  VTSS_M_REW_MIP_TBL_MIP_CFG_CPU_MIP_QU     VTSS_ENCODE_BITMASK(1,3)
#define  VTSS_X_REW_MIP_TBL_MIP_CFG_CPU_MIP_QU(x)  VTSS_EXTRACT_BITFIELD(x,1,3)
#define  VTSS_F_REW_MIP_TBL_MIP_CFG_PIPELINE_PT  VTSS_BIT(0)

#define VTSS_REW_MIP_TBL_LBM_MAC_HIGH(gi)    VTSS_IOREG_IX(VTSS_TO_REW,0xe000,gi,4,0,1)
#define  VTSS_F_REW_MIP_TBL_LBM_MAC_HIGH_LBM_MAC_HIGH(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_MIP_TBL_LBM_MAC_HIGH_LBM_MAC_HIGH     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_MIP_TBL_LBM_MAC_HIGH_LBM_MAC_HIGH(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_MIP_TBL_LBM_MAC_LOW(gi)     VTSS_IOREG_IX(VTSS_TO_REW,0xe000,gi,4,0,2)

#define VTSS_REW_PTP_CTRL_PTP_TWOSTEP_CTRL   VTSS_IOREG(VTSS_TO_REW,0xfd42)
#define  VTSS_F_REW_PTP_CTRL_PTP_TWOSTEP_CTRL_PTP_NXT  VTSS_BIT(11)
#define  VTSS_F_REW_PTP_CTRL_PTP_TWOSTEP_CTRL_PTP_VLD  VTSS_BIT(10)
#define  VTSS_F_REW_PTP_CTRL_PTP_TWOSTEP_CTRL_STAMP_TX  VTSS_BIT(9)
#define  VTSS_F_REW_PTP_CTRL_PTP_TWOSTEP_CTRL_STAMP_PORT(x)  VTSS_ENCODE_BITFIELD(x,1,8)
#define  VTSS_M_REW_PTP_CTRL_PTP_TWOSTEP_CTRL_STAMP_PORT     VTSS_ENCODE_BITMASK(1,8)
#define  VTSS_X_REW_PTP_CTRL_PTP_TWOSTEP_CTRL_STAMP_PORT(x)  VTSS_EXTRACT_BITFIELD(x,1,8)
#define  VTSS_F_REW_PTP_CTRL_PTP_TWOSTEP_CTRL_PTP_OVFL  VTSS_BIT(0)

#define VTSS_REW_PTP_CTRL_PTP_TWOSTEP_STAMP  VTSS_IOREG(VTSS_TO_REW,0xfd43)

#define VTSS_REW_PTP_CTRL_PTP_CPUVD_MODE_CFG(ri)  VTSS_IOREG(VTSS_TO_REW,0xfd44 + (ri))
#define  VTSS_F_REW_PTP_CTRL_PTP_CPUVD_MODE_CFG_PTP_MODE_VAL(x)  VTSS_ENCODE_BITFIELD(x,2,3)
#define  VTSS_M_REW_PTP_CTRL_PTP_CPUVD_MODE_CFG_PTP_MODE_VAL     VTSS_ENCODE_BITMASK(2,3)
#define  VTSS_X_REW_PTP_CTRL_PTP_CPUVD_MODE_CFG_PTP_MODE_VAL(x)  VTSS_EXTRACT_BITFIELD(x,2,3)
#define  VTSS_F_REW_PTP_CTRL_PTP_CPUVD_MODE_CFG_PTP_DOM_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_PTP_CTRL_PTP_CPUVD_MODE_CFG_PTP_DOM_VAL     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_PTP_CTRL_PTP_CPUVD_MODE_CFG_PTP_DOM_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_REW_PTP_CTRL_PTP_RSRV_NOT_ZERO  VTSS_IOREG(VTSS_TO_REW,0xfd48)

#define VTSS_REW_PTP_CTRL_PTP_RSRV_NOT_ZERO_1  VTSS_IOREG(VTSS_TO_REW,0xfd49)
#define  VTSS_F_REW_PTP_CTRL_PTP_RSRV_NOT_ZERO_1_PTP_RSRV_NOT_ZERO_1(x)  VTSS_ENCODE_BITFIELD(x,0,25)
#define  VTSS_M_REW_PTP_CTRL_PTP_RSRV_NOT_ZERO_1_PTP_RSRV_NOT_ZERO_1     VTSS_ENCODE_BITMASK(0,25)
#define  VTSS_X_REW_PTP_CTRL_PTP_RSRV_NOT_ZERO_1_PTP_RSRV_NOT_ZERO_1(x)  VTSS_EXTRACT_BITFIELD(x,0,25)

#define VTSS_REW_ENCAP_LL_DMAC_MSB(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,0)
#define  VTSS_F_REW_ENCAP_LL_DMAC_MSB_DMAC_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_ENCAP_LL_DMAC_MSB_DMAC_MSB     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_ENCAP_LL_DMAC_MSB_DMAC_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_ENCAP_LL_DMAC_LSB(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,1)

#define VTSS_REW_ENCAP_LL_SMAC_MSB(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,2)
#define  VTSS_F_REW_ENCAP_LL_SMAC_MSB_SMAC_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_ENCAP_LL_SMAC_MSB_SMAC_MSB     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_ENCAP_LL_SMAC_MSB_SMAC_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_ENCAP_LL_SMAC_LSB(gi)       VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,3)

#define VTSS_REW_ENCAP_LL_ETYPE(gi)          VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,4)
#define  VTSS_F_REW_ENCAP_LL_ETYPE_ETYPE(x)   VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_ENCAP_LL_ETYPE_ETYPE      VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_ENCAP_LL_ETYPE_ETYPE(x)   VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_ENCAP_MPLS_LABEL_CFG(gi)    VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,5)
#define  VTSS_F_REW_ENCAP_MPLS_LABEL_CFG_LABEL_CNT(x)  VTSS_ENCODE_BITFIELD(x,2,2)
#define  VTSS_M_REW_ENCAP_MPLS_LABEL_CFG_LABEL_CNT     VTSS_ENCODE_BITMASK(2,2)
#define  VTSS_X_REW_ENCAP_MPLS_LABEL_CFG_LABEL_CNT(x)  VTSS_EXTRACT_BITFIELD(x,2,2)
#define  VTSS_F_REW_ENCAP_MPLS_LABEL_CFG_CW_ENA  VTSS_BIT(1)
#define  VTSS_F_REW_ENCAP_MPLS_LABEL_CFG_INNER_LBL_SEL  VTSS_BIT(0)

#define VTSS_REW_ENCAP_CW_VAL(gi)            VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,6)

#define VTSS_REW_ENCAP_LABEL_VAL(gi,ri)      VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,ri,7)
#define  VTSS_F_REW_ENCAP_LABEL_VAL_LABEL_VAL(x)  VTSS_ENCODE_BITFIELD(x,12,20)
#define  VTSS_M_REW_ENCAP_LABEL_VAL_LABEL_VAL     VTSS_ENCODE_BITMASK(12,20)
#define  VTSS_X_REW_ENCAP_LABEL_VAL_LABEL_VAL(x)  VTSS_EXTRACT_BITFIELD(x,12,20)
#define  VTSS_F_REW_ENCAP_LABEL_VAL_TC_VAL(x)  VTSS_ENCODE_BITFIELD(x,9,3)
#define  VTSS_M_REW_ENCAP_LABEL_VAL_TC_VAL     VTSS_ENCODE_BITMASK(9,3)
#define  VTSS_X_REW_ENCAP_LABEL_VAL_TC_VAL(x)  VTSS_EXTRACT_BITFIELD(x,9,3)
#define  VTSS_F_REW_ENCAP_LABEL_VAL_SBIT_VAL  VTSS_BIT(8)
#define  VTSS_F_REW_ENCAP_LABEL_VAL_TTL_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_REW_ENCAP_LABEL_VAL_TTL_VAL     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_REW_ENCAP_LABEL_VAL_TTL_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_REW_ENCAP_MPLS_REMARK_CFG(gi,ri)  VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,ri,10)
#define  VTSS_F_REW_ENCAP_MPLS_REMARK_CFG_LBL_SEL(x)  VTSS_ENCODE_BITFIELD(x,5,3)
#define  VTSS_M_REW_ENCAP_MPLS_REMARK_CFG_LBL_SEL     VTSS_ENCODE_BITMASK(5,3)
#define  VTSS_X_REW_ENCAP_MPLS_REMARK_CFG_LBL_SEL(x)  VTSS_EXTRACT_BITFIELD(x,5,3)
#define  VTSS_F_REW_ENCAP_MPLS_REMARK_CFG_TC_SEL(x)  VTSS_ENCODE_BITFIELD(x,2,3)
#define  VTSS_M_REW_ENCAP_MPLS_REMARK_CFG_TC_SEL     VTSS_ENCODE_BITMASK(2,3)
#define  VTSS_X_REW_ENCAP_MPLS_REMARK_CFG_TC_SEL(x)  VTSS_EXTRACT_BITFIELD(x,2,3)
#define  VTSS_F_REW_ENCAP_MPLS_REMARK_CFG_SBIT_SEL  VTSS_BIT(1)
#define  VTSS_F_REW_ENCAP_MPLS_REMARK_CFG_TTL_SEL  VTSS_BIT(0)

#define VTSS_REW_ENCAP_LL_TAG_CFG(gi)        VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,0,13)
#define  VTSS_F_REW_ENCAP_LL_TAG_CFG_IFH_ENCAP_MODE  VTSS_BIT(2)
#define  VTSS_F_REW_ENCAP_LL_TAG_CFG_TAG_CFG(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_ENCAP_LL_TAG_CFG_TAG_CFG     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_ENCAP_LL_TAG_CFG_TAG_CFG(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_REW_ENCAP_LL_TAG_VAL(gi,ri)     VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,ri,14)
#define  VTSS_F_REW_ENCAP_LL_TAG_VAL_TAG_VID_VAL(x)  VTSS_ENCODE_BITFIELD(x,4,12)
#define  VTSS_M_REW_ENCAP_LL_TAG_VAL_TAG_VID_VAL     VTSS_ENCODE_BITMASK(4,12)
#define  VTSS_X_REW_ENCAP_LL_TAG_VAL_TAG_VID_VAL(x)  VTSS_EXTRACT_BITFIELD(x,4,12)
#define  VTSS_F_REW_ENCAP_LL_TAG_VAL_TAG_PCP_VAL(x)  VTSS_ENCODE_BITFIELD(x,1,3)
#define  VTSS_M_REW_ENCAP_LL_TAG_VAL_TAG_PCP_VAL     VTSS_ENCODE_BITMASK(1,3)
#define  VTSS_X_REW_ENCAP_LL_TAG_VAL_TAG_PCP_VAL(x)  VTSS_EXTRACT_BITFIELD(x,1,3)
#define  VTSS_F_REW_ENCAP_LL_TAG_VAL_TAG_DEI_VAL  VTSS_BIT(0)
#define  VTSS_F_REW_ENCAP_LL_TAG_VAL_TAG_TPID(x)  VTSS_ENCODE_BITFIELD(x,16,16)
#define  VTSS_M_REW_ENCAP_LL_TAG_VAL_TAG_TPID     VTSS_ENCODE_BITMASK(16,16)
#define  VTSS_X_REW_ENCAP_LL_TAG_VAL_TAG_TPID(x)  VTSS_EXTRACT_BITFIELD(x,16,16)

#define VTSS_REW_ENCAP_LL_TAG_REMARK_CFG(gi,ri)  VTSS_IOREG_IX(VTSS_TO_REW,0x0,gi,32,ri,16)
#define  VTSS_F_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_VID_SEL  VTSS_BIT(7)
#define  VTSS_F_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_PCP_SEL(x)  VTSS_ENCODE_BITFIELD(x,4,3)
#define  VTSS_M_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_PCP_SEL     VTSS_ENCODE_BITMASK(4,3)
#define  VTSS_X_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_PCP_SEL(x)  VTSS_EXTRACT_BITFIELD(x,4,3)
#define  VTSS_F_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_DEI_SEL(x)  VTSS_ENCODE_BITFIELD(x,1,3)
#define  VTSS_M_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_DEI_SEL     VTSS_ENCODE_BITMASK(1,3)
#define  VTSS_X_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_DEI_SEL(x)  VTSS_EXTRACT_BITFIELD(x,1,3)
#define  VTSS_F_REW_ENCAP_LL_TAG_REMARK_CFG_TAG_TPID_SEL  VTSS_BIT(0)

#define VTSS_REW_ENCAP_ID_ENCAP_ID_CFG(gi)   VTSS_IOREG_IX(VTSS_TO_REW,0x10000,gi,1,0,0)
#define  VTSS_F_REW_ENCAP_ID_ENCAP_ID_CFG_ENCAP_PROT_CFG(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_ENCAP_ID_ENCAP_ID_CFG_ENCAP_PROT_CFG     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_ENCAP_ID_ENCAP_ID_CFG_ENCAP_PROT_CFG(x)  VTSS_EXTRACT_BITFIELD(x,0,2)
#define  VTSS_F_REW_ENCAP_ID_ENCAP_ID_CFG_ENCAP_ID_P(x)  VTSS_ENCODE_BITFIELD(x,2,10)
#define  VTSS_M_REW_ENCAP_ID_ENCAP_ID_CFG_ENCAP_ID_P     VTSS_ENCODE_BITMASK(2,10)
#define  VTSS_X_REW_ENCAP_ID_ENCAP_ID_CFG_ENCAP_ID_P(x)  VTSS_EXTRACT_BITFIELD(x,2,10)

#define VTSS_REW_VMID_RLEG_CTRL(gi)          VTSS_IOREG_IX(VTSS_TO_REW,0xfd80,gi,1,0,0)
#define  VTSS_F_REW_VMID_RLEG_CTRL_RLEG_EVID(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_REW_VMID_RLEG_CTRL_RLEG_EVID     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_REW_VMID_RLEG_CTRL_RLEG_EVID(x)  VTSS_EXTRACT_BITFIELD(x,0,12)
#define  VTSS_F_REW_VMID_RLEG_CTRL_RLEG_VSTAX2_WAS_TAGGED  VTSS_BIT(12)

#define VTSS_REW_PTP_SEQ_NO_PTP_SEQ_NO(ri)   VTSS_IOREG(VTSS_TO_REW,0x10800 + (ri))
#define  VTSS_F_REW_PTP_SEQ_NO_PTP_SEQ_NO_PTP_SEQ_NO(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_PTP_SEQ_NO_PTP_SEQ_NO_PTP_SEQ_NO     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_PTP_SEQ_NO_PTP_SEQ_NO_PTP_SEQ_NO(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_VOE_SRV_LM_CNT_SRV_LM_CNT_LSB(gi)  VTSS_IOREG_IX(VTSS_TO_REW,0xc000,gi,1,0,0)

#define VTSS_REW_VOE_PORT_LM_CNT_PORT_LM_CNT_LSB(gi)  VTSS_IOREG_IX(VTSS_TO_REW,0xfe00,gi,1,0,0)

#define VTSS_REW_OAM_PDU_MOD_CONT_TEMP_CNT_REG(gi)  VTSS_IOREG_IX(VTSS_TO_REW,0x10400,gi,8,0,0)
#define  VTSS_F_REW_OAM_PDU_MOD_CONT_TEMP_CNT_REG_TEMP_CNT_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_REW_OAM_PDU_MOD_CONT_TEMP_CNT_REG_TEMP_CNT_VAL     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_REW_OAM_PDU_MOD_CONT_TEMP_CNT_REG_TEMP_CNT_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_REW_OAM_PDU_MOD_CONT_LM_CNT_FRAME(gi)  VTSS_IOREG_IX(VTSS_TO_REW,0x10400,gi,8,0,1)
#define  VTSS_F_REW_OAM_PDU_MOD_CONT_LM_CNT_FRAME_SRV_CNT_FRM  VTSS_BIT(1)
#define  VTSS_F_REW_OAM_PDU_MOD_CONT_LM_CNT_FRAME_PATH_CNT_FRM  VTSS_BIT(0)

#define VTSS_REW_OAM_PDU_MOD_CONT_CCM_LM_INFO_REG(gi)  VTSS_IOREG_IX(VTSS_TO_REW,0x10400,gi,8,0,2)
#define  VTSS_F_REW_OAM_PDU_MOD_CONT_CCM_LM_INFO_REG_CCM_LM_INFO_VLD  VTSS_BIT(11)
#define  VTSS_F_REW_OAM_PDU_MOD_CONT_CCM_LM_INFO_REG_CCM_LM_VOE_IDX(x)  VTSS_ENCODE_BITFIELD(x,0,11)
#define  VTSS_M_REW_OAM_PDU_MOD_CONT_CCM_LM_INFO_REG_CCM_LM_VOE_IDX     VTSS_ENCODE_BITMASK(0,11)
#define  VTSS_X_REW_OAM_PDU_MOD_CONT_CCM_LM_INFO_REG_CCM_LM_VOE_IDX(x)  VTSS_EXTRACT_BITFIELD(x,0,11)

#define VTSS_REW_OAM_PDU_MOD_CONT_CCM_LM_TX_B_REG(gi)  VTSS_IOREG_IX(VTSS_TO_REW,0x10400,gi,8,0,3)

#define VTSS_REW_OAM_PDU_MOD_CONT_CCM_LM_RX_B_REG(gi)  VTSS_IOREG_IX(VTSS_TO_REW,0x10400,gi,8,0,4)

#define VTSS_REW_PDU_MOD_CFG_DM_PTP_DOMAIN_CFG(ri)  VTSS_IOREG(VTSS_TO_REW,0xfd4a + (ri))
#define  VTSS_F_REW_PDU_MOD_CFG_DM_PTP_DOMAIN_CFG_PTP_DOMAIN(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_REW_PDU_MOD_CFG_DM_PTP_DOMAIN_CFG_PTP_DOMAIN     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_REW_PDU_MOD_CFG_DM_PTP_DOMAIN_CFG_PTP_DOMAIN(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_REW_RAM_CTRL_RAM_INIT           VTSS_IOREG(VTSS_TO_REW,0xfd7f)
#define  VTSS_F_REW_RAM_CTRL_RAM_INIT_RAM_INIT  VTSS_BIT(1)
#define  VTSS_F_REW_RAM_CTRL_RAM_INIT_RAM_ENA  VTSS_BIT(0)

#define VTSS_REW_COREMEM_CM_ADDR             VTSS_IOREG(VTSS_TO_REW,0xfd40)
#define  VTSS_F_REW_COREMEM_CM_ADDR_CM_ID(x)  VTSS_ENCODE_BITFIELD(x,22,8)
#define  VTSS_M_REW_COREMEM_CM_ADDR_CM_ID     VTSS_ENCODE_BITMASK(22,8)
#define  VTSS_X_REW_COREMEM_CM_ADDR_CM_ID(x)  VTSS_EXTRACT_BITFIELD(x,22,8)
#define  VTSS_F_REW_COREMEM_CM_ADDR_CM_ADDR(x)  VTSS_ENCODE_BITFIELD(x,0,22)
#define  VTSS_M_REW_COREMEM_CM_ADDR_CM_ADDR     VTSS_ENCODE_BITMASK(0,22)
#define  VTSS_X_REW_COREMEM_CM_ADDR_CM_ADDR(x)  VTSS_EXTRACT_BITFIELD(x,0,22)

#define VTSS_REW_COREMEM_CM_DATA             VTSS_IOREG(VTSS_TO_REW,0xfd41)


#endif /* _VTSS_JAGUAR2_REGS_REW_H_ */