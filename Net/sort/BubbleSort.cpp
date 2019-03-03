#include "BubbleSort.h"
#include <stdio.h>


BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
}

void BubbleSort::Sort1(int a[], int length) {
	int i, j, temp;
	int change = 0;//检测一次排序中是否有交换，没有交换说明已经有序
	for (i = length - 1; i >= 0 && change == 0; i--) {
		change = 1;//位置不能变
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				//角标较小的数比角标较大的数大，交换之
				change = 0;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int Parition(int arr[], int low, int high) {
	int privotLoc = arr[low];
	int temp;
	printf("low:%d,high:%d\n", low, high);
	while (low < high)
	{
		while (low<high&&arr[high] >= privotLoc)
		{
			--high;
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
		while (low < high && arr[low] <= privotLoc)
		{
			++low;
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	return low;
}
void BubbleSort::QSort(int arr[], int n, int low, int hight) {
	int privoloc;
	if (low < hight) {
		privoloc = Parition(arr, low, hight);
		QSort(arr, n, low, privoloc - 1);
		QSort(arr, n, privoloc + 1, hight);
	}
}

