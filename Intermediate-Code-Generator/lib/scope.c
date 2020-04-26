#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#include "symbol_table.h"
#define _SCOPE

typedef struct scope_node_struct scope_node_t;

// structure for a node of the scope
struct scope_node_struct
{
    int scope_num;
    scope_node_t *parent_scope;
};

scope_node_t *create_scope();

// for creating the global scope
scope_node_t *init_scope();
bool check_in_current_scope(symbol_node_t **symbol_table, char *symbol, scope_node_t *curr_scope);

// initial scope count
int scope_count = 0;
scope_node_t *create_scope()
{   
    // allocating memory
    scope_node_t *node = (scope_node_t *)malloc(sizeof(scope_node_t));
    node->scope_num = scope_count++;
    node->parent_scope = NULL;

    return node;
}

// Initializes global scope
scope_node_t *init_scope()
{
    return create_scope();
}

//checking if a scope number is present in the current scope or any of the previous scopes.
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

// finding the scope of the parent and deallocating the current scope
scope_node_t *goto_parent_scope(scope_node_t *curr_scope)
{
    scope_node_t *parent = curr_scope->parent_scope;
    free(curr_scope);

    return parent;
}

// creating the scpoe of the child
scope_node_t *add_child_scope(scope_node_t *curr_scope)
{
    scope_node_t *node = create_scope();
    node->parent_scope = curr_scope;

    return node;
}

//checking if a scope number is present in the current scope
bool check_in_current_scope(symbol_node_t **symbol_tab, char *symb, scope_node_t *curr_scope){
    int hash_index = symbol_table_hash(symb);

    for (symbol_node_t *curr = symbol_tab[hash_index]; curr != NULL; curr = curr->next)
    {
        if (!strcmp(curr->symbol, symb))
        {
            if (curr_scope->scope_num == curr->scope_num)
            {   break;
                return true;
            }
        }
    }
    return false;
}

scope_node_t *scope_check(symbol_node_t **symbol_tab, char *symb, scope_node_t *curr_scope)
{
    int hash_index = symbol_table_hash(symb);
    for (symbol_node_t *curr = symbol_tab[hash_index]; curr != NULL; curr = curr->next)
    {
        if (!strcmp(curr->symbol, symb))
        {
            if (check_within_scope(curr_scope, curr->scope_num))
            {
                return curr;
            }
        }
    }
    return NULL;
}


