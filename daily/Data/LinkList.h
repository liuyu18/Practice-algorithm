#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct node {
  int data;
  struct node *pNext;
}LinkListNode;

LinkListNode *InitLinkList(void);
int GetSizeLinkList(LinkListNode *pHead);
LinkListNode *GetSizeLinkListNode(LinkListNode *pHead,int pos);
LinkListNode *LocateLinkList(LinkListNode *pHead,int objData);
LinkListNode *Create_Rear_LkList(ElemType arr[],int length);
LinkListNode *Create_Front1_LkList(ElemType arr[],int length);
LinkListNode* Create_Front2_LkList(ElemType arr[], int length);
LinkListNode* Create_Front3_LkList(ElemType arr[], int length);
void Insert_After_LkList(LinkListNode* ptr, ElemType x);
void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x);
LinkListNode* Delete_After_LkList(LinkListNode* ptr);
LinkListNode* Delete_i_LkList(LinkListNode* pHead, int i);
void ShowLkList(LinkListNode* pHead);
