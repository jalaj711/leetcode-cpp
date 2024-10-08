#include<vector>

using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int l = 0,
        n = citations.size(),
        r = n - 1,
        ans = 0,
        m;
    while (l <= r) {
      m = (l + r) / 2;
      if (citations[m] >= n - m) {
        ans = n - m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};