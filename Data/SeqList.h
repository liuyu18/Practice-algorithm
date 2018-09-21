#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;//假定线性表的元素类型为整型
#define LIST_SIZE 1024 //假定我们的线性表长度是1024
#define TRUE 1
#define FALSE 0
typedef struct {
	ElemType data[LIST_SIZE];
	int last;//指向最后一个节点的位置
}SequenList;


SequenList* InitSeq();

int GetSizeSeq(SequenList *pList);
int GetElemSqList(SequenList* pList,int pos,ElemType *e);
int LocateElemSqlist(SequenList *pList,ElemType key);
int InsertElemSqList(SequenList *pList,ElemType x,int k);
int DelElemSqList(SequenList *pList,int k);
void showSeqList(SequenList *pList);
