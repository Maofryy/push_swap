#!/usr/bin/env bash

## ARGS TESTS
# echo $#
# Pseudo code : if non option (v for verbose, h for help) in case loop, then test if it can be
# an argument for the function and store it as it is entered : if $1 isnt an option and if -n $NB_TEST
VERB=0
HELP=0
RET=0

NB_TESTS=1
SIZE=3
INT_MIN=-10
INT_MAX=10

for param in $@; do
  case $param in
    -v) VERB=1
        shift
        ;;
    -h) HELP=1
        shift
        ;;
    -m) RET=1
        shift
        ;;
    #*) echo "Option $1 not recognized"
  esac
done

if [ $HELP -eq 1 ] || [ $INT_MIN -ge $INT_MAX ] || [ $NB_TESTS -le 0 ]
then
  echo "usage : tests.sh -options [number of tests] [size of int list] [int min] [int max]"
  echo "        -v Verbose mode, displaying each test and return from executables"
  echo "        -h Help displays this help message"
  exit
fi

if [ ! -z $1 ]
then
  NB_TESTS=$1
fi
if [ ! -z $2 ]
then
  SIZE=$2
fi
if [ ! -z $3 ]
then
  INT_MIN=$3
fi
if [ ! -z $4 ]
then
  INT_MAX=$4
fi

MAX=0
MIN=10000

#CHK=./checker.exe
#PS=./push_swap.exe
CHK=./checker
PS=./push_swap

echo "$NB_TESTS tests of $SIZE ints between $INT_MIN and $INT_MAX"

NB_TEST=$NB_TESTS
while [ $NB_TEST -ne 0 ]
do
  TEST=$(perl srcs_test/gen_int_lst.prl $SIZE $INT_MIN $INT_MAX)
  $PS $TEST > ps.ret
  cat ps.ret | $CHK $TEST > file.ret
  # ./push_swap.exe $TEST | ./checker.exe $TEST > ret_file
  KO_RET=$(cat file.ret | grep KO | wc -l)
  NB_OP=$(cat ps.ret | wc -l)

  if [ $NB_OP -gt $MAX ]
  then
    cat ps.ret > max_ps.ret
    cat file.ret > max_file.ret
    echo $TEST > max_test.ret
    MAX=$NB_OP
  fi
  if [ $NB_OP -lt $MIN ]
  then
    cat ps.ret > min_ps.ret
    cat file.ret > min_file.ret
    echo $TEST > min_test.ret
    MIN=$NB_OP
  fi

  if [ $VERB -eq 1 ]
  then
    echo "Test number : $[$NB_TESTS - $NB_TEST + 1] "
    echo "$TEST=> "
    paste -d ' ' -s ps.ret file.ret
    echo ' '
  fi

  if [ $KO_RET -ge 1 ]
  then
    echo "Incorrect operation : KO"
    echo $TEST
    KO=1
    exit
  fi

  NB_TEST=$[$NB_TEST-1];
done

if [ $RET -eq 1 ]
then
echo "Min number of operations $MIN :"
paste -d ' ' -s min_ps.ret
cat min_file.ret | grep OK
cat min_test.ret
echo "Max number of operations $MAX :"
paste -d ' ' -s max_ps.ret
cat max_file.ret | grep OK
cat max_test.ret
fi
