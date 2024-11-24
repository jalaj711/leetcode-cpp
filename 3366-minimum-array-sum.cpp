#include<vector>
using namespace std;

class Solution {
public:
  int minArraySum(vector<int>& nums, int k, int op1, int op2) {
    int n = nums.size();
    vector<vector<int>> prev(op1+1, vector<int> (op2+1, 0));
    vector<vector<int>> curr(op1+1, vector<int> (op2+1, 0));

    for(int idx=n-1;idx>=0;idx--) {
      for (int o1 = 0;o1 <= op1;o1++) {
        for (int o2 = 0;o2 <= op2;o2++) {
          int nothing = nums[idx] + prev[o1][o2];
          int x1 = 2e9;
          if (o1 > 0)
            x1 = (nums[idx]+1)/2 + prev[o1-1][o2];
          int x2 = 2e9;
          if (o2 > 0 && nums[idx] >= k)
            x2 = nums[idx] - k + prev[o1][o2-1];

          int both = 2e9;
          if (o1 > 0 && o2 > 0 && nums[idx] >= k) {
            both = prev[o1-1][o2-1];
            int x1x2 = (nums[idx]+1)/2;
            if (x1x2 >= k) x1x2 -= k;
            else x1x2 = 2e9;

            int x2x1 = (nums[idx]-k+1)/2;

            both += min(x1x2, x2x1);
          }
          curr[o1][o2] = min(nothing, min(x1, min(x2, both)));
        }
      }
      prev = curr;
    }
    return prev[op1][op2];
  }
};