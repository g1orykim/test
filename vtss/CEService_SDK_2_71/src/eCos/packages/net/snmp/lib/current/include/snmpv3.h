//==========================================================================
//
//      ./lib/current/include/snmpv3.h
//
//
//==========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//####UCDSNMPCOPYRIGHTBEGIN####
//
// -------------------------------------------
//
// Portions of this software may have been derived from the UCD-SNMP
// project,  <http://ucd-snmp.ucdavis.edu/>  from the University of
// California at Davis, which was originally based on the Carnegie Mellon
// University SNMP implementation.  Portions of this software are therefore
// covered by the appropriate copyright disclaimers included herein.
//
// The release used was version 4.1.2 of May 2000.  "ucd-snmp-4.1.2"
// -------------------------------------------
//
//####UCDSNMPCOPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    hmt
// Contributors: hmt
// Date:         2000-05-30
// Purpose:      Port of UCD-SNMP distribution to eCos.
// Description:  
//              
//
//####DESCRIPTIONEND####
//
//==========================================================================
/********************************************************************
       Copyright 1989, 1991, 1992 by Carnegie Mellon University

			  Derivative Work -
Copyright 1996, 1998, 1999, 2000 The Regents of the University of California

			 All Rights Reserved

Permission to use, copy, modify and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appears in all copies and
that both that copyright notice and this permission notice appear in
supporting documentation, and that the name of CMU and The Regents of
the University of California not be used in advertising or publicity
pertaining to distribution of the software without specific written
permission.

CMU AND THE REGENTS OF THE UNIVERSITY OF CALIFORNIA DISCLAIM ALL
WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL CMU OR
THE REGENTS OF THE UNIVERSITY OF CALIFORNIA BE LIABLE FOR ANY SPECIAL,
INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
FROM THE LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*********************************************************************/
/*
 * snmpv3.h
 */

#ifndef SNMPV3_H
#define SNMPV3_H

#ifdef __cplusplus
extern "C" {
#endif

/* peter, 2007/12, The format of 'Engine ID' is restricted to 5 - 32 octet string
#define MAX_ENGINEID_LENGTH 128 */
#define MAX_ENGINEID_LENGTH 32

int     setup_engineID(u_char **eidp, const char *text);
void    engineID_conf(const char *word, char *cptr);
void    engineBoots_conf(const char *, char *);
void    snmpv3_authtype_conf(const char *word, char *cptr);
void    snmpv3_privtype_conf(const char *word, char *cptr);
void	usm_parse_create_usmUser(const char *token, char *line);
void    init_snmpv3(const char *);
int	init_snmpv3_post_config(int majorid, int minorid, void *serverarg,
                                void *clientarg);
void    shutdown_snmpv3(const char *type);
int     snmpv3_store(int majorID, int minorID, void *serverarg,
                     void *clientarg);
u_long  snmpv3_local_snmpEngineBoots(void);
int     snmpv3_clone_engineID(u_char **, size_t* , u_char*, size_t);
int     snmpv3_get_engineID(u_char *buf, size_t buflen);
u_char *snmpv3_generate_engineID(int *);
u_long  snmpv3_local_snmpEngineTime(void);
int     get_default_secLevel(void);
oid    *get_default_authtype(size_t *);
oid    *get_default_privtype(size_t *);
void    snmpv3_set_engineBootsAndTime(int boots, int ttime); 

/* peter, 2007/12 add new function for configure SNMP modlue */
int SnmpdSetEngineId(const char *engine_id, int len);

#ifdef __cplusplus
}
#endif

#endif /* SNMPV3_H */
