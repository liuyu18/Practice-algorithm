#include "Permutation.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PermutationCore(vector<string> &result, string str, int begin){
    if(begin == str.size()-1){
        result.push_back(str);
    }else{
        for(int i=begin; i<str.size(); i++){
            if(i!=begin && str[i]==str[begin])
                continue;
            cout<<"-----------str1:-----------"<<str<<endl;
            cout<<"str[i] :"<<str[i]<<",i :"<<i<<endl;
            cout<<"str[begin] :"<<str[begin]<<",begin:"<<begin<<endl;

            swap(str[i], str[begin]);
            cout<<"-----------str2:-----------"<<str<<endl;
            PermutationCore(result, str, begin+1);
            swap(str[i], str[begin]);
            cout<<"-----------str3:-----------"<<str<<endl;
        }
    }
}

vector<string> Permutation::PermutationString(string str){
    vector<string> result;
    if(str.size()<=0){
        return result;
    }
    PermutationCore(result, str, 0);
    // for(vector<string>::iterator iter = result.begin(); iter != result.end(); iter++)
    // {
    //     cout<<"result1 :"<<*iter<<endl;
    // }
    // cout<<"----------------------"<<endl;
    sort(result.begin(), result.end());
    //     for(vector<string>::iterator iter = result.begin(); iter != result.end(); iter++)
    // {
    //     cout<<"result2 :"<<*iter<<endl;
    // }
    // cout<<"----------------------"<<endl;
    return result;
}

