#!/bin/bash
# Usage ./runtests.sh for redirecting outputs to file,
# and with an arguement to print on commandline as well

D='output'

lex -l scan.l && gcc lex.yy.c library/sym_tab.c -lfl -o scan.out
TEMP_OUTPUT="$D"
./scan.out < input.c > $TEMP_OUTPUT

FILTERED_OUTPUT='sed -r "s/\x1B\[([0-9]{1,2}(;[0-9]{1,2})?)?[m|K]//g" $TEMP_OUTPUT'
FINAL_OUTPUT="${TEMP_OUTPUT%.*}.tokens"
eval $FILTERED_OUTPUT > $FINAL_OUTPUT
rm $TEMP_OUTPUT
printf "$testcase scanned. ✔ \n"
