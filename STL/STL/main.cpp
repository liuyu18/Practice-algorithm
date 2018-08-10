//
//  main.cpp
//  STL
//
//  Created by Yu on 2018/7/26.
//  Copyright © 2018年 Yu. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <iterator>
using namespace std;
int main() {
    
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> v(a,a+10);
    vector<int>::reverse_iterator rpos(v.end());
    cout << "反向迭代器的数据" << *rpos << endl;
    cout << "反向头迭代器的数据" << *v.rbegin() << endl;
    vector<int>::iterator pos1;
    pos1 = find(v.begin(), v.end(), 6);
    vector<int>::reverse_iterator rpos1(pos1);
    cout << "正向迭代器指向的数据是" << *pos1 << endl;
    cout << "反向迭代器所指向的数据为" << *rpos1 << endl;
    cin.get();
    return 0;
}
