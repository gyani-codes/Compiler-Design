
%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/symbol_table.h"
#include "lib/scope.h"
#include "lib/misc.h"

#define TRACE_ENABLED false

// Number of rows in Hash table for symbol and constant tables
#define MAX_NODES 1000

void yyerror(const char * s);

symbol_node_t *symbol_table[MAX_NODES];
symbol_node_t *constant_table[MAX_NODES];

// To track the current scope so that out of scope errors can be found
scope_node_t *curr_scope;

extern char *yytext;
extern int yylineno;

char datatype[100];
int num_params;

symbol_node_t * check_redefined_error(char *symbol);

%}

%token INCLUDE

// To allow for mutiple datatypes
%union {
	char char_pointer[100];
}

%token <char_pointer> IDENTIFIER
%token <char_pointer> INT
%token <char_pointer> CHAR
%token <char_pointer> FLOAT
%token <char_pointer> DOUBLE
%token <char_pointer> VOID

%type <char_pointer> Type

%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN         
%left LOGIC_AND LOGIC_OR NOT INCREMENT_OPERATOR DECREMENT_OPERATOR
%left LESSER_EQUAL GREATER_EQUAL DOUBLE_EQUAL NOT_EQUAL LESSER_THAN GREATER_THAN             
%left '+' '-' '*' '/' '%' '^' '&' 


// %token INT FLOAT CHAR DOUBLE VOID RETURN
%token SIGNED UNSIGNED LONG SHORT
%token SWITCH BREAK CONTINUE CASE DEFAULT RETURN
%token FOR WHILE DO
%token IF ELSE  
%token <char_pointer> CONSTANT_INTEGER
%token <char_pointer> CONSTANT_FLOAT
%token <char_pointer> CONSTANT_STRING
%token <char_pointer> CONSTANT_CHAR


%start Begin //	start symbol

%% 
Begin   
    : Include
    | Include Begin
    | Declaration
    | Declaration Begin
	| Function_Definition
    | Function_Definition Begin
    | Function_Declaration
    | Function_Declaration Begin
	;

Declaration
    :  Type Identifier_List ';'    
    ;


Function_Declaration
    : Type IDENTIFIER Bracket_open Formal_Param_List ')' ';' {          
                                                        check_redeclaration_error($2);                  
                                                        char funcType[100] = "Function: ";
                                                        strcat(funcType, datatype);
                                                        symbol_node_t *node = sym_tab_insert(symbol_table,$2, curr_scope->scope_num, funcType, "", yylineno);
                                                        node->is_function_defined = false;
                                                        node->num_params = num_params;
                                                    }
    ;

Function_Definition
	: Type IDENTIFIER Bracket_open Formal_Param_List ')' Compound_Statement      {          
                                                                            symbol_node_t *node = check_redefined_error($2);
                                                                            char funcType[100] = "Function: ";
                                                                            strcat(funcType, datatype);
                                                                            if(!node) {
                                                                                symbol_node_t *node = sym_tab_insert(symbol_table,$2, curr_scope->scope_num, funcType, "", yylineno);
                                                                                node->num_params = num_params;
                                                                            }
                                                                            else {
                                                                                node->is_function_defined = true;
                                                                                node->num_params = num_params;
                                                                            }
                                                                        }
	;

Bracket_open
    : '('                                                               { num_params = 0; }
    ;

Identifier_List
    : Array_Notation
    | IDENTIFIER ',' Identifier_List        {   check_redeclaration_error($1);
                                                sym_tab_insert(symbol_table,$1 , curr_scope->scope_num, datatype, "", yylineno);
                                            }
    | '*' IDENTIFIER ',' Identifier_List    {
                                                check_redeclaration_error($2);
                                                int len = strlen(datatype);
                                                datatype[len] = '*';
                                                datatype[len +1] = '\0';
                                                sym_tab_insert(symbol_table,$2 , curr_scope->scope_num, datatype, "", yylineno);
                                                datatype[len] = '\0';
                                            }
    | Array_Notation ',' Identifier_List 
    | IDENTIFIER                            {   
                                                check_redeclaration_error($1);
                                                sym_tab_insert(symbol_table,$1 , curr_scope->scope_num, datatype, "", yylineno);} 
    | '*' IDENTIFIER                        {
                                                check_redeclaration_error($2);
                                                int len = strlen(datatype);
                                                datatype[len] = '*';
                                                datatype[len +1] = '\0';
                                                sym_tab_insert(symbol_table,$2 , curr_scope->scope_num, datatype, "", yylineno);
                                                datatype[len] = '\0';
                                            }
    | Define_Assign ',' Identifier_List
    | Define_Assign 
    ;


Formal_Param_List
	: VOID
    | Type IDENTIFIER                                  { num_params++; check_void_parameter_error($1); sym_tab_insert(symbol_table,$2 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 1\n");}
	| Type '*' IDENTIFIER                              { num_params++; check_void_parameter_error($1); sym_tab_insert(symbol_table,$3 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 2\n");}
	| Type Array_Notation                              { num_params++; check_void_parameter_error($1); trace("Formal_Param_List Rule 3\n");}
	| Type IDENTIFIER ',' Formal_Param_List            { num_params++; check_void_parameter_error($1); sym_tab_insert(symbol_table,$2 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 4\n");}
	| Type '*' IDENTIFIER ',' Formal_Param_List        { num_params++; check_void_parameter_error($1); sym_tab_insert(symbol_table,$3 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 5\n");}
	| Type Array_Notation ',' Formal_Param_List        { num_params++; check_void_parameter_error($1); trace("Formal_Param_List Rule 6\n");}
	|
	;


Modifiers
    : SHORT | LONG | UNSIGNED | SIGNED
    ;

Array_Notation
    : IDENTIFIER '[' CONSTANT_INTEGER ']' {   
                                        char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                        check_array_dimension_error($1, $3);
                                        sym_tab_insert(symbol_table,$1, curr_scope->scope_num, arrayType, $3, yylineno);
                                        check_array_subscript_error($1);
                                    }
    | '*' IDENTIFIER '[' CONSTANT_INTEGER ']' {   
                                        check_redeclaration_error($2);
                                        check_array_dimension_error($2, $4);
                                        int len = strlen(datatype);
                                        datatype[len] = '*';
                                        datatype[len +1] = '\0';                                
                                        char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                        sym_tab_insert(symbol_table,$2, curr_scope->scope_num, arrayType, $4, yylineno);
                                        datatype[len] = '\0';
                                        check_array_subscript_error($2);
                                    }
    | '&' IDENTIFIER '[' CONSTANT_INTEGER ']' {
                                        check_redeclaration_error($2);
                                        check_array_dimension_error($2, $4);
                                        char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                        sym_tab_insert(symbol_table,$2, curr_scope->scope_num, arrayType, $4, yylineno);
                                        check_array_subscript_error($2);
                                    }
    | IDENTIFIER '[' '-' CONSTANT_INTEGER ']' {   
                                        yyerror(strcat($1, " has non-positive array size"));
                                    }
    | '*' IDENTIFIER '[' '-' CONSTANT_INTEGER ']' {   
                                        yyerror(strcat($2, " has non-positive array size"));
                                    }
    | '&' IDENTIFIER '[' '-' CONSTANT_INTEGER ']' {
                                        yyerror(strcat($2, " has non-positive array size"));
                                    }
    ;

Type
    : INT                       { strcpy($$, $1); strcpy(datatype, $1);}
    | FLOAT                     { strcpy($$, $1); strcpy(datatype, $1);}
    | VOID                      { strcpy($$, $1); strcpy(datatype, $1);}
    | CHAR                      { strcpy($$, $1); strcpy(datatype, $1);}
    | DOUBLE                    { strcpy($$, $1); strcpy(datatype, $1);}
    | Modifiers INT             { strcpy(datatype, $2);}
    | Modifiers FLOAT           { strcpy(datatype, $2);}
    | Modifiers DOUBLE          { strcpy(datatype, $2);}
    | Modifiers CHAR            { strcpy(datatype, $2);}
    ;


Define_Assign
    : IDENTIFIER Assignment_Operator Expression             {
                                                                //check_redeclaration_error($1);
                                                                sym_tab_insert(symbol_table,$1 , curr_scope->scope_num, datatype, "", yylineno);trace("Define_Assign Rule 1\n");
                                                            }  
    | '*' IDENTIFIER Assignment_Operator Expression         {
                                                                //check_redeclaration_error($2);
                                                                sym_tab_insert(symbol_table,$2 , curr_scope->scope_num, datatype, "", yylineno);
                                                            }
    | Array_Notation Assignment_Operator Expression                
    ;

Param_List
    : Expression                                            { num_params++; }
    | Expression ',' Param_List                             { num_params++; }
    | 
    ;

Assignment
    : IDENTIFIER Assignment_Operator Expression           { check_scope_error($1); trace("Assignment Rule 1\n");}
    | '*' IDENTIFIER Assignment_Operator Expression       { check_scope_error($2); trace("Assignment Rule 2\n");}  
    | Array_Notation Assignment_Operator Expression       { trace("Array Element Assign Rule"); }
    | Primary
    ;

    Assignment_Operator
	: '='
    | ADD_ASSIGN
    | SUB_ASSIGN
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;



Expression
    : Logical_Expression
    ;

Logical_Expression
    : Relational_Expression
    | Logical_Expression LOGIC_AND Relational_Expression
    | Logical_Expression LOGIC_OR Relational_Expression
    | NOT Relational_Expression 
    ;

Relational_Expression
    : Additive_Expression
    | Relational_Expression GREATER_THAN Additive_Expression
    | Relational_Expression LESSER_THAN Additive_Expression
    | Relational_Expression GREATER_EQUAL Additive_Expression
    | Relational_Expression LESSER_EQUAL Additive_Expression
    | Relational_Expression DOUBLE_EQUAL Additive_Expression
    | Relational_Expression NOT_EQUAL Additive_Expression
    ;

Additive_Expression
    : Multiplicative_Expression
    | Additive_Expression '+' Multiplicative_Expression
    | Additive_Expression '-' Multiplicative_Expression
    ;

Multiplicative_Expression
    : Primary
    | Multiplicative_Expression '*' Primary
    | Multiplicative_Expression '/' Primary
    | Multiplicative_Expression '%' Primary
    ;

Compound_Statement
    : Scope_Start Statement_List Scope_End
	;

Scope_Start
    : '{'   {   curr_scope = add_child_scope(curr_scope);   }
    ;


Scope_End
    : '}'   {   curr_scope = goto_parent_scope(curr_scope);   }
    ;

Statement_List
    : Statement Statement_List
    | Compound_Statement Statement_List
    |
    ;

Statement
    : While_Statement 
    | Declaration   
    | For_Statement  
    | If_Statement  
    | Assignment    ';'
    | Expression ';'
    | Return_Statement    
    | Do_While_Statement      
    | BREAK ';'
    | CONTINUE ';'                    
	| ';'
    ; 

Return_Statement
    : RETURN Expression ';'   {trace("Return_Statement Call\n");}
    ;

While_Statement
    : WHILE '(' Expression ')' Statement                                                        
    | WHILE '(' Expression ')' Compound_Statement
    ;

Do_While_Statement
    : DO Compound_Statement WHILE '(' Expression ')' ';'
    ;


For_Statement
    : FOR '(' Assignment ';' Expression ';' Assignment ')' Statement 
    | FOR '(' Assignment ';' Expression ';' Assignment ')' Compound_Statement 
    ;

If_Statement
    : IF '(' Expression ')' Statement Else_Statement     
    | IF '(' Expression ')' Compound_Statement Else_Statement
    ;

Else_Statement
    : ELSE Compound_Statement
    | ELSE Statement
    |
    ;

Function_Call
    : IDENTIFIER Bracket_open Param_List ')'     { check_scope_error($1); parameter_check($1); is_function($1); /*sym_tab_insert(symbol_table, $1, curr_scope->scope_num, "Function", "", yylineno);trace("Function Call\n"); */} 
    ;

Include_Statement
	: '#' INCLUDE LESSER_THAN IDENTIFIER GREATER_THAN   {check_scope_error($4);}
	| '#' INCLUDE LESSER_THAN IDENTIFIER '.' IDENTIFIER GREATER_THAN    {check_scope_error($4);check_scope_error($6);}
	;

Include
	: Include_Statement
	;



Primary
    : '(' Expression ')'
    | '(' Assignment ')'
    | CONSTANT_INTEGER     {sym_tab_insert(constant_table, $1, -1, "int", "", yylineno); trace("CONSTANT_INTEGER\n");}
    | CONSTANT_FLOAT       {sym_tab_insert(constant_table, $1, -1, "float", "", yylineno); trace("CONSTANT_FLOAT\n");}
    | CONSTANT_CHAR        {sym_tab_insert(constant_table, $1, -1, "char", "", yylineno); trace("CONSTANT_CHAR\n");}
    | CONSTANT_STRING      {sym_tab_insert(constant_table, $1, -1, "string", "", yylineno); trace("CONSTANT_STRING\n");}
    | IDENTIFIER           {check_scope_error($1);trace("Primary Identifier\n");}
    | '*' IDENTIFIER       {check_scope_error($2);trace("Pointer Identifier\n");}
    | '&' IDENTIFIER       {check_scope_error($2);trace("Address of Identifier\n");}
    | '-' Primary
    | '+' Primary
    | Array_Notation
    | Function_Call
    | INCREMENT_OPERATOR IDENTIFIER     {check_scope_error($2);}
    | IDENTIFIER INCREMENT_OPERATOR     {check_scope_error($1);}
    | DECREMENT_OPERATOR IDENTIFIER     {check_scope_error($2);}
    | IDENTIFIER DECREMENT_OPERATOR     {check_scope_error($1);}
    ;


%%

// The function check_scope_error() is used to check wheather a identifier(symbol) is declared in the legal scope or not

inline void check_scope_error(char *symbol){
    if(!scope_check(symbol_table, symbol, curr_scope)){
        yyerror(strcat(symbol, " is not defined in the legal scope"));
    }
}

// The function parameter_check() checks the count of the total number of parameter of a function i:e wheather there are less arguments // or extra arguments 

inline void parameter_check(char *symbol) {

    symbol_node_t *node = scope_check(symbol_table, symbol, curr_scope);
    if(node != NULL && num_params > node->num_params) {
        char msg[100] = "Too many arguments for the function ";
        yyerror(strcat(msg, symbol));
    }
    else if(node != NULL && num_params < node->num_params) {
        char msg[100] = "Too few arguments arguments for the function  ";
        yyerror(strcat(msg, symbol));
    }
}

// The function check_redeclaration_error checks wheather a identifier or a function is already declared or not. If it is already     // declared, it throws an error

inline void check_redeclaration_error(char *symbol){
    if(check_in_current_scope(symbol_table, symbol, curr_scope)){
        yyerror(strcat(symbol, " already declared in current scope"));
    }
}

// The function check_redefined_error checks wheather a function is already defined or not. If it is already defined, it throws an error

symbol_node_t * check_redefined_error(char *symbol){
    symbol_node_t *node = scope_check(symbol_table, symbol, curr_scope);
    if(node != NULL && node->is_function_defined)
        yyerror(strcat(symbol, " is already defined in the current scope"));

    return node;
}


// The function is check_array_dimension_error is responsible for checking thee dimension of the error such that the dimension would be // >=0, If it is not it throws an error

inline void check_array_dimension_error(char *symbol, char *arr_size){
    if(atoi(arr_size) < 1){
        yyerror(strcat(symbol, " has array size <=0 "));
    }
}


// The function check_array_subscript_error checks wheather the symbol is an array or not by checking the syntax of array

inline void check_array_subscript_error(char *symbol){
    symbol_node_t *node = sym_tab_arrayLook(symbol_table, symbol);
    if(!strstr(node->type, "Array")){
        yyerror(strcat(symbol, " is not an array"));
    }
}


// This function checks wheather a function's parameter's datatype should not be void

inline void check_void_parameter_error(char *type) {
    if(!strcmp(type, "void")) {
        yyerror("Parameter of function has void datatype");
    }
}


// The function is_function checks wheather a symbol is a function or not

inline void is_function(char *func_name) {
    
    symbol_node_t *node = sym_tab_arrayLook(symbol_table, func_name);
    if(node == NULL) {
        yyerror(strcat(func_name, " function is not declared"));                                        
    }
    if(!strstr(node->type, "Function")) {
        yyerror(strcat(func_name, " is not a function"));
    }
}

inline void trace(char *s){
    if(TRACE_ENABLED)
        fprintf(stderr, FORE_CYN "%-20.20s%20.20s%20d\n" RESET, s, yytext, yylineno);
}


int main()
{
	// initialising current scope
    curr_scope = init_scope();    
    sym_tab_init(symbol_table);
    sym_tab_init(constant_table);

    yyparse();

    printf(FORE_GRN "\n\n Parsing successfully completed  ✔ \n\n" RESET); 
    
    sym_tab_free(symbol_table);
    sym_tab_free(constant_table);
    // TODO: Free Scope
    
    return 0;
}


//This function is the error  function. Whenever any error is found in during parsing, the corresponding function calls this function // to display the error and to stop parsing.

void yyerror(const char *s) {
	printf(FORE_RED "%d : %s %s\n" RESET, yylineno, s, yytext );
    printf(FORE_RED "\nParsing failed because of symantic error  \n\n" RESET);
    exit(-2);
}
