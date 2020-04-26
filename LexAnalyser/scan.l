/* Auxiliary declarations*/
%{
   #include "library/miscellaneous.h"
   #include "library/sym_tab.h"

   #define nodes_Max 10000
   sym_node_t *sym_tab[nodes_Max];
   sym_node_t *const_tab[nodes_Max];

   void print(char *knowledge, char *tokenVal, int lineNum);
%}

/* Normal definitions */

digit               [0-9]
letter              [A-Za-z]
alphanumeric        {letter}|{digit}
keyword              char|int|main|float|double|short|long|unsigned|signed|main|while|for|break|if|else|continue|return|void|struct
operator            "+"|"-"|"++"|"--"|"!"|"~"|"*"|"/"|"%"|">>"|"<<"|"&"|"^"|\||\|\||"="|">"|"<"|">="|"<="|"=="|"!="
function            ((_|{letter})({alphanumeric}|_)*)/[ ]*[(]
esc_seq             0|a|b|f|n|r|t|v|"\\"|"\""|"\'"

/* Rules for Pattern Matching */

%%
" "                                           {}
"\n"                                          {}
"#include"[ ]*"<"{letter}({alphanumeric})*".h>"   { print("PREPROCESSOR DIRECTIVE", yytext, yylineno); }
"#define"[ ]+(_|{letter})({alphanumeric})*[ ]*(.)+   { print("PREPROCESSOR DIRECTIVE", yytext, yylineno); }

"//".*                                       { print("SINGLE LINE COMMENT", yytext, yylineno); }
("/*")(([^*]*[*]+[^*/])*([^*]*[*]+[/]))      { print("MULTI LINE COMMENT", yytext, yylineno); }

("/*")(([^*]*([*]+[^/])*)*)*                 { print(F_R "ERROR: MULTI LINE COMMENT NOT CLOSED", yytext, yylineno); }

("\"")[^\n\"]*("\"")                         {
                                                print("STRING", yytext, yylineno);
                                                sym_tab_insert(const_tab, yytext, "String", yylineno);
                                             }
("\"")[^\n\"]*                               { print(F_R "ERROR: UNCLOSED STRING", yytext, yylineno); }

("\'")(("\\"({esc_seq}))|.)("\'")   {
                                                print("CHARACTER", yytext, yylineno);
                                                sym_tab_insert(const_tab, yytext, "Character", yylineno);
                                             }

("\'")(((("\\")[^0abfnrtv\\\"\'][^\n\']*))|[^\n\''][^\n\'']+)("\'") {
                                               print(F_R "ERROR: NOT A CHARACTER", yytext, yylineno); }

{keyword}/[ ]*[(]?                           {
                                                print("KEYWORD", yytext, yylineno);
                                             }

#include[/"<][ ]*{letter}{letter}*\.h[/">]   {
                                                print("HEADER", yytext, yylineno);
                                             }

{operator}                                   { print("OPERATOR", yytext, yylineno); }


{function}                                   {
                                                print("FUNCTION", yytext, yylineno);
                                                sym_tab_insert(sym_tab, yytext, "Function", yylineno);
                                             }

(_|{letter})({alphanumeric}|_)*                  {
                                                print("IDENTIFIER", yytext, yylineno);
                                                sym_tab_insert(sym_tab, yytext, "Identfier", yylineno);
                                             }

"-"?{digit}+                                 {
                                                print("INTEGER", yytext, yylineno);
                                                sym_tab_insert(const_tab, yytext, "Integer", yylineno);
                                             }

"-"?{digit}+\.({digit}+)?                    {
                                                print("FLOATING POINT", yytext, yylineno);
                                                sym_tab_insert(const_tab, yytext, "Floating point", yylineno);
                                             }

"["                                          { print("LEFT BRACKET", yytext, yylineno); }
"]"                                          { print("RIGHT BRACKET", yytext, yylineno); }
"("                                          { print("LEFT PARENTHESIS", yytext, yylineno); }
")"                                          { print("RIGHT PARENTHESIS", yytext, yylineno); }
"{"                                          { print("LEFT BRACE", yytext, yylineno); }
"}"                                          { print("RIGHT BRACE", yytext, yylineno); }
","                                          { print("COMMA", yytext, yylineno); }
";"                                          { print("SEMICOLON", yytext, yylineno); }

%%

void print(char *knowledge, char *tokenVal, int lineNum){
   printf(F_C "%-30s%-30s%-30d\n" CLEAR, knowledge, tokenVal, lineNum);
}

/* User SubRoutines from dir and libraries */

int main()
{

   printf(F_M "\n" DASH CLEAR);
   printf(F_C "\t\t\tLexical Analyser for language of C\n" CLEAR);
   printf(F_M DASH "\n" CLEAR);

   printf(F_G "%-30s%-30s%-30s\n", "TOKEN TYPE", "TOKEN VALUE", "LINE NUMBER" CLEAR);

   yylex();

   sym_tab_print(sym_tab, "Symbol Table");
   sym_tab_print(const_tab, "Constant Table");

   return 0;
}
