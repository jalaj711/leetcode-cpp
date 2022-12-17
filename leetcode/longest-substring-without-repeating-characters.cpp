#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<char> reps;
        int max = 0;
        for (int i = 0; i < s.length(); i++)
        {
            reps.clear();
            for (int j = i; j < s.length(); j++)
            {
                if (find(reps.begin(), reps.end(), s[j]) != reps.end())
                {
                    break;
                }
                else
                {
                    reps.push_back(s[j]);
                }
            }
            if (reps.size() > max)
            {
                max = reps.size();
            }
        }
        return max;
    }
};

int main()
{
}