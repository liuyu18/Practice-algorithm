//
//  AppleMinBags.cpp
//  zuo
//
//  Created by Yu on 2019/5/20.
//  Copyright © 2019 Yu. All rights reserved.
//

#include "AppleMinBags.hpp"
#include <math.h>
#include <iostream>
#include <limits.h>

using namespace std;

int AppleMinBag::minBags(int apple){
    if (apple < 0) {
        return 0;
    }
    int bag6 = -1;
    int bag8 = apple / 8;
    int rest = apple - 8 * bag8;
    //24 6 8 最小的公约数
    while (bag8 >= 0 && rest < 24) {
        int restUse6 = minBagBase6(rest);
        if(restUse6 != -1){
            bag6 = restUse6;
            break;
        }
        rest = apple - 8 * (--bag8);
    }
    return bag6 == -1 ? -1 : bag6 + bag8;
}

int AppleMinBag::minBagBase6(int rest){
    return rest % 6 == 0 ? (rest / 6) : -1;
}

int AppleMinBag::minBagAwesome(int apple){
    if ((apple & 1) != 0) {
        return -1;
    }
    if (apple < 18) {
        return apple == 0 ? 0 : (apple == 6 || apple == 8) ? 1
        : (apple == 12 || apple == 14 || apple == 16) ? 2 : -1;
    }
    return (apple - 18) / 8 + 3;
}

void AppleMinBag::Log(){
    int max = INT_MAX;
    int testTime = 100000000;
    for (int test = 0; test < testTime; test++) {
        int apple = (int) (10 * max);
        if (minBags(apple) != minBagAwesome(apple)) {
            cout<<"error"<<endl;
        }
    }
}

