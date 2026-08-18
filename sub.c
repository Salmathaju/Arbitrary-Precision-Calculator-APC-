#include<stdio.h>
#include<stdlib.h>
#include "types.h"
#include "dll.h"


int cmp(Dlist *head1,Dlist *head2)
{
   
    Dlist *list1=head1;
    Dlist *list2=head2;

    while(list1!=NULL && list1->data==0 && list1->next!=NULL)
    {
        
        list1=list1->next;
    }

    while(list2!=NULL&&list2->data==0 &&list2->next!=NULL)
    {
       
        list2=list2->next;
    }
    int count1=0;
    int count2=0;
    Dlist *temp1 = list1;
    Dlist *temp2 = list2;
    while(temp1!=NULL)
    {
        count1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        count2++;
        temp2=temp2->next;
    }

    if(count1 > count2)
    {
        return 1;
    }
    if(count1 < count2)
    {
        return -1;
    }

    /*list1=head1;
    list2=head2;*/
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data > list2->data)
        {
         return 1;
        }
        if(list1->data < list2->data)
        {
            return -1;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return 0;

}
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int result;
    int borrow = 0;

    while (tail1 != NULL || tail2 != NULL)
    {
        if (tail1 != NULL && tail2 != NULL)
        {
            int num1 = tail1->data - borrow;
            int num2 = tail2->data;

            if (num1 < num2)
            {
                num1 += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            result = num1 - num2;

            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if (tail1 != NULL && tail2 == NULL)
        {
            int num1 = tail1->data - borrow;

            if (num1 < 0)
            {
                num1 += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            result = num1;

            tail1 = tail1->prev;
        }
        else
        {
            break;
        }

        insert_at_first(headR, tailR, result);
    }
    while (*headR != NULL &&
           (*headR)->data == 0 &&
           (*headR)->next != NULL)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;

        (*headR)->prev = NULL;

        free(temp);
    }

    return SUCCESS;
}