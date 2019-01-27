#include <vector>
#include <deque>
#include <iostream>
using namespace std;

//int main() {
//	vector<int> v(2, 5);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//int main() {
//	vector<int> v(2);
//	v[0] = 10;
//	int *p = &v[0];
//	cout << "vector中第一个元素的迭代指针*p:" << *p << endl;
//	v.push_back(20);
//	cout << "vector容量变化后vector第一个元素的迭代指针*p:" << *p << endl;
//	system("pause");
//	return 0;
//}


template<class T>
class MyQueue {
	deque<T> d;
public:
	void push(const T& t) {
		d.push_back(t);
	}
	void pop() {
		d.pop_front();
	}
	int size() {
		return d.size();
	}
	bool empty() {
		return d.empty();
	}

};