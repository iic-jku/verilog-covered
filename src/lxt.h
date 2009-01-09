#ifndef __LXT_H__
#define __LXT_H__

/*
 Copyright (c) 2006-2009 Trevor Williams

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with this program;
 if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/*!
 \file     lxt.h
 \author   Trevor Williams  (phase1geo@gmail.com)
 \date     1/25/2006
 \brief    Contains functions for LXT parsing/simulation
*/


/*! \brief  Parses and scores LXT-style dumpfile */
void lxt_parse(
  const char* lxt_file
);


/*
 $Log$
 Revision 1.5  2009/01/09 21:25:01  phase1geo
 More generate block fixes.  Updated all copyright information source code files
 for the year 2009.  Checkpointing.

 Revision 1.4  2008/03/11 22:06:48  phase1geo
 Finishing first round of exception handling code.

 Revision 1.3  2007/11/20 05:28:58  phase1geo
 Updating e-mail address from trevorw@charter.net to phase1geo@gmail.com.

 Revision 1.2  2006/03/28 22:28:27  phase1geo
 Updates to user guide and added copyright information to each source file in the
 src directory.  Added test directory in user documentation directory containing the
 example used in line, toggle, combinational logic and FSM descriptions.

 Revision 1.1  2006/01/26 17:34:04  phase1geo
 Finished work on lxt2_read.c and fixed bug in LXT-based simulator.  Also adding
 missing lxt.h header file.

*/

#endif

