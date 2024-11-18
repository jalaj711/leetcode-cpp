#include<vector>
using namespace std;

class Solution {
public:
  bool check(vector<int> &diff, vector<int> &nums, int n){
    int z = 0;
    int d = 0;
    for (int i=0;i<n;i++) {
      d += diff[i];

      if (nums[i] - d <= 0) z++;
      if (z == n) break;
    }
    return z == n;
  }
  void genDiff(vector<int> &d, vector<int> &nd, vector<vector<int>> &q, int l, int r) {
    for (int i=l;i<=r;i++) {
      nd[q[i][0]] += q[i][2];
      if (q[i][1] < d.size()-1) nd[q[i][1]+1] -= q[i][2];
    }
    return;
  }
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int q = queries.size();
    bool all = true;
    for(const auto &x: nums) {
      all &= (x==0);
      if (!all) break;
    }
    if (all) return 0;
    vector<int> diff(n, 0);

    int l = 0;
    int r = q-1;
    int a = -2;
    int m;
    while(l <= r){
      m = l + (r-l)/2;

      vector<int> nd (diff.begin(), diff.end());
      genDiff(diff, nd, queries, l, m);

      if (check(nd, nums, n)) {
        a = m;
        r = m - 1;
      } else {
        l = m+1;
        diff = nd;
      }
    }

    return a+1;

  }
};