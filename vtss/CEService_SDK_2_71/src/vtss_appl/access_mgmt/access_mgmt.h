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

#ifndef _ACCESS_MGMT_H_
#define _ACCESS_MGMT_H_

/* ================================================================= *
 *  Trace definitions
 * ================================================================= */

#include "access_mgmt_api.h"
#include "vtss_module_id.h"

#include <vtss_module_id.h>
#include <vtss_trace_lvl_api.h>

#define VTSS_TRACE_MODULE_ID VTSS_MODULE_ID_ACCESS_MGMT

#define VTSS_TRACE_GRP_DEFAULT      0
#define TRACE_GRP_CRIT              1
#define TRACE_GRP_CNT               2

#include <vtss_trace_api.h>

/* ================================================================= *
 *  Access management configuration blocks
 * ================================================================= */

/* Block versions */
#define ACCESS_MGMT_CONF_BLK_VERSION      2

/* Access management configuration block */
typedef struct {
    u32                 version;            /* Block version */
    access_mgmt_conf_t  access_mgmt_conf;   /* Access management configuration */
} access_mgmt_conf_blk_t;


/* ================================================================= *
 *  Access management global structure
 * ================================================================= */

/* Access management global structure */
typedef struct {
    critd_t             crit;
    access_mgmt_conf_t  access_mgmt_conf;
} access_mgmt_global_t;

#endif /* _ACCESS_MGMT_H_ */

/****************************************************************************/
/*                                                                          */
/*  End of file.                                                            */
/*                                                                          */
/****************************************************************************/