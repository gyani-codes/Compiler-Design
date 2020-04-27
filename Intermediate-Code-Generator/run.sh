#!/bin/bash
# yacc -d parser.y
yacc -d parser.y -Wnone
lex scanner.l

gcc lex.yy.c y.tab.c lib/symbol_table.c lib/scope.c lib/stack.c -w -lm -o parser.out

if [ $1 ]; then
    printf "Parsing $1 ↓\n"
    ./parser.out < $1
else
    echo "Enter C code to parse (<Ctrl+D> to stop):"
    ./parser.out    
fi