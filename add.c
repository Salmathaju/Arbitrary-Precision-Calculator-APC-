#include<stdio.h>
#include "types.h"
#include "dll.h"
int addition(Dlist *tail1,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    int carry=0;
    int digit;
    while(tail1!=NULL ||tail2!=NULL)
    {
        int result=carry;
        if(tail1!=NULL && tail2!=NULL)
        {
        result = tail1 -> data + tail2 ->data + result;
        tail1 = tail1->prev;
        tail2 = tail2->prev;
        }
        else if(tail1!=NULL && tail2==NULL)
        {
            result = tail1->data + result;
            tail1 = tail1-> prev;
        }
        else if(tail1==NULL && tail2!=NULL)  
        {
            result = tail2 -> data + result;
            tail2 = tail2 -> prev;
        }
        if(result > 9)
        {
            digit = result % 10;
            
            carry =1;
        }
        else
        {
            digit=result;
           carry=0;
        }
        insert_at_first(headR,tailR,digit);
    }
    if(carry==1)
    {
       insert_at_first(headR, tailR, carry); 
    }
    return SUCCESS;
}