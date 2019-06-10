//
//  01.cpp
//  zuo
//
//  Created by Yu on 2019/5/20.
//  Copyright © 2019 Yu. All rights reserved.
//

#include "01.hpp"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//查找[0,end]中第一个值大于等于value的索引位置index
int longestCover::nearestIndex(vector<int>&nums, int end, int value){
    
    if(value<0) return 0;
    //计算起点与数组终点的距离
    int begin=0;
    int mid=0, index=end;
    
    while(begin<end){
        //>>1  除以2，这种求中值的方法可以防止溢出
        mid=begin+((end-begin)>>1);
        if(nums[mid]>=value){
            //记录当前值大于等于value的点的索引位置index
            index=mid;
            end=mid-1;
        }else{
            begin=mid+1;
        }
    }
    return index;
}

int longestCover::maxPoint(vector<int>&nums, int L){
    if(L<=0 || nums.size()<1) return 0;
    
    int res=1, nearest=0;
    for(int i=0; i<nums.size(); i++){
        nearest=nearestIndex(nums, i, nums[i]-L);
        res=max(res, i-nearest+1);
    }
    return res;
}

int longestCover::longest(){
    std::vector<int>line={0, 13, 24, 35, 46, 57, 60, 72, 87 };
    int L = 6;
    std::cout<< maxPoint(line, L) << std::endl;
    
    return 0;
}

