#ifndef _VTSS_JAGUAR2_REGS_QFWD_H_
#define _VTSS_JAGUAR2_REGS_QFWD_H_

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

#define VTSS_QFWD_SYSTEM_SWITCH_PORT_MODE(ri)  VTSS_IOREG(VTSS_TO_QFWD,0x10e4 + (ri))
#define  VTSS_F_QFWD_SYSTEM_SWITCH_PORT_MODE_PORT_ENA  VTSS_BIT(10)
#define  VTSS_F_QFWD_SYSTEM_SWITCH_PORT_MODE_FWD_SPEED(x)  VTSS_ENCODE_BITFIELD(x,8,2)
#define  VTSS_M_QFWD_SYSTEM_SWITCH_PORT_MODE_FWD_SPEED     VTSS_ENCODE_BITMASK(8,2)
#define  VTSS_X_QFWD_SYSTEM_SWITCH_PORT_MODE_FWD_SPEED(x)  VTSS_EXTRACT_BITFIELD(x,8,2)
#define  VTSS_F_QFWD_SYSTEM_SWITCH_PORT_MODE_YEL_RSRVD(x)  VTSS_ENCODE_BITFIELD(x,4,4)
#define  VTSS_M_QFWD_SYSTEM_SWITCH_PORT_MODE_YEL_RSRVD     VTSS_ENCODE_BITMASK(4,4)
#define  VTSS_X_QFWD_SYSTEM_SWITCH_PORT_MODE_YEL_RSRVD(x)  VTSS_EXTRACT_BITFIELD(x,4,4)
#define  VTSS_F_QFWD_SYSTEM_SWITCH_PORT_MODE_INGRESS_DROP_MODE  VTSS_BIT(3)
#define  VTSS_F_QFWD_SYSTEM_SWITCH_PORT_MODE_IGR_NO_SHARING  VTSS_BIT(2)
#define  VTSS_F_QFWD_SYSTEM_SWITCH_PORT_MODE_EGR_NO_SHARING  VTSS_BIT(1)
#define  VTSS_F_QFWD_SYSTEM_SWITCH_PORT_MODE_EGRESS_DROP_MODE  VTSS_BIT(0)

#define VTSS_QFWD_SYSTEM_STAT_CNT_CFG        VTSS_IOREG(VTSS_TO_QFWD,0x111d)
#define  VTSS_F_QFWD_SYSTEM_STAT_CNT_CFG_DROP_COUNT_EGRESS  VTSS_BIT(0)

#define VTSS_QFWD_SYSTEM_FWD_IDLE_CNT        VTSS_IOREG(VTSS_TO_QFWD,0x111e)
#define  VTSS_F_QFWD_SYSTEM_FWD_IDLE_CNT_FWD_IDLE_CNT(x)  VTSS_ENCODE_BITFIELD(x,0,13)
#define  VTSS_M_QFWD_SYSTEM_FWD_IDLE_CNT_FWD_IDLE_CNT     VTSS_ENCODE_BITMASK(0,13)
#define  VTSS_X_QFWD_SYSTEM_FWD_IDLE_CNT_FWD_IDLE_CNT(x)  VTSS_EXTRACT_BITFIELD(x,0,13)

#define VTSS_QFWD_SYSTEM_FRAME_COPY_CFG(ri)  VTSS_IOREG(VTSS_TO_QFWD,0x111f + (ri))
#define  VTSS_F_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_PORT_VAL(x)  VTSS_ENCODE_BITFIELD(x,6,6)
#define  VTSS_M_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_PORT_VAL     VTSS_ENCODE_BITMASK(6,6)
#define  VTSS_X_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_PORT_VAL(x)  VTSS_EXTRACT_BITFIELD(x,6,6)
#define  VTSS_F_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_QOS_VAL(x)  VTSS_ENCODE_BITFIELD(x,3,3)
#define  VTSS_M_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_QOS_VAL     VTSS_ENCODE_BITMASK(3,3)
#define  VTSS_X_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_QOS_VAL(x)  VTSS_EXTRACT_BITFIELD(x,3,3)
#define  VTSS_F_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_QOS_ENA  VTSS_BIT(2)
#define  VTSS_F_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_SP_ENA(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_SP_ENA     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_QFWD_SYSTEM_FRAME_COPY_CFG_FRMC_SP_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_QFWD_SYSTEM_FRAME_COPY_LRNA_CFG  VTSS_IOREG(VTSS_TO_QFWD,0x112b)
#define  VTSS_F_QFWD_SYSTEM_FRAME_COPY_LRNA_CFG_FRMC_PORT_LRNA_VAL(x)  VTSS_ENCODE_BITFIELD(x,0,6)
#define  VTSS_M_QFWD_SYSTEM_FRAME_COPY_LRNA_CFG_FRMC_PORT_LRNA_VAL     VTSS_ENCODE_BITMASK(0,6)
#define  VTSS_X_QFWD_SYSTEM_FRAME_COPY_LRNA_CFG_FRMC_PORT_LRNA_VAL(x)  VTSS_EXTRACT_BITFIELD(x,0,6)

#define VTSS_QFWD_SYSTEM_FWD_DROP_EVENTS(ri)  VTSS_IOREG(VTSS_TO_QFWD,0x112c + (ri))
#define  VTSS_F_QFWD_SYSTEM_FWD_DROP_EVENTS_FWD_DROP_NORM_STICKY  VTSS_BIT(4)
#define  VTSS_F_QFWD_SYSTEM_FWD_DROP_EVENTS_FWD_DROP_CPU_STICKY  VTSS_BIT(3)
#define  VTSS_F_QFWD_SYSTEM_FWD_DROP_EVENTS_FWD_DROP_LEARN_STICKY  VTSS_BIT(2)
#define  VTSS_F_QFWD_SYSTEM_FWD_DROP_EVENTS_FWD_DROP_MIRR_STICKY  VTSS_BIT(1)
#define  VTSS_F_QFWD_SYSTEM_FWD_DROP_EVENTS_FWD_DROP_QMAP_STICKY  VTSS_BIT(0)

#define VTSS_QFWD_SYSTEM_FWD_CPU_DROP_CNT    VTSS_IOREG(VTSS_TO_QFWD,0x1165)

#define VTSS_QFWD_SYSTEM_FWD_PRESS_DROP_CNT  VTSS_IOREG(VTSS_TO_QFWD,0x1166)

#define VTSS_QFWD_SYSTEM_FWD_STAT_CNT(ri)    VTSS_IOREG(VTSS_TO_QFWD,0x1167 + (ri))

#define VTSS_QFWD_SYSTEM_MIRROR_CFG          VTSS_IOREG(VTSS_TO_QFWD,0x116a)
#define  VTSS_F_QFWD_SYSTEM_MIRROR_CFG_MIRROR_DISCARDS(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_QFWD_SYSTEM_MIRROR_CFG_MIRROR_DISCARDS     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_QFWD_SYSTEM_MIRROR_CFG_MIRROR_DISCARDS(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_QFWD_SYSTEM_CPUQ_DISCARD        VTSS_IOREG(VTSS_TO_QFWD,0x116b)
#define  VTSS_F_QFWD_SYSTEM_CPUQ_DISCARD_CPUQ_DISCARD(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_QFWD_SYSTEM_CPUQ_DISCARD_CPUQ_DISCARD     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_QFWD_SYSTEM_CPUQ_DISCARD_CPUQ_DISCARD(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_QFWD_QMAP_QMAP_CFG(gi)          VTSS_IOREG_IX(VTSS_TO_QFWD,0x1000,gi,4,0,0)
#define  VTSS_F_QFWD_QMAP_QMAP_CFG_QMAP_CH_SEL(x)  VTSS_ENCODE_BITFIELD(x,8,3)
#define  VTSS_M_QFWD_QMAP_QMAP_CFG_QMAP_CH_SEL     VTSS_ENCODE_BITMASK(8,3)
#define  VTSS_X_QFWD_QMAP_QMAP_CFG_QMAP_CH_SEL(x)  VTSS_EXTRACT_BITFIELD(x,8,3)
#define  VTSS_F_QFWD_QMAP_QMAP_CFG_QMAP_QOS_SEL(x)  VTSS_ENCODE_BITFIELD(x,5,3)
#define  VTSS_M_QFWD_QMAP_QMAP_CFG_QMAP_QOS_SEL     VTSS_ENCODE_BITMASK(5,3)
#define  VTSS_X_QFWD_QMAP_QMAP_CFG_QMAP_QOS_SEL(x)  VTSS_EXTRACT_BITFIELD(x,5,3)
#define  VTSS_F_QFWD_QMAP_QMAP_CFG_QMAP_SFT_VAL  VTSS_BIT(4)
#define  VTSS_F_QFWD_QMAP_QMAP_CFG_QMAP_SFT_CNT(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_QFWD_QMAP_QMAP_CFG_QMAP_SFT_CNT     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_QFWD_QMAP_QMAP_CFG_QMAP_SFT_CNT(x)  VTSS_EXTRACT_BITFIELD(x,0,4)

#define VTSS_QFWD_QMAP_QMAP_RANGES(gi)       VTSS_IOREG_IX(VTSS_TO_QFWD,0x1000,gi,4,0,1)
#define  VTSS_F_QFWD_QMAP_QMAP_RANGES_QMAP_CH_BASE(x)  VTSS_ENCODE_BITFIELD(x,15,12)
#define  VTSS_M_QFWD_QMAP_QMAP_RANGES_QMAP_CH_BASE     VTSS_ENCODE_BITMASK(15,12)
#define  VTSS_X_QFWD_QMAP_QMAP_RANGES_QMAP_CH_BASE(x)  VTSS_EXTRACT_BITFIELD(x,15,12)
#define  VTSS_F_QFWD_QMAP_QMAP_RANGES_QMAP_QUEUE_MAX(x)  VTSS_ENCODE_BITFIELD(x,0,15)
#define  VTSS_M_QFWD_QMAP_QMAP_RANGES_QMAP_QUEUE_MAX     VTSS_ENCODE_BITMASK(0,15)
#define  VTSS_X_QFWD_QMAP_QMAP_RANGES_QMAP_QUEUE_MAX(x)  VTSS_EXTRACT_BITFIELD(x,0,15)

#define VTSS_QFWD_QMAP_QMAP_SE_CFG(gi)       VTSS_IOREG_IX(VTSS_TO_QFWD,0x1000,gi,4,0,2)
#define  VTSS_F_QFWD_QMAP_QMAP_SE_CFG_QMAP_SE_BASE(x)  VTSS_ENCODE_BITFIELD(x,1,12)
#define  VTSS_M_QFWD_QMAP_QMAP_SE_CFG_QMAP_SE_BASE     VTSS_ENCODE_BITMASK(1,12)
#define  VTSS_X_QFWD_QMAP_QMAP_SE_CFG_QMAP_SE_BASE(x)  VTSS_EXTRACT_BITFIELD(x,1,12)
#define  VTSS_F_QFWD_QMAP_QMAP_SE_CFG_QMAP_SE_WIDTH  VTSS_BIT(0)

#define VTSS_QFWD_QMAP_TBL_QMAP_TBL_CFG(gi)  VTSS_IOREG_IX(VTSS_TO_QFWD,0x0,gi,1,0,0)
#define  VTSS_F_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_CH_0_VAL(x)  VTSS_ENCODE_BITFIELD(x,14,10)
#define  VTSS_M_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_CH_0_VAL     VTSS_ENCODE_BITMASK(14,10)
#define  VTSS_X_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_CH_0_VAL(x)  VTSS_EXTRACT_BITFIELD(x,14,10)
#define  VTSS_F_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_CH_1_VAL(x)  VTSS_ENCODE_BITFIELD(x,4,10)
#define  VTSS_M_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_CH_1_VAL     VTSS_ENCODE_BITMASK(4,10)
#define  VTSS_X_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_CH_1_VAL(x)  VTSS_EXTRACT_BITFIELD(x,4,10)
#define  VTSS_F_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_USE_CID_0  VTSS_BIT(3)
#define  VTSS_F_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_USE_CID_1  VTSS_BIT(2)
#define  VTSS_F_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_USE_CID_2  VTSS_BIT(1)
#define  VTSS_F_QFWD_QMAP_TBL_QMAP_TBL_CFG_QMAP_USE_CID_3  VTSS_BIT(0)


#endif /* _VTSS_JAGUAR2_REGS_QFWD_H_ */
