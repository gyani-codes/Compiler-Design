#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.h"
#include "misc.h"

void sym_tab_init(symbol_node_t **symbol_table){

   for(int i=0; i< MAX_SYMBOL_TABLE_SIZE; ++i){
      symbol_table[i] = NULL;
   }
}

int symbol_table_hash(const char *symbol){

   return ((int)symbol[0]) % MAX_SYMBOL_TABLE_SIZE;
}

symbol_node_t *create_symbol_node(const char* symbol, const char *type, const int scope_num,  const char *arr_size, const int line_number){

   symbol_node_t *node = malloc(sizeof(symbol_node_t));
   node->symbol = malloc(sizeof(char) * (strlen(symbol) +1));
   node->type = malloc(sizeof(char) * (strlen(type) +1));
   node->arr_size = malloc(sizeof(char) * (strlen(arr_size) +1));

   strcpy(node->symbol, symbol);
   strcpy(node->type, type);
   strcpy(node->arr_size, arr_size);
   // node->symbol = (char*)symbol;
   // node->type = (char*)type;
   node->scope_num = scope_num;
   node->line_number = line_number;
   node->next = NULL;
   node->num_params = 0;
   node->is_function_defined = true;

   return node;
}

symbol_node_t * sym_tab_insert(symbol_node_t **symbol_table, const char* symbol, const int scope_num, const char *type, const char *arr_size, const int line_number){
   // if(sym_tab_arrayLook(symbol_table, symbol))
   //    return;

   int hash_index = symbol_table_hash(symbol);
   symbol_node_t *node = create_symbol_node(symbol, type, scope_num, arr_size, line_number);

   symbol_node_t *curr = symbol_table[hash_index];
   while(curr != NULL && curr->next != NULL){
      curr = curr->next;
   }
   // Add as first item
   if(curr == NULL){
      symbol_table[hash_index] = node;
   }
   else{
      curr->next= node;
   }
}

symbol_node_t * sym_tab_arrayLook(symbol_node_t **symbol_table, const char* symbol){

   int hash_index = symbol_table_hash(symbol);
   for(symbol_node_t *curr = symbol_table[hash_index]; curr != NULL; curr = curr->next){
      // Symbol found in table
      if(!strcmp(curr->symbol, symbol)){
         return curr;
      }
   }

   // Symbol not found in table
   return NULL;
}

void sym_tab_free(symbol_node_t **symbol_table){

   for(int i=0; i< MAX_SYMBOL_TABLE_SIZE; ++i){
      free(symbol_table[i]);
   }
}
