#include<vector>

using namespace std;

class Solution {
public:
  int minimumSize(vector<int> &nums, int op) {
    int n = nums.size(),
        l = 1,
        r = 1e9,
        m, a;


    while (l <= r) {
      m = l + (r - l) / 2;
      int b = 0;
      for (int &i: nums) {
        b += (i + m - 1) / m;
      }
      if (b <= n + op) {
        a = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return a;
  }
};