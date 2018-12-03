#include <stdio.h>

#define stackSize 100
#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef int ElemType;

typedef struct {
    ElemType stack[stackSize];
    int top;
}SeqStack;

BOOL init(SeqStack *pStack){
    pStack->top = 0;
    return 1;
}
BOOL isEmpty(SeqStack *pStack){
    return (pStack->top == 0);
}

BOOL pushStack(SeqStack *pStack,ElemType x){
    if(pStack->top == stackSize){
        printf("空间溢出\n");
		return FALSE;
    }
    pStack->top = pStack->top + 1;
    pStack->stack[pStack->top] = x;
    return TRUE;
}

ElemType popStack(SeqStack *pStack){
    ElemType tmp;
    if(pStack->top == 0){
        printf("当前是空栈\n");
		return -1;
    }
    tmp = pStack->stack[pStack->top];
    pStack->top = pStack->top - 1;
    return tmp;
}

void myConv(SeqStack *pStack,int n){
    int e;
    while(n){
        pushStack(pStack,n % 8);
        n = n / 8;
    }
    while(!isEmpty(pStack)){
        e = popStack(pStack);
		printf("%d", e);
    }
}

BOOL GetSeqStack(SeqStack *s,ElemType *data){
    if(s->top == 0){
        return FALSE;
    }
    *data = s->stack[s->top];
    return TRUE;
}

int main(int argc, char const *argv[])
{
    SeqStack s;
	init(&s);
	printf("十进制数1348，转为的8进制是：\n");
	myConv(&s, 1348);
	getchar();
    return 0;
}
