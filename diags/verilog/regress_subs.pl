# Name:    regress_subs.pl
# Author:  Trevor Williams  <phase1geo(gmail.com)>
# Date:    6/16/2008
# Purpose: Contains shared Perl subroutines for performing regression
#          runs.

####################
# GLOBAL VARIABLES #
####################

# Global variable that can be used to specify Covered's executable pathname
$COVERED = "../../src/covered";

# Specifies the make command to run
$MAKE = "make";

# Global command flags to use for all Covered commands
$COVERED_GFLAGS = "-D";

# Global generate command flags to use when running the runGenerateCommand subroutine
$COVERED_GEN_GFLAGS = "-P";

# Global score command flags to use when running the runScoreCommand subroutine
$COVERED_SCORE_GFLAGS = "-P";

# Global merge command flags to use when running the runMergeCommand subroutine
$COVERED_MERGE_GFLAGS = "";

# Global report command flags to use when running the runReportCommand subroutine
$COVERED_REPORT_GFLAGS = "";

# Global rank command flags to use when running the runRankCommand subroutine
$COVERED_RANK_GFLAGS = "";

# Global exclude command flags to use when running the runExcludeCommand subroutine
$COVERED_EXCLUDE_GFLAGS = "";

# Global rank command flags to use when running the runRankCommand subroutine
$COVERED_RANK_GFLAGS = "";

# Specifies the location of the check_mem script
$CHECK_MEM = "./check_mem";

# Specifies which simulator should be used for simulating the design (IV, CVER, VCS, VERILATOR)
$SIMULATOR = "IV";

# Specifies the type of dumpfile that should be used by the score command (VCD, LXT)
$DUMPTYPE = "VCD";

# Specifies if the VPI mode of operation should be used for this simulation (0, 1)
$USE_VPI = 0;

# Specifies the relative pathname to the directory containing CDD files to
# compare against.
$CDD_DIR = "../cdd";

# Specifies the relative pathname to the directory containing report files to
# compare against.
$RPT_DIR = "../rpt";

# Specifies the relative pathname to the directory containing error files to
# compare against
$ERR_DIR = "../err";

# Specifies the name of the file containing regression results in the Verilog
# directory.
$RPT_OUTPUT = "regress.output";

# Specifies the name of the file containing all failed regression runs in the
# Verilog directory.
$FAIL_OUTPUT = "regress.failed";

# Specifies the type of processor being used
$PROCESSOR = `uname -p`;

# Simulation plusargs to pass to the runtime
$SIM_PLUSARGS = "+option1 +option2 +optionB=0000000100100011010001010110011110001001101010111100110111101111 +optionO=0123456776543210012345 +optionD=81985529216486895 +optionH=0123456789abcdef +optionE=123.456 +optionF=123.456 +optionG=123.456 +optionS1=\"Small +optionS2=small.dog";


######################
# GLOBAL SUBROUTINES #
######################

# Initializes the diagnostic "environment".  This should be called in each diagnostic script
# before the script does anything.
sub initialize {

  my( $diagname, $error, @args ) = @_;
  my( $arg );

  print "Running ${diagname}";

  # If the diagnostic is supposed to result in an error, output a message to the user so that they
  # are not surprised by the output
  if( $error == 1 ) {
    print " -- should see an error message\n";
  } else {
    print "\n";
  }

  # Parse arguments
  foreach $arg (@args) {

    if( $arg =~ /^(\w+)=(.*)$/ ) {

      my( $varname  ) = $1;
      my( $varvalue ) = $2;

      if( $varname eq "COVERED_GFLAG" ) {
        $COVERED_GFLAGS = $varvalue;
      } elsif( $varname eq "COVERED_SCORE_GFLAG" ) {
        $COVERED_SCORE_GFLAGS = $varvalue;
      } elsif( $varname eq "COVERED_MERGE_GFLAG" ) {
        $COVERED_MERGE_GFLAGS = $varvalue;
      } elsif( $varname eq "COVERED_REPORT_GFLAG" ) {
        $COVERED_REPORT_GFLAGS = $varvalue;
      } elsif( $varname eq "COVERED_RANK_GFLAG" ) {
        $COVERED_RANK_GFLAGS = $varvalue;
      } elsif( $varname eq "COVERED_EXCLUDE_GFLAG" ) {
        $COVERED_EXCLUDE_GFLAGS = $varvalue;
      } elsif( $varname eq "USE_CVER" ) {
        $SIMULATOR = "CVER";
      } elsif( $varname eq "USE_VCS" ) {
        $SIMULATOR = "VCS";
      } elsif( $varname eq "USE_VERILATOR" ) {
        $SIMULATOR = "VERILATOR";
      } elsif( $varname eq "USE_VERIWELL" ) {
        $SIMULATOR = "VERIWELL";
      } elsif( $varname eq "LXT" ) {
        $DUMPTYPE = "LXT";
      } elsif( $varname eq "VPI" ) {
        $USE_VPI  = 1;
        $DUMPTYPE = "VPI";
      }

    }

  }

  # If the TESTMODE was found in the src Makefile, go ahead and allow the usage of the check_mem script in
  # Covered command runs.
  $CHECK_MEM_CMD = &checkForTestMode;

  # Figure out which version of MAKE to run
  if( `which gmake` ne "" ) {
    $MAKE = "gmake";
  } else {
    $MAKE = "make";
  }

}

# Returns the string "| ./check_mem" if we are in TESTMODE mode; otherwise, returns the empty string
sub checkForTestMode {

  my( $check_mem_cmd ) = "";

  open( MFILE, "../../src/Makefile" ) || die "Can't open ../../src/Makefile for reading: $!\n";
  while( <MFILE> ) {
    if( /-DTESTMODE/ ) {
      $check_mem_cmd = "| $CHECK_MEM";
      break;
    }
  }
  close( MFILE );

  return( $check_mem_cmd );

}

# Runs the generate command with the given arguments.
sub runGenerateCommand {

  my( $generate_args ) = $_[0];

  # Create generate command
  my( $cmd ) = "$COVERED $COVERED_GFLAGS $COVERED_GEN_GFLAGS generate $generate_args $CHECK_MEM_CMD";

  &runCommand( $cmd );

}

# Runs the score command with the given arguments.
sub runScoreCommand {

  my( $score_args ) = $_[0];

  # If the -vcd option was used but the user specified the LXT dumpfile format should be used,
  # perform the substitution.
  if( ($score_args =~ /^(.*)\s+-vcd\s+(\w+)\s+(.*)$/) && ($dumptype eq "LXT") ) {
    $score_args = "$1 -lxt $2 $3";

  # Otherwise, if the -lxt option was used by the user specified the VCD dumpfile format should be used,
  # perform the substitution
  } elsif( ($score_args =~ /^(.*)\s+-lxt\s+(\w+)\s+(.*)$/) && ($dumptype eq "VCD") ) {
    $score_args = "$1 -vcd $2 $3";
  }

  # Create score command
  my( $cmd ) = "$COVERED $COVERED_GFLAGS $COVERED_SCORE_GFLAGS score $score_args $CHECK_MEM_CMD";

  &runCommand( $cmd );

}

# Runs the merge command with the given arguments.
sub runMergeCommand {

  my( $merge_args ) = $_[0];

  # Create merge command
  my( $cmd ) = "$COVERED $COVERED_GFLAGS $COVERED_MERGE_GFLAGS merge $merge_args $CHECK_MEM_CMD";

  &runCommand( $cmd );

}

# Runs the report command with the given arguments.
sub runReportCommand {

  my( $report_args ) = $_[0];

  # Create report command
  my( $cmd ) = "$COVERED $COVERED_GFLAGS $COVERED_REPORT_GFLAGS report $report_args $CHECK_MEM_CMD";

  &runCommand( $cmd );

}

# Runs the rank command with the given arguments.
sub runRankCommand {

  my( $rank_args ) = $_[0];

  # Create rank command
  my( $cmd ) = "$COVERED $COVERED_GFLAGS $COVERED_RANK_GFLAGS rank $rank_args $CHECK_MEM_CMD";

  &runCommand( $cmd );

}

# Runs the exclude command with the given arguments.
sub runExcludeCommand {

  my( $exclude_args ) = $_[0];

  # Create exclude command
  my( $cmd ) = "$COVERED $COVERED_GFLAGS $COVERED_EXCLUDE_GFLAGS exclude $exclude_args $CHECK_MEM_CMD";

  &runCommand( $cmd );

}

# This subroutine should be used whenever a system command needs to be
# executed from a regression script.  Echoes the given command and then
# executes it.
sub runCommand {
  
  my( $cmd ) = $_[0];
  
  print "$cmd\n";
  system( "$cmd" ) && die;
  
}

# Verifies that specified diagnostic successfully passed all phases of testing.
# Note:    mode 0:  Normally run diagnostic error check (checks report and CDD files)
#          mode 1:  Error diagnostic (checks output against *.err files)
#          mode 2:  Skipped diagnostic (no check but increment PASSED count)
#          mode 3:  Finish run (removes all *.done files if FAILED count == 0)
#          mode 4:  Finish run but leave *.done files
#          mode 5:  Run report file diagnostic error check (for use with LXT/VPI dump verification)
#          mode 6:  Remove CDD files only (that match)
sub checkTest {
 
  my( $test, $rm_cdd, $mode ) = @_;

  my( $passed ) = 0;
  my( $failed ) = 0;
  my( $retval ) = 0;
  
  # Open report results file if it currently exists and accumulate info.
  if( open( RPT_RESULTS, "${RPT_OUTPUT}" ) > 0 ) {

    my( $results ) = <RPT_RESULTS>;
    chomp( $results );

    if( $results =~ /^DIAGNOSTICS PASSED: (\d+), FAILED: (\d+)$/ ) {
      $passed = $1;
      $failed = $2;
    } else {
      die "Bad format for regression results file\n";
    }

    close( RPT_RESULTS );

  }

  # If this is the finish mode, remove all *.done files if failed count shows no failures
  if( ($mode == 3) || ($mode == 4) ) {

    system( "echo; cat $RPT_OUTPUT; echo; rm -rf $RPT_OUTPUT" ) && die;

    if( ($failed == 0) && ($mode == 3) ) {
      system( "rm -rf *.done $FAIL_OUTPUT" ) && die;
    }

  } else {

    my( $check1, $check2, $check3, $check4, $check5 );
    
    # If this is not an error test, check the CDD and report files */
    if( ($mode == 0) || ($mode == 1) || ($mode == 5) || ($mode == 6) ) {

      # Check CDD file
      if( (-e "${test}.cdd") || ($mode == 1) ) {
        if( ($mode != 5) && (($mode == 0) || (-e "${CDD_DIR}/${test}.cdd")) ) {
          $check1 = system( "./cdd_diff ${test}.cdd ${CDD_DIR}/${test}.cdd" );
        } elsif( $mode == 6 ) {
          $check1 = 1;
        } else {
          $check1 = 0;
        }
        if( ($check1 == 0) || ($mode == 5) ) {
          if( $rm_cdd > 0 ) {
            system( "rm -f ${test}.cdd" ) && die;
          }
          if( $rm_cdd > 1 ) {
            system( "rm -f ${test}a.cdd" ) && die;
          }
          if( $rm_cdd > 2 ) {
            system( "rm -f ${test}b.cdd" ) && die;
          }
          if( $rm_cdd > 3 ) {
            system( "rm -f ${test}c.cdd" ) && die;
          }
          if( $rm_cdd > 4 ) {
            system( "rm -f ${test}d.cdd" ) && die;
          }
          if( $rm_cdd > 5 ) {
            system( "rm -f ${test}e.cdd" ) && die;
          }
          if( $rm_cdd > 6 ) {
            system( "rm -f ${test}f.cdd" ) && die;
          }
          if( $rm_cdd > 7 ) {
            system( "rm -f ${test}g.cdd" ) && die;
          }
          if( $rm_cdd > 8 ) {
            system( "rm -f ${test}h.cdd" ) && die;
          }
          if( $rm_cdd > 9 ) {
            system( "rm -f ${test}i.cdd" ) && die;
          }
        }
      } elsif( $mode == 0 ) {
        $check1 = 1;
      }

    }

    if( ($mode == 0) || ($mode == 5) ) {

      # Check module report
      if( -f "${test}.rptM" ) {
        $check2 = system( "diff ${test}.rptM ${RPT_DIR}/${test}.rptM" );
        if( $check2 == 0 ) {
          system( "rm ${test}.rptM" ) && die;
        }
      }

      # Check instance report
      if( -f "${test}.rptI" ) {
        $check3 = system( "diff ${test}.rptI ${RPT_DIR}/${test}.rptI" );
        if( $check3 == 0 ) {
          system( "rm ${test}.rptI" ) && die;
        }
      }

      # Check module with line-width report
      if( -f "${test}.rptWM" ) {
        $check4 = system( "diff ${test}.rptWM ${RPT_DIR}/${test}.rptWM" );
        if( $check4 == 0 ) {
          system( "rm ${test}.rptWM" ) && die;
        }
      }

      # Check instance with line-width report
      if( -f "${test}.rptWI" ) {
        $check5 = system( "diff ${test}.rptWI ${RPT_DIR}/${test}.rptWI" );
        if( $check5 == 0 ) {
          system( "rm ${test}.rptWI" ) && die;
        }
      }

    # If this is an error test, check the error file
    } elsif( $mode == 1 ) {
  
      $check1 = system( "diff ${test}.err ${ERR_DIR}/${test}.err" );
      if( $check1 == 0 ) {
        system( "rm ${test}.err" ) && die;
      }

    }

    if( $mode != 6 ) {

      open( RPT_RESULTS, ">${RPT_OUTPUT}" ) || die "Can't open ${RPT_OUTPUT} for writing!\n";
      open( RPT_FAILED, ">>${FAIL_OUTPUT}" ) || die "Can't open ${FAIL_OUTPUT} for writing!\n";

      if( (($mode == 0) && (($check1 > 0) || ($check2 > 0) || ($check3 > 0) || ($check4 > 0) || ($check5 > 0))) ||
          (($mode == 1) && ($check1 > 0)) ||
          (($mode == 5) && (($check2 > 0) || ($check3 > 0) || ($check4 > 0) || ($check5 > 0))) ) {
        print "  Checking output results         -- FAILED\n";
        print RPT_FAILED "${test}\n";
        $failed++;
        $retval = 1;

      } else {

        # Check to make sure that a tmp* file does not exist
        my( $tmp ) = `ls | grep ^tmp`;
        chomp( $tmp );
        if( $tmp ne "" ) {
          die "  Temporary file was not removed!\n";
        }

        if( ($mode == 0) || ($mode == 1) || ($mode == 5) ) {
          print "  Checking output results         -- PASSED\n";
        }
        $passed++;

        # Remove VCD file
        # system( "rm -f *.vcd" ) && die;
 
        # Create the done file
        system( "touch ${test}.done" ) && die;

      }

      print RPT_RESULTS "DIAGNOSTICS PASSED: ${passed}, FAILED: ${failed}\n";

      close( RPT_RESULTS );
      close( RPT_FAILED  );

    }

  }

  return $retval;
 
}

# Converts a configuration file for the current dump type.
sub convertCfg {

  my( $type, $dumponly, $using_verilator, $file ) = @_;
  my( $tmpline ) = "";

  open( OFILE, ">${file}" ) || die "Can't open ${file} for writing!\n";
  open( IFILE, "../regress/${file}" ) || die "Can't open ../regress/${file} for reading!\n";

  while( $line = <IFILE> ) {
    if( $dumponly == 1 ) {
      $tmpline = "";
      if( $line =~ /(-vcd\s+[a-zA-Z0-9_\.]+\s+)/ ) {
        $tmpline .= $1;
      }
      if( $line =~ /(-(o|cdd)\s+[a-zA-Z0-9_\.]+\s+)/ ) {
        $tmpline .= $1;
      }
      $line = $tmpline;
    } elsif( $using_verilator == 1 ) {
      my( $basename );
      if( $file =~ /(.*)\.cfg/ ) {
        $basename = $1;
      }
      $line =~ s/-v\s+$basename.v/-v $basename.verilator.v/;
      if( $line =~ /-i\s+/ ) {
        $line =~ s/-i\s+main/-i TOP.v/;
      } else {
        $line .= "-i TOP.v";
      }
      $line .= " -ep";
    }
    $line =~ s/\-vcd/\-$type/g;
    if( ($type eq "vpi") || ($type eq "inline -vpi") ) {
      $line =~ s/[0-9a-zA-Z_\.]+\.(vcd|dump)/covered_vpi.v/g;
    } elsif( ($type eq "inline") || ($type eq "inline -inline-comb-depth 1") ) {
      $line =~ s/[0-9a-zA-Z_\.]+\.(vcd|dump)//g;
    }
    print OFILE $line;
  }

  close( IFILE );
  close( OFILE );

}

sub dequote {
  local $_ = shift;
  s/^\s*\@\@\@[ ]?//gm;
  return $_;
}

sub regress_run {

  my( $diagname, @args ) = @_;

  # Initialize the environment from the specified arguments
  &initialize( $diagname, 0, @args );

  # Perform the simulation
  if( $SIMULATOR eq "IV" ) {
    &regress_iv( $diagname );
  } elsif( $SIMULATOR eq "CVER" ) {
    &regress_cver( $diagname );
  } elsif( $SIMULATOR eq "VCS" ) {
    &regress_vcs( $diagname );
  } elsif( $SIMULATOR eq "VERIWELL" ) {
    &regress_veriwell( $diagname );
  } elsif( $SIMULATOR eq "VERILATOR" ) {
    &regress_verilator( $diagname );
  } else {
    die "Unknown simulator type ($SIMULATOR)\n";
  }

  # Generate reports
  &runReportCommand( "-d v -e -m ltcfam    -o ${diagname}.rptM ${diagname}.cdd" );
  &runReportCommand( "-d v -e -m ltcfam -i -o ${diagname}.rptI ${diagname}.cdd" );

  if( $SIMULATOR eq "VERILATOR" ) {
    &runCommand( "mv ${diagname}.cdd  ${diagname}.verilator.cdd" );
    &runCommand( "mv ${diagname}.rptM ${diagname}.verilator.rptM" );
    &runCommand( "mv ${diagname}.rptI ${diagname}.verilator.rptI" );
    $diagname .= ".verilator";
  }

  # Check the output files
  if( $USE_VPI || ($DUMPTYPE eq "LXT") ) {
    &checkTest( $diagname, 1, 5 );
  } else {
    &checkTest( $diagname, 1, 0 );
  }

}

sub regress_iv {

  my( $diagname ) = $_[0];
  my( $vflags )   = "-cconfig_file -I./include -DRUNTEST";

  if( $USE_VPI ) {

    # Generate database
    &runGenerateCommand( "-f ../regress/${diagname}.cfg -vpi" );

    # Compile the simulation
    &runCommand( "iverilog $vflags -m ../../lib/covered.vpi covered/verilog/${diagname}.v covered/verilog/covered_vpi.v" );

    # Run the simulation
    if( $COVERED_GFLAG =~ /-D/ ) {
      &runCommand( "vvp a.out +covered_cdd=${diagname}.cdd +covered_debug $SIM_PLUSARGS" );
    } else {
      &runCommand( "vvp a.out +covered_cdd=${diagname}.cdd $SIM_PLUSARGS" );
    }

  } else {

    # Generate database
    &runGenerateCommand( "-f ../regress/${diagname}.cfg -D DUMP" );

    # If we are doing VCD dumping, create a dumpfile for comparing against the generated dumpfile
    if( $DUMPTYPE eq "VCD" ) {
      &runCommand( "iverilog $vflags -DDUMP ${diagname}.v" );
      &runCommand( "vvp a.out $SIM_PLUSARGS" );
      &runCommand( "mv ${diagname}.vcd ${diagname}.vcd.1" );
    }

    # Compile the simulation
    &runCommand( "iverilog $vflags -DDUMP covered/verilog/${diagname}.v" );

    # Run the simulation
    if( $DUMPTYPE eq "VCD" ) {
      &runCommand( "vvp a.out $SIM_PLUSARGS" );
    } else {
      &runCommand( "vvp a.out $SIM_PLUSARGS -lxt2" );
    }

    # Compare the VCD files for differences and score the simulation
    if( $DUMPTYPE eq "VCD" ) {
      if( $COVERED_GFLAG =~ /-D/ ) {
        &runCommand( "./vcd_diff -v ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
      } else {
        &runCommand( "./vcd_diff    ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
      }
      &runCommand( "rm -f ${diagname}.vcd.1" );
      &runScoreCommand( "-vcd ${diagname}.vcd" );
    } else {
      &runScoreCommand( "-lxt ${diagname}.vcd" );
    }

  }

}

sub regress_cver {

  my( $diagname ) = $_[0];
  my( $vflags )   = "-q +librescan +libext+.v+.vlib+ -y ./covered/verilog -y ./lib -y ./ovl +incdir+./ovl +incdir+./include +define+RUNTEST +define+OVL_VERILOG +define+OVL_COVER_ON +define+OVL_COVER_DEFAULT=15";

  if( $USE_VPI ) {

    # Generate database
    &runGenerateCommand( "-f ../regress/${diagname}.cfg -vpi" );

    # Compile and run the simulation
    if( $COVERED_GFLAG =~ /-D/ ) {
      &runCommand( "cver $vflags +loadvpi=../../lib/covered.cver.so:vpi_compat_bootstrap +define+DUMP covered/verilog/${diagname}.v covered/verilog/covered_vpi.v +covered_cdd=${diagname}.cdd +covered_debug $SIM_PLUSARGS" );
    } else {
      &runCommand( "cver $vflags +loadvpi=../../lib/covered/cver.so:vpi_compat_bootstrap +define+DUMP covered/verilog/${diagname}.v covered/verilog/covered_vpi.v +covered_cdd=${diagname}.cdd $SIM_PLUSARGS" );
    }

  } else {

    # Generate database
    &runGenerateCommand( "-f ../regress/${diagname}.cfg -D DUMP" );

    # If we are doing VCD dumping, create a dumpfile for comparing against the generated dumpfile
    &runCommand( "cver $vflags +define+DUMP $SIM_PLUSARGS ${diagname}.v" );
    &runCommand( "mv ${diagname}.vcd ${diagname}.vcd.1" );

    # Compile and run the simulation
    &runCommand( "cver $vflags +define+DUMP $SIM_PLUSARGS covered/verilog/${diagname}.v" );

    # Compare the VCD files for differences and score the simulation
    if( $COVERED_GFLAG =~ /-D/ ) {
      &runCommand( "./vcd_diff -v ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
    } else {
      &runCommand( "./vcd_diff    ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
    }
    &runCommand( "rm -f ${diagname}.vcd.1" );
    &runScoreCommand( "-vcd ${diagname}.vcd" );

  }

}

sub regress_vcs {

  my( $diagname ) = $_[0];
  my( $vflags )   = "+librescan +libext+.v+.vlib+ -y ./covered/verilog -y ./lib -y ./ovl +incdir+./ovl +incdir+./include +define+RUNTEST +define+OVL_VERILOG +define+OVL_COVER_ON +define+OVL_COVER_DEFAULT=15 +v2k -sverilog -ntb_opts dtm -PP +vcs+lic+wait -v2k_generate";

  if( $USE_VPI ) {

    # Generate database
    &runGenerateCommand( "-f ../regress/${diagname}.cfg -vpi" );

    # Compile the simulation
    if( $PROCESSOR eq "x86_64" ) {
      $vflags .= " -full64";
    }
    &runCommand( "vcs $vflags +vpi -load ../../lib/covered.vcs.so:covered_register covered/verilog/${diagname}.v covered/verilog/covered_vpi.v" );

    # Run the simulation
    if( $COVERED_GFLAG =~ /-D/ ) {
      &runCommand( "./simv +covered_cdd=${diagname}.cdd +covered_debug $SIM_PLUSARGS" );
    } else {
      &runCommand( "./simv +covered_cdd=${diagname}.cdd $SIM_PLUSARGS" );
    }

  } else {

    # Generate database
    &runGenerateCommand( "-f ../regress/${diagnmae}.cfg -D DUMP" );

    # If we are doing VCD dumping, create a dumpfile for comparing against the generated dumpfile
    &runCommand( "vcs $vflags +define+DUMP ${diagname}.v" );
    &runCommand( "./simv $SIM_PLUSARGS" );
    &runCommand( "mv ${diagname}.vcd ${diagname}.vcd.1" );

    # Compile the simulation
    &runCommand( "vcs $vflags +define+DUMP covered/verilog/${diagname}.v" );

    # Run the simulation
    &runCommand( "./simv $SIM_PLUSARGS" );

    # Compare the VCD files for differences and score the simulation
    if( $COVERED_GFLAG =~ /-D/ ) {
      &runCommand( "./vcd_diff -v ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
    } else {
      &runCommand( "./vcd_diff    ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
    }
    &runCommand( "rm -f ${diagname}.vcd.1" );
    &runScoreCommand( "-vcd ${diagname}.vcd" );

  }

}

sub regress_veriwell {

  my( $diagname ) = $_[0];
  my( $vflags )   = "+libext+.v+.vlib -y ./lib -y ./covered/verilog -y ./ovl +incdir+./ovl +incdir+./include +define+RUNTEST +define+OVL_VERILOG +define+OVL_COVER_ON +define+OVL_COVER_DEFAULT=15 +define+DUMP +define+V1995_COV_MODE";

  # Generate database
  &runGenerateCommand( "-f ../regress/${diagname}.cfg -D DUMP" );

  # If we are doing VCD dumping, create a dumpfile for comparing against the generated dumpfile
  &runCommand( "veriwell $vflags +define+DUMP $SIM_PLUSARGS ${diagname}.v" );
  &runCommand( "mv ${diagname}.vcd ${diagname}.vcd.1" );

  # Compile and run the simulation
  &runCommand( "veriwell $vflags +define+DUMP $SIM_PLUSARGS covered/verilog/${diagname}.v" );

  # Compare the VCD files for differences and score the simulation
  if( $COVERED_GFLAG =~ /-D/ ) {
    &runCommand( "./vcd_diff -v ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
  } else {
    &runCommand( "./vcd_diff    ${diagname}.vcd ${diagname}.vcd.1 ${diagname}.map" );
  }
  &runCommand( "rm -f ${diagname}.vcd.1" );
  &runScoreCommand( "-vcd ${diagname}.vcd" );

}

sub regress_verilator {

  my( $diagname ) = $_[0];

  # Verilator only supports VCD dumping
  if( $DUMPTYPE eq "VCD" ) {

    # Run Verilator on the .v and sim_main.cpp files in the diagname directory
    &runCommand( "verilator --cc $diagname/$diagname.v --trace --exe $diagname/sim_main.cpp" );

    # Perform a "make" in the obj_dir directory
    &runCommand( "cd obj_dir; make -f V$diagname.mk" );

    # Now run the simulation -- the VCD dumpfile will be output in the obj_dir directory
    &runCommand( "cd obj_dir; ./V$diagname $SIM_PLUSARGS" );

    # Score the run (substitute the -v option with the Verilog file in the diagname directory
    $runargs = `cat ../regress/$diagname.cfg`;
    $runargs =~ s/-v\s+(\w+)/-v $diagname\/$1/;
    &runScoreCommand( $runargs );

  }

}

