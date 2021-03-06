/*

 Vitesse Switch Software.

 Copyright (c) 2002-2010 Vitesse Semiconductor Corporation "Vitesse". All
 Rights Reserved.

 Unpublished rights reserved under the copyright laws of the United States of
 America, other countries and international treaties. Permission to use, copy,
 store and modify, the software and its source code is granted. Permission to
 integrate into other products, disclose, transmit and distribute the software
 in an absolute machine readable format (e.g. HEX file) is also granted.  The
 source code of the software may not be disclosed, transmitted or distributed
 without the written permission of Vitesse. The software and its source code
 may only be used in products utilizing the Vitesse switch products.

 This copyright notice must appear in any copy, modification, disclosure,
 transmission or distribution of the software. Vitesse retains all ownership,
 copyright, trade secret and proprietary rights in the software.

 THIS SOFTWARE HAS BEEN PROVIDED "AS IS," WITHOUT EXPRESS OR IMPLIED WARRANTY
 INCLUDING, WITHOUT LIMITATION, IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR USE AND NON-INFRINGEMENT.

*/
/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.old-api.conf
 */

#ifndef LLDPXMEDMIB_H
#define LLDPXMEDMIB_H

/*
 * function declarations
 */
void            init_lldpXMedMIB(void);
FindVarMethod   var_lldpXMedMIB;
FindVarMethod   var_lldpXMedLocMediaPolicyTable;
FindVarMethod   var_lldpXMedLocXPoEPSEPortTable;
FindVarMethod   var_lldpXMedPortConfigTable;
FindVarMethod   var_lldpXMedRemCapabilitiesTable;
FindVarMethod   var_lldpXMedRemXPoETable;
FindVarMethod   var_lldpXMedRemInventoryTable;
FindVarMethod   var_lldpXMedLocLocationTable;
FindVarMethod   var_lldpXMedRemXPoEPDTable;
FindVarMethod   var_lldpXMedRemXPoEPSETable;
FindVarMethod   var_lldpXMedRemMediaPolicyTable;
FindVarMethod   var_lldpXMedRemLocationTable;
WriteMethod     write_lldpXMedFastStartRepeatCount;
WriteMethod     write_lldpXMedPortConfigTLVsTxEnable;
WriteMethod     write_lldpXMedPortConfigNotifEnable;
WriteMethod     write_lldpXMedLocLocationInfo;

#endif                          /* LLDPXMEDMIB_H */

