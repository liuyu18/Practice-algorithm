#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct student {
    int num;
    float score;
}node;
#define LIST_SIZE 50
#define TRUE 1
#define FALSE 0

typedef struct {
    node data[LIST_SIZE];
    int last;
}SeqList;

int GetSize(SeqList *pList){
    return pList->last;
}

void ShowSeqList(SeqList *pList){
    for(int i = 0;i < pList->last; i++){
        printf("学生的学号是%d,成绩是%f\n", pList->data[i].num, pList->data[i].score);
    }
}

SeqList *InitSeq() {
    SeqList *pList = NULL;
    pList = (SeqList *)malloc(sizeof(SeqList));
    if(pList != NULL){
        pList->last = 0;
    }
    return pList;
}

int InsertStySeq(SeqList *pList,node *pNode,int k){
    int j;
    for(j = pList->last; j >= k;j--){
        pList->data[j+1].num = pList->data[j].num;
        pList->data[j+1].score = pList->data[j].score;
    }
    pList->data[k].num = pNode->num;
    pList->data[k].score = pNode->score;
    pList->last++;
    return TRUE;
}

int DelSeqList(SeqList *pList,int k){
    if(pList->last == 0){
        return FALSE;
    }
	for (int j = k;j <= pList->last;j++) {
		pList->data[j].num = pList->data[j + 1].num;
		pList->data[j].score = pList->data[j + 1].score;
	}
	pList->last--;
	return TRUE;
}

void DisplayStu(SeqList *pList,int stuNo){
    	for (int i = 0;i < pList->last;i++) {
		if (pList->data[i].num == stuNo) {
			printf("该学生的成绩是%f\n", pList->data[i].score);
			return;
		}
	}
	printf("该学生不存在\n");
}


int main(void) {
	SeqList* stuList = InitSeq();
	node stu[2];
	stu[0].num = 1;
	stu[0].score = 99;
	stu[1].num = 2;
	stu[1].score = 100;
	if (stuList) {
		for (int i = 0;i < 2;i++) {
			InsertStySeq(stuList, &stu[i], i);
		}

	}
	ShowSeqList(stuList);
	//DelSeqList(stuList, 1);
	//ShowSeqList(stuList);
	printf("\n************\n");
	DisplayStu(stuList, 1);
	getchar();
	return 0;
}