/*

 Vitesse Switch API software.

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

#ifndef __ICFG_API_H__
#define __ICFG_API_H__

/**
 * \file
 *
 * \brief ICFG API.
 *
 * \details ICFG implements a library of functions for text-mode synthesis of
 * the currently running configuration. This configuration is expressed as
 * a structured and ordered set of ICLI-format command lines.
 *
 * A module with relevant configuration information must register itself with
 * ICFG at system startup-time. The module inserts a callback function pointer
 * to itself into the hard-coded synthesis order defined by enum
 * #vtss_icfg_ordering_t.
 *
 * Then, later, when synthesis is requested by the operator (through the GUI or
 * CLI), all callbacks are invoked in the correct order and with relevant
 * parameters (struct #vtss_icfg_query_request_t), allowing the callbacks to
 * generate appropriate output.
 *
 * This generation is done using a #printf-style function, #vtss_icfg_printf,
 * into a result data structure, #vtss_icfg_query_result_t. Client modules
 * should treat this data type as opaque. One call to the printf function may
 * freely generate several lines of output.
 *
 * Note that there is an upper limit to the amount of text that can be generated
 * in one call to #vtss_icfg_printf: #VTSS_ICFG_QUERY_RESULT_BLOCK_SIZE.
 *
 * NOTE WELL: Registration must be performed on all switches in a stack, but
 *            all query-related functions are only valid on the switch stack
 *            master. Do not call on slave switches or VTSS_RC_ERROR will be
 *            returned.
 *
 * Per-module Integration
 * ======================
 * For a module to integrate with ICLI, the following steps must be taken:
 *
 * 1. Determine where the module fits in the ordering, #vtss_icfg_ordering_t,
 *    and create new constants there. Observe the naming recommendations.
 *    Note that one module may appear several times in the ordering, but each
 *    time with a unique constant.
 *
 * 2. Create one or more callback functions with the prototype given by
 *    #vtss_icfg_query_func_t and, in the module's intialization, register them
 *    with ICFG using #vtss_icfg_query_register and the constants created in
 *    step 1.
 */

#include <vtss_types.h>
#include "icli_api.h"

/** \brief Comment lead-in.
 *
 * \details Comments are one-lined with a specific lead-in character. Callbacks
 * are allowed to generate comment lines, but must do so very sparingly and
 * only in essential cases. As a rule, don't try to tell the system
 * administrator things he/she can reasonably be expected to know.
 */
#define VTSS_ICFG_COMMENT_LEADIN "!"



/** \brief ICFG Query Ordering.
 *
 * \details This enum orders the output generated by ICFG querying all
 * registered callbacks.
 *
 * Some of the enum values are reserved and used for grouping per ICLI command
 * submode; they are recognizable by the ...BEGIN and ..._END suffixes.
 *
 * IMPORTANT: All enum names should obey this naming convention:
 *
 *     VTSS_ICFG_module-name_command-identity
 *
 * The module-name is obvious, e.g. PORT or VLAN; the command-identity should
 * identify the command/set-of-commands generated here.
 *
 * For example, we could imagine an identifier like VTSS_ICFG_PORT_SPEED_DUPLEX
 * for the port module's synthesis of 'speed' and 'duplex' commands.
 *
 * Note how global config can be inserted between all submodes, if appropriate.
 *
 * Note: It is not allowed for multiple modules to use the same position in the
 * ordering. This so we avoid unexpected behavior depending on, say, runtime
 * module initialization order.
 */

typedef enum {
#ifdef VTSS_SW_OPTION_ICLI
    VTSS_ICFG_GLOBAL_ICLI,
#endif

    // System boot will occur a system boot log, so we run the syslog configuration first.
#if defined(VTSS_SW_OPTION_SYSLOG)
    VTSS_ICFG_SYSLOG_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_SYSLOG */

#ifdef VTSS_SW_OPTION_USERS
    VTSS_ICFG_GLOBAL_USERS,
#else
    VTSS_ICFG_GLOBAL_SYSUTIL, // For system password
#endif

#ifdef VTSS_SW_OPTION_ACCESS_MGMT
    VTSS_ICFG_GLOBAL_ACCESS_MGMT,
#endif

#ifdef VTSS_SW_OPTION_LOOP_PROTECT
    VTSS_ICFG_GLOBAL_LOOP_PROTECT,
#endif

#if VTSS_SWITCH_STACKABLE
    VTSS_ICFG_GLOBAL_STACK,
#endif

#ifdef VTSS_SW_OPTION_DHCP_SERVER
    VTSS_ICFG_GLOBAL_DHCP_SERVER,
#endif

    VTSS_ICFG_EVC_GLOBAL_CONF,

    //------------------------- VLAN submode begin ----------------------------
    VTSS_ICFG_VLAN_BEGIN,
#if defined(VTSS_SW_OPTION_VLAN)
    VTSS_ICFG_VLAN_NAME_CONF,
#endif /* VTSS_SW_OPTION_VLAN */
    VTSS_ICFG_VLAN_END,
    //------------------------- VLAN submode end ------------------------------

#if defined(VTSS_SW_OPTION_IPMC_LIB)
    VTSS_ICFG_IPMC_LIB_IPMC_RANGE,

    //------------------------- IPMC submode begin ----------------------------
    VTSS_ICFG_IPMC_BEGIN,
    VTSS_ICFG_IPMC_LIB_PROFILE_DESC_RANGE,
    VTSS_ICFG_IPMC_END,
    //------------------------- IPMC submode end ------------------------------

    VTSS_ICFG_IPMC_LIB_IPMC_PROFILE_CTRL,
#endif /* VTSS_SW_OPTION_IPMC_LIB */

    //------------------------- RFC2544 submode begin ----------------------------
    VTSS_ICFG_RFC2544_BEGIN,
#if defined(VTSS_SW_OPTION_RFC2544)
    VTSS_ICFG_RFC2544_PROFILE,
#endif /* VTSS_SW_OPTION_RFC2544 */
    VTSS_ICFG_RFC2544_END,
    //------------------------- RFC2544 submode end ------------------------------

#if defined(VTSS_SW_OPTION_SNMP)
    //------------------------- SNMP server host submode begin ----------------
    VTSS_ICFG_SNMPSERVER_HOST_BEGIN,
    VTSS_ICFG_TRAP_HOST_CONF,
    VTSS_ICFG_SNMPSERVER_HOST_END,
    //------------------------- SNMP server host submode end ------------------
#endif /* VTSS_SW_OPTION_SNMP */

#ifdef VTSS_SW_OPTION_IP2
    VTSS_ICFG_IPV4_GLOBAL,
#endif /* VTSS_SW_OPTION_IP2 */

#ifdef VTSS_SW_OPTION_DNS
    VTSS_ICFG_IP_DNS_CONF,
#endif /* VTSS_SW_OPTION_DNS */

#if defined(VTSS_SW_OPTION_MVR)
    VTSS_ICFG_IPMC_MVR_GLOBAL,
    VTSS_ICFG_IPMC_MVR_INTF,
#endif /* VTSS_SW_OPTION_MVR */

#if defined(VTSS_SW_OPTION_IPMC)
    VTSS_ICFG_IPMC_SNP_IGMP_CTRL,
    VTSS_ICFG_IPMC_SNP_IGMP,
#if defined(VTSS_SW_OPTION_SMB_IPMC)
    VTSS_ICFG_IPMC_SNP_MLD_CTRL,
    VTSS_ICFG_IPMC_SNP_MLD,
#endif /* VTSS_SW_OPTION_SMB_IPMC */
#endif /* VTSS_SW_OPTION_IPMC */

#if defined(VTSS_SW_OPTION_VLAN)
    VTSS_ICFG_VLAN_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_VLAN */

#if defined(VTSS_SW_OPTION_VCL)
    VTSS_ICFG_VCL_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_VCL */

#if defined(VTSS_SW_OPTION_DHCP_SNOOPING)
    VTSS_ICFG_DHCP_SNOOPING_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_DHCP_SNOOPING */

#if defined(VTSS_SW_OPTION_DHCP_RELAY)
    VTSS_ICFG_DHCP_RELAY_CONFIG,
#endif /* VTSS_SW_OPTION_DHCP_RELAY */

#if defined(VTSS_SW_OPTION_ARP_INSPECTION)
    VTSS_ICFG_ARP_INSPECTION_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_ARP_INSPECTION */
#if defined(VTSS_SW_OPTION_IP_SOURCE_GUARD)
    VTSS_ICFG_IP_SOURCE_GUARD_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_IP_SOURCE_GUARD */
#if defined(VTSS_SW_OPTION_NTP)
    VTSS_ICFG_VTSS_NTP_GLOBAL_CONF,
#else
    VTSS_ICFG_VTSS_SNTP_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_NTP */
#if defined(VTSS_SW_OPTION_DAYLIGHT_SAVING)
    VTSS_ICFG_DAYLIGHT_SAVING_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_DAYLIGHT_SAVING */

#if defined(VTSS_SW_OPTION_HTTPS)
    VTSS_HTTPS_ICFG_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_HTTPS */

#if defined(VTSS_SW_OPTION_SSH)
    VTSS_SSH_ICFG_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_SSH */

#if defined(VTSS_SW_OPTION_MIRROR)
    VTSS_ICFG_MIRROR_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_MIRROR */

#if defined(VTSS_SW_OPTION_MAC)
    VTSS_ICFG_MAC_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_MAC */

#if defined(VTSS_SW_OPTION_AGGR)
    VTSS_ICFG_AGGR_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_AGGR */

#if defined(VTSS_SW_OPTION_LACP)
    VTSS_ICFG_LACP_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_LACP */

#if defined(VTSS_SW_OPTION_MSTP)
    VTSS_ICFG_MSTP_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_MSTP */

#if defined(VTSS_SW_OPTION_EEE)
    VTSS_ICFG_EEE_GLOBAL_CONF,
#endif // VTSS_SW_OPTION_EEE

#if defined(VTSS_SW_OPTION_FAN)
    VTSS_ICFG_FAN_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_FAN */

#if defined(VTSS_SW_OPTION_LED_POW_REDUC)
    VTSS_ICFG_LED_POW_REDUC_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_LED_POW_REDUC */

#if defined(VTSS_SW_OPTION_LLDP)
    VTSS_ICFG_LLDP_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_LLDP */

#if defined(VTSS_SW_OPTION_LLDP_MED)
    VTSS_ICFG_LLDPMED_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_LLDP_MED */

#if defined(VTSS_SW_OPTION_SFLOW)
    VTSS_ICFG_SFLOW_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_SFLOW */

#if defined(VTSS_SW_OPTION_POE)
    VTSS_ICFG_POE_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_POE*/

#if defined(VTSS_SW_OPTION_THERMAL_PROTECT)
    VTSS_ICFG_THERMAL_PROTECT_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_THERMAL_PROTECT */

#if defined(VTSS_SW_OPTION_SNMP)
    VTSS_ICFG_SNMP_GLOBAL_CONF,
    VTSS_ICFG_TRAP_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_SNMP */

#if defined(VTSS_SW_OPTION_AUTH)
    VTSS_ICFG_AUTH_AGENT_CONF,
    VTSS_ICFG_AUTH_RADIUS_CONF,
    VTSS_ICFG_AUTH_TACACS_CONF,
#endif /* VTSS_SW_OPTION_AUTH */

#if defined(VTSS_SW_OPTION_UPNP)
    VTSS_ICFG_UPNP_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_UPNP */

#if defined(VTSS_SW_OPTION_QOS)
    VTSS_ICFG_QOS_GLOBAL_CONF,
    VTSS_ICFG_QOS_QCE_CONF,
#endif /* VTSS_SW_OPTION_QOS */

#if defined(VTSS_SW_OPTION_ACL)
    VTSS_ICFG_ACL_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_ACL */

#ifdef VTSS_SW_OPTION_VOICE_VLAN
    VTSS_ICFG_GLOBAL_VOICE_VLAN,
#endif

#ifdef VTSS_SW_OPTION_PHY
    VTSS_ICFG_PHY_GLOBAL_CONF,
#endif

#if defined(VTSS_FEATURE_PORT_CONTROL)
    VTSS_ICFG_PORT_GLOBAL_CONF,
#endif

#if defined(VTSS_SW_OPTION_DOT1X)
    VTSS_ICFG_DOT1X_GLOBAL_CONF,
#endif

#if defined(VTSS_SW_OPTION_PSEC_LIMIT)
    VTSS_ICFG_PSEC_LIMIT_GLOBAL_CONF,
#endif

#if defined(VTSS_FEATURE_SYNCE)
    VTSS_ICFG_SYNCE_GLOBAL_CONF,
#endif

#if defined(VTSS_SW_OPTION_VLAN_TRANSLATION)
    VTSS_ICFG_VLAN_TRANSLATION_GLOBAL_CONF,
#endif

#if defined(VTSS_SW_OPTION_PRIV_LVL)
    VTSS_ICFG_WEB_PRIV_LVL_GLOBAL_CONF,
#endif

#if defined(VTSS_SW_OPTION_PTP)
    VTSS_ICFG_PTP_GLOBAL_CONF,
#endif

#ifdef VTSS_SW_OPTION_GVRP
    VTSS_ICFG_GVRP,
#endif

#if defined(VTSS_SW_OPTION_PERF_MON)
    VTSS_ICFG_PERF_MON_GLOBAL_CONF,
#endif /* VTSS_SW_OPTION_PERF_MON */

    //------------------------- Interface Ethernet submode begin --------------
    VTSS_ICFG_INTERFACE_ETHERNET_BEGIN,

#ifdef VTSS_SW_OPTION_VOICE_VLAN
    VTSS_ICFG_INTERFACE_ETHERNET_VOICE_VLAN,
#endif

#ifdef VTSS_SW_OPTION_LOOP_PROTECT
    VTSS_ICFG_INTERFACE_ETHERNET_LOOP_PROTECT,
#endif

#if defined(VTSS_SW_OPTION_VLAN)
    VTSS_ICFG_VLAN_PORT_CONF,
#endif /* VTSS_SW_OPTION_VLAN */

#if defined(VTSS_SW_OPTION_VCL)
    VTSS_ICFG_VCL_PORT_CONF,
#endif /* VTSS_SW_OPTION_VCL */

#if defined(VTSS_SW_OPTION_PVLAN)
    VTSS_ICFG_PVLAN_PORT_CONF,
#endif /* VTSS_SW_OPTION_PVLAN */

#if defined(VTSS_SW_OPTION_MVR)
    VTSS_ICFG_IPMC_MVR_PORT,
#endif /* VTSS_SW_OPTION_MVR */

#if defined(VTSS_SW_OPTION_IPMC)
    VTSS_ICFG_IPMC_SNP_IGMP_PORT,
#if defined(VTSS_SW_OPTION_SMB_IPMC)
    VTSS_ICFG_IPMC_SNP_MLD_PORT,
#endif /* VTSS_SW_OPTION_SMB_IPMC */
#endif /* VTSS_SW_OPTION_IPMC */

#if defined(VTSS_SW_OPTION_DHCP_SNOOPING)
    VTSS_ICFG_DHCP_SNOOPING_PORT_CONF,
#endif /* VTSS_SW_OPTION_DHCP_SNOOPING */

#if defined(VTSS_SW_OPTION_ARP_INSPECTION)
    VTSS_ICFG_ARP_INSPECTION_PORT_CONF,
#endif /* VTSS_SW_OPTION_ARP_INSPECTION */
#if defined(VTSS_SW_OPTION_IP_SOURCE_GUARD)
    VTSS_ICFG_IP_SOURCE_GUARD_PORT_CONF,
#endif /* VTSS_SW_OPTION_IP_SOURCE_GUARD */
#ifdef VTSS_SW_OPTION_RMON
    VTSS_ICFG_INTERFACE_ETHERNET_RMON,
#endif
#if defined(VTSS_SW_OPTION_LLDP)
    VTSS_ICFG_LLDP_PORT_CONF,
#endif /* VTSS_SW_OPTION_LLDP */

#if defined(VTSS_SW_OPTION_LLDP_MED)
    VTSS_ICFG_LLDPMED_PORT_CONF,
#endif /* VTSS_SW_OPTION_LLDP_MED */

#if defined(VTSS_SW_OPTION_SFLOW)
    VTSS_ICFG_SFLOW_PORT_CONF,
#endif /* VTSS_SW_OPTION_SFLOW */

#if defined(VTSS_SW_OPTION_POE)
    VTSS_ICFG_POE_PORT_CONF,
#endif /* VTSS_SW_OPTION_POE */

#if defined(VTSS_SW_OPTION_QOS)
    VTSS_ICFG_QOS_PORT_CONF,
#endif /* VTSS_SW_OPTION_QOS */

#if defined(VTSS_SW_OPTION_ACL)
    VTSS_ICFG_ACL_PORT_CONF,
#endif /* VTSS_SW_OPTION_ACL */

#if defined(VTSS_SW_OPTION_THERMAL_PROTECT)
    VTSS_ICFG_THERMAL_PROTECT_PORT_CONF,
#endif /* VTSS_SW_OPTION_THERMAL_PROTECT */

#if defined(VTSS_SW_OPTION_EEE)
    VTSS_ICFG_EEE_PORT_CONF,
#endif // VTSS_SW_OPTION_EEE

#if VTSS_SW_OPTION_PHY_POWER_CONTROL
    VTSS_ICFG_PHY_POWER_CONTROL_PORT_CONF,
#endif // VTSS_SW_OPTION_PHY_POWER_CONTROL

#if defined(VTSS_SW_OPTION_MAC)
    VTSS_ICFG_MAC_INTERFACE_CONF,
#endif /* VTSS_SW_OPTION_MAC */

#if defined(VTSS_SW_OPTION_MSTP)
    VTSS_ICFG_MSTP_INTERFACE_CONF,
#endif /* VTSS_SW_OPTION_MSTP */

#if defined(VTSS_SW_OPTION_LACP)
    VTSS_ICFG_LACP_INTERFACE_CONF,
#endif /* VTSS_SW_OPTION_LACP */

#if defined(VTSS_SW_OPTION_ETH_LINK_OAM)
    VTSS_ICFG_ETH_LINK_OAM_INTERFACE_CONF,
#endif /* VTSS_SW_OPTION_ETH_LINK_OAM */

#if defined(VTSS_SW_OPTION_SNMP)
    VTSS_ICFG_TRAP_PORT_CONF,
#endif /* VTSS_SW_OPTION_SNMP */

#if defined(VTSS_FEATURE_PORT_CONTROL)
    VTSS_ICFG_PORT_INTERFACE_CONF,
#endif

#if defined(VTSS_SW_OPTION_DOT1X)
    VTSS_ICFG_DOT1X_INTERFACE_CONF,
#endif /* VTSS_SW_OPTION_DOT1X */

#if defined(VTSS_SW_OPTION_PSEC_LIMIT)
    VTSS_ICFG_PSEC_LIMIT_INTERFACE_CONF,
#endif

#if defined(VTSS_FEATURE_SYNCE)
    VTSS_ICFG_SYNCE_INTERFACE_CONF,
#endif

#if defined(VTSS_SW_OPTION_PTP)
    VTSS_ICFG_PTP_INTERFACE_CONF,
#endif
#if defined(VTSS_SW_OPTION_VLAN_TRANSLATION)
    VTSS_ICFG_VLAN_TRANSLATION_INTERFACE_CONF,
#endif

    VTSS_ICFG_EVC_PORT_CONF,

#if defined(VTSS_SW_OPTION_AGGR)
    VTSS_ICFG_AGGR_INTERFACE_CONF,
#endif /* VTSS_SW_OPTION_AGGR */

#if defined(VTSS_SW_OPTION_GVRP)
    VTSS_ICFG_GVRP_INTERFACE_CONF,
#endif /* VTSS_SW_OPTION_GVRP */

#if defined(VTSS_SW_OPTION_PHY)
    VTSS_ICFG_PHY_INTERFACE_CONF,
#endif

    VTSS_ICFG_INTERFACE_ETHERNET_END,
    //------------------------- Interface Ethernet submode end ----------------

    //------------------------- Interface VLAN submode begin ------------------
    VTSS_ICFG_INTERFACE_VLAN_BEGIN,

#ifdef VTSS_SW_OPTION_IP2
    VTSS_ICFG_IPV4_INTERFACE,
#endif /* VTSS_SW_OPTION_IP2 */

#ifdef VTSS_SW_OPTION_IPV6
    VTSS_ICFG_IPV6_INTERFACE,
#endif /* VTSS_SW_OPTION_IPV6 */

#if defined(VTSS_SW_OPTION_IPMC)
    VTSS_ICFG_IPMC_SNP_IGMP_INTF,
#if defined(VTSS_SW_OPTION_SMB_IPMC)
    VTSS_ICFG_IPMC_SNP_MLD_INTF,
#endif /* VTSS_SW_OPTION_SMB_IPMC */
#endif /* VTSS_SW_OPTION_IPMC */

#ifdef VTSS_SW_OPTION_DHCP_SERVER
    VTSS_ICFG_INTERFACE_VLAN_DHCP_SERVER,
#endif

    VTSS_ICFG_INTERFACE_VLAN_END,
    //------------------------- Interface VLAN submode end --------------------

#ifdef VTSS_SW_OPTION_IPV6
    VTSS_ICFG_IPV6_GLOBAL,
#endif /* VTSS_SW_OPTION_IPV6 */

#if defined(VTSS_SW_OPTION_MEP)
    VTSS_ICFG_MEP_GLOBAL_CONF,
#endif

#if defined(VTSS_SW_OPTION_EPS)
    VTSS_ICFG_EPS_GLOBAL_CONF,
#endif

#if defined(VTSS_SW_OPTION_ERPS)
    VTSS_ICFG_ERPS_GLOBAL_CONF,
#endif

    //------------------------- STP aggregation submode begin -----------------
    VTSS_ICFG_STP_AGGR_BEGIN,
#if defined(VTSS_SW_OPTION_MSTP)
    VTSS_ICFG_MSTP_AGGR_CONF,
#endif /* VTSS_SW_OPTION_MSTP */
    VTSS_ICFG_STP_AGGR_END,
    //------------------------- STP aggregation submode end -------------------

#ifdef VTSS_SW_OPTION_RMON
    VTSS_ICFG_GLOBAL_RMON,
#endif

    //------------------------- Line submode begin ----------------------------
    VTSS_ICFG_LINE_BEGIN,
#ifdef VTSS_SW_OPTION_ICLI
    VTSS_ICFG_LINE_ICLI,
#endif
    VTSS_ICFG_LINE_END,
    //------------------------- Line submode end ------------------------------

    //------------------------- DHCP pool submode begin -----------------------
#ifdef VTSS_SW_OPTION_DHCP_SERVER
    VTSS_ICFG_DHCP_POOL_BEGIN,
    VTSS_ICFG_DHCP_POOL_DHCP_SERVER,
    VTSS_ICFG_DHCP_POOL_END,
#endif
    //------------------------- DHCP pool submode end -------------------------


    VTSS_ICFG_LAST
} vtss_icfg_ordering_t;



/** \section Query Result API.
 *
 * \details These data structures and functions are used during synthesis of
 * configuration.
 *
 * The #vtss_icfg_query_result_t result structure is made up of a linked list
 * of #vtss_icfg_query_result_buf_t blocks of output. A new block is allocated
 * when the current (pointed to by #tail) runs out of capacity. NOTE that
 * a block may not be filled completely; observe #used. This also holds for
 * non-tail blocks, and is caused by the way printf is implemented.
 */

/** \brief One data block; linked list. text[] is always zero-terminated. */
typedef struct _vtss_icfg_query_result_buf_t {
    BOOL                                 free_text;  /* TRUE = text must be free'd at end-of-use */
    u32                                  used;    /* Number of chars used; index of next free char */
    u32                                  size;    /* Number of chars allocated for #text[] */
    struct _vtss_icfg_query_result_buf_t *next;   /* NULL == this is tail */
    char                                 *text; /* Text here; size is variable */
} vtss_icfg_query_result_buf_t;

/** \brief The query result data structure. Linked list.
 */
typedef struct {
    vtss_icfg_query_result_buf_t *head;   /* First buf filled in */
    vtss_icfg_query_result_buf_t *tail;   /* Current buf being filled in */
} vtss_icfg_query_result_t;

/** \brief Initialize a query result data structure.
 *
 * \details Only valid on stack master.
 *
 * \param initial_size [IN]     Size of first block in bytes. Zero == default
 * \param res          [IN/OUT] The result data structure
 *
 * \return VTSS_RC_OK on success; VTSS_RC_ERROR on memory allocation problems.
 */
vtss_rc vtss_icfg_init_query_result(u32 initial_size,
                                    vtss_icfg_query_result_t *res);

/** \brief Free all memory allocated by a query result data structure.
 * The structure is invalid after the call and must be re-initialized before
 * any further use.
 * \details Only valid on stack master.
 * \param res [IN/OUT] The result data structure.
 */
void vtss_icfg_free_query_result(vtss_icfg_query_result_t *res);

/** \brief Overlay a single text buffer with a vtss_icfg_query_result_t struct.
 * This is used to host "foreign" read-only data that won't be freed by
 * vtss_icfg_free_query_result(). res must be uninitialized at time of call.
 * \details Only valid on stack master.
 * \param res [IN/OUT] The result data structure.
 * \return VTSS_RC_OK on success; VTSS_RC_ERROR on memory allocation problems.
 */
vtss_rc vtss_icfg_overlay_query_result(char *buf, u32 length, vtss_icfg_query_result_t *res);

/** \brief printf into a result data structure.
 * \details Only valid on stack master.
 * \param res    [IN/OUT] The result data structure.
 * \param format [IN]     printf-style format string.
 * \return VTSS_RC_OK on success; VTSS_RC_ERROR on memory allocation problems.
 */
vtss_rc vtss_icfg_printf(vtss_icfg_query_result_t *res, const char *format, ...) __attribute__ ((format (printf, 2, 3)));

/** \section Query Request API.
 *
 * \details A module wanting to synthesize configuration must create one or
 * more callback functions which are then invoked by the ICFG core. The callback
 * function is provided with parameters that identify which ICLI mode that's
 * being processed at the moment plus mode-specific instance parameters.
 * Also, a result buffer structure is passed for filling in.
 *
 * For items in global config, the callback is only invoked once. For sub-modes
 * (e.g. interfaces or VLANs) the callback is invoked once per interface or
 * VLAN instance.
 */

typedef struct {
    icli_cmd_mode_t      cmd_mode;          /* ICLI command mode */
    vtss_icfg_ordering_t order;             /* Order */
    BOOL                 all_defaults;      /* TRUE == generate commands and parameters for default settings too. FALSE == only non-default */
    union {
        icli_switch_port_range_t port;      /* Not used for ranges, only single ports (port.port_cnt is always 1) */
        u32                      vlan;
        u32                      line;
        char                     string[64];
    } instance_id;                          /* Instance identification */
} vtss_icfg_query_request_t;


/** \brief The struct used in vtss_icfg_conf_print function
 */

typedef struct {
    BOOL is_default; /**< Set to TRUE if the configuration value is the same as the default value.*/
    BOOL print_no_arguments; /**< Set to TRUE to ignore all parameter for no commands. Usefull to be able to set the to FALSE and get parameters printed if the no parameter only disables some configurations in a list of configurations*/
    BOOL *bool_list;    /**< Boolean list which will be converted into a text (e.g. 1,3,5-7) and printed before the parameters */
    u16   bool_list_max; /**< The last index number */
    u16   bool_list_min; /**< The first index number*/
    BOOL  bool_list_in_front_of_parameter; /**< TRUE - The bool list is printed in front of parameters else it is printed after the parameters */
} vtss_icfg_conf_print_t;

// See icfg_api.c
void vtss_icfg_conf_print_init(vtss_icfg_conf_print_t *conf_print);

// See icfg_api.c
vtss_rc vtss_icfg_conf_print(const vtss_icfg_query_request_t *req,
                             vtss_icfg_query_result_t *result,
                             vtss_icfg_conf_print_t conf_print,
                             const char *cmd_string,
                             const char *format, ...);


/** \brief Callback signature.
 * \param req    [IN]     Request data.
 * \param result [IN/OUT] Result data. Treat as opaque.
 * \return Return value. VTSS_RC_ERROR on memory/parameter errors.
 */
typedef vtss_rc (*vtss_icfg_query_func_t)(const vtss_icfg_query_request_t *req,
                                          vtss_icfg_query_result_t *result);

/** \brief Query all modules and return the result.
 *
 * \details Only valid on stack master.
 *
 * Note: User must call #vtss_icfg_query_result_free(result) when done with the
 * results.
 *
 * \param all_defaults [IN]     TRUE: Callbacks should include all default
 *                              values
 * \param result       [IN/OUT] Result data. NOTE: #vtss_icfg_init_query_result
 *                              will be called by this function, so don't do it
 *                              in advance or memory will leak.
 */
vtss_rc vtss_icfg_query_all(BOOL                     all_defaults,
                            vtss_icfg_query_result_t *result);

/** \brief Query all modules for specific feature and return the result.
 *
 * \details Only valid on stack master.
 *
 * Note: User must call #vtss_icfg_query_result_free(result) when done with the
 * results.
 *
 * \param all_defaults [IN]     TRUE: Callbacks should include all default
 *                              values
 * \param feature_name [IN]     Name of feature
 * \param result       [IN/OUT] Result data. NOTE: #vtss_icfg_init_query_result
 *                              will be called by this function, so don't do it
 *                              in advance or memory will leak.
 */
vtss_rc vtss_icfg_query_feature(BOOL                     all_defaults,
                                const char *const        feature_name,
                                vtss_icfg_query_result_t *result);

/** \brief Query all modules for something specific and return the result.
 *
 * \details Only valid on stack master.
 *
 * Note: User must call #vtss_icfg_init_query_result(..., result) prior to
 * calling this function.
 *
 * Note: User must call #vtss_icfg_query_result_free(result) when done with the
 * results.
 *
 * \param req    [IN/OUT] Request. Note: req.order is ignored and overwritten.
 * \param result [IN/OUT] Result data. NOTE: #vtss_icfg_init_query_result will
 * be called by this function, so don't do it in advance or memory will leak.
 */
vtss_rc vtss_icfg_query_specific(vtss_icfg_query_request_t *req,
                                 vtss_icfg_query_result_t  *result);



/** \section Query Registration API.
 */


/** \brief Register callback at a particular position in the order.
 *
 * \details Valid on all switches in a stack.
 *
 * \param global_order [IN]   Where in the ordering to insert the #query_cb
 * \param feature_name [IN]   End-user-visible feature name, or NULL.
 *                            IMPORTANT: String must be static and const.
 * \param query_cb     [IN]   Callback.
 *
 * \return Result code. VTSS_RC_ERROR if insert failed (already used, bad
 * index).
 */
vtss_rc vtss_icfg_query_register(vtss_icfg_ordering_t   global_order,
                                 const char *const      feature_name,
                                 vtss_icfg_query_func_t query_cb);



/** \section Utilities.
 */

/** \brief Return list of feature words.
 *
 * \param cnt     [IN]  Number of pointers in list. Up to cnt-1 strings can be
 *                      returned.
 * \param list    [OUT] List of pointers to words. List is NULL-terminated.
 */
void icfg_feature_list_get(const u32 cnt, const char *list[]);



/** \section Initialization.
 *
 * ICFG slots into the initfun sequence in two locations:
 *
 * 1. As the first module. This is for INIT_CMD_CONF_DEF in order to stop the
 *    the ICFG loading thread such that the other modules can safely load
 *    their defaults.
 * 2. As the last module. The other relevant init commands are usually best run
 *    after the other modules have had a chance to act.
 */

/** \brief Early init function.
 *
 * \param data [IN] The initialization struct.
 */
vtss_rc icfg_early_init(vtss_init_data_t *data);

/** \brief Late init function.
 *
 * \param data [IN] The initialization struct.
 */
vtss_rc icfg_late_init(vtss_init_data_t *data);



/** \section Load/Save mutex.
 *
 * \details This mutex is used for protecting whole-file load/save operations:
 *          Max one can be in progress at any time; overlapping requests must
 *          be denied with an error message
 */

/** \brief Try to lock the mutex.
 *
 * \return TRUE == obtained lock; FALSE == already locked, can't load/save now
 */
BOOL vtss_icfg_try_lock_io_mutex(void);

/** \brief Unlock the mutex.
 */
void vtss_icfg_unlock_io_mutex(void);



/** \section Silent Upgrade.
 *
 * \details The first time an ICFG-enabled image is booted on a system, it will
 *          attempt to upgrade the 'conf'-based configuration.
 */

/** \brief Return whether the system is performing silent upgrade.
 *
 * \return TRUE == performing silent upgrade; FALSE == not performing s.u.
 */
BOOL vtss_icfg_silent_upgrade_active(void);

/** \brief Return whether the system has invoked silent upgrade since boot
 *         (i.e. this info isn't stored across reboots).
 * \return TRUE == yes; FALSE == no.
 */
BOOL vtss_icfg_silent_upgrade_invoked(void);

#endif /* __ICFG_API_H__ */
