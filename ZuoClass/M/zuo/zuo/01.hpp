//
//  01.hpp
//  zuo
//
//  Created by Yu on 2019/5/20.
//  Copyright © 2019 Yu. All rights reserved.
//

#ifndef _1_hpp
#define _1_hpp

#include <stdio.h>
#include <vector>

class longestCover {
    
    
public:
    int longest();
private:
    int maxPoint(std::vector<int>&nums, int L);
    int nearestIndex(std::vector<int>&nums, int end, int value);
};


#endif /* _1_hpp */
