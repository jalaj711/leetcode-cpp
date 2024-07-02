#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<string> ans;
    void genStrings(int openCount, int closeCount, string curr, int n)
    {
        // cout << openCount << " " << closeCount << " " << curr << n << endl;
        if (openCount == closeCount && openCount + closeCount == 2*n)
        {
            ans.push_back(curr);
            return;
        }


        if (openCount < n)
        {
            genStrings(openCount+1, closeCount, curr + "(", n);
        }

        if (closeCount < openCount)
        {
            genStrings(openCount, closeCount + 1, curr + ")", n);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        genStrings(0, 0, "", n);
        return ans;
    }
};

void print(vector<string> &arr)
{
    for (string s : arr)
    {
        cout << s << endl;
    }
}

int main()
{
    Solution s;
    vector<string> ans1 = s.generateParenthesis(3);
    print(ans1);
}
