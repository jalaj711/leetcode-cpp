#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> stack;
        bool flag = false;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '{':
                stack.push_back('{');
                break;
            case '(':
                stack.push_back('(');
                break;
            case '[':
                stack.push_back('[');
                break;

            case '}':
                if (stack.size() >= 1 && stack[stack.size() - 1] == '{')
                {
                    stack.pop_back();
                }
                else
                {
                    flag = true;
                }
                break;

            case ')':
                if (stack.size() >= 1 && stack[stack.size() - 1] == '(')
                {
                    stack.pop_back();
                }
                else
                {
                    flag = true;
                }
                break;

            case ']':
                if (stack.size() >= 1 && stack[stack.size() - 1] == '[')
                {
                    stack.pop_back();
                }
                else
                {
                    flag = true;
                }
                break;
            }
            if (flag)
            {
                break;
            }
        }

        if (flag || stack.size() != 0)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    bool isValid = (new Solution())->isValid("[](){}");
}
