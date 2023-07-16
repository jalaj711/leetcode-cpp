#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        for (i = 0; i < n; i++)
        {
            for (j = i+1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        };
        return vector<int>{i, j};
    };
};
int main()
{
    vector<int> q{3, 2, 4};
    Solution s;
    s.twoSum(q, 6);
}
