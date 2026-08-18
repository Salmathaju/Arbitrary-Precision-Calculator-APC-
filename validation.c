#include<stdio.h>
#include "validation.h"
int check_arg_count(int argc)
{
    if(argc!=4)
    {
        printf("SORRY, YOU GAVE INVALID NUMBER OF ARGUMENTS\n");
        return FAILURE;
    }

    printf("THANKS FOR GIVING CORRECT NUMBER OF ARGUMENTS\n");
    return SUCCESS;
}
int validation_operation(char *operand)
{
    int i=0;
    if(operand[0]=='-')
    {
        i=1;
    }
    while(operand[i]!='\0')
    {
        if(operand[i] < '0' ||operand[i] > '9')
        {
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;

}

