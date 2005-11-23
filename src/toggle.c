/*!
 \file     toggle.c
 \author   Trevor Williams  (trevorw@charter.net)
 \date     3/31/2002
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <assert.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include "toggle.h"
#include "defines.h"
#include "vector.h"
#include "util.h"
#include "link.h"


extern funit_inst* instance_root;
extern funit_link* funit_head;

extern bool report_covered;
extern bool report_instance;
extern char leading_hierarchy[4096];
extern char second_hierarchy[4096];

/*!
 \param sigl   Pointer to signal list to search.
 \param total  Total number of bits in the design/functional unit.
 \param hit01  Number of bits toggling from 0 to 1 during simulation.
 \param hit10  Number of bits toggling from 1 to 0 during simulation.

 Searches specified expression list and signal list, gathering information 
 about toggled bits.  For each bit that is found in the design, the total
 value is incremented by one.  For each bit that toggled from a 0 to a 1,
 the value of hit01 is incremented by one.  For each bit that toggled from
 a 1 to a 0, the value of hit10 is incremented by one.
*/
void toggle_get_stats( sig_link* sigl, float* total, int* hit01, int* hit10 ) {

  sig_link* curr_sig = sigl;    /* Current signal being evaluated     */
  
  /* Search signal list */
  while( curr_sig != NULL ) {
    if( (curr_sig->sig->name[0] != '#') && (curr_sig->sig->value->suppl.part.mba == 0) ) {
      *total = *total + curr_sig->sig->value->width;
      vector_toggle_count( curr_sig->sig->value, hit01, hit10 );
    }
    curr_sig = curr_sig->next;
  }

}

bool toggle_collect( char* funit_name, int funit_type, int cov, expression*** sigs, int* sig_cnt ) {

  bool        retval = TRUE;  /* Return value for this function                 */
  func_unit   funit;          /* Functional unit used for searching             */
  funit_link* funitl;         /* Pointer to found functional unit link          */
  sig_link*   curr_sig;       /* Pointer to current signal link being evaluated */
  int         hit01;          /* Number of bits that toggled from 0 to 1        */
  int         hit10;          /* Number of bits that toggled from 1 to 0        */
  int         sig_size; 
  exp_link*   expl;           /* Pointer to expression linked list              */
     
  /* First, find functional unit in functional unit array */
  funit.name = funit_name;
  funit.type = funit_type;

  if( (funitl = funit_link_find( &funit, funit_head )) != NULL ) {

    /* Create an array that will hold the number of uncovered lines */
    sig_size = 20;
    *sig_cnt = 0;
    *sigs    = (expression**)malloc_safe( (sizeof( expression* ) * sig_size), __FILE__, __LINE__ );

    curr_sig = funitl->funit->sig_head;

    while( curr_sig != NULL ) {

      hit01 = 0;
      hit10 = 0;

      if( (curr_sig->sig->name[0] != '#') && (curr_sig->sig->value->suppl.part.mba == 0) ) {

        vector_toggle_count( curr_sig->sig->value, &hit01, &hit10 );

        if( ((cov == 1) && (hit01 == curr_sig->sig->value->width) && (hit10 == curr_sig->sig->value->width)) ||
	    ((cov == 0) && ((hit01 < curr_sig->sig->value->width) || (hit10 < curr_sig->sig->value->width))) ) {

          expl = curr_sig->sig->exp_head;
	  while( expl != NULL ) {
            if( expl->exp->line != 0 ) {	
              if( *sig_cnt == sig_size ) {
                sig_size += 20;
  	        *sigs    = (expression**)realloc( *sigs, (sizeof( expression* ) * sig_size) );
              }
              (*sigs)[(*sig_cnt)] = expl->exp;
              (*sig_cnt)++;
	    } 
	    expl = expl->next; 
	  } 
          
        }

      }

      curr_sig = curr_sig->next;

    }

  } else {
 
    retval = FALSE;

  }

  return( retval );

}

bool toggle_get_coverage( char* funit_name, int funit_type, char* sig_name, int* msb, int* lsb, char** tog01, char** tog10 ) {

  bool        retval = TRUE;  /* Return value for this function        */
  func_unit   funit;          /* Functional unit used for searching    */
  funit_link* funitl;         /* Pointer to found functional unit link */
  vsignal     sig;            /* Signal used for searching             */
  sig_link*   sigl;           /* Pointer to found signal link          */

  funit.name = funit_name;
  funit.type = funit_type;

  if( (funitl = funit_link_find( &funit, funit_head )) != NULL ) {

    sig.name = sig_name;

    if( (sigl = sig_link_find( &sig, funitl->funit->sig_head )) != NULL ) {
      *msb = sigl->sig->lsb + (sigl->sig->value->width - 1);
      *lsb = sigl->sig->lsb; 
      *tog01 = vector_get_toggle01( sigl->sig->value->value, sigl->sig->value->width );
      *tog10 = vector_get_toggle10( sigl->sig->value->value, sigl->sig->value->width );
    } else {
      retval = FALSE;
    }

  } else {

    retval = FALSE;

  }

  return( retval );

}

/*!
 \param funit_name  Name of functional unit to retrieve summary information from.
 \param funit_type  Type of functional unit to retrieve summary information from.
 \param total       Pointer to total number of toggles in this functional unit.
 \param hit01       Pointer to number of toggles hit going 0 -> 1 in this functional unit.
 \param hit10       Pointer to number of toggles hit going 1 -> 0 in this functional unit.

 \return Returns TRUE if specified functional unit was found in design; otherwise,
         returns FALSE.

 Looks up summary information for specified functional unit.  If the functional unit was found,
 the hit and total values for this functional unit are returned to the calling function.
 If the functional unit was not found, a value of FALSE is returned to the calling
 function, indicating that the functional unit was not found in the design and the values
 of total and hit should not be used.
*/
bool toggle_get_funit_summary( char* funit_name, int funit_type, int* total, int* hit01, int* hit10 ) {

  bool        retval = TRUE;  /* Return value for this function        */
  func_unit   funit;          /* Functional unit used for searching    */
  funit_link* funitl;         /* Pointer to found functional unit link */
  char        tmp[21];        /* Temporary string for total            */

  funit.name = funit_name;
  funit.type = funit_type;

  if( (funitl = funit_link_find( &funit, funit_head )) != NULL ) {

    snprintf( tmp, 21, "%20.0f", funitl->funit->stat->tog_total );
    assert( sscanf( tmp, "%d", total ) == 1 );
    *hit01 = funitl->funit->stat->tog01_hit;
    *hit10 = funitl->funit->stat->tog10_hit;

  } else {

    retval = FALSE;

  }

  return( retval );

}

/*!
 \param ofile        File to output coverage information to.
 \param root         Instance node in the functional unit instance tree being evaluated.
 \param parent_inst  Name of parent instance.

 \return Returns TRUE if any bits were found to be not toggled; otherwise, returns FALSE.

 Displays the toggle instance summarization to the specified file.  Recursively
 iterates through functional unit instance tree, outputting the toggle information that
 is found at that instance.
*/
bool toggle_instance_summary( FILE* ofile, funit_inst* root, char* parent_inst ) {

  funit_inst* curr;           /* Pointer to current child functional unit instance of this node */
  float       percent01;      /* Percentage of bits toggling from 0 -> 1               */
  float       percent10;      /* Percentage of bits toggling from 1 -> 0               */
  float       miss01;         /* Number of bits that did not toggle from 0 -> 1        */
  float       miss10;         /* Number of bits that did not toggle from 1 -> 0        */
  char        tmpname[4096];  /* Temporary name holder for instance                    */

  assert( root != NULL );
  assert( root->stat != NULL );

  /* Calculate for toggle01 information */
  if( root->stat->tog_total == 0 ) {
    percent01 = 100;
  } else {
    percent01 = ((root->stat->tog01_hit / root->stat->tog_total) * 100);
  }
  miss01    = (root->stat->tog_total - root->stat->tog01_hit);

  /* Calculate for toggle10 information */
  if( root->stat->tog_total == 0 ) {
    percent10 = 100;
  } else {
    percent10 = ((root->stat->tog10_hit / root->stat->tog_total) * 100);
  }
  miss10    = (root->stat->tog_total - root->stat->tog10_hit);

  if( strcmp( parent_inst, "*" ) == 0 ) {
    strcpy( tmpname, root->name );
  } else {
    snprintf( tmpname, 4096, "%s.%s", parent_inst, root->name );
  }

  fprintf( ofile, "  %-43.43s    %5d/%5.0f/%5.0f      %3.0f%%         %5d/%5.0f/%5.0f      %3.0f%%\n",
           tmpname,
           root->stat->tog01_hit,
           miss01,
           root->stat->tog_total,
           percent01,
           root->stat->tog10_hit,
           miss10,
           root->stat->tog_total,
           percent10 );

  curr = root->child_head;
  while( curr != NULL ) {
    miss01 = miss01 + toggle_instance_summary( ofile, curr, tmpname );
    curr = curr->next;
  }

  return( (miss01 > 0) || (miss10 > 0) );

}

/*!
 \param ofile  Pointer to file to display coverage results to.
 \param head   Pointer to head of functional unit list to parse.

 \return Returns TRUE if any bits were found to be untoggled; otherwise, returns FALSE.

 Iterates through the functional unit list displaying the toggle coverage for
 each functional unit.
*/
bool toggle_funit_summary( FILE* ofile, funit_link* head ) {

  float percent01;           /* Percentage of bits that toggled from 0 to 1    */
  float percent10;           /* Percentage of bits that toggled from 1 to 0    */
  float miss01;              /* Number of bits that did not toggle from 0 to 1 */
  float miss10;              /* Number of bits that did not toggle from 1 to 0 */
  float miss_found = FALSE;  /* Set to TRUE if missing toggles were found      */

  while( head != NULL ) {

    /* Calculate for toggle01 */
    if( head->funit->stat->tog_total == 0 ) {
      percent01 = 100;
    } else {
      percent01 = ((head->funit->stat->tog01_hit / head->funit->stat->tog_total) * 100);
    }
    miss01 = (head->funit->stat->tog_total - head->funit->stat->tog01_hit);

    /* Calculate for toggle10 */
    if( head->funit->stat->tog_total == 0 ) {
      percent10 = 100;
    } else {
      percent10 = ((head->funit->stat->tog10_hit / head->funit->stat->tog_total) * 100);
    }
    miss10 = (head->funit->stat->tog_total - head->funit->stat->tog10_hit);

    miss_found = ((miss01 > 0) || (miss10 > 0)) ? TRUE : miss_found;

    fprintf( ofile, "  %-20.20s    %-20.20s   %5d/%5.0f/%5.0f      %3.0f%%         %5d/%5.0f/%5.0f      %3.0f%%\n", 
             head->funit->name,
             get_basename( head->funit->filename ),
             head->funit->stat->tog01_hit,
             miss01,
             head->funit->stat->tog_total,
             percent01,
             head->funit->stat->tog10_hit,
             miss10,
             head->funit->stat->tog_total,
             percent10 );

    head = head->next;

  }

  return( miss_found );

}

/*!
 \param ofile  Pointer to file to output results to.
 \param sigl   Pointer to signal list head.

 Displays the signals that did not achieve 100% toggle coverage to standard 
 output from the specified signal list.
*/
void toggle_display_verbose( FILE* ofile, sig_link* sigl ) {

  sig_link* curr_sig;   /* Pointer to current signal link being evaluated */
  int       hit01;      /* Number of bits that toggled from 0 to 1        */
  int       hit10;      /* Number of bits that toggled from 1 to 0        */

  if( report_covered ) {
    fprintf( ofile, "    Signals getting 100%% toggle coverage\n\n" );
  } else {
    fprintf( ofile, "    Signals not getting 100%% toggle coverage\n\n" );
    fprintf( ofile, "      Signal                    Toggle\n" );
  }

  fprintf( ofile, "      ---------------------------------------------------------------------------------------------------------\n" );

  curr_sig = sigl;

  while( curr_sig != NULL ) {

    hit01 = 0;
    hit10 = 0;

    if( (curr_sig->sig->name[0] != '#') && (curr_sig->sig->value->suppl.part.mba == 0) ) {

      vector_toggle_count( curr_sig->sig->value, &hit01, &hit10 );

      if( report_covered ) {

        if( (hit01 == curr_sig->sig->value->width) && (hit10 == curr_sig->sig->value->width) ) {
        
          fprintf( ofile, "      %-24s\n", curr_sig->sig->name );

        }

      } else {

        if( (hit01 < curr_sig->sig->value->width) || (hit10 < curr_sig->sig->value->width) ) {

          fprintf( ofile, "      %-24s  0->1: ", curr_sig->sig->name );
          vector_display_toggle01( curr_sig->sig->value->value, curr_sig->sig->value->width, ofile );      
          fprintf( ofile, "\n      ......................... 1->0: " );
          vector_display_toggle10( curr_sig->sig->value->value, curr_sig->sig->value->width, ofile );      
          fprintf( ofile, " ...\n" );

        }

      }

    }

    curr_sig = curr_sig->next;

  }

}

/*!
 \param ofile        Pointer to file to display coverage results to.
 \param root         Pointer to root of instance functional unit tree to parse.
 \param parent_inst  Name of parent instance.

 Displays the verbose toggle coverage results to the specified output stream on
 an instance basis.  The verbose toggle coverage includes the signal names
 and their bits that did not receive 100% toggle coverage during simulation. 
*/
void toggle_instance_verbose( FILE* ofile, funit_inst* root, char* parent_inst ) {

  funit_inst* curr_inst;      /* Pointer to current instance being evaluated */
  char        tmpname[4096];  /* Temporary name holder of instance           */

  assert( root != NULL );

  if( strcmp( parent_inst, "*" ) == 0 ) {
    strcpy( tmpname, root->name );
  } else {
    snprintf( tmpname, 4096, "%s.%s", parent_inst, root->name );
  }

  if( (root->stat->tog01_hit < root->stat->tog_total) ||
      (root->stat->tog10_hit < root->stat->tog_total) ) {

    fprintf( ofile, "\n" );
    switch( root->funit->type ) {
      case FUNIT_MODULE      :  fprintf( ofile, "    Module: " );       break;
      case FUNIT_NAMED_BLOCK :  fprintf( ofile, "    Named Block: " );  break;
      case FUNIT_FUNCTION    :  fprintf( ofile, "    Function: " );     break;
      case FUNIT_TASK        :  fprintf( ofile, "    Task: " );         break;
      default                :  fprintf( ofile, "    UNKNOWN: " );      break;
    }
    fprintf( ofile, "%s, File: %s, Instance: %s\n", root->funit->name, root->funit->filename, tmpname );
    fprintf( ofile, "    -------------------------------------------------------------------------------------------------------------\n" );

    toggle_display_verbose( ofile, root->funit->sig_head );

  }

  curr_inst = root->child_head;
  while( curr_inst != NULL ) {
    toggle_instance_verbose( ofile, curr_inst, tmpname );
    curr_inst = curr_inst->next;
  }

}

/*!
 \param ofile  Pointer to file to display coverage results to.
 \param head   Pointer to head of functional unit list to parse.

 Displays the verbose toggle coverage results to the specified output stream on
 a functional unit basis (combining functional units that are instantiated multiple times).
 The verbose toggle coverage includes the signal names and their bits that
 did not receive 100% toggle coverage during simulation.
*/
void toggle_funit_verbose( FILE* ofile, funit_link* head ) {

  while( head != NULL ) {

    if( (head->funit->stat->tog01_hit < head->funit->stat->tog_total) ||
        (head->funit->stat->tog10_hit < head->funit->stat->tog_total) ) {

      fprintf( ofile, "\n" );
      switch( head->funit->type ) {
        case FUNIT_MODULE      :  fprintf( ofile, "    Module: " );       break;
        case FUNIT_NAMED_BLOCK :  fprintf( ofile, "    Named Block: " );  break;
        case FUNIT_FUNCTION    :  fprintf( ofile, "    Function: " );     break;
        case FUNIT_TASK        :  fprintf( ofile, "    Task: " );         break;
        default                :  fprintf( ofile, "    UNKNOWN: " );      break;
      }
      fprintf( ofile, "%s, File: %s\n", head->funit->name, head->funit->filename );
      fprintf( ofile, "    -------------------------------------------------------------------------------------------------------------\n" );

      toggle_display_verbose( ofile, head->funit->sig_head );

    }

    head = head->next;

  }

}

/*!
 \param ofile     Pointer to file to output results to.
 \param verbose   Specifies whether or not to provide verbose information

 After the design is read into the functional unit hierarchy, parses the hierarchy by functional unit,
 reporting the toggle coverage for each functional unit encountered.  The parent functional unit will
 specify its own toggle coverage along with a total toggle coverage including its 
 children.
*/
void toggle_report( FILE* ofile, bool verbose ) {

  bool missed_found;  /* If set to TRUE, indicates that untoggled bits were found */
  char tmp[4096];     /* Temporary string value                                   */

  fprintf( ofile, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
  fprintf( ofile, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   TOGGLE COVERAGE RESULTS   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
  fprintf( ofile, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );

  if( report_instance ) {

    if( strcmp( leading_hierarchy, second_hierarchy ) != 0 ) {
      strcpy( tmp, "<NA>" );
    } else {
      strcpy( tmp, leading_hierarchy );
    }

    fprintf( ofile, "Instance                                                   Toggle 0 -> 1                       Toggle 1 -> 0\n" );
    fprintf( ofile, "                                                   Hit/ Miss/Total    Percent hit      Hit/ Miss/Total    Percent hit\n" );
    fprintf( ofile, "---------------------------------------------------------------------------------------------------------------------\n" );

    missed_found = toggle_instance_summary( ofile, instance_root, tmp );
    
    if( verbose && missed_found ) {
      fprintf( ofile, "---------------------------------------------------------------------------------------------------------------------\n" );
      toggle_instance_verbose( ofile, instance_root, tmp );
    }

  } else {

    fprintf( ofile, "Module/Task/Function      Filename                         Toggle 0 -> 1                       Toggle 1 -> 0\n" );
    fprintf( ofile, "                                                   Hit/ Miss/Total    Percent hit      Hit/ Miss/Total    Percent hit\n" );
    fprintf( ofile, "---------------------------------------------------------------------------------------------------------------------\n" );

    missed_found = toggle_funit_summary( ofile, funit_head );

    if( verbose && missed_found ) {
      fprintf( ofile, "---------------------------------------------------------------------------------------------------------------------\n" );
      toggle_funit_verbose( ofile, funit_head );
    }

  }

  fprintf( ofile, "\n\n" );

}

/*
 $Log$
 Revision 1.30  2005/11/23 23:05:24  phase1geo
 Updating regression files.  Full regression now passes.

 Revision 1.29  2005/11/10 19:28:23  phase1geo
 Updates/fixes for tasks/functions.  Also updated Tcl/Tk scripts for these changes.
 Fixed bug with net_decl_assign statements -- the line, start column and end column
 information was incorrect, causing problems with the GUI output.

 Revision 1.28  2005/11/08 23:12:10  phase1geo
 Fixes for function/task additions.  Still a lot of testing on these structures;
 however, regressions now pass again so we are checkpointing here.

 Revision 1.27  2004/08/08 12:50:27  phase1geo
 Snapshot of addition of toggle coverage in GUI.  This is not working exactly as
 it will be, but it is getting close.

 Revision 1.26  2004/03/15 21:38:17  phase1geo
 Updated source files after running lint on these files.  Full regression
 still passes at this point.

 Revision 1.25  2004/01/31 18:58:43  phase1geo
 Finished reformatting of reports.  Fixed bug where merged reports with
 different leading hierarchies were outputting the leading hierarchy of one
 which lead to confusion when interpreting reports.  Also made modification
 to information line in CDD file for these cases.  Full regression runs clean
 with Icarus Verilog at this point.

 Revision 1.24  2004/01/30 23:23:27  phase1geo
 More report output improvements.  Still not ready with regressions.

 Revision 1.23  2004/01/30 06:04:45  phase1geo
 More report output format tweaks.  Adjusted lines and spaces to make things
 look more organized.  Still some more to go.  Regression will fail at this
 point.

 Revision 1.22  2004/01/23 14:37:41  phase1geo
 Fixing output of instance line, toggle, comb and fsm to only output module
 name if logic is detected missing in that instance.  Full regression fails
 with this fix.

 Revision 1.21  2003/10/17 12:55:36  phase1geo
 Intermediate checkin for LSB fixes.

 Revision 1.20  2003/10/03 12:31:04  phase1geo
 More report tweaking.

 Revision 1.19  2003/10/03 03:08:44  phase1geo
 Modifying filename in summary output to only specify basename of file instead
 of entire path.  The verbose report contains the full pathname still, however.

 Revision 1.18  2003/08/25 13:02:04  phase1geo
 Initial stab at adding FSM support.  Contains summary reporting capability
 at this point and roughly works.  Updated regress suite as a result of these
 changes.

 Revision 1.17  2003/02/23 23:32:36  phase1geo
 Updates to provide better cross-platform compiler support.

 Revision 1.16  2003/02/17 22:47:20  phase1geo
 Fixing bug with merging same DUTs from different testbenches.  Updated reports
 to display full path instead of instance name and parent instance name.  Added
 merge tests and added merge testing into regression test suite.  Fixing bug with
 -D/-Q option specified with merge command.  Full regression passing.

 Revision 1.15  2002/11/02 16:16:20  phase1geo
 Cleaned up all compiler warnings in source and header files.

 Revision 1.14  2002/10/29 19:57:51  phase1geo
 Fixing problems with beginning block comments within comments which are
 produced automatically by CVS.  Should fix warning messages from compiler.

 Revision 1.13  2002/10/01 13:21:25  phase1geo
 Fixing bug in report output for single and multi-bit selects.  Also modifying
 the way that parameters are dealt with to allow proper handling of run-time
 changing bit selects of parameter values.  Full regression passes again and
 all report generators have been updated for changes.

 Revision 1.12  2002/09/13 05:12:25  phase1geo
 Adding final touches to -d option to report.  Adding documentation and
 updating development documentation to stay in sync.

 Revision 1.11  2002/08/20 04:48:18  phase1geo
 Adding option to report command that allows the user to display logic that is
 being covered (-c option).  This overrides the default behavior of displaying
 uncovered logic.  This is useful for debugging purposes and understanding what
 logic the tool is capable of handling.

 Revision 1.10  2002/08/19 04:59:49  phase1geo
 Adjusting summary format to allow for larger line, toggle and combination
 counts.

 Revision 1.9  2002/07/20 18:46:38  phase1geo
 Causing fully covered modules to not be output in reports.  Adding
 instance3.v diagnostic to verify this works correctly.

 Revision 1.8  2002/07/17 06:27:18  phase1geo
 Added start for fixes to bit select code starting with single bit selection.
 Full regression passes with addition of sbit_sel1 diagnostic.

 Revision 1.7  2002/07/14 05:27:34  phase1geo
 Fixing report outputting to allow multiple modules/instances to be
 output.

 Revision 1.6  2002/07/09 03:24:48  phase1geo
 Various fixes for module instantiantion handling.  This now works.  Also
 modified report output for toggle, line and combinational information.
 Regression passes.

 Revision 1.5  2002/07/03 03:31:11  phase1geo
 Adding RCS Log strings in files that were missing them so that file version
 information is contained in every source and header file.  Reordering src
 Makefile to be alphabetical.  Adding mult1.v diagnostic to regression suite.
*/

