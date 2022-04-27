#ifndef _VTSS_JAGUAR2_REGS_TWI_H_
#define _VTSS_JAGUAR2_REGS_TWI_H_

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

#define VTSS_TWI_TWI_CFG(target)             VTSS_IOREG(target,0x0)
#define  VTSS_F_TWI_TWI_CFG_SLAVE_DIS         VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_CFG_RESTART_ENA       VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_CFG_MASTER_10BITADDR  VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_CFG_SLAVE_10BITADDR   VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_CFG_SPEED(x)          VTSS_ENCODE_BITFIELD(x,1,2)
#define  VTSS_M_TWI_TWI_CFG_SPEED             VTSS_ENCODE_BITMASK(1,2)
#define  VTSS_X_TWI_TWI_CFG_SPEED(x)          VTSS_EXTRACT_BITFIELD(x,1,2)
#define  VTSS_F_TWI_TWI_CFG_MASTER_ENA        VTSS_BIT(0)

#define VTSS_TWI_TWI_TAR(target)             VTSS_IOREG(target,0x1)
#define  VTSS_F_TWI_TWI_TAR_GC_OR_START_ENA   VTSS_BIT(11)
#define  VTSS_F_TWI_TWI_TAR_GC_OR_START       VTSS_BIT(10)
#define  VTSS_F_TWI_TWI_TAR_TAR(x)            VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_TWI_TWI_TAR_TAR               VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_TWI_TWI_TAR_TAR(x)            VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_TWI_TWI_SAR(target)             VTSS_IOREG(target,0x2)
#define  VTSS_F_TWI_TWI_SAR_SAR(x)            VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_TWI_TWI_SAR_SAR               VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_TWI_TWI_SAR_SAR(x)            VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_TWI_TWI_RESERVED1(target)       VTSS_IOREG(target,0x3)

#define VTSS_TWI_TWI_DATA_CMD(target)        VTSS_IOREG(target,0x4)
#define  VTSS_F_TWI_TWI_DATA_CMD_CMD          VTSS_BIT(8)
#define  VTSS_F_TWI_TWI_DATA_CMD_DATA(x)      VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_TWI_TWI_DATA_CMD_DATA         VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_TWI_TWI_DATA_CMD_DATA(x)      VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_TWI_TWI_SS_SCL_HCNT(target)     VTSS_IOREG(target,0x5)
#define  VTSS_F_TWI_TWI_SS_SCL_HCNT_SS_SCL_HCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_SS_SCL_HCNT_SS_SCL_HCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_SS_SCL_HCNT_SS_SCL_HCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_SS_SCL_LCNT(target)     VTSS_IOREG(target,0x6)
#define  VTSS_F_TWI_TWI_SS_SCL_LCNT_SS_SCL_LCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_SS_SCL_LCNT_SS_SCL_LCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_SS_SCL_LCNT_SS_SCL_LCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_FS_SCL_HCNT(target)     VTSS_IOREG(target,0x7)
#define  VTSS_F_TWI_TWI_FS_SCL_HCNT_FS_SCL_HCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_FS_SCL_HCNT_FS_SCL_HCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_FS_SCL_HCNT_FS_SCL_HCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_FS_SCL_LCNT(target)     VTSS_IOREG(target,0x8)
#define  VTSS_F_TWI_TWI_FS_SCL_LCNT_FS_SCL_LCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_FS_SCL_LCNT_FS_SCL_LCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_FS_SCL_LCNT_FS_SCL_LCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_RESERVED2(target,ri)    VTSS_IOREG(target,0x9 + (ri))

#define VTSS_TWI_TWI_INTR_STAT(target)       VTSS_IOREG(target,0xb)
#define  VTSS_F_TWI_TWI_INTR_STAT_GEN_CALL    VTSS_BIT(11)
#define  VTSS_F_TWI_TWI_INTR_STAT_START_DET   VTSS_BIT(10)
#define  VTSS_F_TWI_TWI_INTR_STAT_STOP_DET    VTSS_BIT(9)
#define  VTSS_F_TWI_TWI_INTR_STAT_ACTIVITY    VTSS_BIT(8)
#define  VTSS_F_TWI_TWI_INTR_STAT_RX_DONE     VTSS_BIT(7)
#define  VTSS_F_TWI_TWI_INTR_STAT_TX_ABRT     VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_INTR_STAT_RD_REQ      VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_INTR_STAT_TX_EMPTY    VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_INTR_STAT_TX_OVER     VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_INTR_STAT_RX_FULL     VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_INTR_STAT_RX_OVER     VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_INTR_STAT_RX_UNDER    VTSS_BIT(0)

#define VTSS_TWI_TWI_INTR_MASK(target)       VTSS_IOREG(target,0xc)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_GEN_CALL  VTSS_BIT(11)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_START_DET  VTSS_BIT(10)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_STOP_DET  VTSS_BIT(9)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_ACTIVITY  VTSS_BIT(8)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_RX_DONE   VTSS_BIT(7)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_TX_ABRT   VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_RD_REQ    VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_TX_EMPTY  VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_TX_OVER   VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_RX_FULL   VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_RX_OVER   VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_INTR_MASK_M_RX_UNDER  VTSS_BIT(0)

#define VTSS_TWI_TWI_RAW_INTR_STAT(target)   VTSS_IOREG(target,0xd)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_GEN_CALL  VTSS_BIT(11)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_START_DET  VTSS_BIT(10)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_STOP_DET  VTSS_BIT(9)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_ACTIVITY  VTSS_BIT(8)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_RX_DONE  VTSS_BIT(7)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_TX_ABRT  VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_RD_REQ  VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_TX_EMPTY  VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_TX_OVER  VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_RX_FULL  VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_RX_OVER  VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_RAW_INTR_STAT_R_RX_UNDER  VTSS_BIT(0)

#define VTSS_TWI_TWI_RX_TL(target)           VTSS_IOREG(target,0xe)
#define  VTSS_F_TWI_TWI_RX_TL_RX_TL(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_RX_TL_RX_TL           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_RX_TL_RX_TL(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_TX_TL(target)           VTSS_IOREG(target,0xf)
#define  VTSS_F_TWI_TWI_TX_TL_TX_TL(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_TX_TL_TX_TL           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_TX_TL_TX_TL(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_CLR_INTR(target)        VTSS_IOREG(target,0x10)
#define  VTSS_F_TWI_TWI_CLR_INTR_CLR_INTR     VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RX_UNDER(target)    VTSS_IOREG(target,0x11)
#define  VTSS_F_TWI_TWI_CLR_RX_UNDER_CLR_RX_UNDER  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RX_OVER(target)     VTSS_IOREG(target,0x12)
#define  VTSS_F_TWI_TWI_CLR_RX_OVER_CLR_RX_OVER  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_TX_OVER(target)     VTSS_IOREG(target,0x13)
#define  VTSS_F_TWI_TWI_CLR_TX_OVER_CLR_TX_OVER  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RD_REQ(target)      VTSS_IOREG(target,0x14)
#define  VTSS_F_TWI_TWI_CLR_RD_REQ_CLR_RD_REQ  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_TX_ABRT(target)     VTSS_IOREG(target,0x15)
#define  VTSS_F_TWI_TWI_CLR_TX_ABRT_CLR_TX_ABRT  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RX_DONE(target)     VTSS_IOREG(target,0x16)
#define  VTSS_F_TWI_TWI_CLR_RX_DONE_CLR_RX_DONE  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_ACTIVITY(target)    VTSS_IOREG(target,0x17)
#define  VTSS_F_TWI_TWI_CLR_ACTIVITY_CLR_ACTIVITY  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_STOP_DET(target)    VTSS_IOREG(target,0x18)
#define  VTSS_F_TWI_TWI_CLR_STOP_DET_CLR_STOP_DET  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_START_DET(target)   VTSS_IOREG(target,0x19)
#define  VTSS_F_TWI_TWI_CLR_START_DET_CLR_START_DET  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_GEN_CALL(target)    VTSS_IOREG(target,0x1a)
#define  VTSS_F_TWI_TWI_CLR_GEN_CALL_CLR_GEN_CALL  VTSS_BIT(0)

#define VTSS_TWI_TWI_CTRL(target)            VTSS_IOREG(target,0x1b)
#define  VTSS_F_TWI_TWI_CTRL_ENABLE           VTSS_BIT(0)

#define VTSS_TWI_TWI_STAT(target)            VTSS_IOREG(target,0x1c)
#define  VTSS_F_TWI_TWI_STAT_SLV_ACTIVITY     VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_STAT_MST_ACTIVITY     VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_STAT_RFF              VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_STAT_RFNE             VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_STAT_TFE              VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_STAT_TFNF             VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_STAT_BUS_ACTIVITY     VTSS_BIT(0)

#define VTSS_TWI_TWI_TXFLR(target)           VTSS_IOREG(target,0x1d)
#define  VTSS_F_TWI_TWI_TXFLR_TXFLR(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_TXFLR_TXFLR           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_TXFLR_TXFLR(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_RXFLR(target)           VTSS_IOREG(target,0x1e)
#define  VTSS_F_TWI_TWI_RXFLR_RXFLR(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_RXFLR_RXFLR           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_RXFLR_RXFLR(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_RESERVED3(target)       VTSS_IOREG(target,0x1f)

#define VTSS_TWI_TWI_TX_ABRT_SOURCE(target)  VTSS_IOREG(target,0x20)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SLVRD_INTX  VTSS_BIT(15)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST  VTSS_BIT(14)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO  VTSS_BIT(13)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ARB_LOST  VTSS_BIT(12)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_MASTER_DIS  VTSS_BIT(11)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT  VTSS_BIT(10)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT  VTSS_BIT(9)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_HS_NORSTRT  VTSS_BIT(8)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET  VTSS_BIT(7)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_HS_ACKDET  VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_GCALL_READ  VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_GCALL_NOACK  VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK  VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK  VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK  VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK  VTSS_BIT(0)

#define VTSS_TWI_TWI_RESERVED8(target)       VTSS_IOREG(target,0x21)

#define VTSS_TWI_TWI_RESERVED4(target)       VTSS_IOREG(target,0x22)

#define VTSS_TWI_TWI_RESERVED5(target)       VTSS_IOREG(target,0x23)

#define VTSS_TWI_TWI_RESERVED6(target)       VTSS_IOREG(target,0x24)

#define VTSS_TWI_TWI_SDA_SETUP(target)       VTSS_IOREG(target,0x25)
#define  VTSS_F_TWI_TWI_SDA_SETUP_SDA_SETUP(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_TWI_TWI_SDA_SETUP_SDA_SETUP     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_TWI_TWI_SDA_SETUP_SDA_SETUP(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_TWI_TWI_ACK_GEN_CALL(target)    VTSS_IOREG(target,0x26)
#define  VTSS_F_TWI_TWI_ACK_GEN_CALL_ACK_GEN_CALL  VTSS_BIT(0)

#define VTSS_TWI_TWI_ENABLE_STATUS(target)   VTSS_IOREG(target,0x27)
#define  VTSS_F_TWI_TWI_ENABLE_STATUS_SLV_FIFO_FILLED_AND_FLUSHED  VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_ENABLE_STATUS_SLV_RX_ABORTED  VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_ENABLE_STATUS_BUSY    VTSS_BIT(0)

#define VTSS_TWI_TWI_RESERVED7(target,ri)    VTSS_IOREG(target,0x28 + (ri))

#define VTSS_TWI_TWI_COMP_PARAM_1(target)    VTSS_IOREG(target,0x3d)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_TX_BUFFER_DEPTH(x)  VTSS_ENCODE_BITFIELD(x,16,8)
#define  VTSS_M_TWI_TWI_COMP_PARAM_1_TX_BUFFER_DEPTH     VTSS_ENCODE_BITMASK(16,8)
#define  VTSS_X_TWI_TWI_COMP_PARAM_1_TX_BUFFER_DEPTH(x)  VTSS_EXTRACT_BITFIELD(x,16,8)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_RX_BUFFER_DEPTH(x)  VTSS_ENCODE_BITFIELD(x,8,8)
#define  VTSS_M_TWI_TWI_COMP_PARAM_1_RX_BUFFER_DEPTH     VTSS_ENCODE_BITMASK(8,8)
#define  VTSS_X_TWI_TWI_COMP_PARAM_1_RX_BUFFER_DEPTH(x)  VTSS_EXTRACT_BITFIELD(x,8,8)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_ADD_ENCODED_PARAMS  VTSS_BIT(7)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_HAS_DMA  VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_INTR_IO  VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_HC_COUNT_VALUES  VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_MAX_SPEED_MODE(x)  VTSS_ENCODE_BITFIELD(x,2,2)
#define  VTSS_M_TWI_TWI_COMP_PARAM_1_MAX_SPEED_MODE     VTSS_ENCODE_BITMASK(2,2)
#define  VTSS_X_TWI_TWI_COMP_PARAM_1_MAX_SPEED_MODE(x)  VTSS_EXTRACT_BITFIELD(x,2,2)
#define  VTSS_F_TWI_TWI_COMP_PARAM_1_APB_DATA_WIDTH(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_TWI_TWI_COMP_PARAM_1_APB_DATA_WIDTH     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_TWI_TWI_COMP_PARAM_1_APB_DATA_WIDTH(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_TWI_TWI_COMP_VERSION(target)    VTSS_IOREG(target,0x3e)

#define VTSS_TWI_TWI_COMP_TYPE(target)       VTSS_IOREG(target,0x3f)


#endif /* _VTSS_JAGUAR2_REGS_TWI_H_ */