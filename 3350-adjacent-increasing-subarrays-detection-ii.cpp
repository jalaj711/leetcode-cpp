#include<vector>

using namespace std;

class Solution {
public:
  int maxIncreasingSubarrays(vector<int>& nums) {
    int n = nums.size();
    int maxK = 1;
    // stores the size of increasing subarray starting from position i
    vector<int> pre(nums.size(), 1);
    for(int i=n-2;i>=0;i--) {
      if (nums[i] < nums[i+1]) pre[i] = pre[i+1]+1;
    }

    for(int i=0;i<n;i++) {
      int k = 1;
      if (i+pre[i]<n && pre[i+pre[i]] >= pre[i]) k = pre[i];
      k = max(k, pre[i]/2);
      maxK = max(maxK, k);
    }

    return maxK;
  }
};