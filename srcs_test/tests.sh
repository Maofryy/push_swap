#!/usr/bin/env bash

# echo $#
if [ $# -ne 4 ] || [ $1 = "-h" ] || [ $1 = "--help" ] || [ $2 = "--help" ] || [ $2 = "-h" ]
then
  echo "usage : tests.sh [number of tests] [size of int list] [int min] [int max]"
  exit
fi

NB=$1
MAX=0

echo "$1 tests of $2 ints between $3 and $4"

while [ $NB -ne 0 ]
do
  TEST=$(perl srcs_test/gen_int_lst.prl $2 $3 $4)
  ./push_swap.exe $TEST > ret_ps
  cat ret_ps | ./checker.exe $TEST > ret_file
  # ./push_swap.exe $TEST | ./checker.exe $TEST > ret_file
  KO_RET=$(cat ret_file | grep KO | wc -l)
  NB_OP=$(cat ret_file | grep ops. |cut -d ' ' -f 1)

  if [ $NB_OP -gt $MAX ]
  then
    MAX=$NB_OP
  fi


  # echo $NB
  echo "$TEST : "
  paste -d ' ' -s ret_ps ret_file
  echo ' '

  if [ $KO_RET -ge 1 ]
  then
    echo "Incorrect operation : KO"
    echo $TEST
    KO=1
    exit
  fi

  NB=$[$NB-1];
done

echo "Max number of operations :" $MAX
