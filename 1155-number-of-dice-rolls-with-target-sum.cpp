#include<vector>
using namespace std;
// solution with recursion (easy TLE)
//class Solution {
//public:
//  int inf = 1e9+7;
//  int rec(int i, int n, int k, int target) {
//    if (i >= n || target <= 0) return 0;
//    if (i == n-1) return target <= k;
//
//    int ans = 0;
//    for (int j=1;j<=k;j++) {
//      ans = (ans+rec(i+1, n, k, target-j))%inf;
//    }
//    return ans%inf;
//  }
//  int numRollsToTarget(int n, int k, int target) {
//    return rec(0, n, k, target);
//  }
//};

// solution with recursion + memoisation
class Solution {
public:
  int inf = 1e9+7;
  int rec(int i, int n, int k, int target, vector<vector<int>> &dp) {
    if (i >= n || target <= 0) return 0;
    if (i == n-1) return target <= k;
    if (dp[i][target-1] > -1) return dp[i][target-1];

    int ans = 0;
    for (int j=1;j<=k;j++) {
      ans = (ans+rec(i+1, n, k, target-j, dp))%inf;
    }
    return dp[i][target-1] = ans%inf;
  }
  int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp (n, vector<int> (target, -1));
    return rec(0, n, k, target, dp);
  }
};