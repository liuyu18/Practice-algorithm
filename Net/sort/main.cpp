#include  <stdio.h>

#include "BubbleSort.h"


int main(void) {
	int ArrarOrg[] = { 49,38,65,97,76,
		13,27,49,55,4 };
	BubbleSort *sort = new BubbleSort();
	//sort->Sort1(ArrarOrg, 10);
	sort->QSort(ArrarOrg, 10, 0, 9);

	for (int i = 0;i < 10;i++) {
		printf("%d ", ArrarOrg[i]);
	}
	getchar();
	return 0;
}

