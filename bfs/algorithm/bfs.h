#pragma once
#include <vector>
//课程修示意图已经添加
using namespace std;
class bfs
{
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
	bfs();
	~bfs();
};

