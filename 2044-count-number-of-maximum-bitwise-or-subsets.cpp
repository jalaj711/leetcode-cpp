#include<vector>
using namespace std;

class Solution {
public:
  int highest = 0;
  int cnt = 0;
  void recur(int idx, int curr, vector<int> &nums) {
    if (idx >= nums.size()) return;

    // dont pick
    recur(idx+1, curr, nums);

    curr = curr | nums[idx];

    if (curr > highest) {
      highest = curr;
      cnt = 1;
    } else if (curr == highest) {
      cnt++;
    }
    // pick
    recur(idx+1, curr, nums);
    return;
  }
  int countMaxOrSubsets(vector<int>& nums) {
    recur(0,0,nums);
    return cnt;
  }
};