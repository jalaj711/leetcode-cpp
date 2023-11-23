#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int m = l.size();
        int n = nums.size();

        vector<bool> ans(m, true);
        int size, diff;
        while (--m >= 0)
        {
            vector<int> sub(nums.begin() + l[m], nums.begin() + r[m] + 1);
            sort(sub.begin(), sub.end());
            size = r[m] - l[m];
            diff = sub[1] - sub[0];
            while (size > 1)
            {
                if (sub[size] - sub[size - 1] != diff)
                {
                    ans[m] = false;
                    break;
                }
                size--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> q{4, 6, 5, 9, 3, 7}, l{0, 0, 2}, r{0, 3, 5};
    s.checkArithmeticSubarrays(q, l, r);
}