#include <stdio.h>

void create_btree(int b_tree[], int nodelist[], int len) {
	int i;
	int level;
	b_tree[1] = nodelist[1];

	for (i = 2;i < len;i++) {
		level = 1;
		while (b_tree[level] != 0) {
            printf("===nodelist [i] :%d=====\n",nodelist[i]);
            printf("==b_tree [level] :%d===\n",b_tree[level]);
			if (nodelist[i] < b_tree[level]) {
				level = level * 2;
			}
			else {
				level = level * 2 + 1;
			}
		}
		b_tree[level] = nodelist[i];
	}

}



int main(void){
	int b_tree[16] = { 0 };
	int nodelist[16] = { 0, 6,3,8,
						5,2,9,4,7,
						10,0,0,0,
						0,0,0};//根据角标的定义，我们的数组形式不用0开始做编号
	create_btree(b_tree, nodelist, 16);
	for (int i = 1;i < 16;i++) {
		printf("%d,[%d] \n", i, b_tree[i]);
	}
}