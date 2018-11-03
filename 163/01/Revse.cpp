#include "SeqList.h"
#include "arrayTable.cpp"
SequenList* pGlobalSeq;

void RevseSeqList(SequenList *pList){
    int temp;
    int count,i;
    if(pList->last == 0|| pList->last == 1){
        return;
    }
    count = pList->last / 2;
    for(i = 0;i < count;i++){
        temp = pList->data[i];
        pList->data[i] = pList->data[pList->last - 1 - i];
        pList->data[pList->last - 1 -i] = temp;
    }
}

int main1(void) {
	pGlobalSeq=InitSeq();
	for (int i = 0;i < 10;i++) {
		InsertElemSqList(pGlobalSeq, i * 2, i);
	}
	printf("\n============当前的顺序表元素============\n");
	showSeqList(pGlobalSeq);
	RevseSeqList(pGlobalSeq);
	printf("\n============当前的顺序表元素============\n");
	showSeqList(pGlobalSeq);
	free(pGlobalSeq);
	getchar();
	return 0;
}