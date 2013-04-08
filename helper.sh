#!/bin/bash

SUITENAME=""
INFILE=""
OUTFILE=""
EXPECTED=""

function cleanstring {
  #first, strip underscores
  CLEAN="$1"
  CLEAN=${CLEAN//_/}
  # next, replace spaces with underscores
  CLEAN=${CLEAN// /_}
  # now, clean out anything that's not alphanumeric or an underscore
  CLEAN=${CLEAN//[^a-zA-Z0-9_]/}
  # finally, lowercase with TR
  CLEAN=`echo -n $CLEAN | tr A-Z a-z`
  echo $CLEAN
}


#
# Compare a program's stdout to a reference given a stdin.
# will print message success/failure message as well as comparison of 
# invalid output to expected output.
# invocation as `test_file $INPUT_FILE $EXECUTABLE $EXPECTED_OUTPUT`
# optional message as fourth argument
# 
function test_file {
  cat $1 > $INFILE 
  cat $3 > $EXPECTED
  <$INFILE $2 >$OUTFILE
  
  diff $OUTFILE $EXPECTED &> /dev/null 
  if [[ "$?" == 0 ]]; then
    echo "  [TEST SUCCESS] $4"
  else
    echo "  [TEST FAIL] $4"
    echo "    EXPECTED:"
    <$EXPECTED showtabs | sed "s/^/      /"
    echo ""
    echo "    FOUND:"
    <$OUTFILE  showtabs | sed "s/^/      /"
    echo ""
    if [[ "$STOP_ON_FAILURE" == "-failfast" ]];then exit 1; fi
  fi
}

#
# Same as test_file, but for strings
#
function test_string {
  test_file <(echo -e "$1") $2 <(echo -e "$3") "$4"
}

function suite {
  SUITENAME=$(cleanstring $1)
  INFILE="$SUITENAME""_infile.tmp"
  OUTFILE="$SUITENAME""_outfile.tmp"
  EXPECTED="$SUITENAME""_expected.tmp"
  echo "[SUITE $SUITENAME]"
  STOP_ON_FAILURE="$2"
}

function endsuite {
  rm $INFILE
  rm $OUTFILE
  rm $EXPECTED
  
}
