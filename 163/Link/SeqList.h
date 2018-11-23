
#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define LIST_SIZE 1024
#define TRUE 1
#define FALSE 0
typedef struct {
	ElemType data[LIST_SIZE];
	int last;
}SequenList;
SequenList* InitSeq();
int GetSizeSeq(SequenList* pList);
int GetElemSqList(SequenList* pList, int pos, ElemType *e);
int LocateElemSqList(SequenList* pList, ElemType key);
int InsertElemSqList(SequenList* pList, ElemType x, int k);
int DelElemSqList(SequenList *pList, int k);
void showSeqList(SequenList* pList);
