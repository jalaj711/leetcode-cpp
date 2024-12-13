#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
public:
  long long findScore(vector<int>& nums) {
    long long score = 0;

    int n = nums.size();
    char marked[n];
    int idx[n];
    memset(marked, 0, n);

    for(int i=0;i<n;i++) idx[i] = i;
    sort(idx, idx+n, [&](int a, int b) {
      if (nums[a] == nums[b]) return a < b;
      return nums[a] < nums[b];
    });

    for(int i=0;i<n;i++) {
      if (marked[idx[i]]) continue;

      score += nums[idx[i]];
      marked[idx[i]] = 1;
      if (idx[i] > 0) marked[idx[i]-1] = 1;
      if (idx[i] < n-1) marked[idx[i]+1] = 1;
    }

    return score;
  }
};