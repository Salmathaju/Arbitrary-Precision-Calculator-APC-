#include<stdio.h>
#include<stdlib.h>
#include "dll.h"
#include "types.h"
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
   Dlist *new = malloc(sizeof(Dlist));
   if(new==NULL)
   {
    return FAILURE;
   } 
   new->data=data;
   new->next=NULL;
   new->prev=NULL;
   if(*head==NULL)
   {
    *head=new;
    *tail=new;
    return SUCCESS;
   }
   else
   {
    new->prev=*tail;
    (*tail)->next=new;
    *tail=new;
   }
   return SUCCESS;
}

int insert_at_first(Dlist **head, Dlist **tail, int data)
{
Dlist *new=malloc(sizeof(Dlist));
if(new==NULL)
{
   return FAILURE;
}
new->data=data;
new->prev=NULL;
new->next=NULL;
if(*head==NULL)
{
   *head=new;
   *tail=new;
}
else
{
   new->next=*head;
   (*head)->prev=new;
   *head=new;
}
return SUCCESS;
}

void print_list(Dlist *head)
{
    Dlist *temp = head;

    while (temp != NULL && temp->data == 0 && temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL)
    {
        return FAILURE;
    }

    Dlist *temp;

    while (*head != NULL)
    {
        temp = *head;

        *head = (*head)->next;

        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}