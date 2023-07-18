#include <string>
#include <deque>
#include <iostream>
using namespace std;

class Solution
{
public:
    int end_of_parenthesis(string s)
    {
        int cnt = 1;
        int i = 1;
        while (cnt != 0 && i < s.length())
        {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')')
                cnt--;
            i++;
        }
        return --i;
    }
    int calculate(string s)
    {
        if (s.length() < 2)
            return stoi(s);

        int ans = 0;
        char opr = '+';

        int i = 0, j;
        while (i < s.length())
        {

            while (s[i] == ' ')
                i++;
            if (s.length() > i)
            {
                if (s[i] == '(')
                {
                    j = end_of_parenthesis(s.substr(i));
                    ans += (opr == '+' ? 1 : -1) * calculate(s.substr(++i, j - 1));
                    i += j;
                }
                else if (s[i] == '+' || s[i] == '-') { opr = s[i]; i++; }
                else
                {
                    j = s[i] - '0';
                    while (i+1 < s.length() && s[i+1] >= '0' && s[i+1] <= '9') {
                        j = j*10 + (s[i+1] - '0');
                        i++;
                    }
                    ans += (opr == '+' ? 1 : -1) * j;
                    i++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    // string s = " 2-1+2 ";
    Solution st;
    st.calculate(s);
    // cout << st.end_of_parenthesis(s);// << s.substr(0, 16);
}
