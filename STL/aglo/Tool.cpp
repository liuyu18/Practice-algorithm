#include "Tool.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <bitset>
#include <array>
#include <list>
#include <iterator>
using namespace std;


Tool::Tool()
{
}
bool mygreater(int temp){
    return temp>4;
}
void Tool::Find(){
    int a[] = { 1,2,2,2,3,4,4,5,6,7,1,2,2,3 };
	int nSize = sizeof(a) / sizeof(int);

	//第一个等于3
	int *p1 = find(a, a + nSize, 3);

	if (p1 != a + nSize)
		cout << p1 - a << endl;

	//出现第一个大于4
	int *p2 = find_if(a, a + nSize, mygreater);
	if (p2 != a + nSize)
		cout << p2 - a << endl;

	//首次在a数组中，发现有b数组元素的位置
	int b[] = { 10,12,6 };
	int nSize2 = sizeof(b) / sizeof(int);
	int *p3 = find_first_of(a, a + nSize, b, b + nSize2);
	if (p3 != a + nSize)
		cout << p3 - a << "\t" << *p3 << endl;

	//在当前容器中，首次相邻元素的位置
	int *p4 = adjacent_find(a, a + nSize);
	if (p4 != a + nSize)
		cout << p4 - a << "\t" << *p4 << endl;

	//最后一次匹配c数组的位置
	int c[] = { 2,3 };
	int nSize3 = sizeof(c) / sizeof(int);
	int *p5 = find_end(a, a + nSize, c, c + nSize3);
	if(p5!=a+nSize)
	cout << p5 - a << endl;

	//首次匹配的位置
	int *p6 = search(a, a + nSize, c, c + nSize3);
	if (p6 != a + nSize)
		cout << p6 - a << endl;
}
void Tool::Search(){
    	int a[] = { 1,2,2,3,3,
				3,4,4,4,4,
				6,6,6,6,6,6 };
	list<int> l(a, a + 16);
    bool bExit = binary_search(l.begin(),l.end(),5);
    cout << (bExit == 0 ? "false" : "true") << endl;

    list<int>::iterator iterFirst = lower_bound(l.begin(),l.end(),3);
    if (iterFirst != l.end()) {
        cout<<distance(l.begin(),iterFirst)<<endl;
    }
    list<int>::iterator iterLast = upper_bound(l.begin(),l.end(),4);
    if (iterLast != l.end()) {
        cout<<distance(l.begin(),--iterLast)<<endl;
    }
    pair<list<int>::iterator,list<int>::iterator> p = equal_range(l.begin(),l.end(),4);
    if (p.first != p.second) {
		int nSize = distance(p.first,p.second);
		cout << nSize << endl;

	}
	cin.get();
}

void Tool::Sort(){
    int a[] = { 10,1,3,11,32,
			 487,99,-1,-2,86 };
    list<int> l(a,a+10);
    l.sort();
    copy(l.begin(),l.end(),ostream_iterator<int>(cout,"\t"));
    cin.get();
}

void Tool::copy(){
    int a[] = { 1,2,3,4,5 };
	int b[5];
    vector<int> v;

    copy(a,a+5,back_inserter(v));
    	for (int i = 0;i < 5;i++) {
		cout << v[i] << endl;
	}
}

Tool::~Tool()
{
}
