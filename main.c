#include "Stack_ds.h"
#include "Stack_ds_d.h"

stack_ds_t stack1;
uint32_t stack_pop_value;
uint32_t stack_top_value;
uint32_t stack_size_value;
stack_d_t * stack2;

int main(){

    return_status_t ret = R_NOK;
    uint8_t c;
    printf("Static or Dynamic ? S or D  ");
    scanf("%c",&c);
    if(c == 'S'){
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
    }
    else{
        uint32_t size;
        stack_status_d_t ret_status = STACK_D_NOK;
        sint32_t stack_c = 0;
        void * stack_return = NULL;

        uint32_t var1 = 0x11;
        uint16_t var2 = 3.22;
        uint8_t var3 = 'a';
        
        printf("Enter number of elements in dynamic stack: ");
        scanf("%i", &size);
        stack2 = create_stack(size, &ret_status);
        if(ret){
            printf("Dynamic stack created");
        }

        ret_status = push_stack(stack2, &var1);
        printf("Stack Status = %i \n",ret_status);
        ret_status = push_stack(stack2, &var2);
        printf("Stack Status = %i \n",ret_status);
        ret_status = push_stack(stack2, &var3);
        printf("Stack Status = %i \n",ret_status);
        ret_status = stack_count(stack2, &stack_c);
        printf("Stack Status = %i, Stack Count = %i\n",ret_status, stack_c);
        stack_return = pop_stack(stack2, &ret_status);
        printf("Stack Status = %i, Stack Top = %c\n",ret_status, *(uint8_t*)stack_return);
        ret_status = push_stack(stack2, &var1);
        ret_status = push_stack(stack2, &var2);
        printf("Stack Status = %i \n",ret_status);
        stack_return = pop_stack(stack2, &ret_status);
        stack_return = pop_stack(stack2, &ret_status);
        stack_return = pop_stack(stack2, &ret_status);
        stack_return = pop_stack(stack2, &ret_status);
        printf("Stack Status = %i \n",ret_status);
        ret_status = stack_count(stack2, &stack_c);
        printf("Stack Status = %i, Stack Count = %i\n",ret_status, stack_c);
        
        destroy_stack(stack2, &ret_status);
    }
    return 0;
}