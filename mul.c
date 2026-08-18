#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "types.h"

int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0,result = 0,count = 0;

    Dlist *temp = tail1;

    Dlist *rhead1 = NULL;
    Dlist *rtail1 = NULL;

   

    while ( tail2!= NULL)
    {
         Dlist *rhead2 = NULL;
         Dlist *rtail2 = NULL;
        carry = 0;
        int i=0;
        while(i < count)
        {
            insert_at_last(&rhead2, &rtail2, 0);
            i++;
        }

        tail1=temp;

        while (tail1!=NULL)
        {
            result = tail1->data * tail2->data + carry;

            if (result >= 10)
            {
                carry = result / 10;
                result = result % 10;
            }
            else
            {
                carry = 0;
            }

            if(count==0)
            {
                insert_at_first(&rhead1, &rtail1, result);
            }
            else
            {
                insert_at_first(&rhead2, &rtail2, result);
            }


            tail1 = tail1->prev;
        }
        if(carry !=0)
        {
        
        if (count==0 && carry!=0)
        {
            insert_at_first(&rhead1, &rtail1, carry);
        }
        else
        {
            insert_at_first(&rhead2, &rtail2, carry);
        }
    }
    

        count++;

        if (count > 1)
        {
            addition(rtail1, rtail2, headR, tailR);

            delete_list(&rhead1, &rtail1);

            rhead1 = *headR;
            rtail1 = *tailR;

            delete_list(&rhead2, &rtail2);

            *headR = NULL;
            *tailR = NULL;
        }

        tail2 = tail2->prev;
    }
    *headR=rhead1;
    *tailR=rtail1;

    return SUCCESS;
}