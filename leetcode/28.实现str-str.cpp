using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        if (needle.size() > haystack.size())
        {
            return -1;
        }
        int i, j;
        i = 0;
        j = 0;
        for (i = 0; i < hacystack.size(); i++)
        {
            if (j == needle.size())
            {
                return i - needle.size();
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            else
            {
                i -= j;
                j = 0;
            }
        }
        if (j == needle.szie())
        {
            return i - needle.size();
        }
        return -1;
    }
}