#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef struct node{
    dataType data;
    struct node *left,*right;
}BitTree;


BitTree* Q[16];