
#ifndef _STACK
#define _STACK

#define BUFFER_TOTAL_CAPACITY 100
#define STACK_VARIABLE_SIZE 100
#define STACK_SIZE 100
#define TEMP_VAR "#REG"

typedef struct stack_node stack_node;
typedef struct stack stack;
typedef struct TAC_buffer_node TAC_buffer_node;
typedef struct TAC_code_stack TAC_code_stack;

struct stack_node {
    int temp_num; // -1 if it isn't a temporary variable
    char var_name[STACK_VARIABLE_SIZE];
};

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

#endif
