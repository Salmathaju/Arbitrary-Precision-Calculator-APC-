#include <stdio.h>
#include "dll.h"
#include "types.h"

int division(Dlist *head1, Dlist *head2,
             Dlist *tail1, Dlist *tail2,
             Dlist **res_head, Dlist **res_tail)
{
    int count = 0;
    int temp, value;

    Dlist *newhead = NULL;
    Dlist *newtail = NULL;
    Dlist *tempnode = NULL;

    /* Division by zero */

    if (head2->data == 0 && head2->next == NULL)
    {
        return FAILURE;
    }

    /* Dividend < Divisor */

    if (cmp(head1, head2) == -1)
    {
        insert_at_first(res_head, res_tail, 0);

        return SUCCESS;
    }

    /* Dividend == Divisor */

    if (cmp(head1, head2) == 0)
    {
        insert_at_first(res_head, res_tail, 1);

        return SUCCESS;
    }

    while (cmp(head1, head2) >= 0)
    {
        newhead = NULL;
        newtail = NULL;

        subtraction(tail1, tail2, &newhead, &newtail);

        delete_list(&head1, &tail1);

        head1 = newhead;
        tail1 = newtail;

        count++;

        temp = count;

        tempnode = *res_tail;

        while (tempnode != NULL && temp > 0)
        {
            tempnode->data = temp % 10;

            tempnode = tempnode->prev;

            temp /= 10;
        }

        while (temp > 0)
        {
            value = temp % 10;

            insert_at_first(res_head, res_tail, value);

            temp /= 10;
        }
    }

    return SUCCESS;
}