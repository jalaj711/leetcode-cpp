#include<vector>
using namespace std;

/**
 * Recursive solution
 *
 *    class Solution {
 *      int dp(int idx, bool pn, vector<int> &nums) {
 *          if (idx == nums.size()-1) {
 *              return 1;
 *          }
 *          bool cn = nums[idx+1]<nums[idx];
 *          if (cn^pn && nums[idx+1] != nums[idx]) return 1+dp(idx+1, cn, nums);
 *          return dp(idx+1, pn, nums);
 *      }
 *  public:
 *      int wiggleMaxLength(vector<int>& nums) {
 *          int n = nums.size();
 *         return max(dp(0, false, nums), dp(0, true, nums));
 *      }
 *  };
 *
 */

/**
 * Memoized solution
 *
 * class Solution {
 *   public:
 *       int wiggleMaxLength(vector<int>& nums) {
 *           int n = nums.size();
 *           vector<vector<int>> dp(n, vector<int> (2, -1));
 *           dp[n-1][0] = 1;
 *           dp[n-1][1] = 1;
 *
 *           for (int idx=n-2;idx >= 0;idx--) {
 *               bool cn = nums[idx+1]<nums[idx];
 *               for (int pn=1;pn>=0;pn--) {
 *                   if (cn^pn && nums[idx+1] != nums[idx]) dp[idx][pn] = 1+dp[idx+1][cn];
 *                   else dp[idx][pn] = dp[idx+1][pn];
 *               }
 *           }
 *
 *           return max(dp[0][false], dp[0][true]);
 *       }
 *   };
 */

/**
 * Space optimised memoization
 */
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int> prev {1, 1};
    vector<int> curr {0, 0};
    bool a, b;

    for (int idx=n-2;idx >= 0;idx--) {
      a = nums[idx+1]<nums[idx];
      b = nums[idx+1] != nums[idx];

      if (!a && b) curr[1] = 1+prev[a];
      else curr[1] = prev[1];

      if (a && b) curr[0] = 1+prev[a];
      else curr[0] = prev[0];

      prev = curr;
    }

    return max(prev[0], prev[1]);
  }
};