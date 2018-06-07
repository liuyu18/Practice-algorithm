//
//  land.hpp
//  land
//
//  Created by Yu on 2018/6/2.
//  Copyright © 2018年 Yu. All rights reserved.
//

#ifndef land_hpp
#define land_hpp

#include <stdio.h>
#include <vector>

class IsLand{
public:
    void dfs(std::vector<std::vector<bool>> &grid, int x, int y);
    int numIslands(std::vector<std::vector<bool>>& grid);
};
#endif /* land_hpp */
