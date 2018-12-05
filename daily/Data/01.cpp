#include "SeqList.h"


SeqList *lPtr;
SeqList *InitSeq(){
  SeqList *pList = NULL;
  pList = (SequenList *)malloc(sizeof(SeqList));
  if (pList != NULL) {
    pList->last = 0;
  }
  return pList;
}
int GetSizeSeq(SequenList *pList){
  return pList->last;
}

int GetElemSqList(SequenList *pList,int pos,ElemType *e){
  if (pos < 0 || pos > pList->last) {
    return FALSE;
  }
  if (pos->last <= 0) {
    return FALSE;
  }
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
int main1(void) {
	lPtr = InitSeq();//这样是否可以=>可以的，且使用NULL来判断是否初始化完毕
	if (lPtr) {
		//todo:继续使用这个顺序表
		for (int i = 0;i < 10;i++) {
			InsertElemSqList(lPtr, i, i);
		}
		printf("初始化后顺序表的元素个数：%d", GetSizeSeq(lPtr));
		printf("************\n");
		showSeqList(lPtr);
		InsertElemSqList(lPtr, 2000, 0);
		printf("初始化后顺序表的元素个数：%d", GetSizeSeq(lPtr));
		printf("************\n");
		showSeqList(lPtr);
		DelElemSqList(lPtr, 1);
		printf("初始化后顺序表的元素个数：%d", GetSizeSeq(lPtr));
		printf("************\n");
		showSeqList(lPtr);
		int pos = LocateElemSqList(lPtr, 16);
		if (pos >= 0) {
			printf("当前元素位于%d", pos);
		}
		else {
			printf("没有找到这个元素");
		}
		printf("************\n");
		showSeqList(lPtr);

	}
	else {
		//todo:提示没有可以使用的空间
	}
	getchar();
	getchar();
	return 0;
}
