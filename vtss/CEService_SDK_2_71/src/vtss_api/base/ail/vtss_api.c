/*

 Vitesse API software.

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

 $Id$
 $Revision$

*/

#include "vtss_api.h"
#include "vtss_state.h"
#include "vtss_common.h"

#if defined(VTSS_ARCH_LUTON28)
#include "../luton28/vtss_luton28.h"
#endif

#if defined(VTSS_ARCH_LUTON26)
#include "../luton26/vtss_luton26.h"
#endif

#if defined(VTSS_ARCH_SERVAL)
#include "../serval/vtss_serval.h"
#endif

#if defined(VTSS_ARCH_B2)
#include "../b2/vtss_b2.h"
#endif

#if defined(VTSS_ARCH_JAGUAR_1)
#include "../jaguar1/vtss_jaguar1.h"
#endif

#if defined(VTSS_ARCH_JAGUAR_2)
#include "../jaguar2/vtss_jaguar2.h"
#endif

#if defined(VTSS_ARCH_DAYTONA)
#include "../daytona/vtss_daytona.h"
#endif

#if defined(VTSS_FEATURE_FDMA) && VTSS_OPT_FDMA
#include "vtss_fdma_common.h"
#endif
#if defined(VTSS_CHIP_CU_PHY) || defined(VTSS_CHIP_10G_PHY)
#if defined (VTSS_FEATURE_PHY_TIMESTAMP)
#include "../phy/ts/vtss_phy_ts.h"
#endif /* VTSS_FEATURE_PHY_TIMESTAMP */
#endif /* VTSS_CHIP_CU_PHY || VTSS_CHIP_10G_PHY*/

/* Default instance */
vtss_inst_t vtss_default_inst = NULL;

/* Trace group table */
vtss_trace_conf_t vtss_trace_conf[VTSS_TRACE_GROUP_COUNT] =
{
    [VTSS_TRACE_GROUP_DEFAULT] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_PORT] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_PHY] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_PACKET] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_QOS] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_L2] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_L3] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_SECURITY] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_EVC] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_FDMA_NORMAL] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_FDMA_IRQ] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
#ifdef VTSS_ARCH_DAYTONA
    [VTSS_TRACE_GROUP_XFI] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_UPI] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
#endif /* VTSS_ARCH_DAYTONA */
    [VTSS_TRACE_GROUP_REG_CHECK] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_MPLS] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_VCAP] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_OAM] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
    [VTSS_TRACE_GROUP_TS] = {
        .level = { VTSS_TRACE_LEVEL_ERROR, VTSS_TRACE_LEVEL_ERROR}
    },
};

/* ================================================================= *
 *  Initialization
 * ================================================================= */

/* Check and get instance */
vtss_rc vtss_inst_check_get(const vtss_inst_t inst, vtss_state_t **vtss_state)
{
    /* Default instance is used if inst is NULL */
    *vtss_state = (inst == NULL ? vtss_default_inst : inst);

    VTSS_N("enter");

    /* Check cookie */
    if (*vtss_state == NULL || (*vtss_state)->cookie != VTSS_STATE_COOKIE) {
        VTSS_E("illegal inst: %p", inst);
        return VTSS_RC_ERROR;
    }

    return VTSS_RC_OK;
}

/* Check instance and save state pointers */
vtss_rc vtss_inst_check(const vtss_inst_t inst, vtss_state_t **vtss_state)
{
    vtss_rc rc;

    if ((rc = vtss_inst_check_get(inst, vtss_state)) == VTSS_RC_OK) {
        /* Select first device by default */
        (*vtss_state)->chip_no = 0;
    }
    return rc;
}

/* Check instance and return the state pointer */
vtss_state_t *vtss_inst_check_no_persist(const vtss_inst_t inst)
{
    /* Default instance is used if inst is NULL */
    vtss_state_t *state = (inst == NULL ? vtss_default_inst : inst);

    VTSS_N("enter");

    /* Check cookie */
    if (state == NULL || state->cookie != VTSS_STATE_COOKIE) {
        VTSS_E("illegal inst: %p", inst);
    }

    return state;
}

vtss_rc vtss_inst_port_no_check(const vtss_inst_t    inst,
                                vtss_state_t         **vtss_state,
                                const vtss_port_no_t port_no)
{
    vtss_rc rc;

    if ((rc = vtss_inst_check(inst, vtss_state)) == VTSS_RC_OK)
        rc = vtss_port_no_check(*vtss_state, port_no);

    return rc;
}

vtss_rc vtss_inst_chip_no_check(const vtss_inst_t    inst,
                                vtss_state_t         **vtss_state,
                                const vtss_chip_no_t chip_no)
{
    vtss_rc rc;

    if ((rc = vtss_inst_check(inst, vtss_state)) == VTSS_RC_OK) {
        if (chip_no >= (*vtss_state)->chip_count) {
            VTSS_E("illegal chip_no: %u", chip_no);
            rc = VTSS_RC_ERROR;
        } else {
            (*vtss_state)->chip_no = chip_no;
        }
    }
    return rc;
}

vtss_rc vtss_inst_get(const vtss_target_type_t target,
                      vtss_inst_create_t       *const create)
{
    VTSS_D("enter");
    create->target = target;
    VTSS_D("exit");

    return VTSS_RC_OK;
}

/* Initialize state to default values */
static vtss_rc vtss_inst_default_set(vtss_state_t *vtss_state)
{
    VTSS_D("enter");

    vtss_state->port_count = VTSS_PORTS;

#if defined(VTSS_ARCH_LUTON28)
    {
        vtss_pi_conf_t *pi = &vtss_state->init_conf.pi;
        pi->width = VTSS_PI_WIDTH_16;
        pi->use_extended_bus_cycle = 1;
    }
#endif /* VTSS_ARCH_LUTON28 */

#if defined(VTSS_CHIP_10G_PHY)
    {
        vtss_port_no_t port_no;
        
        for (port_no = VTSS_PORT_NO_START; port_no < VTSS_PORT_NO_END; port_no++) {
            vtss_state->phy_10g_api_base_no = VTSS_PORT_NO_NONE;
            vtss_state->phy_88_event_B[0] = FALSE;
            vtss_state->phy_88_event_B[1] = FALSE;
        }
    }
#endif

#if defined(VTSS_FEATURE_SYNCE)
    {
        u32               i;
        for (i=0; i<VTSS_SYNCE_CLK_PORT_ARRAY_SIZE; i++) {
            vtss_state->synce.old_port_no[i] = 0xFFFFFFFF;
        }
    }
#endif /* VTSS_FEATURE_SYNCE*/

#if defined(VTSS_FEATURE_MACSEC)
    vtss_macsec_internal_conf_t  *macsec;
    vtss_port_no_t    port_no;
    u16 secy, sc, sa;
    for (port_no = VTSS_PORT_NO_START; port_no < VTSS_PORT_NO_END; port_no++) {
        macsec = &vtss_state->macsec_conf[port_no];
        for (secy = 0; secy < VTSS_MACSEC_MAX_SECY; secy++) {
            for (sc = 0; sc < VTSS_MACSEC_MAX_SC_RX; sc++) {
                macsec->secy[secy].rx_sc[sc] = NULL;
            }
            for (sa = 0; sa < VTSS_MACSEC_SA_PER_SC; sa++) {
                macsec->secy[secy].tx_sc.sa[sa] = NULL;
            }
        }

        for (sc = 0; sc < VTSS_MACSEC_MAX_SC_RX; sc++) {
            for (sa = 0; sa < VTSS_MACSEC_SA_PER_SC; sa++) {
                macsec->rx_sc[sc].sa[sa] = NULL;
            }
        }
    }
#endif /* VTSS_FEATURE_MACSEC */

    // Register access checking is by default disabled.
    // (0 enables it). The reason for choosing this
    // polarity is that the API itself may wish to disable
    // access checking from time to time.
    vtss_state->reg_check.disable_cnt = 1;

    VTSS_D("exit");
    return VTSS_RC_OK;
}

vtss_rc vtss_inst_create(const vtss_inst_create_t *const create,
                         vtss_inst_t              *const inst)
{
    vtss_state_t *vtss_state;
    vtss_arch_t  arch;
    
    VTSS_D("enter, sizeof(*vtss_state): %zu", sizeof(*vtss_state));

    if ((vtss_state = VTSS_OS_MALLOC(sizeof(*vtss_state), VTSS_MEM_FLAGS_NONE)) == NULL)
        return VTSS_RC_ERROR;

    memset(vtss_state, 0, sizeof(*vtss_state));
    vtss_state->cookie = VTSS_STATE_COOKIE;
    vtss_state->create = *create;
    vtss_state->chip_count = 1;

    switch (create->target) {
    case VTSS_TARGET_CU_PHY:
        arch = VTSS_ARCH_CU_PHY;
#if defined(VTSS_FEATURE_WIS) && !defined(VTSS_ARCH_DAYTONA)
        if (vtss_phy_inst_ewis_create(vtss_state) != VTSS_RC_OK)  {
            VTSS_E("Could not hook up ewis functions")
        }
#endif
        break;
    case VTSS_TARGET_10G_PHY:
        arch = VTSS_ARCH_10G_PHY;
#if defined(VTSS_FEATURE_WIS) && !defined(VTSS_ARCH_DAYTONA)
        if (vtss_phy_inst_ewis_create(vtss_state) != VTSS_RC_OK)  {
            VTSS_E("Could not hook up ewis functions")
        }
#endif
        break;
#if defined(VTSS_ARCH_SERVAL)
    case VTSS_TARGET_SERVAL:
    case VTSS_TARGET_SERVAL_LITE:
    case VTSS_TARGET_SPARX_III_11:
    case VTSS_TARGET_SEVILLE:
        arch = VTSS_ARCH_SRVL;
        VTSS_RC(vtss_serval_inst_create(vtss_state));
        break;
#endif /* VTSS_ARCH_SERVAL */
#if defined(VTSS_ARCH_LUTON26)
    case VTSS_TARGET_SPARX_III_10_UM:
    case VTSS_TARGET_SPARX_III_17_UM:
    case VTSS_TARGET_SPARX_III_25_UM:
    case VTSS_TARGET_SPARX_III_10:
    case VTSS_TARGET_SPARX_III_18:
    case VTSS_TARGET_SPARX_III_24:
    case VTSS_TARGET_SPARX_III_26:
    case VTSS_TARGET_SPARX_III_10_01:
    case VTSS_TARGET_CARACAL_1:
    case VTSS_TARGET_CARACAL_2:
        arch = VTSS_ARCH_L26;
        VTSS_RC(vtss_luton26_inst_create(vtss_state));
        break;
#endif /* VTSS_ARCH_LUTON26 */
#if defined(VTSS_ARCH_LUTON28)
    case VTSS_TARGET_SPARX_II_16:
    case VTSS_TARGET_SPARX_II_24:
    case VTSS_TARGET_E_STAX_34:
        arch = VTSS_ARCH_L28;
        VTSS_RC(vtss_luton28_inst_create(vtss_state));
        break;
#endif /* VTSS_ARCH_LUTON28 */
#if defined(VTSS_ARCH_B2)
    case VTSS_TARGET_BARRINGTON_II:
    case VTSS_TARGET_SCHAUMBURG_II:
    case VTSS_TARGET_EXEC_1:
        arch = VTSS_ARCH_BR2;
        VTSS_RC(vtss_b2_inst_create(vtss_state));
        break;
#endif /* VTSS_ARCH_B2 */
#if defined(VTSS_ARCH_DAYTONA)
    case VTSS_TARGET_DAYTONA:
    case VTSS_TARGET_TALLADEGA:
        VTSS_RC(vtss_daytona_inst_create(vtss_state));
        arch = VTSS_ARCH_DAYT;
        VTSS_D("daytona inst create");
        break;
#endif /* VTSS_ARCH_B2 */
#if defined(VTSS_ARCH_JAGUAR_1)
    case VTSS_TARGET_E_STAX_III_24_DUAL:
    case VTSS_TARGET_E_STAX_III_68_DUAL:
        /* Dual device targets */
        vtss_state->chip_count = 2;
        /* FALLTHROUGH */
    case VTSS_TARGET_JAGUAR_1:
    case VTSS_TARGET_LYNX_1:
    case VTSS_TARGET_CE_MAX_24:
    case VTSS_TARGET_CE_MAX_12:
    case VTSS_TARGET_E_STAX_III_48:
    case VTSS_TARGET_E_STAX_III_68:
        arch = VTSS_ARCH_JR1;
        VTSS_RC(vtss_jaguar1_inst_create(vtss_state));
        break;
#endif /* VTSS_ARCH_JAGUAR_1 */
#if defined(VTSS_ARCH_JAGUAR_2)
    case VTSS_TARGET_JAGUAR_2:
        arch = VTSS_ARCH_JR2;
        VTSS_RC(vtss_jaguar2_inst_create(vtss_state));
        break;
#endif /* VTSS_ARCH_JAGUAR_2 */
    default:
        VTSS_E("unknown target: 0x%05x", create->target);
        return VTSS_RC_ERROR;
    }

    vtss_state->arch = arch;

    /* Set default configuration */
    VTSS_RC(vtss_inst_default_set(vtss_state));

#if defined(VTSS_FEATURE_MISC)
    VTSS_RC(vtss_misc_inst_create(vtss_state));
#endif /* VTSS_FEATURE_MISC */

#if defined(VTSS_FEATURE_PORT_CONTROL)
    VTSS_RC(vtss_port_inst_create(vtss_state));
#endif /* VTSS_FEATURE_PORT_CONTROL */

#if defined(VTSS_FEATURE_PACKET)
    VTSS_RC(vtss_packet_inst_create(vtss_state));
#endif /* VTSS_FEATURE_PACKET */

#if defined(VTSS_FEATURE_QOS)
    VTSS_RC(vtss_qos_inst_create(vtss_state));
#endif /* VTSS_FEATURE_QOS */

#if defined(VTSS_FEATURE_LAYER2)
    VTSS_RC(vtss_l2_inst_create(vtss_state));
#endif /* VTSS_FEATURE_LAYER2 */

#if defined(VTSS_FEATURE_VCAP)
    VTSS_RC(vtss_vcap_inst_create(vtss_state));
#endif /* VTSS_FEATURE_VCAP */

#if defined(VTSS_FEATURE_EVC)
    VTSS_RC(vtss_evc_inst_create(vtss_state));
#endif /* VTSS_FEATURE_EVC */

#if defined(VTSS_FEATURE_OAM)
    VTSS_RC(vtss_oam_inst_create(vtss_state));
#endif /* VTSS_FEATURE_OAM */

#if defined(VTSS_FEATURE_MPLS)
    VTSS_RC(vtss_mpls_inst_create(vtss_state));
#endif /* VTSS_FEATURE_MPLS */

#if defined(VTSS_FEATURE_TIMESTAMP)
    VTSS_RC(vtss_ts_inst_create(vtss_state));
#endif /* VTSS_FEATURE_TIMESTAMP */

#if defined(VTSS_CHIP_10G_PHY)
    VTSS_RC(vtss_phy_10g_inst_venice_create(vtss_state));
#endif /* VTSS_CHIP_10G_PHY */

    /* Setup default instance */
    if (vtss_default_inst == NULL)
        vtss_default_inst = vtss_state;

    /* Return instance to application */
    if (inst != NULL)
        *inst = vtss_state;

    VTSS_D("exit");

    return VTSS_RC_OK;
}

vtss_rc vtss_inst_destroy(const vtss_inst_t inst)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_D("enter");
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        if (vtss_state == vtss_default_inst)
            vtss_default_inst = NULL;
        VTSS_OS_FREE(vtss_state, VTSS_MEM_FLAGS_NONE);
    }
    VTSS_D("exit");

    return rc;
}

/* Get initialization configuration */
vtss_rc vtss_init_conf_get(const vtss_inst_t        inst,
                           vtss_init_conf_t * const conf)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_D("enter");
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK)
        *conf = vtss_state->init_conf;
    VTSS_D("exit");

    return rc;
}

/* Set initialization configuration */
vtss_rc vtss_init_conf_set(const vtss_inst_t              inst,
                           const vtss_init_conf_t * const conf)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_D("enter");
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        vtss_state->init_conf = *conf;
        if (vtss_state->create.target != VTSS_TARGET_CU_PHY &&
            vtss_state->create.target != VTSS_TARGET_10G_PHY) {
            rc = VTSS_FUNC_0(cil.init_conf_set);
        } 
#if defined(VTSS_CHIP_CU_PHY)
        if (rc == VTSS_RC_OK)
            rc = vtss_phy_init_conf_set(vtss_state);
#endif /* VTSS_CHIP_CU_PHY */
#if defined(VTSS_CHIP_10G_PHY)
        if (rc == VTSS_RC_OK)
            rc = vtss_phy_10g_init_conf_set(vtss_state);
#endif /* VTSS_CHIP_10G_PHY */
#if defined(VTSS_FEATURE_FDMA) && VTSS_OPT_FDMA
        if (rc == VTSS_RC_OK) {
        if (vtss_state->create.target != VTSS_TARGET_CU_PHY &&
            vtss_state->create.target != VTSS_TARGET_10G_PHY) {
            rc = vtss_fdma_cmn_init_conf_set(vtss_state);
        }
        }
#endif /* defined(VTSS_FEATURE_FDMA) && VTSS_OPT_FDMA */
        vtss_state->warm_start_prev = vtss_state->warm_start_cur;
    } else {
        VTSS_E("Initialization check failed");
    }
    VTSS_D("exit");

    return rc;
}

/* ================================================================= *
 *  Miscellaneous
 * ================================================================= */

/* Get trace configuration */
vtss_rc vtss_trace_conf_get(const vtss_trace_group_t group,
                            vtss_trace_conf_t * const conf)
{
    if (group >= VTSS_TRACE_GROUP_COUNT) {
        VTSS_E("illegal group: %d", group);
        return VTSS_RC_ERROR;
    }

    *conf = vtss_trace_conf[group];
    return VTSS_RC_OK;
}

/* Set trace configuration */
vtss_rc vtss_trace_conf_set(const vtss_trace_group_t group,
                            const vtss_trace_conf_t * const conf)
{
    if (group >= VTSS_TRACE_GROUP_COUNT) {
        VTSS_E("illegal group: %d", group);
        return VTSS_RC_ERROR;
    }

    vtss_trace_conf[group] = *conf;
    return VTSS_RC_OK;
}

const char *vtss_port_if_txt(vtss_port_interface_t if_type)
{
    switch (if_type) {
    case VTSS_PORT_INTERFACE_NO_CONNECTION: return "N/C";
    case VTSS_PORT_INTERFACE_LOOPBACK:      return "LOOPBACK";
    case VTSS_PORT_INTERFACE_INTERNAL:      return "INTERNAL";
    case VTSS_PORT_INTERFACE_MII:           return "MII";
    case VTSS_PORT_INTERFACE_GMII:          return "GMII";
    case VTSS_PORT_INTERFACE_RGMII:         return "RGMII";
    case VTSS_PORT_INTERFACE_TBI:           return "TBI";
    case VTSS_PORT_INTERFACE_RTBI:          return "RTBI";
    case VTSS_PORT_INTERFACE_SGMII:         return "SGMII";
    case VTSS_PORT_INTERFACE_SERDES:        return "SERDES";
    case VTSS_PORT_INTERFACE_VAUI:          return "VAUI";
    case VTSS_PORT_INTERFACE_100FX:         return "100FX";
    case VTSS_PORT_INTERFACE_XAUI:          return "XAUI";
    case VTSS_PORT_INTERFACE_RXAUI:         return "RXAUI";
    case VTSS_PORT_INTERFACE_XGMII:         return "XGMII";
    case VTSS_PORT_INTERFACE_SPI4:          return "SPI4";
    case VTSS_PORT_INTERFACE_SGMII_CISCO:   return "SGMII_CISCO";
    case VTSS_PORT_INTERFACE_QSGMII:        return "QSGMII";
    }
    return "?   ";
}

/* - API tod functions -------------------------------------- */

/*
 * If an external ns read function must be called, this variable holds a pointer
 * to the function, otherwise it is NULL.
 */
static tod_get_ns_cnt_cb_t hw_get_ns_callout = 0;

void vtss_tod_set_ns_cnt_cb(tod_get_ns_cnt_cb_t cb) 
{
    hw_get_ns_callout = cb;
}

/**
 * \brief Get the current hw nanosec time
 *  Because this function can be called from interrupt and/or with interrupt disabled,
 *  the normal VTSS_ENTER macro is not used, neither is the VTSS_FUNC used, because it copies
 *  an instance pointer to a global variable.
 *  Therefore the CIL layer function is called via the default_inst pointer.
 *
 * \returns actual ns counter
 */
u32 vtss_tod_get_ns_cnt(void) 
{
    if (hw_get_ns_callout) {
        return hw_get_ns_callout();
#if defined(VTSS_FEATURE_TIMESTAMP)
    } else if (vtss_default_inst->ts.ns_cnt_get){
        return vtss_default_inst->ts.ns_cnt_get(vtss_default_inst);
#endif
    } else {
        return 0; /* currently no HW support */
    }
}

/* - API SYNCE functions -------------------------------------- */

#if defined(VTSS_FEATURE_SYNCE)
#define clk_port_inx ((clk_port == VTSS_SYNCE_CLK_A) ? 0 : 1)
/* Set the configuration of a selected output clock port - against external clock controller. */
vtss_rc vtss_synce_clock_out_set(const vtss_inst_t              inst,
                                 const vtss_synce_clk_port_t    clk_port,
                                 const vtss_synce_clock_out_t   *const conf)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        if ((clk_port == VTSS_SYNCE_CLK_A) || (clk_port == VTSS_SYNCE_CLK_B)) {
            vtss_state->synce.out_conf[clk_port_inx] = *conf;
            rc = VTSS_FUNC_COLD(synce.clock_out_set, clk_port_inx);
        }
        else    rc = VTSS_RC_ERROR;
    }
    VTSS_EXIT();
    return rc;
}

/* Get the configuration of a selected output clock port - against external clock controller. */
vtss_rc vtss_synce_clock_out_get(const vtss_inst_t            inst,
                                 const vtss_synce_clk_port_t  clk_port,
                                 vtss_synce_clock_out_t       *const conf)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        if ((clk_port == VTSS_SYNCE_CLK_A) || (clk_port == VTSS_SYNCE_CLK_B))
            *conf = vtss_state->synce.out_conf[clk_port_inx];
        else    rc = VTSS_RC_ERROR;
    }
    VTSS_EXIT();
    return rc;
}

/* Set the configuration of input port for a selected output clock port */
vtss_rc vtss_synce_clock_in_set(const vtss_inst_t              inst,
                                const vtss_synce_clk_port_t    clk_port,
                                const vtss_synce_clock_in_t    *const conf)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        if ((clk_port == VTSS_SYNCE_CLK_A) || (clk_port == VTSS_SYNCE_CLK_B)) {
            vtss_state->synce.in_conf[clk_port_inx] = *conf;
            rc = VTSS_FUNC_COLD(synce.clock_in_set, clk_port_inx);
        }
        else    rc = VTSS_RC_ERROR;
    }
    VTSS_EXIT();
    return rc;
}

/* Get the configuration of input port for a selected output clock port */
vtss_rc vtss_synce_clock_in_get(const vtss_inst_t            inst,
                                const vtss_synce_clk_port_t  clk_port,
                                vtss_synce_clock_in_t        *const conf)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        if ((clk_port == VTSS_SYNCE_CLK_A) || (clk_port == VTSS_SYNCE_CLK_B))
            *conf = vtss_state->synce.in_conf[clk_port_inx];
        else    rc = VTSS_RC_ERROR;
    }
    VTSS_EXIT();
    return rc;
}
#endif /* VTSS_FEATURE_SYNCE */

/* - Warm start functions -------------------------------------- */
#if defined(VTSS_FEATURE_WARM_START)
static vtss_rc vtss_restart_sync(vtss_state_t *vtss_state)
{
#ifndef VTSS_ARCH_DAYTONA
    vtss_port_no_t port_no;

    for (port_no = VTSS_PORT_NO_START; port_no < vtss_state->port_count; port_no++) {
#if defined(VTSS_CHIP_CU_PHY)
        VTSS_RC(vtss_phy_sync(vtss_state, port_no));
#endif /* VTSS_CHIP_CU_PHY */
#if defined(VTSS_CHIP_10G_PHY)
        VTSS_RC(vtss_phy_10g_sync(vtss_state, port_no));
#if defined(VTSS_FEATURE_WIS)
        VTSS_RC(vtss_phy_ewis_sync(vtss_state, port_no));
#endif /* VTSS_FEATURE_WIS */
#endif /* VTSS_CHIP_10G_PHY */
#if defined(VTSS_CHIP_CU_PHY) || defined(VTSS_CHIP_10G_PHY)
#if defined (VTSS_FEATURE_PHY_TIMESTAMP)
        //VTSS_RC(vtss_phy_ts_sync(vtss_state, port_no)); BZ #10559/10560, do not call until fixed 
#endif /* VTSS_FEATURE_PHY_TIMESTAMP */
#endif /* VTSS_CHIP_CU_PHY || VTSS_CHIP_10G_PHY*/
    }
    if (vtss_state->create.target == VTSS_TARGET_CU_PHY ||
        vtss_state->create.target == VTSS_TARGET_10G_PHY) {
        return VTSS_RC_OK;
    }

#if defined(VTSS_FEATURE_PORT_CONTROL)
    VTSS_RC(vtss_port_restart_sync(vtss_state));
#endif /* VTSS_FEATURE_PORT_CONTROL */

#if defined(VTSS_FEATURE_QOS)
    VTSS_RC(vtss_qos_restart_sync(vtss_state));
#endif /* VTSS_FEATURE_QOS */

#if defined(VTSS_FEATURE_LAYER2)
    VTSS_RC(vtss_l2_restart_sync(vtss_state));
#endif /* VTSS_FEATURE_LAYER2 */

#if defined(VTSS_FEATURE_EVC)
    VTSS_RC(vtss_evc_restart_sync(vtss_state));
#endif /* VTSS_FEATURE_EVC */

#if defined(VTSS_FEATURE_VCAP)
    VTSS_RC(vtss_vcap_restart_sync(vtss_state));
#endif /* VTSS_FEATURE_VCAP */

#endif /* VTSS_ARCH_DAYTONA */
    return VTSS_RC_OK;
}

static vtss_rc vtss_restart_cur_set(vtss_state_t *vtss_state, const vtss_restart_t restart)
{
    vtss_rc rc = VTSS_RC_OK;
    
    vtss_state->restart_cur = restart;

    if (vtss_state->create.target != VTSS_TARGET_CU_PHY &&
        vtss_state->create.target != VTSS_TARGET_10G_PHY) {
        rc = VTSS_FUNC_0(cil.restart_conf_set);
    }
#if defined(VTSS_CHIP_CU_PHY)
    if (rc == VTSS_RC_OK)
        rc = vtss_phy_restart_conf_set(vtss_state);
#endif /* VTSS_CHIP_CU_PHY */
#if defined(VTSS_CHIP_10G_PHY)
    if (rc == VTSS_RC_OK)
        rc = vtss_phy_10g_restart_conf_set(vtss_state);
#endif /* VTSS_CHIP_10G_PHY */
    return rc;
}

vtss_rc vtss_restart_conf_end(const vtss_inst_t inst)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        if (vtss_state->warm_start_cur) {
            /* Leave warm start mode */
            vtss_state->warm_start_cur = 0;

            /* Apply configuration */
            VTSS_I("warm start sync start");
            rc = vtss_restart_sync(vtss_state);
            VTSS_I("warm start sync done");
        } else {
            VTSS_I("cold/cool start end");
        }
        /* Next restart is warm */
        rc = vtss_restart_cur_set(vtss_state, VTSS_RESTART_WARM);
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_restart_status_get(const vtss_inst_t inst,
                                vtss_restart_status_t *const status)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        status->restart = vtss_state->restart_prev;
        status->prev_version = vtss_state->version_prev;
        status->cur_version = vtss_state->version_cur;
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_restart_conf_get(const vtss_inst_t inst,
                              vtss_restart_t *const restart)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        *restart = vtss_state->restart_cur;
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_restart_conf_set(const vtss_inst_t inst,
                              const vtss_restart_t restart)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK &&
        vtss_state->warm_start_cur == 0) {
        rc = vtss_restart_cur_set(vtss_state, restart);
    }
    VTSS_EXIT();

    return rc;
}
#endif /* VTSS_FEATURE_WARM_START */

#if defined(VTSS_ARCH_JAGUAR_1)
vtss_rc vtss_qs_conf_set(const vtss_inst_t inst, 
                         const vtss_qs_conf_t *const qs)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        vtss_state->init_conf.qs_conf = *qs;
        rc = VTSS_FUNC(cil.qs_conf_set);
    }
    VTSS_EXIT();

    return rc;
}
vtss_rc vtss_qs_conf_get(const vtss_inst_t inst, 
                         vtss_qs_conf_t *const qs)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        *qs = vtss_state->init_conf.qs_conf;
    }
    VTSS_EXIT();

    return rc;
}
#endif /* VTSS_ARCH_JAGUAR_1 */

/* - Daytona misc functions ------------------------------- */
#ifdef VTSS_ARCH_DAYTONA
vtss_rc vtss_interrupt_enable_set(const vtss_inst_t             inst,
                                  const vtss_interrupt_block_t  *const blocks)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        rc = VTSS_FUNC(cil.interrupt_enable_set, blocks);
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_interrupt_enable_get(const vtss_inst_t       inst,
                                  vtss_interrupt_block_t  *const blocks)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        rc = VTSS_FUNC(cil.interrupt_enable_get, blocks);
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_interrupt_status_get(const vtss_inst_t        inst,
                                  vtss_interrupt_block_t   *const status)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        rc = VTSS_FUNC(cil.interrupt_status_get, status);
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_pmtick_set(const vtss_inst_t     inst,
                        const vtss_port_no_t port_no,
                        const vtss_pmtick_control_t *const control)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        rc = VTSS_FUNC(cil.pmtick_enable_set, port_no, control);
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_channel_mode_set(const vtss_inst_t inst,
                              const u16 channel,
                              const vtss_config_mode_t conf_mode,
                              const u32 two_lane_upi)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        rc = VTSS_FUNC(cil.channel_mode_set, channel, conf_mode, two_lane_upi);
    }
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_fast_regs_conf_get(const vtss_inst_t inst,
                                u32 *const reg_addr)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK) {
        (void)VTSS_FUNC(cil.fast_regs_conf_get, reg_addr);
    }
    VTSS_EXIT();

    return rc;
}
#endif /* VTSS_ARCH_DAYTONA */


/* - Debug information functions ------------------------------- */

vtss_rc vtss_debug_info_get(vtss_debug_info_t *const info)
{
    vtss_port_no_t port_no;

    memset(info, 0, sizeof(*info));
    info->chip_no = VTSS_CHIP_NO_ALL;
    for (port_no = VTSS_PORT_NO_START; port_no < VTSS_PORT_NO_END; port_no++)
        info->port_list[port_no] = 1;
    return VTSS_RC_OK;
}

vtss_rc vtss_debug_info_print(const vtss_inst_t         inst,
                              const vtss_debug_printf_t pr,
                              const vtss_debug_info_t   *const info)
{
    vtss_state_t *vtss_state;
    vtss_rc      rc;

    VTSS_ENTER();
    if ((rc = vtss_inst_check(inst, &vtss_state)) == VTSS_RC_OK)
        rc = vtss_cmn_debug_info_print(vtss_state, pr, info);
    VTSS_EXIT();

    return rc;
}

vtss_rc vtss_debug_reg_check_set(const vtss_inst_t inst,
                                 const BOOL        enable)
{
    vtss_state_t *state = vtss_inst_check_no_persist(inst);

    if (state == NULL || state != vtss_default_inst) {
        VTSS_EG(VTSS_TRACE_GROUP_REG_CHECK, "Register checking is only supported when only one instance of the API is instantiated.");
        return VTSS_RC_ERROR;
    }

    return vtss_cmn_debug_reg_check_set(state, enable);
}

