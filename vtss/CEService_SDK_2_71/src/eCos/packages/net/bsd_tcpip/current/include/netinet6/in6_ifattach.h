//==========================================================================
//
//      include/netinet6/in6_ifattach.h
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

/*	$KAME: in6_ifattach.h,v 1.16 2001/08/31 05:13:40 jinmei Exp $	*/

/*
 * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _NETINET6_IN6_IFATTACH_H_
#define _NETINET6_IN6_IFATTACH_H_

#ifdef _KERNEL
void in6_nigroup_attach __P((const char *, int));
void in6_nigroup_detach __P((const char *, int));
void in6_ifattach __P((struct ifnet *, struct ifnet *));
void in6_ifdetach __P((struct ifnet *));
int in6_get_tmpifid __P((struct ifnet *, u_int8_t *, const u_int8_t *, int));
void in6_tmpaddrtimer __P((void *));
int in6_nigroup __P((struct ifnet *, const char *, int, struct in6_addr *));
#ifndef	VTSS_IP6_IMPL
#define VTSS_IP6_IMPL       1
#endif /* VTSS_IP6_IMPL */
#if (defined(VTSS_IP6_IMPL) && VTSS_IP6_IMPL) /* BSD-8.2 */
int get_hw_ifid __P((struct ifnet *, struct in6_addr *));
#endif /* VTSS_IP6_IMPL: BSD-8.2 */
#ifdef MIP6
int get_ifid __P((struct ifnet *, struct ifnet *, struct in6_addr *));
#endif /* MIP6 */
#endif /* _KERNEL */

#endif /* _NETINET6_IN6_IFATTACH_H_ */
