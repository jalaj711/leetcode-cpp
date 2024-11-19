#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    long long maxS = 0;
    long long curS = 0;
    int cnt = 0;

    unordered_map<int, int> freq;

    for (int i=0;i<k;i++) {
      if (++freq[nums[i]] == 1) cnt++;
      curS += nums[i];
    }
    if (cnt == k) maxS = curS;

    for (int i=0;i<n-k;i++) {
      if (++freq[nums[i+k]] == 1) cnt++;
      if (--freq[nums[i]] == 0) cnt--;

      curS += nums[i+k] - nums[i];
      if (cnt == k) maxS = max(maxS, curS);
    }
    return maxS;
  }
};