

////设有一个顺序表，其数据为a,b,c,d,e,f,g,要求将其就地转置成g,f,e,d,c,b,a
////要求逆转表仍然占据原空间
//#include "SeqList.h"
//SequenList* pGlobalSeq;
//
//void RevseSeqList(SequenList* pList) {
//	int temp;
//	int count, i;
//	if (pList->last == 0 || pList->last == 1)
//		return;
//	count = pList->last / 2;
//	for (i = 0;i < count;i++) {
//		temp = pList->data[i];
//		pList->data[i] = pList->data[pList->last - 1 - i];
//		pList->data[pList->last - 1 - i] = temp;
//	}
//}
//int main(void) {
//	pGlobalSeq=InitSeq();
//	for (int i = 0;i < 10;i++) {
//		InsertElemSqList(pGlobalSeq, i * 2, i);
//	}
//	printf("\n**********当前的顺序表元素********\n");
//	showSeqList(pGlobalSeq);
//	RevseSeqList(pGlobalSeq);
//	printf("\n**********当前的顺序表元素********\n");
//	showSeqList(pGlobalSeq);
//	free(pGlobalSeq);
//	getchar();
//	return 0;
//}

#include "LinkList.h"

LinkListNode* ReverseLkList(LinkListNode* pHead) {
	LinkListNode* Pointer, *Next;

	LinkListNode* Back;

	Back = pHead;
	Pointer = Back->pNext;

	Next = Pointer->pNext;
	Pointer->pNext = Back;

	Back = Pointer;
	Pointer = Next;

	while (Pointer->pNext != NULL) {
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
int mainAAA(void) {
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
