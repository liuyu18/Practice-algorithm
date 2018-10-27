
#include "SeqList.h"

SequenList* lPtr;

SequenList* InitSeq() {
	SequenList *pList=NULL;
	pList = (SequenList *)malloc(sizeof(SequenList));
	if (pList != NULL)
		pList->last = 0;

	return pList;
}
int GetSizeSeq(SequenList* pList) {
	return pList->last;
}

int GetElemSqList(SequenList* pList, int pos, ElemType *e) {
	if (pos<0 || pos>pList->last) {
		return FALSE;
	}
	if (pList->last <= 0)
		return FALSE;
	*e = pList->data[pos];
	return TRUE;
}

int LocateElemSqList(SequenList* pList, ElemType key) {
	int i;
	for (i = 0;i < pList->last;i++) {
		if (pList->data[i] == key)
			return i;
	}
	return -1;
}

int InsertElemSqList(SequenList* pList, ElemType x, int k) {
	int j;
	if (pList->last >= LIST_SIZE - 1)
		return FALSE;
	if (k<0 || k>(pList->last + 1))
		return FALSE;
	for (j = pList->last;j >= k;j--) {
		pList->data[j + 1] = pList->data[j];
	}
	pList->data[k] = x;
	pList->last = pList->last + 1;
	return TRUE;
}


int DelElemSqList(SequenList *pList, int k) {
	if ((k >= 0 && k <= pList->last) && (pList->last != 0)) {
		for (int j = k;j <= pList->last;j++) {
			pList->data[j] = pList->data[j + 1];
		}
		pList->last--;
		return TRUE;
	}
	return FALSE;
}


void showSeqList(SequenList* pList) {
	for (int i = 0;i < pList->last;i++) {
		printf(" %d", pList->data[i]);
	}
}


int main(void) {
	lPtr = InitSeq();
	if (lPtr) {
		for (int i = 0;i < 10;i++) {
			InsertElemSqList(lPtr, i, i);
		}
		printf("初始化后顺序表的元素个数：%d\n", GetSizeSeq(lPtr));
		printf("\n=========\n");
		showSeqList(lPtr);
        printf("\n=========\n");
		InsertElemSqList(lPtr, 2000, 0);
		printf("插入新的元素后顺序表的元素个数：%d\n", GetSizeSeq(lPtr));
		printf("\n=========\n");
		showSeqList(lPtr);
        printf("\n\n=========\n");
		DelElemSqList(lPtr, 1);
		printf("删除元素之后顺序表的元素个数：%d\n", GetSizeSeq(lPtr));
		printf("\n=========\n");
		showSeqList(lPtr);
        printf("\n=========\n");
		int pos = LocateElemSqList(lPtr, 16);
		if (pos >= 0) {
			printf("当前元素位于%d\n", pos);
		}
		else {
			printf("没有找到这个元素");
		}
		printf("\n=========\n");
		showSeqList(lPtr);

	}
	// else {

	// }
	// getchar();
	// getchar();
	return 0;
}

