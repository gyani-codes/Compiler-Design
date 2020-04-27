#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.h"
#include "misc.h"

void symbol_table_initialize(symbol_node_t **symbol_table){

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

symbol_node_t * symbol_table_insert(symbol_node_t **symbol_table, const char* symbol, const int scope_num, const char *type, const char *arr_size, const int line_number){
   // if(symbol_table_lookup(symbol_table, symbol))
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

symbol_node_t * symbol_table_lookup(symbol_node_t **symbol_table, const char* symbol){

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

void symbol_table_free(symbol_node_t **symbol_table){

   for(int i=0; i< MAX_SYMBOL_TABLE_SIZE; ++i){
      free(symbol_table[i]);
   }
}

void symbol_table_print(symbol_node_t **symbol_table, const char *table_name){
   printf("\n\n" FORE_MAG DASHES RESET);
   printf(FORE_CYN "%s\t\n" RESET, table_name);
   printf(FORE_YEL DASHES RESET);

   printf(FORE_GRN "|\t%-20.20s" "|\t%-20.20s" "|\t%-20.20s|" "|\t%-20.20s|" "|\t%-20.20s|" "\n" RESET, "Symbol", "Scope_Num", "Type", "Array Dim", "Line Number");
   printf(FORE_YEL DASHES RESET);

   for(int i=0; i< MAX_SYMBOL_TABLE_SIZE; ++i){
      for(symbol_node_t *curr = symbol_table[i]; curr != NULL; curr = curr->next){
         printf(FORE_GRN "|\t%-20.20s" "|\t%-20d" "|\t%-20.20s" "|\t%-20.20s" ATTR_BOLD "|\t%-20d|" "\n" RESET, curr->symbol, curr->scope_num, curr->type, curr->arr_size, curr->line_number);
      }
   }

   printf(FORE_MAG DASHES RESET "\n\n");
}
