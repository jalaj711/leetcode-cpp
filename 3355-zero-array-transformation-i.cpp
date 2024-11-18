#include<vector>
using namespace std;

class Solution {
public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> diff(n, 0);
    for (const auto &q: queries) {
      diff[q[0]]++;
      if (q[1] < n-1) diff[q[1]+1]--;
    }
    int zeroes = 0;
    int currDiff = 0;
    for (int i=0;i<n;i++) {
      currDiff += diff[i];
      if (nums[i]-currDiff <= 0) zeroes++;
    }
    return zeroes==n;
  }
};