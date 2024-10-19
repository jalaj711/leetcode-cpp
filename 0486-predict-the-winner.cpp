#include<vector>
#include<climits>
#define UNDEF (INT_MIN)
#define ARR_END (INT_MIN+1)

using namespace std;

// recursive solution
//
//class Solution {
//public:
//  int recur(int l, int r, bool first, vector<int> &nums) {
//    if (r < l) return INT_MIN;
//
//    int sl = recur(l+1, r, !first, nums);
//    if (sl == INT_MIN) {
//      sl = (nums[l] * (first ? 1 : -1));
//    } else sl += (nums[l] * (first ? 1 : -1));
//    int sr = recur(l, r-1, !first, nums);
//    if (sr == INT_MIN) {
//      sr = (nums[r] * (first ? 1 : -1));
//    } else sr += (nums[r] * (first ? 1 : -1));
//
//    return first ? max(sl, sr) : min(sl, sr);
//  }
//  bool predictTheWinner(vector<int>& nums) {
//    return recur(0, nums.size()-1, true, nums) >= 0;
//  }
//};

// recursion with memoisation
//
//#define UNDEF (INT_MIN)
//#define ARR_END (INT_MIN+1)
//
//class Solution {
//public:
//  int recur(int l, int r, bool first, vector<int> &nums, vector<vector<vector<int>>> &dp) {
//    if (r < l) return ARR_END;
//
//    if (dp[l][r][first] > UNDEF) return dp[l][r][first];
//
//    // pick left most
//    int sl = recur(l+1, r, !first, nums, dp);
//    if (sl == ARR_END) sl = (nums[l] * (first ? 1 : -1));
//    else sl += (nums[l] * (first ? 1 : -1));
//
//    // pick right most
//    int sr = recur(l, r-1, !first, nums, dp);
//    if (sr == ARR_END) {
//      sr = (nums[r] * (first ? 1 : -1));
//    } else sr += (nums[r] * (first ? 1 : -1));
//
//    // since both players play optimally, player 1 tries
//    // to maximise the score while player 2 tries to
//    // minimise it
//    return dp[l][r][first] = first ? max(sl, sr) : min(sl, sr);
//  }
//  bool predictTheWinner(vector<int>& nums) {
//    int n = nums.size();
//    vector<vector<vector<int>>> dp (n, vector<vector<int>>(n, vector<int>(2, UNDEF)));
//    return recur(0, nums.size()-1, true, nums, dp) >= 0;
//  }
//};

// tabulation solution
//#define UNDEF (INT_MIN)
//#define ARR_END (INT_MIN+1)
//
//class Solution {
//public:
//  bool predictTheWinner(vector<int>& nums) {
//    int n = nums.size();
//    vector<vector<vector<int>>> dp (n, vector<vector<int>>(n, vector<int>(2, ARR_END)));
//
//    for (int l=n-1;l>=0;l--) {
//      for (int r=0;r<n;r++) {
//        if (r < l) {
//          dp[l][r][0] = ARR_END;
//          dp[l][r][1] = ARR_END;
//          continue;
//        }
//        for (int first=0;first<2;first++) {
//
//          // pick left most
//          int sl = l < n-1 ? dp[l+1][r][!first] : ARR_END;
//          if (sl == ARR_END) sl = (nums[l] * (first ? 1 : -1));
//          else sl += (nums[l] * (first ? 1 : -1));
//
//          // pick right most
//          int sr = r > 0 ? dp[l][r-1][!first] : ARR_END;
//          if (sr == ARR_END) {
//            sr = (nums[r] * (first ? 1 : -1));
//          } else sr += (nums[r] * (first ? 1 : -1));
//
//          // since both players play optimally, player 1 tries
//          // to maximise the score while player 2 tries to
//          // minimise it
//          dp[l][r][first] = first ? max(sl, sr) : min(sl, sr);
//        }
//      }
//    }
//
//    return dp[0][nums.size()-1][1] >= 0;
//  }
//};

// space optimised tabulation
class Solution {
public:
  bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> prev (n, vector<int>(2, ARR_END));
    vector<vector<int>> curr (n, vector<int>(2, ARR_END));

    prev[n-1][0] = -nums[n-1];
    prev[n-1][1] = nums[n-1];

    for (int l=n-2;l>=0;l--) {
      for (int r=0;r<n;r++) {
        if (r < l) {
          curr[r][0] = ARR_END;
          curr[r][1] = ARR_END;
          continue;
        }
        for (int first=0;first<2;first++) {

          // pick left most
          int sl = l < n-1 ? prev[r][!first] : ARR_END;
          if (sl == ARR_END) sl = (nums[l] * (first ? 1 : -1));
          else sl += (nums[l] * (first ? 1 : -1));

          // pick right most
          int sr = r > 0 ? curr[r-1][!first] : ARR_END;
          if (sr == ARR_END) {
            sr = (nums[r] * (first ? 1 : -1));
          } else sr += (nums[r] * (first ? 1 : -1));

          // since both players play optimally, player 1 tries
          // to maximise the score while player 2 tries to
          // minimise it
          curr[r][first] = first ? max(sl, sr) : min(sl, sr);
        }
      }
      prev = curr;
    }

    return prev[nums.size()-1][1] >= 0;
  }
};