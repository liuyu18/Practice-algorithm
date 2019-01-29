#include "Tool.h"
#include "TemplateClass.cpp"
#include <iostream>
using namespace std;
int main()
{
	float A[] = { 1.0,2.1,3.2,4.3,5.4 };
	const int N = sizeof(A) / sizeof(int);

    PrintInfo<float,void> p = for_each(A,A + N,PrintInfo<float,void>());

	cout << "sum:" << p.GetSum() << endl;
	cout << "max:" << p.GetMax() << endl;
	cout << "min:" << p.GetMin() << endl;

	cin.get();
    // Tool *test = new Tool();
    // test->showUseSTL();
    //system("pause");
    return 0;
}