#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int index = 0;
        if (strs.empty())
        {
            return "";
        }

        for (int i = 0; i < strs[0].length(); i++)
        {
            char current = strs[0][index];
            for (string str : strs)
            {
                if (str.length() == i || current != str[index])
                {
                    return str.substr(0, index);
                }
            }
            index++;
        }

        return strs[0] substr(0, index);
    }
}