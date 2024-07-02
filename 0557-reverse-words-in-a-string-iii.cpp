#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = s.length() - 1, end = 0;
        int j, k;
        char ch;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                j = start;
                while (j != (end + start) / 2)
                {
                    k = end - (j - start);
                    ch = s[j];
                    s[j] = s[k];
                    s[k] = ch;
                    j--;
                }
                start = i - 1;
            }
            else
            {
                end = i;
                if (i == 0)
                {
                    j = start;
                    while (j != (end + start) / 2)
                    {
                        k = end - (j - start);
                        ch = s[j];
                        s[j] = s[k];
                        s[k] = ch;
                        j--;
                    }
                }
            }
        }
        return s;
    }
};

int main()
{
    string s = "testing this program";
    string ans = (new Solution())->reverseWords(s);
    return 0;
}