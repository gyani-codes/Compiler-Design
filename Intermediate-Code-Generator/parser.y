/*
* Parser for C language
*
* Ref: http://www.quut.com/c/ANSI-C-grammar-y.html
*
* @author Shashank P, Praveen Gupta, Ashwin Joisa
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/symbol_table.h"
#include "lib/scope.h"
#include "lib/misc.h"
#include "lib/stack.h"

#define TRACE_ENABLED false

// Number of rows in Hash table for symbol and constant tables
#define MAX_NODES 1000

void yyerror(const char * s);

symbol_node_t *symbol_table[MAX_NODES];
symbol_node_t *constant_table[MAX_NODES];

scope_node_t *curr_scope;

extern char *yytext;
extern int yylineno;

char datatype[100];
int num_params;

symbol_node_t * redefined_error_check(char *symbol);


// ICG 3-address-code
stack *three_address_code_stack;
TAC_code_stack *TAC_code;

TAC_buffer_node *curr_buff = NULL;
bool BUFFER_ENABLED = true;
// If BUFFER_ENABLED is true, TAC is directed to a buffer instead of stdout

char temp_buf[100];
int LABEL_COUNT = 1;
int loopStartLabel = -1, loopEndLabel = -1;
%}

// %token INT FLOAT CHAR DOUBLE VOID RETURN
%token SIGNED UNSIGNED LONG SHORT
%token SWITCH BREAK CONTINUE CASE DEFAULT RETURN
%token FOR WHILE DO
%token IF ELSE  
%token <char_ptr> CONSTANT_INTEGER
%token <char_ptr> CONSTANT_FLOAT
%token <char_ptr> CONSTANT_STRING
%token <char_ptr> CONSTANT_CHAR

%token INCLUDE

// To allow for mutiple datatypes
%union {
	char char_ptr[100];
    int intval;
}

%token <char_ptr> IDENTIFIER
%token <char_ptr> INT
%token <char_ptr> CHAR
%token <char_ptr> FLOAT
%token <char_ptr> DOUBLE
%token <char_ptr> VOID

%type <char_ptr> Type
%type <intval> IfNotGoto ElseNotGoto NotWhileGoto NotWhileLabel NotDoWhileLabel RepeatForLabel ForExitGoto

%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN         
%left LOGIC_AND LOGIC_OR NOT INCREMENT_OPERATOR DECREMENT_OPERATOR
%left LESSER_EQUAL GREATER_EQUAL DOUBLE_EQUAL NOT_EQUAL LESSER_THAN GREATER_THAN             
%left '+' '-' '*' '/' '%' '^' '&' 

%nonassoc IfWithoutElse
%nonassoc ELSE

%start Begin

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

Identifier_List
    : Array_Notation
    | IDENTIFIER ',' Identifier_List        {   redeclaration_error_check($1);
                                                symbol_table_insert(symbol_table,$1 , curr_scope->scope_num, datatype, "", yylineno);
                                            }
    | '*' IDENTIFIER ',' Identifier_List    {
                                                redeclaration_error_check($2);
                                                int len = strlen(datatype);
                                                datatype[len] = '*';
                                                datatype[len +1] = '\0';
                                                symbol_table_insert(symbol_table,$2 , curr_scope->scope_num, datatype, "", yylineno);
                                                datatype[len] = '\0';
                                            }
    | Array_Notation ',' Identifier_List 
    | IDENTIFIER                            {   
                                                redeclaration_error_check($1);
                                                symbol_table_insert(symbol_table,$1 , curr_scope->scope_num, datatype, "", yylineno);} 
    | '*' IDENTIFIER                        {
                                                redeclaration_error_check($2);
                                                int len = strlen(datatype);
                                                datatype[len] = '*';
                                                datatype[len +1] = '\0';
                                                symbol_table_insert(symbol_table,$2 , curr_scope->scope_num, datatype, "", yylineno);
                                                datatype[len] = '\0';
                                            }
    | Define_Assign ',' Identifier_List
    | Define_Assign 
    ;

Function_Declaration
        : Type IDENTIFIER Bracket_open Formal_Param_List ')' ';'    {          
                                                                        redeclaration_error_check($2);                  
                                                                        char funcType[100] = "Function: ";
                                                                        strcat(funcType, datatype);
                                                                        symbol_node_t *node = symbol_table_insert(symbol_table,$2, curr_scope->scope_num, funcType, "", yylineno);
                                                                        node->is_function_defined = false;
                                                                        node->num_params = num_params;
                                                                    }
    ;

Function_Definition
	: Type IDENTIFIER 
        Bracket_open Formal_Param_List ')' 
                            {   curr_buff = get_new_node(TAC_code);
                                sprintf(temp_buf, "Func %s begin:\n", $2);
                                strcat(curr_buff->code, temp_buf);
                            }
        Compound_Statement     {          
                                    symbol_node_t *node = redefined_error_check($2);
                                    char funcType[100] = "Function: ";
                                    strcat(funcType, datatype);
                                    if(!node) {
                                        symbol_node_t *node = symbol_table_insert(symbol_table,$2, curr_scope->scope_num, funcType, "", yylineno);
                                        node->num_params = num_params;
                                    }
                                    else {
                                        node->is_function_defined = true;
                                        node->num_params = num_params;
                                    }

                                    curr_buff = get_new_node(TAC_code);
                                    sprintf(temp_buf, "Func end\n");
                                    strcat(curr_buff->code, temp_buf);
                                }
	;

Bracket_open
    : '('                                                               { num_params = 0; }
    ;

Formal_Param_List
	: VOID
    | Type IDENTIFIER                                  { num_params++; void_param_check($1); symbol_table_insert(symbol_table,$2 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 1\n");}
	| Type '*' IDENTIFIER                              { num_params++; void_param_check($1); symbol_table_insert(symbol_table,$3 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 2\n");}
	| Type Array_Notation                              { num_params++; void_param_check($1); trace("Formal_Param_List Rule 3\n");}
	| Type IDENTIFIER ',' Formal_Param_List            { num_params++; void_param_check($1); symbol_table_insert(symbol_table,$2 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 4\n");}
	| Type '*' IDENTIFIER ',' Formal_Param_List        { num_params++; void_param_check($1); symbol_table_insert(symbol_table,$3 , curr_scope->scope_num, $1, "", yylineno);trace("Formal_Param_List Rule 5\n");}
	| Type Array_Notation ',' Formal_Param_List        { num_params++; void_param_check($1); trace("Formal_Param_List Rule 6\n");}
	|
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

Modifiers
    : SHORT | LONG | UNSIGNED | SIGNED
    ;

Array_Notation
    : IDENTIFIER '[' CONSTANT_INTEGER ']'   {   
                                                char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                                arr_dimension_check($1, $3);
                                                symbol_table_insert(symbol_table,$1, curr_scope->scope_num, arrayType, $3, yylineno);
                                                arr_subscript_check($1);
                                            }
    | '*' IDENTIFIER '[' CONSTANT_INTEGER ']'   {   
                                                    redeclaration_error_check($2);
                                                    arr_dimension_check($2, $4);
                                                    int len = strlen(datatype);
                                                    datatype[len] = '*';
                                                    datatype[len +1] = '\0';                                
                                                    char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                                    symbol_table_insert(symbol_table,$2, curr_scope->scope_num, arrayType, $4, yylineno);
                                                    datatype[len] = '\0';
                                                    arr_subscript_check($2);
                                                }
    | '&' IDENTIFIER '[' CONSTANT_INTEGER ']'   {
                                                    redeclaration_error_check($2);
                                                    arr_dimension_check($2, $4);
                                                    char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                                    symbol_table_insert(symbol_table,$2, curr_scope->scope_num, arrayType, $4, yylineno);
                                                    arr_subscript_check($2);
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



Define_Assign
    : IDENTIFIER Assignment_Operator Expression             {
                                                                //redeclaration_error_check($1);
                                                                symbol_table_insert(symbol_table,$1 , curr_scope->scope_num, datatype, "", yylineno);
                                                                trace("Define_Assign Rule 1\n");

                                                                stack_node op = pop_stack(three_address_code_stack);
                                                                curr_buff = get_new_node(TAC_code);
                                                                push_stack(three_address_code_stack, $1);
                                                                
                                                                if(BUFFER_ENABLED) {
                                                                    sprintf(temp_buf, "%s = %s\n", $1, op.var_name);
                                                                    strcat(curr_buff->code, temp_buf);
                                                                }
                                                                else
                                                                    printf("%s = %s\n", $1, op.var_name);

                                                            }  
    | '*' IDENTIFIER Assignment_Operator Expression         {
                                                                //redeclaration_error_check($2);
                                                                symbol_table_insert(symbol_table,$2 , curr_scope->scope_num, datatype, "", yylineno);
                                                            }
    | Array_Notation Assignment_Operator Expression                
    ;

Param_List
    : Expression                                            { num_params++; }
    | Expression ',' Param_List                             { num_params++; }
    | 
    ;

Assignment
    : IDENTIFIER Assignment_Operator Expression             { 
                                                                scope_error_check($1); 
                                                                trace("Assignment Rule 1\n");

                                                                stack_node op = pop_stack(three_address_code_stack);
                                                                curr_buff = get_new_node(TAC_code);
                                                                push_stack(three_address_code_stack, $1);

                                                                if(BUFFER_ENABLED) {
                                                                    sprintf(temp_buf, "%s = %s\n", $1, op.var_name);
                                                                    strcat(curr_buff->code, temp_buf);
                                                                }
                                                                else
                                                                    printf("%s = %s\n", $1, op.var_name);

                                                            }
    | '*' IDENTIFIER Assignment_Operator Expression         { scope_error_check($2); trace("Assignment Rule 2\n");}  
    | Array_Notation Assignment_Operator Expression         { trace("Array Element Assign Rule"); }
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
    | Logical_Expression LOGIC_AND Relational_Expression    {  
                                                                char op[3] = "&&";
                                                                print_TAC_operator(op);
                                                            }
    | Logical_Expression LOGIC_OR Relational_Expression     {  
                                                                char op[3] = "||";
                                                                print_TAC_operator(op);
                                                            }
    | NOT Relational_Expression                             {
                                                                stack_node op = pop_stack(three_address_code_stack);
                                                                curr_buff = get_new_node(TAC_code);
                                                                push_stack(three_address_code_stack, TEMP_VAR);
                                                                print_stack_top(three_address_code_stack, curr_buff);

                                                                if(BUFFER_ENABLED) {
                                                                    sprintf(temp_buf, " = NOT %s\n", op.var_name);
                                                                    strcat(curr_buff->code, temp_buf);
                                                                }
                                                                else
                                                                    printf(" = NOT %s\n", op.var_name);
                                                            }
    ;

Relational_Expression
    : Additive_Expression
    | Relational_Expression GREATER_THAN Additive_Expression    {  
                                                                    char op[3] = ">";
                                                                    print_TAC_operator(op);
                                                                }
    | Relational_Expression LESSER_THAN Additive_Expression     {  
                                                                    char op[3] = "<";
                                                                    print_TAC_operator(op);
                                                                }
    | Relational_Expression GREATER_EQUAL Additive_Expression   {  
                                                                    char op[3] = ">=";
                                                                    print_TAC_operator(op);
                                                                }
    | Relational_Expression LESSER_EQUAL Additive_Expression    {  
                                                                    char op[3] = "<=";
                                                                    print_TAC_operator(op);
                                                                }
    | Relational_Expression DOUBLE_EQUAL Additive_Expression    {  
                                                                    char op[3] = "==";
                                                                    print_TAC_operator(op);
                                                                }
    | Relational_Expression NOT_EQUAL Additive_Expression       {  
                                                                    char op[3] = "<>";
                                                                    print_TAC_operator(op);
                                                                }
    ;

Additive_Expression
    : Multiplicative_Expression
    | Additive_Expression '+' Multiplicative_Expression {  
                                                            char op[3] = "+";
                                                            print_TAC_operator(op);
                                                        }
    | Additive_Expression '-' Multiplicative_Expression {
                                                            char op[3] = "-";
                                                            print_TAC_operator(op);
                                                        }

    ;

Multiplicative_Expression
    : Primary
    | Multiplicative_Expression '*' Primary             {
                                                            char op[3] = "*";
                                                            print_TAC_operator(op);
                                                        }
    | Multiplicative_Expression '/' Primary             {
                                                            char op[3] = "-";
                                                            print_TAC_operator(op);
                                                        } 
    | Multiplicative_Expression '%' Primary             {
                                                            char op[3] = "%";
                                                            print_TAC_operator(op);
                                                        }
    ;

Primary
    : '(' Expression ')'    
    | '(' Assignment ')'
    | CONSTANT_INTEGER     {push_stack(three_address_code_stack, $1);symbol_table_insert(constant_table, $1, -1, "int", "", yylineno); trace("CONSTANT_INTEGER\n");}
    | CONSTANT_FLOAT       {push_stack(three_address_code_stack, $1);symbol_table_insert(constant_table, $1, -1, "float", "", yylineno); trace("CONSTANT_FLOAT\n");}
    | CONSTANT_CHAR        {push_stack(three_address_code_stack, $1);symbol_table_insert(constant_table, $1, -1, "char", "", yylineno); trace("CONSTANT_CHAR\n");}
    | CONSTANT_STRING      {push_stack(three_address_code_stack, $1);symbol_table_insert(constant_table, $1, -1, "string", "", yylineno); trace("CONSTANT_STRING\n");}
    | IDENTIFIER           {push_stack(three_address_code_stack, $1); scope_error_check($1);trace("Primary Identifier\n");}
    | '*' IDENTIFIER       {push_stack(three_address_code_stack, $2); scope_error_check($2);trace("Pointer Identifier\n");}
    | '&' IDENTIFIER       {push_stack(three_address_code_stack, $2); scope_error_check($2);trace("Address of Identifier\n");}
    | '-' Primary
    | '+' Primary
    | Array_Notation
    | Function_Call
    | INCREMENT_OPERATOR IDENTIFIER     {scope_error_check($2);}
    | IDENTIFIER INCREMENT_OPERATOR     {scope_error_check($1);}
    | DECREMENT_OPERATOR IDENTIFIER     {scope_error_check($2);}
    | IDENTIFIER DECREMENT_OPERATOR     {scope_error_check($1);}
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
    | BREAK ';' {  
                    curr_buff = get_new_node(TAC_code);
                    sprintf(temp_buf, "GOTO L%d:\n", loopEndLabel);
                    strcat(curr_buff->code, temp_buf); 
                }
    | CONTINUE ';'  {  
                    curr_buff = get_new_node(TAC_code);
                    sprintf(temp_buf, "GOTO L%d:\n", loopStartLabel);
                    strcat(curr_buff->code, temp_buf); 
                }                  
	| ';'
    ; 

Return_Statement
    : RETURN Expression ';'   {trace("Return_Statement Call\n");}
    ;

While_Statement
    : WHILE NotWhileLabel '(' Expression ')' NotWhileGoto Statement                 {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "GOTO L%d\n", $2);
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "\nL%d:\n", $6);
                                                                                    }                                                    
    | WHILE NotWhileLabel '(' Expression ')' NotWhileGoto Compound_Statement        {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "GOTO L%d\n", $2);
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "\nL%d:\n", $6);
                                                                                    }  
    ;

NotWhileLabel
    :   {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "L%d:\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopStartLabel = LABEL_COUNT;
            $$ = LABEL_COUNT++;
        }
    ;

NotWhileGoto
    :   {
            stack_node reg = pop_stack(three_address_code_stack);
            curr_buff = get_new_node(TAC_code);
        
            sprintf(temp_buf, "IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopEndLabel = LABEL_COUNT;

            $$ = LABEL_COUNT++;        
        }
    ;

Do_While_Statement
    : DO NotDoWhileLabel Compound_Statement WHILE '(' Expression ')' ';'                {
                                                                                            stack_node reg = pop_stack(three_address_code_stack);
                                                                                            curr_buff = get_new_node(TAC_code);
                                                                                        
                                                                                            sprintf(temp_buf, "IF %s GOTO L%d\n", reg.var_name, $2);
                                                                                            strcat(curr_buff->code, temp_buf);
                                                                                        }
    ;

NotDoWhileLabel 
    :   {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "L%d:\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopStartLabel = LABEL_COUNT;

            $$ = LABEL_COUNT++;
        }
    ;

For_Statement
    : FOR '(' Assignment ';' RepeatForLabel Expression ';' ForExitGoto Assignment IncTop
        ')' Statement                                                                       {
                                                                                                TAC_buffer_node *temp = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top];
                                                                                                TAC_code->stack_arr[TAC_code->top] = NULL;

                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top -2];
                                                                                                TAC_code->stack_arr[TAC_code->top -2] = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                TAC_code->stack_arr[TAC_code->top -1] = NULL;
                                                                                                TAC_code->top -= 2;

                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "GOTO L%d\n", $5);
                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "\nL%d:\n", $8);
                                                                                            }
    | FOR '(' Assignment ';' RepeatForLabel Expression ';' ForExitGoto Assignment IncTop
        ')' Compound_Statement                                                              {
                                                                                                TAC_buffer_node *temp = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top];
                                                                                                TAC_code->stack_arr[TAC_code->top] = NULL;

                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top -2];
                                                                                                TAC_code->stack_arr[TAC_code->top -2] = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                TAC_code->stack_arr[TAC_code->top -1] = NULL;
                                                                                                TAC_code->top -= 2;

                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "GOTO L%d\n", $5);
                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "\nL%d:\n", $8);
                                                                                            }
    ;

IncTop
    : { TAC_code->top++; }
    ;

RepeatForLabel
    :   {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "L%d:\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopStartLabel = LABEL_COUNT;
            $$ = LABEL_COUNT++;
        }
    ;

ForExitGoto
    :   {
            stack_node reg = pop_stack(three_address_code_stack);
            curr_buff = get_new_node(TAC_code);
            
            sprintf(temp_buf, "IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopEndLabel = LABEL_COUNT;

            $$ = LABEL_COUNT++;
            TAC_code->top++;
        } 

If_Statement
    : IF '(' Expression ')' IfNotGoto Statement                                     {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $5);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } %prec IfWithoutElse
    | IF '(' Expression ')' IfNotGoto Compound_Statement                            {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $5);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } %prec IfWithoutElse
    
    | IF '(' Expression ')' IfNotGoto Statement ELSE ElseNotGoto                         {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $5);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } 
        Statement                                                                   {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $8);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } %prec ELSE
    
    | IF '(' Expression ')' IfNotGoto Statement ELSE ElseNotGoto                    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $5);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } 
        Compound_Statement                                                          {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $8);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } %prec ELSE
    
    | IF '(' Expression ')' IfNotGoto Compound_Statement ELSE ElseNotGoto           {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $5);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } 
        Statement                                                                   {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $8);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } %prec ELSE
    
    | IF '(' Expression ')' IfNotGoto Compound_Statement ELSE ElseNotGoto           {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $5);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } 
        Compound_Statement                                                          {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", $8);
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    } %prec ELSE
    
    ;

IfNotGoto
    :   {
            stack_node reg = pop_stack(three_address_code_stack);
            curr_buff = get_new_node(TAC_code);
            
            if(BUFFER_ENABLED) {
                sprintf(temp_buf, "IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);
                strcat(curr_buff->code, temp_buf);
            }
            else
                printf("IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);

            $$ = LABEL_COUNT++;
        }
    ;

ElseNotGoto
    :   {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "GOTO L%d\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            $$ = LABEL_COUNT++;
        }
    ;

Function_Call
    : IDENTIFIER Bracket_open Param_List ')'     { scope_error_check($1); num_param_check($1); check_is_function($1); /*symbol_table_insert(symbol_table, $1, curr_scope->scope_num, "Function", "", yylineno);trace("Function Call\n"); */} 
    ;

Include_Statement
	: '#' INCLUDE LESSER_THAN IDENTIFIER GREATER_THAN   {scope_error_check($4);}
	| '#' INCLUDE LESSER_THAN IDENTIFIER '.' IDENTIFIER GREATER_THAN    {scope_error_check($4);scope_error_check($6);}
	;

Include
	: Include_Statement
	;


%%

inline void print_TAC_operator(char *op) {

    curr_buff = get_new_node(TAC_code);
    stack_node op2 = pop_stack(three_address_code_stack);
    stack_node op1 = pop_stack(three_address_code_stack);
    
    push_stack(three_address_code_stack, TEMP_VAR);
    print_stack_top(three_address_code_stack, curr_buff);
    
    if(BUFFER_ENABLED) {
        sprintf(temp_buf, " = %s %s %s\n", op1.var_name, op, op2.var_name);
        strcat(curr_buff->code, temp_buf);
    }
    else
        printf(" = %s %s %s\n", op1.var_name, op, op2.var_name);
}

inline void scope_error_check(char *symbol){
    if(!scope_check(symbol_table, symbol, curr_scope)){
        yyerror(strcat(symbol, " not found in current or ancestor scopes"));
    }
}

inline void num_param_check(char *symbol) {

    symbol_node_t *node = scope_check(symbol_table, symbol, curr_scope);
    if(node != NULL && num_params > node->num_params) {
        char msg[100] = "Too many arguments passed to ";
        yyerror(strcat(msg, symbol));
    }
    else if(node != NULL && num_params < node->num_params) {
        char msg[100] = "Too few arguments passed to ";
        yyerror(strcat(msg, symbol));
    }
}

inline void redeclaration_error_check(char *symbol){
    if(check_in_current_scope(symbol_table, symbol, curr_scope)){
        yyerror(strcat(symbol, " already declared in current scope"));
    }
}

symbol_node_t * redefined_error_check(char *symbol){
    symbol_node_t *node = scope_check(symbol_table, symbol, curr_scope);
    if(node != NULL && node->is_function_defined)
        yyerror(strcat(symbol, " is a redefinition"));

    return node;
}

inline void arr_dimension_check(char *symbol, char *arr_size){
    if(atoi(arr_size) < 1){
        yyerror(strcat(symbol, " has non-positive array size"));
    }
}

inline void arr_subscript_check(char *symbol){
    symbol_node_t *node = symbol_table_lookup(symbol_table, symbol);
    if(!strstr(node->type, "Array")){
        yyerror(strcat(symbol, " is not an array"));
    }
}

inline void void_param_check(char *type) {
    if(!strcmp(type, "void")) {
        yyerror("Parameter of function has void datatype");
    }
}

inline void check_is_function(char *func_name) {
    
    symbol_node_t *node = symbol_table_lookup(symbol_table, func_name);
    if(node == NULL) {
        yyerror(strcat(func_name, " function not declared"));                                        
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
    curr_scope = init_scope();    
    symbol_table_initialize(symbol_table);
    symbol_table_initialize(constant_table);
    three_address_code_stack = initialize_stack();
    
    TAC_code = initialize_code_stack();
    printf("\n");

    yyparse();

    print_TAC_code(TAC_code);

    // symbol_table_print(symbol_table, "Symbol Table");
    // symbol_table_print(constant_table, "Constant Table");
    printf(FORE_GRN "\n\n Parsing complete  ✔ \n\n" RESET); 
    
    symbol_table_free(symbol_table);
    symbol_table_free(constant_table);
    // TODO: Free Scope
    free_stack(three_address_code_stack);
    return 0;
}


void yyerror(const char *s) {
	printf(FORE_RED "%d : %s %s\n" RESET, yylineno, s, yytext );
    printf(FORE_RED "\nParsing failed ✘ \n\n" RESET);
    exit(-2);
}
