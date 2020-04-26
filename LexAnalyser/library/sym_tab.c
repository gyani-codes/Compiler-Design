// PREPROCESSOR DIRECTIVEs.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sym_tab.h"
#include "miscellaneous.h"

#define f(i,start,end,val) for(int i=start;i<end;i+=val)


void sym_tab_init(sym_node_t **sym_tab){

   f(j,0,MAX_SYM_TAB_SIZE,1){
      sym_tab[j] = NULL;
   }
}

int sym_tab_hash(const char *sym){

   return ((int)sym[0]) % MAX_SYM_TAB_SIZE;
}

sym_node_t *c_sym_node(const char* sym, const char *type, const int lineNum){

   sym_node_t *node = malloc(sizeof(sym_node_t));
   node->sym = malloc(sizeof(char) * (strlen(sym) +1));
   strcpy(node->sym, sym);
   // node->sym = (char*)sym;
   node->type = (char*)type;
   node->lineNum = lineNum;
   node->next = NULL;

   return node;
}

void sym_tab_insert(sym_node_t **sym_tab, const char* sym, const char *type, const int lineNum){
   if(sym_tab_arrayLook(sym_tab, sym))
      return;

   int hash_index = sym_tab_hash(sym);
   sym_node_t *node = c_sym_node(sym, type, lineNum);

   sym_node_t *curr = sym_tab[hash_index];
   while(curr != NULL && curr->next != NULL){
      curr = curr->next;
   }
   // Add as first item
   if(curr == NULL){
      sym_tab[hash_index] = node;
   }
   else{
      curr->next= node;
   }
}

bool sym_tab_arrayLook(sym_node_t **sym_tab, const char* sym){

   int hash_index = sym_tab_hash(sym);
   for(sym_node_t *curr = sym_tab[hash_index]; curr != NULL; curr = curr->next){
      // sym found in tab
      if(!strcmp(curr->sym, sym)){
         return true;
      }
   }

   // sym not found in tab
   return false;
}

void sym_tab_free(sym_node_t **sym_tab){

   f(i,0,MAX_SYM_TAB_SIZE,1){
      free(sym_tab[i]);
   }
}

void sym_tab_print(sym_node_t **sym_tab, const char *tab_name){
   printf("\n\n" F_M DASH CLEAR);
   printf(F_C "%s\t\n" CLEAR, tab_name);
   printf(F_Y DASH CLEAR);

   printf(F_G "|\t%-20s" "|\t%-20s" "|\t%-20s|" "\n" CLEAR, "sym", "Type", "Line Number");
   printf(F_Y DASH CLEAR);

   for(int i=0; i< MAX_SYM_TAB_SIZE; ++i){
      for(sym_node_t *curr = sym_tab[i]; curr != NULL; curr = curr->next){
         printf(F_G "|\t%-20s" "|\t%-20s" A_B "|\t%-20d|" "\n" CLEAR, curr->sym, curr->type, curr->lineNum);
      }
   }

   printf(F_M DASH CLEAR "\n\n");
}
