#include<vector>

using namespace std;

// Solution 1: Naive recursion
//class Solution {
//public:
//  int recur(int i, int t, vector<int> &nums) {
//    if (i >= nums.size()) return 0;
//    if (i == nums.size()-1)
//      return (nums[i] == t) + (-nums[i] == t);
//
//    int pl = recur(i+1, t-nums[i], nums);
//    int ng = recur(i+1, t+nums[i], nums);
//
//    return pl+ng;
//  }
//  int findTargetSumWays(vector<int>& nums, int target) {
//    return recur(0, target, nums);
//  }
//};

// Solution 2: Previous Recursion with memoization
//class Solution {
//public:
//  int recur(int i, int t, vector<int> &nums, vector<unordered_map<int, int>> &dp) {
//    if (i >= nums.size()) return 0;
//    if (i == nums.size()-1)
//      return (nums[i] == t) + (-nums[i] == t);
//    if (dp[i].find(t) != dp[i].end()) return dp[i][t];
//
//    int pl = recur(i+1, t-nums[i], nums, dp);
//    int ng = recur(i+1, t+nums[i], nums, dp);
//
//    return dp[i][t] = pl+ng;
//  }
//  int findTargetSumWays(vector<int>& nums, int target) {
//    int n = nums.size();
//    vector<unordered_map<int, int>> dp(n);
//    return recur(0, target, nums, dp);
//  }
//};

// Solution 3: New approach: convert problem to pick positives. Recursion.
//class Solution {
//public:
//  int recur(int i, int t, vector<int> &nums) {
//    if (i >= nums.size())
//      return t==0;
//
//    int pick = 0;
//    if (nums[i] <= t)
//      pick = recur(i+1, t-nums[i], nums);
//
//    int notpick = recur(i+1, t, nums);
//    return pick+notpick;
//  }
//  int findTargetSumWays(vector<int>& nums, int target) {
//    int s = 0;
//    for (const int &n: nums) s += n;
//    if (target > s || (s+target)%2) return 0;
//    target = (s+target)/2;
//    return recur(0, target, nums);
//  }
//};

// Solution 4: Previous recursion with memoization
//class Solution {
//public:
//  int recur(int i, int t, vector<int> &nums, vector<vector<int>> &dp) {
//    if (i >= nums.size())
//      return t==0;
//    if (dp[i][t] > -1) return dp[i][t];
//
//    int pick = 0;
//    if (nums[i] <= t)
//      pick = recur(i+1, t-nums[i], nums, dp);
//
//    int notpick = recur(i+1, t, nums, dp);
//
//    return dp[i][t] = pick+notpick;
//  }
//  int findTargetSumWays(vector<int>& nums, int target) {
//    int n = nums.size();
//    int s = 0;
//    for (const int &n: nums) s += n;
//    if (target > s || (s+target)%2 || (target < 0 && s < -target)) return 0;
//
//    target = (s+target)/2;
//    vector<vector<int>> dp (n+1, vector<int>(target+1, -1));
//    return recur(0, target, nums, dp);
//  }
//};

// Solution 5: Previous recursion converted to tabulation
//class Solution {
//public:
//  int findTargetSumWays(vector<int>& nums, int target) {
//    int n = nums.size();
//    int s = 0;
//    for (const int &z: nums) s += z;
//    if (target > s || (s+target)%2 || (target < 0 && s < -target)) return 0;
//
//    target = (s+target)/2;
//    vector<vector<int>> dp (n+1, vector<int>(target+1, 0));
//    dp[n][0] = 1;
//
//    for (int i=n-1;i>=0;i--) {
//      for (int t=target;t>=0;t--) {
//        int pick = 0;
//        if (nums[i] <= t)
//          pick = dp[i+1][t-nums[i]];
//
//        int notpick = dp[i+1][t];
//        dp[i][t] = pick+notpick;
//      }
//    }
//    return dp[0][target];
//  }
//};

// Solution 6: Space optimised tabulation
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int s = 0;
    for (const int &z: nums) s += z;
    if (
        target > s ||         // Even if all numbers are taken positive, target can't be formed
        (s + target) % 2 ||   // This must be even for a valid solution to exist, explanation below
        (
            target < 0 &&     // If target is negative & sum is less than abs(target) then
            s < -target       // even if all numbers are taken negative, target cant be formed
        )
        )
      return 0;

    // Suppose,
    // P represents the sum of all numbers whose sign is +
    // N represents the sum of all numbers whose sign is -
    // T is the target provided by problem
    // S is the sum of all "nums"
    // Then,
    // According to the problem, P - N = T
    // And obviously, P + N = S
    // Solving for P,
    // P = (S+T)/2
    // This reduces the problem to a simpler version, which is to
    // pick some elements from nums whose sum is P. P becomes the
    // modified target.
    //
    // Also, as nums is made of whole numbers only, then P must be a whole
    // number. So, (S+T) must be an even number for a solution to exist.
    target = (s + target) / 2;

    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);
    prev[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
      for (int t = target; t >= 0; t--) {
        int pick = 0;
        if (nums[i] <= t)
          pick = prev[t - nums[i]];

        int notpick = prev[t];
        curr[t] = pick + notpick;
      }
      prev = curr;
    }
    return prev[target];
  }
};

// Solution 7: Even more space optimised tabulation
// this one is not that easy to understand by just
// looking at the code. Same as previous one except that
// prev is omitted because we only ever needed prev for
// t-nums[i], which means if we fill curr from right to
// left, no values are overwritten. So only curr is used.

//class Solution {
//public:
//  int findTargetSumWays(vector<int>& nums, int target) {
//    int n = nums.size();
//    int s = 0;
//    for (const int &n: nums) s += n;
//    if (target > s || (s+target)%2 || (target < 0 && s < -target)) return 0;
//
//    target = (s+target)/2;
//
//    vector<int> curr(target+1, 0);
//    curr[0] = 1;
//
//    for (int i=n-1;i>=0;i--) {
//      for (int t=target;t>=0;t--) {
//        int pick = 0;
//        if (nums[i] <= t)
//          pick = curr[t-nums[i]];
//
//        curr[t] += pick;
//      }
//    }
//    return curr[target];
//  }
//};
