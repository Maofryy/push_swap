#!/usr/bin/env bash

# echo $#
if [ $# -ne 4 ] || [ $1 = "-h" ] || [ $1 = "--help" ] || [ $2 = "--help" ] || [ $2 = "-h" ]
then
  echo "usage : tests.sh [number of tests] [size of int list] [int min] [int max]"
  exit
fi

NB=$1
MAX=0

#CHK=./checker.exe
#PS=./push_swap.exe
CHK=./checker
PS=./push_swap

echo "$1 tests of $2 ints between $3 and $4"

while [ $NB -ne 0 ]
do
  TEST=$(perl srcs_test/gen_int_lst.prl $2 $3 $4)
  $PS $TEST > ps.ret
  cat ps.ret | $CHK $TEST > file.ret
  # ./push_swap.exe $TEST | ./checker.exe $TEST > ret_file
  KO_RET=$(cat file.ret | grep KO | wc -l)
  NB_OP=$(cat file.ret | grep ops. |cut -d ' ' -f 1)

  if [ $NB_OP -gt $MAX ]
  then
    cat ps.ret > max_ps.ret
    cat file.ret > max_file.ret
    echo $TEST > max_test.ret
    MAX=$NB_OP
  fi


  # echo $NB
  # echo "$TEST : "
  # paste -d ' ' -s ps.ret file.ret
  # echo ' '

  if [ $KO_RET -ge 1 ]
  then
    echo "Incorrect operation : KO"
    echo $TEST
    KO=1
    exit
  fi

  NB=$[$NB-1];
done

echo "Max number of operations $MAX :"
cat max_ps.ret max_file.ret max_test.ret
