To run the lexical analyser 

1) Compile the syntax analyser with gcc version 4.8 or later, use command  
   gcc syntaxx.c -o syntax

2) To run the syntax analyser , first run the lexical analyser and then syntax analyser 
  ./lex input.t output.lex
  ./syntax output.lex output.ast
 
 input.t is the input while where the input for lexical analyser is given and output.lex contains the outout of the lexical analyser.
