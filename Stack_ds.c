#include "Stack_ds.h"

/**
  * @brief checks if the stack is full
  * @param my_stack is a pointer to the stack
  * @retval Status of the stack 
  */
stack_status_t static stack_full(stack_ds_t *my_stack){
    if(my_stack->stack_pointer == STACK_MAX_SIZE-1){
        return STACK_FULL;
    }
    else{
        return STACK_NOT_FULL;
    }
}

/**
  * @brief checks if the stack is empty
  * @param my_stack is a pointer to the stack
  * @retval Status of the stack 
  */
stack_status_t static stack_empty(stack_ds_t *my_stack){
    if(my_stack->stack_pointer == -1){
        return STACK_EMPTY;
    }
    else{
        return STACK_NOT_FULL;
    }
}

/**
  * @brief Initializes a stack pointer
  * @param my_stack is a pointer to a stack
  * @retval Status of a initialization process 
  */
return_status_t stack_init(stack_ds_t *my_stack){

    return_status_t ret = R_NOK;
    if(NULL == my_stack){
        ret = R_NOK;
    }
    else{
        my_stack->stack_pointer = -1;
        ret = R_OK;
    }

    return ret;
}

/**
  * @brief Pushes an element to a stack
  * @param my_stack is a pointer to a stack
  * @param value is a element we push to stack
  * @retval Status of a process of push
  */
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value){
    return_status_t ret = R_NOK;
    if((NULL == my_stack)||(STACK_FULL == stack_full(my_stack))){
        ret = R_NOK;
        printf("An error has occurred, either the stack pointer is null or the stack is full\n");
    }
    else{
        my_stack->stack_pointer++;
        my_stack->data[my_stack->stack_pointer] = value;
        printf("Value (%i) pushed to the stack at [%i]\n",value,my_stack->stack_pointer);
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief Pops an element from a stack
  * @param my_stack is a pointer to a stack
  * @param value is a pointer to a value that takes a element we pop 
  * @retval Status of a stack  
  */
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value){
    return_status_t ret = R_NOK;
    if((NULL == my_stack)||(NULL == value)||(STACK_EMPTY == stack_empty(my_stack))){
        printf("Error, stack is empty or pointer to value is null\n");
    }
    else{
        *value = my_stack->data[my_stack->stack_pointer];
        my_stack->stack_pointer--;
        printf("Element popped from stack, the value is %i\n",*value);
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief Returns a top element in a stack
  * @param my_stack is a pointer to a stack
  * @param value is a pointer to a integer that takes a top element value
  * @retval Status of a stack 
  */
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value){
    return_status_t ret = R_NOK;
    if((NULL == my_stack)||(NULL == value)||(STACK_EMPTY == stack_empty(my_stack))){
        printf("Error, stack is empty or pointer to top value is null\n");
    }
    else{
        *value = my_stack->data[my_stack->stack_pointer];
        printf("Stack top value = %i\n",*value);
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief Returns a size of a stack
  * @param my_stack is a pointer to a stack
  * @param stack_size is a pointer to an integer that takes a value of size
  * @retval Size of a stack
  */
return_status_t stack_size(stack_ds_t *my_stack, uint32_t *stack_size){
    return_status_t ret = R_NOK;
    if((NULL == my_stack)||(NULL == stack_size)){
        printf("Error, stack is empty or pointer to size value is null\n");
    }
    else{
        *stack_size = my_stack->stack_pointer + 1;
        printf("Stack size = %i\n",*stack_size);
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief Prints all elements of a stack
  * @param my_stack is a pointer to a stack
  * @retval Status of a stack 
  */
return_status_t stack_display(stack_ds_t *my_stack){
    return_status_t ret = R_NOK;
    sint32_t value, l_counter;
    if((NULL == my_stack)||(STACK_EMPTY == stack_empty(my_stack))){
        printf("Error, stack is empty\n");
    }
    else{
        for(l_counter = my_stack->stack_pointer;l_counter >= 0;l_counter--){
            printf("Stack element [%i] = %i\n",l_counter,my_stack->data[l_counter]);
        }
        ret = R_OK;
    }
    return ret;
}