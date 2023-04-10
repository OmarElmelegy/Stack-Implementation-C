#include "Stack_ds_d.h"

/**
  * @brief checks if the stack is full
  * @param my_stack is a pointer to the stack
  * @retval Status of the stack 
  */
static uint8_t stackd_empty(stack_d_t *my_stack){
    return (my_stack->element_count);
}

/**
  * @brief checks if the stack is empty
  * @param my_stack is a pointer to the stack
  * @retval Status of the stack 
  */
static stack_status_d_t stackd_full(stack_d_t *my_stack){
    return (my_stack->element_count == my_stack->stack_max_size);
}

/**
  * @brief Initializes a stack pointer, it also allocates a stack array to keep pointers to pointers of elements of the stack
  * @param my_size is a variable that has the size of the dynamic stack
  * @param ret_status is a pointer to a variable that has the status of the stack
  * @retval Returns a void pointer to the stack created 
  */
stack_d_t *create_stack(uint32_t max_size,stack_status_d_t *ret_status){
    stack_d_t *my_stack = NULL;
    if(NULL == ret_status){
        *ret_status = STACK_D_NULL_POINTER;
    }
    else{
        my_stack = (stack_d_t *)malloc(sizeof(stack_d_t));
        if(!my_stack){
            *ret_status = STACK_D_NOK;
        }
        else{
            my_stack->stack_top = -1;
            my_stack->element_count = 0;
            my_stack->stack_max_size = max_size;
            my_stack->stack_array = (void **)calloc(my_stack->stack_max_size, sizeof(void *));
            if(!my_stack->stack_array){
                free(my_stack);
                my_stack = NULL;
                *ret_status = STACK_D_NOK;
            }
            else{
                *ret_status = STACK_D_OK;
            }
        }
    }
    return my_stack;
}

/**
 * @brief Destroys the stack
 * @param my_stack is a pointer to the stack
 * @param ret_status is a pointer to a variable that has the status of the stack
 * @retval returns NULL if the operation of destruction succeeds
*/
void destroy_stack(stack_d_t *my_stack, stack_status_d_t *ret_status){
    if(NULL == ret_status || NULL == my_stack){
        *ret_status = STACK_D_NULL_POINTER;
    }
    else{
        free(my_stack->stack_array);
        free(my_stack);
        *ret_status = STACK_D_OK;
    }
}

/**
 * @brief Operation of pushing into a dynamic stack
 * @param my_stack is a pointer to a stack
 * @param ItmPtr is a pointer to the item that will be pushed
 * @retval returns status of the process
*/
stack_status_d_t push_stack(stack_d_t *my_stack, void *ItmPtr){
    stack_status_d_t ret = STACK_D_NOK;
    if(NULL == ItmPtr || NULL == my_stack){
        ret = STACK_D_NULL_POINTER;
    }
    else{
        if(stackd_full(my_stack)){
            printf("Stack is full !\n");
            ret = STACK_D_FULL;
        }
        else{
            (my_stack->stack_top)++;
            my_stack->stack_array[my_stack->stack_top] = ItmPtr;
            (my_stack->element_count)++;
            ret = STACK_D_OK;
        }
    }
    return ret;
}

/**
 * @brief Operation of popping from a dynamic stack
 * @param my_stack is a pointer to a stack
 * @param ret_status is a pointer to the variable the has the status of the process
 * @retval returns a void pointer to the item popped from the stack
*/
void *pop_stack(stack_d_t *my_stack, stack_status_d_t *ret_status){
    void *Data_Ptr_out = NULL;
    if(NULL == ret_status || NULL == my_stack){
        *ret_status = STACK_D_NULL_POINTER;
    }
    else{
        if(!stackd_empty(my_stack)){
            printf("Stack is empty !\n");
            *ret_status = STACK_D_EMPTY;
        }
        else{
            Data_Ptr_out = my_stack->stack_array[my_stack->stack_top];
            (my_stack->stack_top)--;
            (my_stack->element_count)--;
            *ret_status = STACK_D_OK;
        }
    }
    return Data_Ptr_out;
}

/**
 * @brief Returnins the top of a dynamic stack
 * @param my_stack is a pointer to a stack
 * @param ret_status is a pointer to the status of the process 
 * @retval returns the top of the stack item
*/
void *top_stack(stack_d_t *my_stack, stack_status_d_t *ret_status){
    void *Data_Ptr_out = NULL;
    if(NULL == ret_status || NULL == my_stack){
        *ret_status = STACK_D_NULL_POINTER;
    }
    else{
        if(!stackd_empty(my_stack)){
            printf("Stack is empty !\n");
            *ret_status = STACK_D_EMPTY;
        }
        else{
            Data_Ptr_out = my_stack->stack_array[my_stack->stack_top];
            *ret_status = STACK_D_OK;
        }
    }
    return Data_Ptr_out;
    
}

/**
 * @brief Returns the number of elements in the stack
 * @param my_stack is pointer to a stack
 * @param stack_count is a pointer to the variable that takes the count of the stack
 * @retval returns status of the process
*/
stack_status_d_t stack_count(stack_d_t *my_stack, uint32_t *stack_count){
    stack_status_d_t ret = STACK_D_NOK;
    if(NULL == stack_count || NULL == my_stack){
        ret = STACK_D_NULL_POINTER;
        }
    else{
        *stack_count = my_stack->element_count;
        ret = STACK_D_OK;
    }
    return ret;
}