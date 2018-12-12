#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./arrayStack.h"

stArrayStack *arrayStack_create(int stzie){
    stArrayStack *parrStack = NULL;
    parrStack = (stArrayStack *)malloc(sizeof(stArrayStack));
    if(parrStack == NULL{
        return NULL;
    }
    parrStack->size = size;
    parrStack->pos = -1;
    parrStack->array = (int *)malloc(sizeof(int)*size);
    if(parrStack->array == NULL){
        free(parrStack);
        return NULL;
    }
    return parrStack;
}

void arrayStack_destory(stArrayStack *parrStack){
    if(parrStack == NULL){
        return;
    }
    if(parrStack->array != NULL){
        free(parrStack->array);
    }
    free(parrStack);
    return;
}
int arrayStack_pop(stArrayStack *parrStack){
    int data = 0;
    if(arrayStack_is_empty(parrStack)){
        return -1;
    }
    data = parrStack->array[parrStack->pos];
    parrStack->pos--;
    return data;
}
int arrayStack_push(stArrayStack *parrStack,int data){
    if(arrayStack_is_full(parrStack)){
        return -1;
    }
    parrStack->pos++;
    parrStack->array[parrStack->pos] = data;
    return 0;
}
int arrayStack_push_new(stArrayStack *parrStack ,int data){
    int *ptmp = NULL;
    if(!arrayStack_is_full(parrStack)){
        
    }
}