#pragma once
#include <vector>
//�γ���ʾ��ͼ�Ѿ����
using namespace std;
class bfs
{
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
	bfs();
	~bfs();
};

