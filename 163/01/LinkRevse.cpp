#include "LinkList.h"
#include "LinkTable.cpp"
LinkListNode *ReverseLkList(LinkListNode *pHead){
    LinkListNode *Pointer,*Next;
    LinkListNode *Back;

    Back = pHead;
    Pointer = Back->pNext;
    Next = Pointer->pNext;
    Pointer->pNext = Back;
    Back = Pointer;
    Pointer = Next;

    while(Pointer->pNext != NULL){
        Next = Pointer->pNext;
        Pointer->pNext = Back;
        Back = Pointer;
        Pointer = Next;
    }
    Pointer->pNext = Back;
    pHead->pNext->pNext = NULL;
    pHead->pNext = Pointer;
    return pHead;
}

int main(void) {
	LinkListNode* pHead = NULL;
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	pHead = Create_Rear_LkList(arr, 10);
	printf("\n************当前的元素有\n");
	ShowLkList(pHead);

	pHead = ReverseLkList(pHead);
	printf("\n************当前的元素有\n");
	ShowLkList(pHead);
	getchar();
	return 0;
}

