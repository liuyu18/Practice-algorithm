//
//  land.cpp
//  land
//
//  Created by Yu on 2018/6/2.
//  Copyright © 2018年 Yu. All rights reserved.
//

#include "land.hpp"
#include <vector>
#include <iostream>

using namespace std;
void IsLand::dfs(vector<vector<bool>> &grid, int x, int y){
//    cout<<"grid.size() : "<<grid.size()<<" x : "<<x<<endl;
//    cout<<"grid[0].size() : "<<grid[0].size()<<" Y : "<<y<<endl;
    if (x < 0 || x >= grid.size()){
//        cout<<"x 的判断 "<<endl;
        return;
    }
    if (y < 0 || y >= grid[0].size()) {
//        cout<<"Y 的判断 "<<endl;
        return;
    }
    if (!grid[x][y]){
//        cout<<"值是 : "<<grid[x][y]<<endl;
//        cout << "x : "<<x<<  " y :"<<y<<"返回"<< endl;
        return;
    }


    grid[x][y] = false;
    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
}
int IsLand::numIslands(vector<vector<bool>> &grid){
    if (grid.empty() || grid[0].empty()) return 0;
    int N = grid.size(), M = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j]) {
                dfs(grid, i, j);
                ++cnt;
            }
        }
    }
    return cnt;
}
