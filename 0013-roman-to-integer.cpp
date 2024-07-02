#include <string>
using namespace std;
int romanEquivalent(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        int n = 0;
        while (n < s.length())
        {
            int num = romanEquivalent(s[n]);
            if (n < s.length() - 1)
            {
                int next_num = romanEquivalent(s[n + 1]);
                if (next_num > num)
                {
                    num = next_num - num;
                    n++;
                }
            }
            ans += num;
            n++;
        }
        return ans;
    }
};