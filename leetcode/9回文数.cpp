class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        if (x >= 0 && x <= 10)
        {
            return true;
        }
        long long temp = 0;
        int xx = x;
        while (x != 0)
        {
            int n = x % 10;
            temp = temp * 10 + n;
            x /= 10;
        }
        if (temp == xx)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
/*
解题思路：数字反转后还是一样就是回文
*/