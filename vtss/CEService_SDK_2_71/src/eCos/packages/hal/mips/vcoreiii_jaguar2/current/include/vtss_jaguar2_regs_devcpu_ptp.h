#ifndef _VTSS_JAGUAR2_REGS_DEVCPU_PTP_H_
#define _VTSS_JAGUAR2_REGS_DEVCPU_PTP_H_

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

#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x20)
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_ENA(x)  VTSS_ENCODE_BITFIELD(x,3,3)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_ENA     VTSS_ENCODE_BITMASK(3,3)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_ENA(x)  VTSS_EXTRACT_BITFIELD(x,3,3)
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_HOLD(x)  VTSS_ENCODE_BITFIELD(x,0,3)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_HOLD     VTSS_ENCODE_BITMASK(0,3)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_MISC_CFG_PTP_HOLD(x)  VTSS_EXTRACT_BITFIELD(x,0,3)

#define VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x21 + (ri))
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_DIR  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_ENA  VTSS_BIT(0)

#define VTSS_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x24 + (ri))
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ_UNIT  VTSS_BIT(30)
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_CLK_ADJ_FRQ_CLK_ADJ(x)  VTSS_EXTRACT_BITFIELD(x,0,30)

#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x27)
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_INTR_PTP(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_INTR_PTP     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_INTR_PTP(x)  VTSS_EXTRACT_BITFIELD(x,0,4)

#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x28)
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA_INTR_PTP_ENA(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA_INTR_PTP_ENA     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_PIN_INTR_ENA_INTR_PTP_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,4)

#define VTSS_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT  VTSS_IOREG(VTSS_TO_DEVCPU_PTP,0x29)
#define  VTSS_F_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT_INTR_PTP_IDENT(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT_INTR_PTP_IDENT     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_DEVCPU_PTP_PTP_CFG_PTP_INTR_IDENT_INTR_PTP_IDENT(x)  VTSS_EXTRACT_BITFIELD(x,0,4)

#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,0)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_ACTION(x)  VTSS_ENCODE_BITFIELD(x,4,3)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_ACTION     VTSS_ENCODE_BITMASK(4,3)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_ACTION(x)  VTSS_EXTRACT_BITFIELD(x,4,3)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_SYNC  VTSS_BIT(3)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_INV_POL  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_DOM(x)  VTSS_ENCODE_BITFIELD(x,0,2)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_DOM     VTSS_ENCODE_BITMASK(0,2)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_PIN_CFG_PTP_PIN_DOM(x)  VTSS_EXTRACT_BITFIELD(x,0,2)

#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,1)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB_PTP_TOD_SEC_MSB(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB_PTP_TOD_SEC_MSB     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_MSB_PTP_TOD_SEC_MSB(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_SEC_LSB(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,2)

#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,3)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC_PTP_TOD_NSEC(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC_PTP_TOD_NSEC     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PTP_TOD_NSEC_PTP_TOD_NSEC(x)  VTSS_EXTRACT_BITFIELD(x,0,30)

#define VTSS_DEVCPU_PTP_PTP_PINS_PTP_NSF(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,4)

#define VTSS_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,5)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD_PIN_WFH(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD_PIN_WFH     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PIN_WF_HIGH_PERIOD_PIN_WFH(x)  VTSS_EXTRACT_BITFIELD(x,0,30)

#define VTSS_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_PTP,0x0,gi,8,0,6)
#define  VTSS_F_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD_PIN_WFL(x)  VTSS_ENCODE_BITFIELD(x,0,30)
#define  VTSS_M_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD_PIN_WFL     VTSS_ENCODE_BITMASK(0,30)
#define  VTSS_X_DEVCPU_PTP_PTP_PINS_PIN_WF_LOW_PERIOD_PIN_WFL(x)  VTSS_EXTRACT_BITFIELD(x,0,30)


#endif /* _VTSS_JAGUAR2_REGS_DEVCPU_PTP_H_ */
