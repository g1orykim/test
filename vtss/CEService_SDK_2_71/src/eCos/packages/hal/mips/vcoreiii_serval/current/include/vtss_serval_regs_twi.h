#ifndef _VTSS_SERVAL_REGS_TWI_H_
#define _VTSS_SERVAL_REGS_TWI_H_

/*
 *
 * VCore-III Register Definitions
 *
 #####ECOSGPLCOPYRIGHTBEGIN#####
 -------------------------------------------
 This file is part of eCos, the Embedded Configurable Operating System.
 Copyright (C) 1998-2012 Free Software Foundation, Inc.

 eCos is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free
 Software Foundation; either version 2 or (at your option) any later
 version.

 eCos is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.

 You should have received a copy of the GNU General Public License
 along with eCos; if not, write to the Free Software Foundation, Inc.,
 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

 As a special exception, if other files instantiate templates or use
 macros or inline functions from this file, or you compile this file
 and link it with other works to produce a work based on this file,
 this file does not by itself cause the resulting work to be covered by
 the GNU General Public License. However the source code for this file
 must still be made available in accordance with section (3) of the GNU
 General Public License v2.

 This exception does not invalidate any other reasons why a work based
 on this file might be covered by the GNU General Public License.
 -------------------------------------------
 #####ECOSGPLCOPYRIGHTEND#####
 */

#include "vtss_serval_regs_common.h"

#define VTSS_TWI_TWI_CFG                     VTSS_IOREG(VTSS_TO_TWI,0x0)
#define  VTSS_F_TWI_TWI_CFG_SLAVE_DIS         VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_CFG_RESTART_ENA       VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_CFG_MASTER_10BITADDR  VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_CFG_SLAVE_10BITADDR   VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_CFG_SPEED(x)          VTSS_ENCODE_BITFIELD(x,1,2)
#define  VTSS_M_TWI_TWI_CFG_SPEED             VTSS_ENCODE_BITMASK(1,2)
#define  VTSS_X_TWI_TWI_CFG_SPEED(x)          VTSS_EXTRACT_BITFIELD(x,1,2)
#define  VTSS_F_TWI_TWI_CFG_MASTER_ENA        VTSS_BIT(0)

#define VTSS_TWI_TWI_TAR                     VTSS_IOREG(VTSS_TO_TWI,0x1)
#define  VTSS_F_TWI_TWI_TAR_GC_OR_START_ENA   VTSS_BIT(11)
#define  VTSS_F_TWI_TWI_TAR_GC_OR_START       VTSS_BIT(10)
#define  VTSS_F_TWI_TWI_TAR_TAR(x)            VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_TWI_TWI_TAR_TAR               VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_TWI_TWI_TAR_TAR(x)            VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_TWI_TWI_SAR                     VTSS_IOREG(VTSS_TO_TWI,0x2)
#define  VTSS_F_TWI_TWI_SAR_SAR(x)            VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_TWI_TWI_SAR_SAR               VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_TWI_TWI_SAR_SAR(x)            VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_TWI_TWI_DATA_CMD                VTSS_IOREG(VTSS_TO_TWI,0x4)
#define  VTSS_F_TWI_TWI_DATA_CMD_CMD          VTSS_BIT(8)
#define  VTSS_F_TWI_TWI_DATA_CMD_DATA(x)      VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_TWI_TWI_DATA_CMD_DATA         VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_TWI_TWI_DATA_CMD_DATA(x)      VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_TWI_TWI_SS_SCL_HCNT             VTSS_IOREG(VTSS_TO_TWI,0x5)
#define  VTSS_F_TWI_TWI_SS_SCL_HCNT_SS_SCL_HCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_SS_SCL_HCNT_SS_SCL_HCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_SS_SCL_HCNT_SS_SCL_HCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_SS_SCL_LCNT             VTSS_IOREG(VTSS_TO_TWI,0x6)
#define  VTSS_F_TWI_TWI_SS_SCL_LCNT_SS_SCL_LCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_SS_SCL_LCNT_SS_SCL_LCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_SS_SCL_LCNT_SS_SCL_LCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_FS_SCL_HCNT             VTSS_IOREG(VTSS_TO_TWI,0x7)
#define  VTSS_F_TWI_TWI_FS_SCL_HCNT_FS_SCL_HCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_FS_SCL_HCNT_FS_SCL_HCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_FS_SCL_HCNT_FS_SCL_HCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_FS_SCL_LCNT             VTSS_IOREG(VTSS_TO_TWI,0x8)
#define  VTSS_F_TWI_TWI_FS_SCL_LCNT_FS_SCL_LCNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_TWI_TWI_FS_SCL_LCNT_FS_SCL_LCNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_TWI_TWI_FS_SCL_LCNT_FS_SCL_LCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_TWI_TWI_INTR_STAT               VTSS_IOREG(VTSS_TO_TWI,0xb)
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

#define VTSS_TWI_TWI_INTR_MASK               VTSS_IOREG(VTSS_TO_TWI,0xc)
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

#define VTSS_TWI_TWI_RAW_INTR_STAT           VTSS_IOREG(VTSS_TO_TWI,0xd)
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

#define VTSS_TWI_TWI_RX_TL                   VTSS_IOREG(VTSS_TO_TWI,0xe)
#define  VTSS_F_TWI_TWI_RX_TL_RX_TL(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_RX_TL_RX_TL           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_RX_TL_RX_TL(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_TX_TL                   VTSS_IOREG(VTSS_TO_TWI,0xf)
#define  VTSS_F_TWI_TWI_TX_TL_TX_TL(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_TX_TL_TX_TL           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_TX_TL_TX_TL(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_CLR_INTR                VTSS_IOREG(VTSS_TO_TWI,0x10)
#define  VTSS_F_TWI_TWI_CLR_INTR_CLR_INTR     VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RX_UNDER            VTSS_IOREG(VTSS_TO_TWI,0x11)
#define  VTSS_F_TWI_TWI_CLR_RX_UNDER_CLR_RX_UNDER  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RX_OVER             VTSS_IOREG(VTSS_TO_TWI,0x12)
#define  VTSS_F_TWI_TWI_CLR_RX_OVER_CLR_RX_OVER  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_TX_OVER             VTSS_IOREG(VTSS_TO_TWI,0x13)
#define  VTSS_F_TWI_TWI_CLR_TX_OVER_CLR_TX_OVER  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RD_REQ              VTSS_IOREG(VTSS_TO_TWI,0x14)
#define  VTSS_F_TWI_TWI_CLR_RD_REQ_CLR_RD_REQ  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_TX_ABRT             VTSS_IOREG(VTSS_TO_TWI,0x15)
#define  VTSS_F_TWI_TWI_CLR_TX_ABRT_CLR_TX_ABRT  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_RX_DONE             VTSS_IOREG(VTSS_TO_TWI,0x16)
#define  VTSS_F_TWI_TWI_CLR_RX_DONE_CLR_RX_DONE  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_ACTIVITY            VTSS_IOREG(VTSS_TO_TWI,0x17)
#define  VTSS_F_TWI_TWI_CLR_ACTIVITY_CLR_ACTIVITY  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_STOP_DET            VTSS_IOREG(VTSS_TO_TWI,0x18)
#define  VTSS_F_TWI_TWI_CLR_STOP_DET_CLR_STOP_DET  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_START_DET           VTSS_IOREG(VTSS_TO_TWI,0x19)
#define  VTSS_F_TWI_TWI_CLR_START_DET_CLR_START_DET  VTSS_BIT(0)

#define VTSS_TWI_TWI_CLR_GEN_CALL            VTSS_IOREG(VTSS_TO_TWI,0x1a)
#define  VTSS_F_TWI_TWI_CLR_GEN_CALL_CLR_GEN_CALL  VTSS_BIT(0)

#define VTSS_TWI_TWI_CTRL                    VTSS_IOREG(VTSS_TO_TWI,0x1b)
#define  VTSS_F_TWI_TWI_CTRL_ENABLE           VTSS_BIT(0)

#define VTSS_TWI_TWI_STAT                    VTSS_IOREG(VTSS_TO_TWI,0x1c)
#define  VTSS_F_TWI_TWI_STAT_SLV_ACTIVITY     VTSS_BIT(6)
#define  VTSS_F_TWI_TWI_STAT_MST_ACTIVITY     VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_STAT_RFF              VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_STAT_RFNE             VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_STAT_TFE              VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_STAT_TFNF             VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_STAT_BUS_ACTIVITY     VTSS_BIT(0)

#define VTSS_TWI_TWI_TXFLR                   VTSS_IOREG(VTSS_TO_TWI,0x1d)
#define  VTSS_F_TWI_TWI_TXFLR_TXFLR(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_TXFLR_TXFLR           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_TXFLR_TXFLR(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_RXFLR                   VTSS_IOREG(VTSS_TO_TWI,0x1e)
#define  VTSS_F_TWI_TWI_RXFLR_RXFLR(x)        VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_TWI_TWI_RXFLR_RXFLR           VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_TWI_TWI_RXFLR_RXFLR(x)        VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_TWI_TWI_TX_ABRT_SOURCE          VTSS_IOREG(VTSS_TO_TWI,0x20)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SLVRD_INTX  VTSS_BIT(15)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST  VTSS_BIT(14)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO  VTSS_BIT(13)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ARB_LOST  VTSS_BIT(12)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_MASTER_DIS  VTSS_BIT(11)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT  VTSS_BIT(10)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT  VTSS_BIT(9)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET  VTSS_BIT(7)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_GCALL_READ  VTSS_BIT(5)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_GCALL_NOACK  VTSS_BIT(4)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK  VTSS_BIT(3)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK  VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK  VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK  VTSS_BIT(0)

#define VTSS_TWI_TWI_SDA_SETUP               VTSS_IOREG(VTSS_TO_TWI,0x25)
#define  VTSS_F_TWI_TWI_SDA_SETUP_SDA_SETUP(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_TWI_TWI_SDA_SETUP_SDA_SETUP     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_TWI_TWI_SDA_SETUP_SDA_SETUP(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_TWI_TWI_ACK_GEN_CALL            VTSS_IOREG(VTSS_TO_TWI,0x26)
#define  VTSS_F_TWI_TWI_ACK_GEN_CALL_ACK_GEN_CALL  VTSS_BIT(0)

#define VTSS_TWI_TWI_ENABLE_STATUS           VTSS_IOREG(VTSS_TO_TWI,0x27)
#define  VTSS_F_TWI_TWI_ENABLE_STATUS_SLV_FIFO_FILLED_AND_FLUSHED  VTSS_BIT(2)
#define  VTSS_F_TWI_TWI_ENABLE_STATUS_SLV_RX_ABORTED  VTSS_BIT(1)
#define  VTSS_F_TWI_TWI_ENABLE_STATUS_BUSY    VTSS_BIT(0)


#endif /* _VTSS_SERVAL_REGS_TWI_H_ */
