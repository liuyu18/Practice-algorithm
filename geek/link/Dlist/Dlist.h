#include <stdio.h>

typedef struct DlistNode{
    struct DlistNode *prev;
    struct DlistNode *next;
    int data;
}stDlistNode;

typedef struct Dlisthead
{
	int size;
	stDlistNode *head;
	stDlistNode *tail;
}stDlistHead;