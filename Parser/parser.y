

/*Declarations starts from here 
  including all header files so that we can use
  the necessary functions
*/

%{
    
    
    #include<stdlib.h>
    #include<stdio.h>
    #include<stdbool.h>
    #include "library/sym_tab.h"
    #include "library/miscellaneous.h"
    #define TRACE_ENABLING true   

    /* Maximum possible rows in symbot table*/
    #define MAX_POSSIBLE_NODES 100

    /*prototype for predefined error function in yacc */
    void yerror(const char *c);
    

    /* declaring symbol table */
    sym_node_t *sym_table[MAX_POSSIBLE_NODES];
    sym_node_t *const_table[MAX_POSSIBLE_NODES];

    extern char *yytext;
    extern int yylineno;
    
    char datatype_of_variables[100];
%}

/* Intialising tokens of the grammar */
%token SIGNED UNSIGNED LONG SHORT
%token SWITCH BREAK CONTINUE CASE DEFAULT RETURN
%token FOR WHILE DO
%token IF ELSE
%token <char_pointer> CONSTANT_INTEGER
%token <char_pointer> CONSTANT_FLOAT
%token <char_pointer> CONSTANT_STRING
%token <char_pointer> CONSTANT_CHAR
%token INCLUDE

%union{
    char char_pointer[100];
}

%token <char_pointer> IDENTIFIER
%token <char_pointer> INT
%token <char_pointer> CHAR
%token <char_pointer> FLOAT
%token <char_pointer> DOUBLE
%token <char_pointer> VOID

/* Defining associations of the operators in grammar */
%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN         
%left LOGIC_AND LOGIC_OR NOT INCREMENT_OPERATOR DECREMENT_OPERATOR
%left LESSER_EQUAL GREATER_EQUAL DOUBLE_EQUAL NOT_EQUAL LESSER_THAN GREATER_THAN             
%left '+' '-' '*' '/' '%' '^' '&' 

/* Start not-terminal of the grammar */
%start Start

/* Rules of the context free grammar */
%%
Start   
    : Include
    | Include Start
    | Declaration
    | Declaration Start
	| Function_Definition
    | Function_Definition Start
	;

Declaration
    :  Type Identifier_List ';'    
    ;

Identifier_List
    : Array_Notation
    | IDENTIFIER ',' Identifier_List        {sym_tab_insert(sym_table,$1,datatype_of_variables,yylineno);}
    | '*' IDENTIFIER ',' Identifier_List    {
                                                int length = strlen(datatype_of_variables);
                                                datatype_of_variables[length] = '*';
                                                datatype_of_variables[length +1] = '\0';
                                                sym_tab_insert(sym_table,$2,datatype_of_variables,yylineno);
                                                datatype_of_variables[length] = '\0';
                                            }
    | Array_Notation ',' Identifier_List 
    | IDENTIFIER                            {sym_tab_insert(sym_table,$1,datatype_of_variables,yylineno);} 
    | '*' IDENTIFIER                        {
                                                int length = strlen(datatype_of_variables);
                                                datatype_of_variables[length] = '*';
                                                datatype_of_variables[length +1] = '\0';
                                                sym_tab_insert(sym_table,$2,datatype_of_variables,yylineno);
                                                datatype_of_variables[length] = '\0';
                                            }
    | Define_Assign ',' Identifier_List
    | Define_Assign 
    ;

Function_Definition
	: Type IDENTIFIER '(' Formal_Param_List ')' Compound_Statement      {                            
                                                                            char functionType[100] = "Function: ";
                                                                            strcat(functionType, datatype_of_variables);
                                                                            sym_tab_insert(sym_table,$2, functionType, yylineno);
                                                                        }
	;

Formal_Param_List
	: Type IDENTIFIER                                  {sym_tab_insert(sym_table,$2,datatype_of_variables,yylineno);trace("Formal_Param_List Rule 1\n");}
	| Type '*' IDENTIFIER                              {sym_tab_insert(sym_table,$3,datatype_of_variables,yylineno);trace("Formal_Param_List Rule 2\n");}
	| Type Array_Notation                              {trace("Formal_Param_List Rule 3\n");}
	| Type IDENTIFIER ',' Formal_Param_List            {sym_tab_insert(sym_table,$2,datatype_of_variables,yylineno);trace("Formal_Param_List Rule 4\n");}
	| Type '*' IDENTIFIER ',' Formal_Param_List        {sym_tab_insert(sym_table,$3,datatype_of_variables,yylineno);trace("Formal_Param_List Rule 5\n");}
	| Type Array_Notation ',' Formal_Param_List        {trace("Formal_Param_List Rule 6\n");}
	|
	;

Type
    : INT                       {strcpy(datatype_of_variables, $1);}
    | FLOAT                     {strcpy(datatype_of_variables, $1);}
    | VOID                      {strcpy(datatype_of_variables, $1);}
    | CHAR                      {strcpy(datatype_of_variables, $1);}
    | DOUBLE                    {strcpy(datatype_of_variables, $1);}
    | Modifiers INT             {strcpy(datatype_of_variables, $2);}
    | Modifiers FLOAT           {strcpy(datatype_of_variables, $2);}
    | Modifiers DOUBLE          {strcpy(datatype_of_variables, $2);}
    | Modifiers CHAR            {strcpy(datatype_of_variables, $2);}
    ;

Modifiers
    : SHORT | LONG | UNSIGNED | SIGNED
    ;

Array_Notation
    : IDENTIFIER '[' ']'            {   
                                        char arrayType[100] = "Array: ";
                                        strcat(arrayType, datatype_of_variables);
                                        sym_tab_insert(sym_table, $1, arrayType, yylineno);
                                    }
    | IDENTIFIER '[' Expression ']' {   
                                        char arrayType[100] = "Array: ";strcat(arrayType, datatype_of_variables);
                                        sym_tab_insert(sym_table,$1, arrayType,yylineno);
                                    }
    | '*' IDENTIFIER '[' Expression ']' {   
                                        int len = strlen(datatype_of_variables);
                                        datatype_of_variables[len] = '*';
                                        datatype_of_variables[len +1] = '\0';                                
                                        char arrayType[100] = "Array: ";strcat(arrayType, datatype_of_variables);
                                        sym_tab_insert(sym_table,$2, arrayType,yylineno);
                                        datatype_of_variables[len] = '\0';
                                    }
    | '&' IDENTIFIER '[' Expression ']' {
                                        char arrayType[100] = "Array: ";strcat(arrayType, datatype_of_variables);
                                        sym_tab_insert(sym_table,$2, arrayType,yylineno);
                                    }
    ;


Define_Assign
    : IDENTIFIER Assignment_Operator Expression          {sym_tab_insert(sym_table,$1,datatype_of_variables,yylineno);trace("Define_Assign Rule 1\n");}  
    | '*' IDENTIFIER Assignment_Operator Expression      {sym_tab_insert(sym_table,$2,datatype_of_variables,yylineno);}
    | Array_Notation Assignment_Operator Expression                   
    ;



Param_List
    : Expression
    | Expression ',' Param_List
    | 
    ;


Assignment
    : IDENTIFIER Assignment_Operator Expression           {trace("Assignment Rule 1\n");}
    | '*' IDENTIFIER Assignment_Operator Expression         
    | Array_Notation Assignment_Operator Expression
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

Primary
    : '(' Expression ')'
    | CONSTANT_INTEGER     {sym_tab_insert(const_table, $1, "int", yylineno); trace("CONSTANT_INTEGER\n");}
    | CONSTANT_FLOAT       {sym_tab_insert(const_table, $1, "float", yylineno); trace("CONSTANT_FLOAT\n");}
    | CONSTANT_CHAR        {sym_tab_insert(const_table, $1, "char", yylineno); trace("CONSTANT_CHAR\n");}
    | CONSTANT_STRING      {sym_tab_insert(const_table, $1, "string", yylineno); trace("CONSTANT_STRING\n");}
    | IDENTIFIER           {trace("Primary Identifier\n");}
    | '*' IDENTIFIER       {trace("Pointer Identifier\n");}
    | '&' IDENTIFIER       {trace("Address of Identifier\n");}
    | '-' Primary
    | '+' Primary
    | Array_Notation
    | Function_Call
    | INCREMENT_OPERATOR IDENTIFIER
    | IDENTIFIER INCREMENT_OPERATOR
    | DECREMENT_OPERATOR IDENTIFIER
    | IDENTIFIER DECREMENT_OPERATOR
    ;

Compound_Statement
    : '{' Statement_List '}'
	;


Statement_List
    : Statement Statement_List
    |
    ;

Statement
    : While_Statement 
    | Declaration   
    | For_Statement  
    | If_Statement  
    | Assignment    ';'
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
    : IDENTIFIER '(' Param_List ')'     {sym_tab_insert(sym_table, $1, "Function", yylineno);trace("Function Call\n");} 
    ;


Include_Statement
	: '#' INCLUDE LESSER_THAN IDENTIFIER GREATER_THAN
	| '#' INCLUDE LESSER_THAN IDENTIFIER '.' IDENTIFIER GREATER_THAN
	;

Include
	: Include_Statement
	;


%%


inline void trace(char *s){
    if(TRACE_ENABLING)
        fprintf(stderr, F_C "%-20.20s%20.20s%20d\n" CLEAR, s, yytext, yylineno);
}

int main()
{
    sym_tab_init(sym_table);
    sym_tab_init(const_table);

    if(!yyparse())
    {
        sym_tab_print(sym_table,"Generated Symbol Table ");
        sym_tab_print(const_table,"Generated Symbol Table ");
        printf(F_G "\n\n Parsing complete  ✔ \n\n" CLEAR);    

    }
    else
    {
        printf(F_R "\nParsing failed ✘ \n\n" CLEAR);

    }
    sym_tab_free(sym_table);
    sym_tab_free(const_table);
    return 0;
}

void yyerror(const char *c)
{
	printf(F_R "%d : %s %s\n" CLEAR, yylineno, c, yytext );

}