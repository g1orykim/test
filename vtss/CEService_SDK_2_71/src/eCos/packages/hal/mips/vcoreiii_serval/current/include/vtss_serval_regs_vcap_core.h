#ifndef _VTSS_SERVAL_REGS_VCAP_CORE_H_
#define _VTSS_SERVAL_REGS_VCAP_CORE_H_

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

#define VTSS_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL(target)  VTSS_IOREG(target,0x0)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_CMD(x)  VTSS_ENCODE_BITFIELD(x,22,3)
#define  VTSS_M_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_CMD     VTSS_ENCODE_BITMASK(22,3)
#define  VTSS_X_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_CMD(x)  VTSS_EXTRACT_BITFIELD(x,22,3)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_ENTRY_DIS  VTSS_BIT(21)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_ACTION_DIS  VTSS_BIT(20)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_CNT_DIS  VTSS_BIT(19)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_ADDR(x)  VTSS_ENCODE_BITFIELD(x,3,16)
#define  VTSS_M_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_ADDR     VTSS_ENCODE_BITMASK(3,16)
#define  VTSS_X_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_ADDR(x)  VTSS_EXTRACT_BITFIELD(x,3,16)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_UPDATE_SHOT  VTSS_BIT(2)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_CLEAR_CACHE  VTSS_BIT(1)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_UPDATE_CTRL_MV_TRAFFIC_IGN  VTSS_BIT(0)

#define VTSS_VCAP_CORE_VCAP_CORE_CFG_VCAP_MV_CFG(target)  VTSS_IOREG(target,0x1)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_MV_CFG_MV_NUM_POS(x)  VTSS_ENCODE_BITFIELD(x,16,16)
#define  VTSS_M_VCAP_CORE_VCAP_CORE_CFG_VCAP_MV_CFG_MV_NUM_POS     VTSS_ENCODE_BITMASK(16,16)
#define  VTSS_X_VCAP_CORE_VCAP_CORE_CFG_VCAP_MV_CFG_MV_NUM_POS(x)  VTSS_EXTRACT_BITFIELD(x,16,16)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_CFG_VCAP_MV_CFG_MV_SIZE(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_VCAP_CORE_VCAP_CORE_CFG_VCAP_MV_CFG_MV_SIZE     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_VCAP_CORE_VCAP_CORE_CFG_VCAP_MV_CFG_MV_SIZE(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_VCAP_CORE_VCAP_CORE_CACHE_VCAP_ENTRY_DAT(target,ri)  VTSS_IOREG(target,0x2 + (ri))

#define VTSS_VCAP_CORE_VCAP_CORE_CACHE_VCAP_MASK_DAT(target,ri)  VTSS_IOREG(target,0x22 + (ri))

#define VTSS_VCAP_CORE_VCAP_CORE_CACHE_VCAP_ACTION_DAT(target,ri)  VTSS_IOREG(target,0x42 + (ri))

#define VTSS_VCAP_CORE_VCAP_CORE_CACHE_VCAP_CNT_DAT(target,ri)  VTSS_IOREG(target,0x62 + (ri))

#define VTSS_VCAP_CORE_VCAP_CORE_CACHE_VCAP_TG_DAT(target)  VTSS_IOREG(target,0x82)

#define VTSS_VCAP_CORE_VCAP_CORE_STICKY_VCAP_STICKY(target)  VTSS_IOREG(target,0x83)
#define  VTSS_F_VCAP_CORE_VCAP_CORE_STICKY_VCAP_STICKY_VCAP_ROW_DELETED_STICKY  VTSS_BIT(0)

#define VTSS_VCAP_CORE_VCAP_CONST_ENTRY_WIDTH(target)  VTSS_IOREG(target,0x84)
#define  VTSS_F_VCAP_CORE_VCAP_CONST_ENTRY_WIDTH_ENTRY_WIDTH(x)  VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_VCAP_CORE_VCAP_CONST_ENTRY_WIDTH_ENTRY_WIDTH     VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_VCAP_CORE_VCAP_CONST_ENTRY_WIDTH_ENTRY_WIDTH(x)  VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_VCAP_CORE_VCAP_CONST_ENTRY_CNT(target)  VTSS_IOREG(target,0x85)
#define  VTSS_F_VCAP_CORE_VCAP_CONST_ENTRY_CNT_ENTRY_CNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_VCAP_CORE_VCAP_CONST_ENTRY_CNT_ENTRY_CNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_VCAP_CORE_VCAP_CONST_ENTRY_CNT_ENTRY_CNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_VCAP_CORE_VCAP_CONST_ENTRY_SWCNT(target)  VTSS_IOREG(target,0x86)
#define  VTSS_F_VCAP_CORE_VCAP_CONST_ENTRY_SWCNT_ENTRY_SWCNT(x)  VTSS_ENCODE_BITFIELD(x,0,6)
#define  VTSS_M_VCAP_CORE_VCAP_CONST_ENTRY_SWCNT_ENTRY_SWCNT     VTSS_ENCODE_BITMASK(0,6)
#define  VTSS_X_VCAP_CORE_VCAP_CONST_ENTRY_SWCNT_ENTRY_SWCNT(x)  VTSS_EXTRACT_BITFIELD(x,0,6)

#define VTSS_VCAP_CORE_VCAP_CONST_ENTRY_TG_WIDTH(target)  VTSS_IOREG(target,0x87)
#define  VTSS_F_VCAP_CORE_VCAP_CONST_ENTRY_TG_WIDTH_ENTRY_TG_WIDTH(x)  VTSS_ENCODE_BITFIELD(x,0,6)
#define  VTSS_M_VCAP_CORE_VCAP_CONST_ENTRY_TG_WIDTH_ENTRY_TG_WIDTH     VTSS_ENCODE_BITMASK(0,6)
#define  VTSS_X_VCAP_CORE_VCAP_CONST_ENTRY_TG_WIDTH_ENTRY_TG_WIDTH(x)  VTSS_EXTRACT_BITFIELD(x,0,6)

#define VTSS_VCAP_CORE_VCAP_CONST_ACTION_DEF_CNT(target)  VTSS_IOREG(target,0x88)
#define  VTSS_F_VCAP_CORE_VCAP_CONST_ACTION_DEF_CNT_ACTION_DEF_CNT(x)  VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_VCAP_CORE_VCAP_CONST_ACTION_DEF_CNT_ACTION_DEF_CNT     VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_VCAP_CORE_VCAP_CONST_ACTION_DEF_CNT_ACTION_DEF_CNT(x)  VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_VCAP_CORE_VCAP_CONST_ACTION_WIDTH(target)  VTSS_IOREG(target,0x89)
#define  VTSS_F_VCAP_CORE_VCAP_CONST_ACTION_WIDTH_ACTION_WIDTH(x)  VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_VCAP_CORE_VCAP_CONST_ACTION_WIDTH_ACTION_WIDTH     VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_VCAP_CORE_VCAP_CONST_ACTION_WIDTH_ACTION_WIDTH(x)  VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_VCAP_CORE_VCAP_CONST_CNT_WIDTH(target)  VTSS_IOREG(target,0x8a)
#define  VTSS_F_VCAP_CORE_VCAP_CONST_CNT_WIDTH_CNT_WIDTH(x)  VTSS_ENCODE_BITFIELD(x,0,10)
#define  VTSS_M_VCAP_CORE_VCAP_CONST_CNT_WIDTH_CNT_WIDTH     VTSS_ENCODE_BITMASK(0,10)
#define  VTSS_X_VCAP_CORE_VCAP_CONST_CNT_WIDTH_CNT_WIDTH(x)  VTSS_EXTRACT_BITFIELD(x,0,10)

#define VTSS_VCAP_CORE_TCAM_BIST_TCAM_CTRL(target)  VTSS_IOREG(target,0x8b)
#define  VTSS_F_VCAP_CORE_TCAM_BIST_TCAM_CTRL_TCAM_BIST  VTSS_BIT(1)
#define  VTSS_F_VCAP_CORE_TCAM_BIST_TCAM_CTRL_TCAM_INIT  VTSS_BIT(0)

#define VTSS_VCAP_CORE_TCAM_BIST_TCAM_STAT(target)  VTSS_IOREG(target,0x8d)
#define  VTSS_F_VCAP_CORE_TCAM_BIST_TCAM_STAT_BIST_ERR  VTSS_BIT(2)
#define  VTSS_F_VCAP_CORE_TCAM_BIST_TCAM_STAT_BIST_BUSY  VTSS_BIT(1)
#define  VTSS_F_VCAP_CORE_TCAM_BIST_TCAM_STAT_TCAM_RDY  VTSS_BIT(0)


#endif /* _VTSS_SERVAL_REGS_VCAP_CORE_H_ */