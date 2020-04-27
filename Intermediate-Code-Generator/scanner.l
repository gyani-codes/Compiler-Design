/*
* Scanner for C language
*
* Ref: http://www.quut.com/c/ANSI-C-grammar-l-2011.html
*
* @author Shashank P, Praveen Gupta, Ashwin Joisa
*/

%{
#include "y.tab.h"
#include "lib/misc.h"

%}

number          [0-9]
letter          [a-zA-Z]
single_operators    [+*/%^&.=-]

%option yylineno
%option noyywrap


%%
\/\/(.)*                            {
                                    }

"/*"                                { multiline_comment(); }

"#include"[ ]*"<"(_|{letter})({letter}|{number}|_)*".h>" {  
                                        trace("Header File");
                                    }
[\n]                                {
                                    }

[{]                                 { 
                                        trace("{");
                                        return *yytext;
                                    }
[}]                                 { 
                                        trace("}");
                                        return *yytext;
                                    }

\"[^"\n]*["\n]                      { 
                                        if(yytext[yyleng-1]!='"'){
                                            yyerror("Unclosed String\n");
                                        }
                                        trace("CONSTANT_STRING");
                                        strcpy(yylval.char_ptr, yytext);
                                        return CONSTANT_STRING;
                                    }

int                                 { 
                                        trace("INT");
										strcpy(yylval.char_ptr, yytext);
                                        return INT;
                                    }

float                               { 
                                        trace("FLOAT");
										strcpy(yylval.char_ptr, yytext);
                                        return FLOAT;
                                    }
char                                { 
                                        trace("CHAR");
										strcpy(yylval.char_ptr, yytext);
                                        return CHAR;
                                    }
double                              { 
                                        trace("DOUBLE");
										strcpy(yylval.char_ptr, yytext);
                                        return DOUBLE;
                                    }
void                                { 
                                        trace("VOID");
										strcpy(yylval.char_ptr, yytext);
                                        return VOID;
                                    }
signed                              { 
                                        trace("SIGNED");
                                        return SIGNED;
                                    }
unsigned                            { 
                                        trace("UNSIGNED");
                                        return UNSIGNED;
                                    }
long                                { 
                                        trace("LONG");
                                        return LONG;
                                    }
short                               { 
                                        trace("SHORT");
                                        return SHORT;
                                      
                                    }
switch                              { 
                                        trace("SWITCH");
                                        return SWITCH;
                                    }
break                               { 
                                        trace("BREAK");
                                        return BREAK;
                                    }
continue                            { 
                                        trace("CONTINUE");
                                        return CONTINUE;
                                    }
case                                { 
                                        trace("CASE");
                                        return CASE;
                                    }
default                             { 
                                        trace("DEFAULT");
                                        return DEFAULT;
                                    }
for                                 { 
                                        trace("FOR");
                                        return FOR;
                                    }
while                               { 
                                        trace("WHILE");
                                        return WHILE;
                                    }
do                                  { 
                                        trace("DO");
                                        return DO;
                                    }
if                                  { 
                                        trace("IF");
                                        return IF;
                                      
                                    }
else                                { 
                                        trace("ELSE");
                                        return ELSE;
                                    }

return                              { 
                                        trace("RETURN");
                                        return RETURN;
                                    }
                                                                                                            
[(]                                 { 
                                        trace("(");
                                        return *yytext;
                                    }
[)]                                 { 
                                        trace(")");
                                        return *yytext;
                                    }
[\[]                                { 
                                        trace("[");
                                        return *yytext;
                                    }
[\]]                                { 
                                        trace("]");
                                        return *yytext;
                                    }
[,]                                 { 
                                        trace(",");
                                        return *yytext;
                                    } 

[\t ]                               {}

[;]                                 { 
                                        trace(";");
                                        return *yytext;
                                    }

\'.\'                               { 
                                        trace("CONSTANT_CHAR"); 
                                        strcpy(yylval.char_ptr, yytext);
                                        return CONSTANT_CHAR;
                                    }

{number}+(\.{number}+)?e{number}+   { 
                                        trace("CONSTANT_FLOAT"); 
                                        strcpy(yylval.char_ptr, yytext);
                                        return CONSTANT_FLOAT;
                                    } 

{number}+\.{number}+                { 
                                        trace("CONSTANT_FLOAT"); 
                                        strcpy(yylval.char_ptr, yytext);
                                        return CONSTANT_FLOAT;
                                    }                                             

{number}+                           { 
                                        trace("CONSTANT_INTEGER"); 
                                        strcpy(yylval.char_ptr, yytext);
                                        return CONSTANT_INTEGER;
                                    }    

(_|{letter})({letter}|{number}|_)*  { 
                                        trace("IDENTIFIER");
                                        strcpy(yylval.char_ptr, yytext);
                                        return IDENTIFIER;
                                    }

{single_operators}                  { 
                                        trace("SINGLE OPERATOR"); 
                                        return *yytext;
                                    }

"=="                                { 
                                        trace("=="); 
                                        return DOUBLE_EQUAL;
                                    }
"!="                                { 
                                        trace("!="); 
                                        return NOT_EQUAL;
                                    }
"<"                                 { 
                                        trace("<"); 
                                        return LESSER_THAN;
                                    }
">"                                 { 
                                        trace(">"); 
                                        return GREATER_THAN;
                                    }
"<="                                 { 
                                        trace("<="); 
                                        return LESSER_EQUAL;
                                    }

"+="                                { 
                                        trace("+="); 
                                        return ADD_ASSIGN;
                                    }

"-="                                { 
                                        trace("-="); 
                                        return SUB_ASSIGN;
                                    }

"*="                                { 
                                        trace("*="); 
                                        return MUL_ASSIGN;
                                    }
                                    
"/="                                { 
                                        trace("/="); 
                                        return DIV_ASSIGN;
                                    }
"%="					            { 
                                        trace("%="); 
                                        return MOD_ASSIGN;
                                    }

">>="					            { 
                                        trace(">>="); 
                                        return RIGHT_ASSIGN;
                                    }
"<<="					            { 
                                        trace("<<="); 
                                        return LEFT_ASSIGN;
                                    }

"&="					            { 
                                        trace("&="); 
                                        return AND_ASSIGN;
                                    }
"^="					            { 
                                        trace("^="); 
                                        return XOR_ASSIGN;
                                    }
"|="					            { 
                                        trace("|="); 
                                        return OR_ASSIGN;
                                    }

">="                                { 
                                        trace(">="); 
                                        return GREATER_EQUAL;
                                    }
"&&"                                { 
                                        trace("&&"); 
                                        return LOGIC_AND;
                                    }
"||"                                { 
                                        trace("||"); 
                                        return LOGIC_OR;
                                    }
"!"                                 { 
                                        trace("!"); 
                                        return NOT;
                                    }
  
"++"                                { 
                                        trace("+="); 
                                        return INCREMENT_OPERATOR;
                                    }  
"--"                                { 
                                        trace("--"); 
                                        return DECREMENT_OPERATOR;
                                    }  
                                                                      

(({number}({letter}|{number}|_)+)|.)      { yyerror("Invalid Token"); }

%%

void multiline_comment()
{
    int c;
    while ((c = input()) != 0){
        if (c == '*'){
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    }

    yyerror("Unterminated Multiline Comment");
}
