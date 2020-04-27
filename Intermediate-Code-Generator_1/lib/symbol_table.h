#include<stdbool.h>

#ifndef _SYMBOL_TABLE
#define _SYMBOL_TABLE

// this typedef to reduce the decleration syntax
typedef struct symbol_node_struct symbol_node_t;


// definition of structure 
struct symbol_node_struct {

  char *symbol; 
  char *type;
  char *arr_size; 
  int scope_num;
  int line_number; 
  bool is_function_defined; // boolen whether function is defined or not
  int num_params; // number of parameter to the function 

  // symbol_node_t* left; // For binary tree based symbol table 
  symbol_node_t *next;
};

#define MAX_SYMBOL_TABLE_SIZE 10 // a golabal to store the maximum table size
// const int MAX_SYMBOL_TABLE_SIZE = 10;

// Function Prototypes

// init function for intialization
void symbl_tbl_initlze(symbol_node_t **symbol_table);

int symbl_tbl_hsh(const char *symbol);


// this is function for insertion
 
symbol_node_t * symbl_tbl_insrt(symbol_node_t **symbol_table, const char* symbol, const int scope_num, const char *type, const char *arr_size, const int line_number);


// this function is for look ups

symbol_node_t *symbl_tbl_lkp(symbol_node_t **symbol_table, const char* symbol);


// funtion to free each pointer of the symbol table
void symbl_tbl_fr(symbol_node_t **symbol_table);

// for printing symbol table
void symbl_tbl_prnt(symbol_node_t **symbol_table, const char *table_name);



#endif
