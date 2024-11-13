#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long ans = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i=n-2;i>=0;i--) {
      int  uid = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin();
      int  lid = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
      ans += uid-lid;
    }
    return ans;
  }
};