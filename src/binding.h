#ifndef __BINDING_H__
#define __BINDING_H__

/*!
 \file     binding.h
 \author   Trevor Williams  (trevorw@charter.net)
 \date     3/4/2002
 \brief    Contains all functions for signal/expression binding.
*/

#include "defines.h"


//! Adds signal and expression to binding list.
void bind_add( char* sig_name, expression* exp, module* mod );

//! Removes the expression with ID of id from binding list.
void bind_remove( int id );

//! Finds signal in module and bind the expression to this signal.
void bind_perform( char* sig_name, expression* exp, module* mod_sig, module* mod_exp, bool implicit_allowed );

//! Performs signal/expression bind (performed after parse completed).
void bind();

/* $Log$
/* Revision 1.5  2002/10/11 04:24:01  phase1geo
/* This checkin represents some major code renovation in the score command to
/* fully accommodate parameter support.  All parameter support is in at this
/* point and the most commonly used parameter usages have been verified.  Some
/* bugs were fixed in handling default values of constants and expression tree
/* resizing has been optimized to its fullest.  Full regression has been
/* updated and passes.  Adding new diagnostics to test suite.  Fixed a few
/* problems in report outputting.
/*
/* Revision 1.4  2002/07/20 22:22:52  phase1geo
/* Added ability to create implicit signals for local signals.  Added implicit1.v
/* diagnostic to test for correctness.  Full regression passes.  Other tweaks to
/* output information.
/*
/* Revision 1.3  2002/07/18 22:02:35  phase1geo
/* In the middle of making improvements/fixes to the expression/signal
/* binding phase.
/* */

#endif

