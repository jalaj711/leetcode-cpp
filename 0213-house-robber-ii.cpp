#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int _rob(vector<int> &nums, int start, int end) {
        int plus_two = nums[end - 1];
        int plus_one = max(nums[end - 2], nums[end - 1]);
        int ans = plus_one;
        for (int i = end - 3; i >= start; i--) {
            ans = max(nums[i] + plus_two, plus_one);
            plus_two = plus_one;
            plus_one = ans;
        }
        return ans;
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        return max(_rob(nums, 0, n - 1), _rob(nums, 1, n));
    }
};