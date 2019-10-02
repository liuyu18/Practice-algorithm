#include <vector>
#include <map>

using namespace std;
/*

解题的思路：
一个map存放着kv结构里面的第一个数的位置和值，再循环一次去做一个相减得到第二个数
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (m.count(temp) && m[temp] != i)
            {
                res.push_back(i);
                res.push_back(m[temp]);
                break;
            }
        }
        return res;
    }
};
