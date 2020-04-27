<<<<<<< HEAD
=======


>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
%{
#include "y.tab.h"

#include "library/miscellaneous.h"
%}

number          [0-9]
letter          [a-zA-Z]
single_operators    [+*/%^&.=-]

/* for excessing number ,letters and  and single operators */

/* "trace" is used to control whether all input characters are ECHOed to output, and needs to be declared and initialised */
%option noyywrap
%option yylineno

%%
\/\/(.)*                            {
                                    }
"/*"                                { multiline_comment(); }
<<<<<<< HEAD
"#include"[ ]*"<"(_|{letter})({letter}|{number}|_)*".h>" {  
=======

"#include"[ ]*"<"(_|{letter})({letter}|{number}|_)*".h>" {
>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
                                        trace("Header File");
                                    }
[\n]                                {
                                    }
<<<<<<< HEAD
[{]                                 { 
=======

[{]                                 {
>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
                                        trace("{");
                                        return *yytext;
                                    }
[}]                                 {
                                        trace("}");
                                        return *yytext;
                                    }
<<<<<<< HEAD
\"[^"\n]*["\n]                      { 
=======

\"[^"\n]*["\n]                      {
>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
                                        if(yytext[yyleng-1]!='"'){
                                            yyerror("String is unclosed\n");
                                        }
                                        trace("CONSTANT_STRING");
                                        strcpy(yylval.char_ptr, yytext);
                                        return CONSTANT_STRING;
                                    }
<<<<<<< HEAD
int                                 { 
=======

int                                 {
>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
                                        trace("INT");
										strcpy(yylval.char_ptr, yytext);
                                        return INT;
                                    }
<<<<<<< HEAD
char                                { 
=======

float                               {
                                        trace("FLOAT");
										strcpy(yylval.char_ptr, yytext);
                                        return FLOAT;
                                    }
char                                {
>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
                                        trace("CHAR");
										strcpy(yylval.char_ptr, yytext);
                                        return CHAR;
                                    }
<<<<<<< HEAD
float                               { 
                                        trace("FLOAT");
										strcpy(yylval.char_ptr, yytext);
                                        return FLOAT;
                                    }
double                              { 
=======
double                              {
>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
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
<<<<<<< HEAD
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
"^="					            { 
                                        trace("^="); 
=======
"^="					            {
                                        trace("^=");
>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a
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
<<<<<<< HEAD
                                    }  
                                                                      
=======
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

>>>>>>> 9176f0a7a7b3fcf35904b80ae6f86ba722a2285a

(({number}({letter}|{number}|_)+)|.) { yyerror("Token  is  wrong"); }

%%

void multiline_comment()
{
    int abc;
    while ((abc = input()) != 0){

        if (abc == '*'){
          
	  while ((abc = input()) == '*');
           
	   if (abc=='/')
               return;

            if (abc== 0)
                break;
        }
    }     yyerror("Unterminated   Multiline   Comment");
}
