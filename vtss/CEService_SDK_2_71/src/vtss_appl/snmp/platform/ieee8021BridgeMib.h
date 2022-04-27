/*
 *
 * Vitesse Switch Software.
 *
 * Copyright (c) 2002-2013 Vitesse Semiconductor Corporation "Vitesse". All
 * Rights Reserved.
 *
 * Unpublished rights reserved under the copyright laws of the United States of
 * America, other countries and international treaties. Permission to use, copy,
 * store and modify, the software and its source code is granted. Permission to
 * integrate into other products, disclose, transmit and distribute the software
 * in an absolute machine readable format (e.g. HEX file) is also granted.  The
 * source code of the software may not be disclosed, transmitted or distributed
 * without the written permission of Vitesse. The software and its source code
 * may only be used in products utilizing the Vitesse switch products.
 *
 * This copyright notice must appear in any copy, modification, disclosure,
 * transmission or distribution of the software. Vitesse retains all ownership,
 * copyright, trade secret and proprietary rights in the software.
 *
 * THIS SOFTWARE HAS BEEN PROVIDED "AS IS," WITHOUT EXPRESS OR IMPLIED WARRANTY
 * INCLUDING, WITHOUT LIMITATION, IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR USE AND NON-INFRINGEMENT.
 *
 */

// Note: This file originally auto-generated by mib2c using vtss_mib2c_ucd_snmp.conf v3.40

#ifndef _IEEE8021BRIDGEBASEPORTTABLE_H_
#define _IEEE8021BRIDGEBASEPORTTABLE_H_


#define IEEE8021BRIDGEBASEPORTTABLE_STR_LEN_MAX    32
#define IEEE8021BRIDGEBASEPORTTABLE_BITS_LEN_MAX   1


/******************************************************************************/
//
// Data structure declarations
//
/******************************************************************************/


// The table entry data structure for ieee8021BridgeBasePortTable
typedef struct {
    // Entry keys
    u_long          ieee8021BridgeBasePortComponentId;
    u_long          ieee8021BridgeBasePort;

    // Entry columns
    long            ieee8021BridgeBasePortIfIndex;
    struct counter64 ieee8021BridgeBasePortDelayExceededDiscards;
    struct counter64 ieee8021BridgeBasePortMtuExceededDiscards;
    char
    ieee8021BridgeBasePortCapabilities
    [IEEE8021BRIDGEBASEPORTTABLE_BITS_LEN_MAX];
    size_t          ieee8021BridgeBasePortCapabilities_len;
    char
    ieee8021BridgeBasePortTypeCapabilities
    [IEEE8021BRIDGEBASEPORTTABLE_BITS_LEN_MAX];
    size_t          ieee8021BridgeBasePortTypeCapabilities_len;
    long            ieee8021BridgeBasePortType;
    long            ieee8021BridgeBasePortExternal;
    long            ieee8021BridgeBasePortAdminPointToPoint;
    long            ieee8021BridgeBasePortOperPointToPoint;
    char
    ieee8021BridgeBasePortName[IEEE8021BRIDGEBASEPORTTABLE_STR_LEN_MAX
                               + 1];
    size_t          ieee8021BridgeBasePortName_len;
} ieee8021BridgeBasePortTable_entry_t;


/******************************************************************************/
//
// Initial function
//
/******************************************************************************/
/**
  * \brief Initializes the SNMP-part of the IEEE8021-BRIDGE-MIB:ieee8021BridgeBasePortTable.
  **/
void            ieee8021BridgeMib_init(void);


/******************************************************************************/
//
// Table entry access function declarations
//
/******************************************************************************/
/**
  * \brief Get first table entry of ieee8021BridgeBasePortTableEntry.
  *
  * \param table_entry [IN_OUT]: Pointer to structure that contains the table
  *                              entry to get the first table entry.
  *
  * \return: 0 if the operation success, non-zero value otherwise.
  **/
int
ieee8021BridgeBasePortTableEntry_getfirst
(ieee8021BridgeBasePortTable_entry_t *table_entry);

/**
  * \brief Get/Getnext table entry of ieee8021BridgeBasePortTableEntry.
  *
  * \param table_entry [IN_OUT]: Pointer to structure that contains the table
  *                              entry to get/getnext the table entry.
  *
  * \return: 0 if the operation success, non-zero value otherwise.
  **/
int
ieee8021BridgeBasePortTableEntry_get(ieee8021BridgeBasePortTable_entry_t *
                                     table_entry, int getnext);

/**
  * \brief Set table entry of ieee8021BridgeBasePortTableEntry.
  *
  * \param table_entry [IN_OUT]: Pointer to structure that contains the table
  *                              entry to set the table entry.
  *
  * \return: 0 if the operation success, non-zero value otherwise.
  **/
int
ieee8021BridgeBasePortTableEntry_set(ieee8021BridgeBasePortTable_entry_t *
                                     table_entry);

#endif                          /* _IEEE8021BRIDGEBASEPORTTABLE_H_ */