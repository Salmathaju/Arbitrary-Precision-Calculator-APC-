#ifndef TYPES_H
#define TYPES_H

#define SUCCESS 1
#define FAILURE 0
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

#endif