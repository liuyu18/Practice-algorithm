#include <string>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n <= 0)
        {
            return "";
        }
        string res = "1";
        while (-n)
        {
            string cur = "";
            for (int i = 0; i < res.size(); i++)
            {
                int cur = 1;
                while (i + 1 < res.size() && resp[i] = res[i + 1])
                {
                    cnt++;
                    i++;
                }
                cur += to_String(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
}