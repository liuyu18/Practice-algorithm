#include <stdio.h>
#include <stdio.h>
#include "SeqStack.h"


BOOL init(SeqStack *pStack){
    pStack->top = 0;
    return 1;
}

BOOL isEmpty(SeqStack *pStack){
    return (pStack->top == 0);
}

BOOL pushStack(SeqStack *pStack,ElemType x){
    if(pStack->top == stackSize){
        return FALSE;
    }
    pStack->top = pStack->top+1;
    pStack->stack[pStack->top] = x;
    return TRUE;
}

ElemType popStack(SeqStack* pStack) {
	ElemType tmp;
	if (pStack->top == 0) {
		printf("当前是空栈\n");
		return -1;
	}
	tmp = pStack->stack[pStack->top];
	pStack->top = pStack->top - 1;//逻辑上的出栈
	return tmp;
}
BOOL GetSeqStack(SeqStack* s, ElemType* data) {
	if (s->top == 0)
		return FALSE;
	*data = s->stack[s->top];
	return TRUE;
}

BOOL Is_Operator(char oper) {
	switch (oper)
	{
	case '+':
	case'-':
	case '*':
	case '/':
		return TRUE;
	default:
		return FALSE;
	}
}

int Priority(char oper) {
	switch (oper)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}
int two_res(int oper, int opand1, int opand2) {
	switch (oper)
	{
	case '+': return (opand2 + opand1);
	case '-':return (opand2 - opand1);
	case '*':return (opand2 * opand1);
	case '/':return (opand2 / opand1);
	default:
		return 0;
	}
}
