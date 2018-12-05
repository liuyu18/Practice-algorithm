//
//  main.cpp
//  land
//
//  Created by Yu on 2018/6/2.
//  Copyright © 2018年 Yu. All rights reserved.
//

#include <iostream>
#include "land.hpp"
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    IsLand land = IsLand();
    
    vector<vector<bool>> arr = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    
    int num = land.numIslands(arr);
    cout<<"num : "<<num<<endl;
    
    return 0;
}
