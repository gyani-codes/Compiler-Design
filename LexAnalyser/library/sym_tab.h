#include<stdbool.h>

#ifndef _SYMBOL_TABLE
#define _SYMBOL_TABLE
typedef struct sym_node_struct sym_node_t;

struct sym_node_struct {
  char *sym;
  char *type;
  int lineNum;
  sym_node_t *next;
};

#define MAX_SYM_TAB_SIZE 10

// Function Prototypes
void sym_tab_init(sym_node_t **sym_table);

void sym_tab_insert(sym_node_t **sym_table, const char* sym, const char *type, const int lineNum);

bool sym_tab_arrayLook(sym_node_t **sym_table, const char* sym);

void sym_tab_free(sym_node_t **sym_table);

void sym_tab_print(sym_node_t **sym_table, const char *table_name);

#endif
