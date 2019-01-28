#include "aglo.h"
#include <boost/array.hpp>
#include <boost/multi_array.hpp>
#include <iostream>
using namespace std;
using namespace  boost; 
aglo::aglo()
{
}

void aglo::showUseSTL()
{
    //运行时，动态创建一维数组，数组长度由用户指定
    //int   a = 3;
    //cin >> a;//用户输入一个长度
    //int  *pArr1 = new int[a];

    //运行时，动态创建二维数组，维度由用户指定
    //int  a = 3, b = 4;
    //cin >> a;
    //cin >> b;
    //  new int[a][b];//错误，无法通过编译，第二维的长度必须是常量

    //得出结论，C++中，除了第一维的可以是变量，后面的维度必须是常量，也就是说
    //编译的时候就要确定大小

    //为什么必须指定除了第一维之外的维度
    int e[][4] = {1, 2, 3, 4, 5, 6};
    /*编译器可以自动算出第一维是2( 6/3 =2)，   
	  1    2    3    4    
	  5    6    0    0


	  
	  int e[3][] = { 1,2,3,4,5,6 }; //初始化值的个数并不能代表数组的长度，因为有默认值
	  比如int  ee[5]={1};
	 
	  第一行       1  2  3  4  5                               1 2 3                       1  2
	  第二行       6  0  0  0  0                                4 5 6                       3  4
	  第三行       0  0  0  0   0                               0 0  0                      5  6
	 */

    //multi_array
    int a = 2; //  cin>>a由用户输入
    int b = 3;
    int c = 4;
    //创建了一个 3维数组，每一维的长度可以动态指定，不需要编译时指定
    multi_array<int, 3> arr(extents[a][b][c]);

    boost::array<int, 3> wd2 = {a, b, c};
    //创建一个 3维数组，使用array构造
    multi_array<int, 3> arr2(wd2);

    //像普通数组一样赋值
    arr[0][0][0] = 111;
    arr[1][2][3] = 666;

    //数组越界（assert）
    //arr[1][2][5] = 888;

    //打印数组的每一维度的长度
    cout << arr.shape()[0] << "  ,   " << arr.shape()[1] << "  ,   " << arr.shape()[2] << endl;

    //循环输出
    for (int i = 0; i < arr.shape()[0]; ++i)
        for (int j = 0; j < arr.shape()[1]; ++j)
            for (int k = 0; k < arr.shape()[2]; ++k)
                cout << arr[i][j][k] << "		";
    cout << endl;

    //元素总个数
    cout << arr.num_elements() << endl;

    //动态改变多维数组的维度的长度,原有元素将被复制到新的内存
    arr.resize(extents[4][5][6]); //改变第三位的长度
    arr[3][4][5] = 999;
    cout << arr[0][0][0] << "  ,  " << arr[1][2][3] << "  ,  " << arr[3][4][5] << endl;

    //改变形状，元素总数不变,  4* 5*6 =  2* 5 *12 ,原有值保存
    boost::array<int, 3> wd = {2, 5, 12};
    arr.reshape(wd);
    cout << arr[0][0][0] << endl;
}

aglo::~aglo()
{
}
