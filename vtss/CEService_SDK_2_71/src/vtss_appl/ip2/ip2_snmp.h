/*

 Vitesse Switch Software.

 Copyright (c) 2002-2013 Vitesse Semiconductor Corporation "Vitesse". All
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
#ifndef _IP2_SNMP_H_
#define _IP2_SNMP_H_

#ifdef VTSS_SW_OPTION_SNMP
#include "ip2_api.h"
#include "ip2_types.h"

vtss_rc vtss_ip2_snmp_init(void);
void vtss_ip2_snmp_signal_global_changes(void);
vtss_rc vtss_ip2_interfaces_last_change(u64 *time);
vtss_rc vtss_ip2_address_created_ipv4(vtss_if_id_vlan_t if_id, u64 *time);
vtss_rc vtss_ip2_address_changed_ipv4(vtss_if_id_vlan_t if_id, u64 *time);
vtss_rc vtss_ip2_address_created_ipv6(vtss_if_id_vlan_t if_id, u64 *time);
vtss_rc vtss_ip2_address_changed_ipv6(vtss_if_id_vlan_t if_id, u64 *time);

#endif /* VTSS_SW_OPTION_SNMP */
#endif /* _IP2_SNMP_H_ */
