#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i=0;i<n;i++) {
      int l = i,
          r = n-1,
          a = -1,
          x = nums[i] + 2*k,
          m;

      while(l <= r) {
        m = l + (r-l)/2;
        if (nums[m] <= x) {
          l = m+1;
          a = m;
        } else r = m-1;
      }
      ans = max(ans, a-i+1);
    }

    return ans;
  }
};