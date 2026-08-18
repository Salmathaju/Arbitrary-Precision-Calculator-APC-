#include <stdio.h>
#include "validation.h"
#include "dll.h"
#include "sign.h"
int main(int argc, char *argv[])
{
    if (check_arg_count(argc) == FAILURE)
    {
        return 1;
    }

    char *operand1 = argv[1];
    
    char *operand2 = argv[3];

    int flag1=get_sign(operand1);
    int flag2=get_sign(operand2);
    int sign_case=check_sign_combination(flag1,flag2);
    int sub_sign_case=check_subtraction_sign(flag1,flag2);
    int mul_sign_case = check_multiplication_sign(flag1, flag2);
    int div_sign_case=check_division_sign(flag1,flag2);
    if (validation_operation(operand1) == FAILURE)
    {
        printf("PLEASE CHECK YOU GIVING INVALID FIRST OPERAND\n");
        return 1;
    }

    if (validation_operation(operand2) == FAILURE)
    {
        printf("INVALID SECOND OPERAND\n");
        return 1;
    }

    printf("BOTH OPERANDS ARE VALID\n");

Dlist *head1 = NULL;
Dlist *tail1 = NULL;

Dlist *head2 = NULL;
Dlist *tail2 = NULL;
int start1=0;
if(operand1[0]=='-')
{
    start1=1;
}
for (int i = start1; operand1[i] != '\0'; i++)
{
    int digit = operand1[i] - '0';

    insert_at_last(&head1, &tail1, digit);
}
int start2=0;
if(operand2[0]=='-')
{
    start2=1;
}
for (int i = start2; operand2[i] != '\0'; i++)
{
    int digit = operand2[i] - '0';

    insert_at_last(&head2, &tail2, digit);
}

Dlist *headR=NULL;
Dlist *tailR=NULL;
char  operator = argv[2][0];
switch(operator)
{
   case '+':
    printf("ADDITION OPERATION\n");

    if (sign_case == 1)
    {
        addition(tail1, tail2, &headR, &tailR);

        printf("RESULT: ");
        print_list(headR);
    }
    else if (sign_case == 2)
    {
        if (cmp(head1, head2) >= 0)
        {
            subtraction(tail1, tail2, &headR, &tailR);

            printf("RESULT: ");
            print_list(headR);
        }
        else
        {
            subtraction(tail2, tail1, &headR, &tailR);

            printf("RESULT: -");
            print_list(headR);
        }
    }
    else if (sign_case == 3)
    {
        if (cmp(head1, head2) >= 0)
        {
            subtraction(tail1, tail2, &headR, &tailR);

            printf("RESULT: -");
            print_list(headR);
        }
        else
        {
            subtraction(tail2, tail1, &headR, &tailR);

            printf("RESULT: ");
            print_list(headR);
        }
    }
    else
    {
        printf("RESULT: -");

        addition(tail1, tail2, &headR, &tailR);

        print_list(headR);
    }

    break;
        
   case '-':
    printf("SUBTRACTION OPERATION\n");

    if (sub_sign_case == 1)
    {
      

        int comparison = cmp(head1, head2);

        if (comparison >= 0)
        {
            subtraction(tail1, tail2, &headR, &tailR);

            printf("RESULT: ");
            print_list(headR);
        }
        else
        {
            subtraction(tail2, tail1, &headR, &tailR);

            printf("RESULT: -");
            print_list(headR);
        }
    }
    else if (sub_sign_case == 2)
    {

        addition(tail1, tail2, &headR, &tailR);

        printf("RESULT: ");
        print_list(headR);
    }
    else if (sub_sign_case == 3)
    {
        

        addition(tail1, tail2, &headR, &tailR);

        printf("RESULT: -");
        print_list(headR);
    }
    else
    {
       
        int comparison = cmp(head1, head2);

        if (comparison >= 0)
        {
            subtraction(tail1, tail2, &headR, &tailR);

            printf("RESULT: -");
            print_list(headR);
        }
        else
        {
            subtraction(tail2, tail1, &headR, &tailR);

            printf("RESULT: ");
            print_list(headR);
        }
    }

    break;
    case 'x':

    printf("MULTIPLICATION OPERATION\n");

    if (multiplication(tail1, tail2, &headR, &tailR) == FAILURE)
    {
        printf("SORRY, YOUR MULTIPLICATION OPERATION FAILED\n");
    }
    else
    {
        printf("RESULT: ");

        if (mul_sign_case == 2 || mul_sign_case == 3)
        {
            printf("-");
        }

        print_list(headR);
    }

    break;
    
case '/':

    printf("DIVISION OPERATION\n");

    if (division(head1, head2,tail1, tail2, &headR, &tailR) == FAILURE)
    {
        printf("DIVISION FAILED\n");
    }
    else
    {
        printf("RESULT: ");

        if (div_sign_case == 2 || div_sign_case == 3)
        {
            printf("-");
        }

        print_list(headR);
    }

    break;



         default:
            printf("INVALID OPERATOR\n");
            return 1;
}
    
        return 0;

}

    
