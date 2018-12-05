#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *pNext;
}LinkCircleListNode;

LinkCircleListNode *Create_Circle_LkList(int arr[],int length){
  LinkCircleListNode *head,*p,*q;
  int i;
  head = (LinkCircleListNode *)malloc(sizeof(LinkCircleListNode;
  q = head;

  for ( i = 0; i < length; i++) {
    p = (LinkCircleListNode *)malloc(sizeof(LinkCircleListNode));
    p->data = arr[i];
    q->pNext = p;
    q = p;
  }
  p->pNext = head;
  return p;
}

void ShowCircleLkList(LinkCircleListNode *pRear){
  LinkCircleListNode *p = pRear->pNext;
  p = p->pNext;
  while (p != pRear->pNext) {
    printf("%d\n",p->data );
    p = p->pNext;
  }
}

LinkCircleListNode *Connect_Circle_LkList(LinkCircleListNode *ra,LinkCircleListNode *rb){
  LinkCircleListNode *p;
  p = ra->pNext;
  ra->pNext = rb->pNext->pNext;
  free(rb->pNext);
  rb->pNext = p;
  return rb;
}
int mainCCCC(void) {
	int arr[] = { 11,22,33,44,55 };
	LinkCircleListNode* pRrear = Create_Circle_LkList(arr, 5);
	//

	//测试合并
	int a[] = { 1,3,5 };
	int b[] = { 2,4,6 };
	LinkCircleListNode *ra, *rb;
	ra = Create_Circle_LkList(a, 3);
	rb = Create_Circle_LkList(b, 3);
	LinkCircleListNode * pRear =Connect_Circle_LkList(ra, rb);
	ShowCircleLkList(pRear);
	getchar();
	return 0;
}
