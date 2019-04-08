#include "GetLeastNumbers.h"
#include <vector>
#include <set>
#include <iostream>

using namespace std;

GetLeastNumbers::GetLeastNumbers(/* args */)
{
}

GetLeastNumbers::~GetLeastNumbers()
{
}

vector<int> GetLeastNumbers::GetLeastNumbers_Solution(vector<int> input, int k){
        if(input.size()<k || k<0)
            return vector<int> ();

        multiset<int, greater<int>> leastNumbers;
        vector<int>::const_iterator iter=input.begin();
        for(; iter!=input.end(); iter++)
        {
            if(leastNumbers.size() < k)
                leastNumbers.insert(*iter);
            else
            {
                multiset<int, greater<int>>::iterator iterGreatest=leastNumbers.begin();
                if(*iter < *iterGreatest)
                {
                    leastNumbers.erase(*iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }
        }
        return vector<int>(leastNumbers.begin(), leastNumbers.end());
}
