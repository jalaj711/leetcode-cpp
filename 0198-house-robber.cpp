#include<vector>

using namespace std;
/* Solution 1
class Solution {
public:
    int recur(vector<int> &nums, int idx, vector<int> &dp) {
        if (idx >= nums.size()) return 0;
        if (dp[idx] > -1) return dp[idx];
        if (idx == nums.size() - 1) {
            return dp[idx] = nums[idx];
        }
        int pick = nums[idx] + recur(nums, idx+2, dp);
        int not_pick = recur(nums, idx+1, dp);
        return dp[idx] = max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recur(nums, 0, dp);
    }
};
*/

// Solution 2: Optimised
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return nums[0];
        int plus_two = nums[n - 1];
        int plus_one = max(nums[n - 2], nums[n - 1]);
        int ans = plus_one;
        for (int i = n - 3; i >= 0; i--) {
            ans = max(nums[i] + plus_two, plus_one);
            plus_two = plus_one;
            plus_one = ans;
        }
        return ans;
    }
};