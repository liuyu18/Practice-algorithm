#include "LinkList.h"

LinkListNode* InitLinkList(void) {
	LinkListNode* pHead = NULL;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (pHead) {
		pHead->pNext = NULL;
	}
	return pHead;
}
int GetSizeLinkList(LinkListNode *pHead){
  int n = 0;
  while (pHead->pNext) {
    n++;
    pHead = pHead->pNext;
  }
  return n;
}

LinkListNode *GetSizeLinkListNode(LinkListNode *pHead,int pos){
  int j;
  LinkListNode *p;
  p = pHead;
  j = 0;
  if (pos == 0) {
    return NULL;
  }
  while (j < pos && p->pNext != NULL) {
    p = p->pNext;
    j++;
  }
  if (pos == j) {
    return p;
  }else{
    return NULL;
  }
}
LinkListNode *LocateLinkList(LinkListNode *pHead,int objData){
  LinkListNode *p;
  p = pHead->pNext;
  while (p != NULL && p->data != objData) {
    p = p->pNext;
  }
  return p;
}
LinkListNode *Create_Rear_LkList(ElemType arr[],int length){
  LinkListNode *pHead,*p,*q;
	int i;
	pHead = (LinkListNode *)malloc(sizeof(LinkListNode));
	q = pHead;
	for (i = 0; i < length; i++) {
		p = (LinkListNode *)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		q->pNext = p;
		q = p;
	}
	p->pNext = NULL;
	return pHead;
}
LinkListNode * Create_Front1_LkList(ElemType arr[], int length){
	LinkListNode *pHead,*p,*q;
	int i;
	pHead = (LinkListNode *)malloc(sizeof(LinkListNode));
	pHead->pNext = NULL;
	q = pHead->pNext;
	for (i = length - 1;i >= 0;i--) {
		p = (LinkListNode *)malloc(sizeof(LinkListNode));
		p->data = arr[i]
		p->pNext = q;
		pHead->pNext = p;
		q = pHead->pNext;
	}
	return pHead;
}
LinkListNode* Create_Front2_LkList(ElemType arr[], int length) {
	LinkListNode* pHead, *p, *q;
	int i;
	q = NULL;
	for (i = length - 1;i >= 0;i--) {
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = q;
		q = p;
	}
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = q;
	return pHead;
}
///头插法建立
LinkListNode* Create_Front3_LkList(ElemType arr[], int length) {
	LinkListNode* pHead, *p;
	int i;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = NULL;
	for (i = length - 1;i >= 0;i--) {
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	return pHead;
}
void Insert_After_LkList(LinkListNode* ptr, ElemType x) {
	LinkListNode *s,qPtr;
	s = (LinkListNode *)malloc(sizeof(LinkListNode));
	s->data = x;
	qPtr = pHead;
	while (qPtr->pNext != ptr) {
		qPtr = qPtr->pNext;
	}
	s->pNext = ptr;
	qPtr->pNext = s;
}
//指定位置之前插入
void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x) {
	LinkListNode* s, *qPtr;
	s = (LinkListNode*)malloc(sizeof(LinkListNode));
	s->data = x;
	qPtr = pHead;//qPtr是用来代替pHead的移动的,ptr是目标节点
	while (qPtr->pNext != ptr)
		qPtr = qPtr->pNext;
	s->pNext = ptr;
	qPtr->pNext = s;
}
LinkListNode* Delete_After_LkList(LinkListNode* ptr){
	LinkListNode *fptr;
	fptr = ptr->pNext;
	ptr->pNext = fptr->pNext;
	return fptr;
}
