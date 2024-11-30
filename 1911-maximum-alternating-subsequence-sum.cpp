#include<vector>

using namespace std;

class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    long long curr[2] = {0};
    long long prev[2] = {0};

    for (int idx = n - 1; idx >= 0; idx--) {
      for (int dir = 1; dir >= 0; dir--) {
        long long pick = nums[idx] * (dir ? 1 : -1) + prev[!dir];

        curr[dir] = max(pick, prev[dir]);
      }
      prev[0] = curr[0];
      prev[1] = curr[1];
    }

    return prev[1];
  }
};