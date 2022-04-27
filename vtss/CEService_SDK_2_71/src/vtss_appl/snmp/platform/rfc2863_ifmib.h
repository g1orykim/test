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

#ifndef RFC2863_IFMIB_H
#define RFC2863_IFMIB_H

#define RFC2863_SUPPORTED_IFMIB     1

/*
 * function declarations
 */
#if RFC2863_SUPPORTED_IFMIB
/* ifmib ----------------------------------------------------------*/
void            init_ifMIB(void);
FindVarMethod   var_ifMIB;
FindVarMethod   var_ifRcvAddressTable;
FindVarMethod   var_ifXTable;
FindVarMethod   var_ifTestTable;
FindVarMethod   var_ifStackTable;
WriteMethod     write_ifRcvAddressStatus;
WriteMethod     write_ifRcvAddressType;
WriteMethod     write_ifLinkUpDownTrapEnable;
WriteMethod     write_ifPromiscuousMode;
WriteMethod     write_ifAlias;
WriteMethod     write_ifTestId;
WriteMethod     write_ifTestStatus;
WriteMethod     write_ifTestType;
WriteMethod     write_ifTestOwner;
WriteMethod     write_ifStackStatus;
#endif /* RFC2863_SUPPORTED_IFMIB */

#endif                          /* RFC2863_IFMIB_H */

