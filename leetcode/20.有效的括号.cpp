#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> tempStack;
        for (char &c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                tempStack.push(c);
                break;
            case ')':
                if (tempStack.empty() || tempStack.top() != '(')
                    return false;
                else
                    tempStack.pop();
                break;
            case '}':
                if (tempStack.empty() || tempStack.top() != '{')
                    return false;
                else
                    tempStack.pop();
                break;
            case ']':
                if (tempStack.empty() || tempStack.top() != '[')
                    return false;
                else
                    tempStack.pop();
                break;
            }
        }
        return tempStack.empty();
    }
}