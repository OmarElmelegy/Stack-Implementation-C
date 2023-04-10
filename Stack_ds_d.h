#ifndef STACK_DS_D
#define STACK_DS_D

#include "std_types.h"

#define STACK_MAX_SIZE 5

typedef struct{
    void **stack_array;
    sint32_t element_count;
    uint32_t stack_max_size;
    uint32_t stack_top;
}stack_d_t;

typedef enum {
    STACK_D_NOK,
    STACK_D_OK,
    STACK_D_FULL,
    STACK_D_EMPTY,
    STACK_D_NULL_POINTER
}stack_status_d_t;

stack_d_t *create_stack(uint32_t max_size, stack_status_d_t *ret_status);
void destroy_stack(stack_d_t *mystack, stack_status_d_t *ret_status);
stack_status_d_t push_stack(stack_d_t *mystack, void *ItmPtr);
void *pop_stack(stack_d_t *my_stack, stack_status_d_t *ret_status);
void *top_stack(stack_d_t *my_stack, stack_status_d_t *ret_status);
stack_status_d_t stack_count(stack_d_t *my_stack, uint32_t *stack_count);

#endif