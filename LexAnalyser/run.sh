lex -l scan.l && gcc lex.yy.c library/sym_tab.c -lfl -o scan.out
if [ $1 ]; then
    ./scan.out < $1
else
    ./scan.out
fi
