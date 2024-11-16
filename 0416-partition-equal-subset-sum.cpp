#include<vector>
using namespace std;

// Solution 1: Memoized Recursion
//class Solution {
//public:
//  bool recur(int idx, int t, vector<int> &nums, vector<vector<int>> &dp) {
//    if (t == 0) return true;
//    if (idx >= nums.size()) return false;
//    if (dp[idx][t-1] > -1) return dp[idx][t-1];
//
//    bool notpick = recur(idx+1, t, nums, dp);
//    bool pick = false;
//    if (nums[idx] <= t)
//      pick = recur(idx+1, t-nums[idx], nums, dp);
//    return dp[idx][t-1] = (pick || notpick);
//  }
//  bool canPartition(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    for (const auto &x: nums) sum += x;
//    if (sum % 2) return false;
//
//    vector<vector<int>> dp (n, vector<int> (sum/2, -1));
//
//    return recur(0, sum / 2, nums, dp);
//  }
//};

// Solution 2: Tabulation
//class Solution {
//public:
//  bool canPartition(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    for (const auto &x: nums) sum += x;
//    if (sum % 2) return false;
//
//    vector<vector<int>> dp (n+1, vector<int> (sum/2+1, 0));
//    for (int i=0;i<n;i++) dp[i][0] = true;
//
//    for(int idx=n-1;idx>=0;idx--) {
//      for(int t=sum/2;t>0;t--) {
//        bool notpick = dp[idx+1][t];
//        bool pick = false;
//        if (nums[idx] <= t)
//          pick = dp[idx+1][t-nums[idx]];
//        dp[idx][t] = (pick || notpick);
//      }
//    }
//
//    return dp[0][sum / 2];
//  }
//};

// Solution 3: Tabulation with O(n) space
//class Solution {
//public:
//  bool canPartition(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    for (const auto &x: nums) sum += x;
//    if (sum % 2) return false;
//
//    vector<int> prev(sum/2+1, 0);
//    vector<int> curr(sum/2+1, 0);
//    prev[0] = true;
//
//    for(int idx=n-1;idx>=0;idx--) {
//      curr[0] = true;
//      for(int t=sum/2;t>0;t--) {
//        bool notpick = prev[t];
//        bool pick = false;
//        if (nums[idx] <= t)
//          pick = prev[t-nums[idx]];
//        curr[t] = (pick || notpick);
//      }
//      prev = curr;
//    }
//
//    return prev[sum / 2];
//  }
//};

// Solution 4: optimised tabulation
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (const auto &x: nums) sum += x;
    if (sum % 2) return false;

    vector<bool> dp(sum/2+1, false);
    dp[0] = true;

    for(int idx=n-1;idx>=0;idx--) {
      for(int t=sum/2;t>0;t--) {
        if (nums[idx] <= t)
          dp[t] = dp[t] || dp[t-nums[idx]];
      }
    }

    return dp[sum / 2];
  }
};
