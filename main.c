#include "Stack_ds.h"

stack_ds_t stack1;
uint32_t stack_pop_value;
uint32_t stack_top_value;
uint32_t stack_size_value;

int main(){

    return_status_t ret = R_NOK;
    ret = stack_init(&stack1);
    if(R_NOK == ret){
        printf("Stack failed to be initialized");
    }
    else{
        ret = stack_push(&stack1, 11);
        ret = stack_push(&stack1, 22);
        ret = stack_push(&stack1, 33);
        ret = stack_push(&stack1, 44);
        ret = stack_push(&stack1, 55);
        ret = stack_push(&stack1, 66);
        stack_size_value = stack_size(&stack1,&stack_size_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        stack_size_value = stack_size(&stack1,&stack_size_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        ret = stack_push(&stack1, 66);
        ret = stack_top(&stack1, &stack_top_value);
        ret = stack_push(&stack1, 1);
        ret = stack_push(&stack1, 2);
        ret = stack_push(&stack1, 3);
        ret = stack_push(&stack1, 4);
        ret = stack_display(&stack1);
    }
    return 0;
}