// algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "bfs.h"
#include <vector>
#include <iostream>
int main()
{
	bfs bf = bfs();
	pair<int, int> order(1, 0);
	vector<pair<int, int>> ordervector[[order]];

	vector<int>result =  bf.findOrder(2, ordervector);
	
	for (vector<int>::const_iterator iter = result.cbegin(); iter != result.cend(); iter++)
	{
		cout << (*iter) << endl;
	}
    return 0;
}

