//==========================================================================
//
//      include/netinet/igmp_var.h
//
//==========================================================================
// ####BSDCOPYRIGHTBEGIN####                                    
// -------------------------------------------                  
// This file is part of eCos, the Embedded Configurable Operating System.
//
// Portions of this software may have been derived from FreeBSD 
// or other sources, and if so are covered by the appropriate copyright
// and license included herein.                                 
//
// Portions created by the Free Software Foundation are         
// Copyright (C) 2002 Free Software Foundation, Inc.            
// -------------------------------------------                  
// ####BSDCOPYRIGHTEND####                                      
//==========================================================================

/*
 * Copyright (c) 1988 Stephen Deering.
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Stephen Deering of Stanford University.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)igmp_var.h	8.1 (Berkeley) 7/19/93
 * $FreeBSD: src/sys/netinet/igmp_var.h,v 1.17 1999/12/29 04:40:59 peter Exp $
 */

#ifndef _NETINET_IGMP_VAR_H_
#define _NETINET_IGMP_VAR_H_

/*
 * Internet Group Management Protocol (IGMP),
 * implementation-specific definitions.
 *
 * Written by Steve Deering, Stanford, May 1988.
 *
 * MULTICAST Revision: 3.5.1.3
 */

#ifndef	VTSS_IP4_IMPL
#define VTSS_IP4_IMPL       1
#endif /* VTSS_IP4_IMPL */

struct igmpstat {
	u_int	igps_rcv_total;		/* total IGMP messages received */
	u_int	igps_rcv_tooshort;	/* received with too few bytes */
	u_int	igps_rcv_badsum;	/* received with bad checksum */
	u_int	igps_rcv_queries;	/* received membership queries */
	u_int	igps_rcv_badqueries;	/* received invalid queries */
	u_int	igps_rcv_reports;	/* received membership reports */
	u_int	igps_rcv_badreports;	/* received invalid reports */
	u_int	igps_rcv_ourreports;	/* received reports for our groups */
	u_int	igps_snd_reports;	/* sent membership reports */
#if (defined(VTSS_IP4_IMPL) && VTSS_IP4_IMPL)
	u_int   igmp_grp_cnt_ref;   /* current registered group count per system */
#endif /* VTSS_IP4_IMPL */
};

#ifdef _KERNEL
#define IGMP_RANDOM_DELAY(X) (random() % (X) + 1)

/*
 * States for IGMPv2's leave processing
 */
#define IGMP_OTHERMEMBER			0
#define IGMP_IREPORTEDLAST			1

/*
 * We must remember what version the subnet's querier is.
 * We conveniently use the IGMP message type for the proper
 * membership report to keep this state.
 */
#define IGMP_V1_ROUTER				IGMP_V1_MEMBERSHIP_REPORT
#define IGMP_V2_ROUTER				IGMP_V2_MEMBERSHIP_REPORT

/*
 * Revert to new router if we haven't heard from an old router in
 * this amount of time.
 */
#define IGMP_AGE_THRESHOLD			540

void	igmp_init __P((void));
void	igmp_input __P((struct mbuf *, int));
void	igmp_joingroup __P((struct in_multi *));
void	igmp_leavegroup __P((struct in_multi *));
void	igmp_fasttimo __P((void));
void	igmp_slowtimo __P((void));

SYSCTL_DECL(_net_inet_igmp);

#endif

/*
 * Names for IGMP sysctl objects
 */
#define IGMPCTL_STATS		1	/* statistics (read-only) */
#define IGMPCTL_MAXID		2

#if (defined(VTSS_IP4_IMPL) && VTSS_IP4_IMPL)
#define IGMP_MULTICAST_ADR  (INADDR_UNSPEC_GROUP)   /* 224.0.0.0 */
#define IGMP_MULTICAST_MSK  ((u_int32_t)0xF0000000) /* 4: 224.0.0.0/4 */

/* INC for each group join, per system */
#define IGMP_GRP_CNT_INC(x) do {    \
	(x).igmp_grp_cnt_ref++;         \
} while (0)

/* DEC for each group leave, per system */
#define IGMP_GRP_CNT_DEC(x) do {                        \
	if ((x).igmp_grp_cnt_ref) {                         \
		(x).igmp_grp_cnt_ref--;                         \
	} else {                                            \
		printf("Invalid IGMP group count reference\n"); \
	}                                                   \
} while (0)

/* INC for each group join, per interface */
#define INTF_GRP_CNT_INC(x) do {    \
	if ((x))                        \
		(x)->igmp_grp_cnt_ref++;    \
} while (0)

/* DEC for each group leave, per interface */
#define INTF_GRP_CNT_DEC(x) do {                        \
	if ((x) && (x)->igmp_grp_cnt_ref) {                 \
		(x)->igmp_grp_cnt_ref--;                        \
	} else {                                            \
		printf("Invalid INTF group count reference\n"); \
	}                                                   \
} while (0)

/* REF for current group registration count, per system */
#define IGMP_GRP_CNT_REF(x) ((x).igmp_grp_cnt_ref)
/* REG status for current group registration, per system */
#define IGMP_GRP_HAS_REG(x) (IGMP_GRP_CNT_REF((x)) > 0)

/* REF for current group registration count, per interface */
#define INTF_GRP_CNT_REF(x) ((x) ? (x)->igmp_grp_cnt_ref : 0)
/* REG status for current group registration, per interface */
#define INTF_GRP_HAS_REG(x) (INTF_GRP_CNT_REF((x)) > 0)
#endif /* VTSS_IP4_IMPL */

#define IGMPCTL_NAMES { \
	{ 0, 0 }, \
	{ "stats", CTLTYPE_STRUCT }, \
}
#endif
