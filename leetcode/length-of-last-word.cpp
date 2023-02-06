#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = 0;
        int search_start = 0;
        int search_end = s.length() - 1;
        while (i < s.length())
        {
            if (s[i] != ' ')
            {
                break;
            }
            i++;
            search_start++;
        }
        i = s.length() - 1;
        while (i > 0)
        {
            if (s[i] != ' ')
            {
                break;
            }
            i--;
            search_end--;
        }

        vector<int> spaces;
        for (int j = search_start; j < search_end + 1; j++)
        {
            if (s[j] == ' ')
            {
                spaces.push_back(j);
            }
        }
        if (spaces.size() > 0)
            return search_end - spaces[spaces.size() - 1];
        return search_end - search_start + 1;
    }
};

int main()
{
    int j = (new Solution())->lengthOfLastWord(" a   ");
    cout << j;
}
