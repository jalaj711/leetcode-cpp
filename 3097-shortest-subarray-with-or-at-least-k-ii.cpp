#include<vector>

using namespace std;

class Solution {
public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> cnt(32, 0);

    int maxL= 10000007;
    int l = 0;
    int r = 0;
    int r_or = nums[0]; // running or
    for (int i=31;i>=0;i--) cnt[i] += ((nums[l] >> i)&1); // insert nums[0] into cnt

    while(l < n && r < n && l <= r) {
      if (r_or >= k) {
        maxL = min(r-l+1, maxL);

        // remove nums[l] from cnt and r_or
        for (int i=31;i>=0;i--) {
          cnt[i] -= ((nums[l] >> i)&1);
          if (cnt[i] == 0) r_or &= ~(1 << i);
        }
        l++;
      } else if(++r < n) {
        // insert nums[r] into cnt and r_or
        for (int i=31;i>=0;i--) {
          cnt[i] += ((nums[r] >> i)&1);
          if (cnt[i] > 0) r_or |= (1 << i);
        }
      }
    }
    return maxL == 10000007 ? -1 : maxL;
  }
};