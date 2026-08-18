#ifndef DLL_H
#define DLL_H

#include "types.h"

int insert_at_last(Dlist **head, Dlist **tail, int data);
int insert_at_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int delete_list(Dlist **head, Dlist **tail);
int addition(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR);
int subtraction(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR);
int cmp(Dlist *head1, Dlist *head2);
int division(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail);

#endif
