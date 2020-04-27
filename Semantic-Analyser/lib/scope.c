

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "symbol_table.h"
#include "scope.h"

int scope_count = 0;

scope_node_t *create_scope()
{
    scope_node_t *node = (scope_node_t *)malloc(sizeof(scope_node_t));
    node->scope_num = scope_count++;
    node->parent_scope = NULL;

    return node;
}

// Create Global Scope
scope_node_t *init_scope()
{
    return create_scope();
}

// Checks whether a given scope num is present in current or any of its
// ancestor scope
bool check_within_scope(scope_node_t *curr_scope, int scope_key)
{
    scope_node_t *node = curr_scope;

    while (node != NULL)
    {
        if (node->scope_num == scope_key)
        {
            return true;
        }

        node = node->parent_scope;
    }

    return false;
}

scope_node_t *add_child_scope(scope_node_t *curr_scope)
{
    scope_node_t *node = create_scope();
    node->parent_scope = curr_scope;

    return node;
}

scope_node_t *goto_parent_scope(scope_node_t *curr_scope)
{
    scope_node_t *parent = curr_scope->parent_scope;
    free(curr_scope);

    return parent;
}

scope_node_t *scope_check(symbol_node_t **symbol_table, char *symbol, scope_node_t *curr_scope)
{
    int hash_index = symbol_table_hash(symbol);
    for (symbol_node_t *curr = symbol_table[hash_index]; curr != NULL; curr = curr->next)
    {
        // Symbol found in table
        if (!strcmp(curr->symbol, symbol))
        {
            if (check_within_scope(curr_scope, curr->scope_num))
            {
                return curr;
            }
        }
    }

    return NULL;
}

bool check_in_current_scope(symbol_node_t **symbol_table, char *symbol, scope_node_t *curr_scope){
    int hash_index = symbol_table_hash(symbol);

    for (symbol_node_t *curr = symbol_table[hash_index]; curr != NULL; curr = curr->next)
    {
        // Symbol found in table
        if (!strcmp(curr->symbol, symbol))
        {
            if (curr_scope->scope_num == curr->scope_num)
            {
                return true;
            }
        }
    }

    return false;
}