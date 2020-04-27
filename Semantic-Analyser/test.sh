#!/bin/bash
# Usage ./runtests.sh for redirecting outputs to file,
# and with an arguement to print on commandline as well
D='output'


yacc -d parse.y
lex scan.l

gcc lex.yy.c y.tab.c lib/symbol_table.c lib/scope.c -w -lm -o parser.out
TEMP_OUTPUT="$D"
./parser.out < input.c > $TEMP_OUTPUT
FILTERED_OUTPUT='sed -r "s/\x1B\[([0-9]{1,2}(;[0-9]{1,2})?)?[m|K]//g" $TEMP_OUTPUT'
FINAL_OUTPUT="${TEMP_OUTPUT%.*}.parse"
eval $FILTERED_OUTPUT > $FINAL_OUTPUT
rm $TEMP_OUTPUT
printf "$testcase parsed. ✔ \n"

