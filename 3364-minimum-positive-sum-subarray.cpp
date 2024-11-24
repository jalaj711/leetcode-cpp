#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
  int minimumSumSubarray(vector<int> &nums, int l, int r) {
    int maxSum = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int s = 0;
      int j = i;
      for (; j < i + l && j < n; j++) s += nums[j];
      if (s > 0 && j == i + l) maxSum = min(maxSum, s);
      if (j != i + l) continue;
      for (; j < i + r && j < n; j++) {
        s += nums[j];
        if (s > 0) maxSum = min(maxSum, s);
      }
    }

    return maxSum == INT_MAX ? -1 : maxSum;
  }
};