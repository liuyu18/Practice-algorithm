#include "Solution.h"
#include <iostream>


Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int Solution::FirstNotRepeatingChar(string str){
    if(str.size() <= 0)
        return -1;

    int tableSize = 256;
    vector<int> numberofChar(tableSize,0);

    for(int i = 0; i < str.size(); i++)
    {
        ++numberofChar[str[i]];
        //遍历的str 的详细
        cout<<"str[i] :"<<str[i]<<endl;
        cout<<"i :"<<i<<endl;
    }
    //vector 的大小
    cout<<"numberofChar :"<<numberofChar.size()<<endl;

    for(vector<int>::iterator iter = numberofChar.begin(); iter != numberofChar.end(); iter++)
    {
        cout<<"查看数组之中有什么 :"<<*iter<<endl;
    }
    //输入的字符串的长度
    cout<<"str.size() :"<<str.size()<<endl;
    for(int i = 0; i < str.size(); i++)
    {
        cout<<"I :"<<i<<endl;
        cout<<"numberofChar[str[i]] :"<<numberofChar[str[i]]<<endl;
        cout<<"str[i] :"<<str[i]<<endl;
        if(numberofChar[str[i]] == 1 && str[i] != '\0'){
            return i;
        }
    }
    return -1;
}