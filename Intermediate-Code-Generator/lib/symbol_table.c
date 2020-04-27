#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.h"
#include "misc.h"

void symbl_tbl_initlze(symbol_node_t **symbol_table){

   for(int i=0; i< MAX_SYMBOL_TABLE_SIZE; ++i){ // array of struct is begin intialized and each one of them pointing to null
      symbol_table[i] = NULL;
   }
}

int symbl_tbl_hsh(const char *symbol){

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

// definition of prototype defined in symboltable.h

symbol_node_t * symbl_tbl_insrt(symbol_node_t **symbol_table, const char* symbol, const int scope_num, const char *type, const char *arr_size, const int line_number){
   // if(symbl_tbl_lkp(symbol_table, symbol))
   //    return;

   int hash_index = symbl_tbl_hsh(symbol);

   symbol_node_t *node = create_symbol_node(symbol, type, scope_num, arr_size, line_number);

   symbol_node_t *temp_var = symbol_table[hash_index];
   while(temp_var != NULL && temp_var->next != NULL){
      temp_var = temp_var->next;
   }
   // Add as first item
   if(temp_var == NULL){
      symbol_table[hash_index] = node;
   }
   else{
      temp_var->next= node;
   }
}

symbol_node_t * symbl_tbl_lkp(symbol_node_t **symbol_table, const char* symbol){

   int hash_index = symbl_tbl_hsh(symbol);
   for(symbol_node_t *temp_var = symbol_table[hash_index]; temp_var != NULL; temp_var = temp_var->next){
      // Symbol found in table
      if(!strcmp(temp_var->symbol, symbol)){
         return temp_var;
      }
   }



   // Symbol not found in table
   return NULL;
}

void symbl_tbl_fr(symbol_node_t **symbol_table){

   for(int x=0; x< MAX_SYMBOL_TABLE_SIZE; ++x){
      	free(symbol_table[x]);
   }
}

void symbl_tbl_prnt(symbol_node_t **symbol_table, const char *table_name){
   printf("\n\n" FORE_MAG DASHES RESET);
   printf(FORE_CYN "%s\t\n" RESET, table_name);
   printf(FORE_YEL DASHES RESET);

   printf(FORE_GRN "|\t%-20.20s" "|\t%-20.20s" "|\t%-20.20s|" "|\t%-20.20s|" "|\t%-20.20s|" "\n" RESET, "Symbol", "Scope_Num", "Type", "Array Dim", "Line Number");
   printf(FORE_YEL DASHES RESET);

   for(int i=0; i< MAX_SYMBOL_TABLE_SIZE; ++i){
      for(symbol_node_t *temp_var = symbol_table[i]; temp_var != NULL; temp_var = temp_var->next){
         printf(FORE_GRN "|\t%-20.20s" "|\t%-20d" "|\t%-20.20s" "|\t%-20.20s" ATTR_BOLD "|\t%-20d|" "\n" RESET, temp_var->symbol, temp_var->scope_num, temp_var->type, temp_var->arr_size, temp_var->line_number);
      }
   }

   printf(FORE_MAG DASHES RESET "\n\n");
}
