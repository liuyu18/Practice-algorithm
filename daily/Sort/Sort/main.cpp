//
//  main.cpp
//  Sort
//
//  Created by Yu on 2018/8/3.
//  Copyright © 2018年 Yu. All rights reserved.
//

#include <iostream>
void printArray(int *pArr, int n)
{
    for(int j = 0; j < n; j++)
    {
        printf("%d ", pArr[j]);
    }
    printf("\n");
}
//冒泡
bool bubbleSort(int *pArr,int arrLen,int *pTar){
    if (NULL == pArr) {
        return false;
    }
    if (NULL == pTar) {
        return false;
    }
    for (int k = 0; k < arrLen; k++) {
        pTar[k] = pArr[k];
    }
    for (int i = 0; i < arrLen - 1; i++) {
        for (int j = 0; j < arrLen - 1 -i; j++) {
            if (pTar[j] > pTar[j+1]) {
                int tmp = pTar[j];
                pTar[j] = pTar[j+1];
                pTar[j+1] = tmp;
            }
            printArray(pTar, arrLen);
        }
    }
    return true;
}

bool insertSort(int *pArr,int arrLen,int *pTar){
    if(NULL == pArr){
        return false;
    }
    if(NULL == pTar){
        return false;
    }
    for(int k = 0; k < arrLen; k++)
    {
        pTar[k] = pArr[k];
    }
    for (int index = 0; index < arrLen - 1; index++) {
        if (pTar[index] > pTar[index + 1]) {
            int j = index;
            int x = pTar[index + 1];
            while (x < pTar[j]) {
                pTar[j + 1] = pTar[j];
                j--;
                if (j < 0) {
                    break;
                }
            }
            pTar[j+1] = x;
        }
        printArray(pTar, arrLen);
    }
    return true;
}
//找出最小值->找最小索引，from（含）,to(不含)
int selectMinKey(int *pArr, int from, int to)
{
    int k = from;
    for(int i = from + 1; i < to; i++)
    {
        if(pArr[k] > pArr[i])
        {
            k = i;
        }
        
    }
    return k;
}

bool selectSort(int *pArr,int arrLen,int *pTar){
    if (NULL == pArr) {
        return false;
    }
    if (NULL == pTar) {
        return false;
    }
    
    for(int k = 0; k < arrLen; k++)
    {
        pTar[k] = pArr[k];
    }
    for (int index = 0; index < arrLen; index++) {
        int key = selectMinKey(pTar, index, arrLen);
        if (key != index) {
            int tmp = pTar[index];
            pTar[index] = pTar[key];
            pTar[key] = tmp;
        }
        printArray(pTar, arrLen);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[5] = {6, 5, 4, 3, 2};
    int tar[5] = {0};
//    bubbleSort(arr, 5, tar);
    insertSort(arr, 5, tar);
    return 0;
}
