//
//  main.cpp
//  Aglo
//
//  Created by Yu on 2019/1/29.
//  Copyright © 2019 Yu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

template<class T,class _outPara>
class PrintInfo :public unary_function<T, _outPara> {
public:
    PrintInfo():m_count(0),m_nSum(0){}
    T GetSum() {
        return m_nSum;
    }
    T GetMax() {
        return m_nMax;
    }
    T GetMin() {
        return m_nMin;
    }
    
    _outPara operator()(T x) {
        if (m_count == 0) {
            m_nMax = x;
            m_nMin = x;
        }
        else {
            if (m_nMax < x)
                m_nMax = x;
            if (m_nMin > x)
                m_nMin = x;
        }
        m_nSum += x;
        m_count++;
    }
    
private:
    T m_nSum;
    T m_nMax;
    T m_nMin;
    int m_count;
    
};

int main(void) {
    float A[] = { 1.0,2.1,3.2,4.3,5.4 };
    const int N = sizeof(A) / sizeof(int);
    
    
    //仿函数：实际上完成了容器元素的回调函数
    PrintInfo<float, void> p = for_each(A, A + N, PrintInfo<float, void>());
    cout << "sum:" << p.GetSum() << endl;
    cout << "max:" << p.GetMax() << endl;
    cout << "min:" << p.GetMin() << endl;
    
    cin.get();
    return 0;
}
