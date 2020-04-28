#ifndef _SCOPE
#define _SCOPE
#include "symbol_table.h"

typedef struct scope_node_struct scope_node_t;

struct scope_node_struct
{
    int scope_num;

    scope_node_t *parent_scope;
    // scope_node_t *previous_scope;
};


scope_node_t *create_scope();

// Create Global Scope
scope_node_t *init_scope();

scope_node_t *add_child_scope(scope_node_t *curr_scope);

scope_node_t *goto_parent_scope(scope_node_t *curr_scope);

scope_node_t * scope_check(symbol_node_t **symbol_table, char *symbol, scope_node_t *curr_scope);

bool check_in_current_scope(symbol_node_t **symbol_table, char *symbol, scope_node_t *curr_scope);

#endif