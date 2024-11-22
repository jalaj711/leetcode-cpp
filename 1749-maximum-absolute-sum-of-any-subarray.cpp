#include<vector>

using namespace std;

class Solution {
public:
  int maxAbsoluteSum(vector<int> &nums) {
    int ma = 0, mi = 0, ans = 0;

    for (const auto &n: nums) {
      if (ma + n < 0) {
        ma = 0;
      } else ma += n;

      if (mi + n > 0) {
        mi = 0;
      } else mi += n;

      ans = max(ans, ma);
      ans = max(ans, -mi);
    }


    return ans;
  }
};