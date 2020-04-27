#include<stdbool.h>

#ifndef _SYMBOL_TABLE
#define _SYMBOL_TABLE
typedef struct symbol_node_struct symbol_node_t;

struct symbol_node_struct {
  char *symbol;
  char *type;
  char *arr_size;
  int scope_num;
  int line_number;
  bool is_function_defined;
  int num_params;

  // symbol_node_t* left; // For binary tree based symbol table 
  symbol_node_t *next;
};

#define MAX_SYMBOL_TABLE_SIZE 10
// const int MAX_SYMBOL_TABLE_SIZE = 10;

// Function Prototypes
void sym_tab_init(symbol_node_t **symbol_table);

int symbol_table_hash(const char *symbol);

symbol_node_t * sym_tab_insert(symbol_node_t **symbol_table, const char* symbol, const int scope_num, const char *type, const char *arr_size, const int line_number);

symbol_node_t *sym_tab_arrayLook(symbol_node_t **symbol_table, const char* symbol);

void sym_tab_free(symbol_node_t **symbol_table);



#endif
