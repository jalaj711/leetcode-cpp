#include <string>
using namespace std;

class Solution
{
private:
    bool is_vowel(char c)
    {
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        };
    }

public:
    int maxVowels(string s, int k)
    {
        int max_count = 0, i = 0;
        for (i = 0; i < k && i < s.size(); i++)
        {
            max_count += is_vowel(s[i]);
        }
        int c_count = max_count;
        while (i < s.size())
        {
            max_count = max(max_count, c_count = (c_count - is_vowel(s[i - k]) + is_vowel(s[i])));
            i++;
        }
        return max_count;
    }
};

int main()
{
    Solution s;
    s.maxVowels("leetcode", 3);
}
