#!/bin/bash
# yacc -d parser.y
yacc -d parse.y -Wnone
lex scan.l

gcc lex.yy.c y.tab.c lib/symbol_table.c lib/scope.c -w -lm -o parse.out

if [ $1 ]; then
    printf "Parsing $1 ↓\n"
    ./parse.out < $1
else
    echo "Enter C code to parse (<Ctrl+D> to stop):"
    ./parse.out    
fi
