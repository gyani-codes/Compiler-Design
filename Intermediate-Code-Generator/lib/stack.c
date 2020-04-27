#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define _STACK
#define BUFFER_TOTAL_CAPACITY 100
#define STACK_VARIABLE_SIZE 100
#define STACK_SIZE 100
#define TEMP_VAR "#REG"
typedef struct stack_node stack_node;
typedef struct stack stack;
typedef struct TAC_buffer_node TAC_buffer_node;
typedef struct TAC_code_stack TAC_code_stack;

// structure for node of the stack
struct stack_node {
    int temp_num;
    char var_name[STACK_VARIABLE_SIZE];
};

// strcuture for stack, contains the top element, count of elements, and the an array of all elements
struct stack {
    int top;
    int temp_count;
    stack_node stack_arr[STACK_SIZE];
};

struct TAC_buffer_node {
    char code[STACK_VARIABLE_SIZE];
    struct TAC_buffer_node *next;
};

struct TAC_code_stack {
    int top;
    TAC_buffer_node *stack_arr[BUFFER_TOTAL_CAPACITY];
};

stack *init_s();
void f_s(stack *st);
stack_node popStack(stack *st);
void print_st(stack *st, TAC_buffer_node *buf);
void pushStack(stack *st, const char *var_name);

TAC_code_stack *init_code_stack();
TAC_buffer_node *get_new_node(TAC_code_stack *st);
void print_TAC_code(TAC_code_stack *st);

extern bool BUFFER_ENABLED;

/* Initialize stack */

stack *init_s(){

    // allocating memory for stack
    stack *st = (stack *)malloc(sizeof(stack));

    // check if stack is NULL or not
    if(st==NULL)
    exit(-1);

    st->top = -1;
    st->temp_count = 0;
    return st;
}


// disallocate the memory given to the stack
void f_s(stack *st){
    free(st);
}


// pop the top element of the stack
stack_node popStack(stack *st) {

    if(st->top == -1){
        printf("Tried popping from Empty Stack\n");
        exit(-1);
    }

    if(st->stack_arr[st->top].temp_num != -1)
        st->temp_count--;
    return st->stack_arr[st->top--];
}

// pushing an element stored in var_name to the stack
void pushStack(stack *st, const char *var_name){

    // check if the stack has already reached its capacity
    if(st->top >= STACK_SIZE){
        printf("stack overflow condition");
        exit(-1);
    }

    st->top++;
    strcpy(st->stack_arr[st->top].var_name, var_name);
    st->stack_arr[st->top].temp_num = 0;

    if(!strcmp(var_name, TEMP_VAR)){
        st->stack_arr[st->top].temp_num = st->temp_count;
        st->temp_count++;
        char buff[STACK_VARIABLE_SIZE];
        sprintf(buff, "%d", st->stack_arr[st->top].temp_num);
        strcat(st->stack_arr[st->top].var_name, buff);
    }
    else
        st->stack_arr[st->top].temp_num = -1;
}

// printing the top element of the stack
void print_st(stack *sta, TAC_buffer_node *buf){

    // check if stack is empty
    if(sta->top == -1) {
        printf("Stack is Empty, nothing to print");
        exit(-1);
    }
    if(BUFFER_ENABLED)
        strcat(buf->code, sta->stack_arr[sta->top].var_name);
    else
        printf("%s", sta->stack_arr[sta->top].var_name);
}

// Initializing the stack in which all code will be pushed
TAC_code_stack *init_code_stack() {

   // allocating memory for stack
    TAC_code_stack *sta = malloc(sizeof(TAC_code_stack));
    sta->top = 0;
    for(int i=0; i<BUFFER_TOTAL_CAPACITY; i++)
        sta->stack_arr[i] = NULL;
    return sta;
}

// recursively printing the content of TAC_code_stack
void rec_print(TAC_buffer_node *node) {

    // base condition
    if(node == NULL)
        return;

    rec_print(node->next);

    printf("%s", node->code);
}

void print_TAC_code(TAC_code_stack *sta) {
    rec_print(sta->stack_arr[sta->top]);
}

// getting a new node for TAC_code_stack
TAC_buffer_node *get_new_node(TAC_code_stack *sta) {

    TAC_buffer_node *temp = malloc(sizeof(TAC_buffer_node));
    temp->next = sta->stack_arr[sta->top];
    sta->stack_arr[sta->top] = temp;
    strcpy(temp->code, "");
    return temp;
}
