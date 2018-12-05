// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

void printArray(int *pArr, int length) {
	for (int i = 0; i < length; i++)
	{
		printf("%d ", pArr[i]);
	}
	printf("\n");
}
//冒泡排序法
bool bubbleSort(int *pArr, int arrLen, int *pTar) {
	if (NULL == pArr)
	{
		return false;
	}
	if (NULL == pTar)
	{
		return false;
	}
	for (int i = 0; i < arrLen; i++)
	{
		pTar[i] = pArr[i];
	}
	for (int i = 0; i < arrLen-1; i++)
	{
		for (int j = 0; j < arrLen-1-i; j++)
		{
			if (pTar[j] > pTar[j+1])
			{
				int tmp = pTar[j];
				pTar[j] = pTar[j + 1];
				pTar[j + 1] = tmp;
			}
			printArray(pTar, arrLen);
		}
	}
	return true;
}
int main()
{
	int arr[5] = { 6, 5, 4, 3, 2 };
	int tar[5] = { 0 };
	bubbleSort(arr, 5, tar);
	system("pause");
    return 0;
}

