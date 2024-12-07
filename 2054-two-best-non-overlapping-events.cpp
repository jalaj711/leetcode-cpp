#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &ev) {
    sort(ev.begin(), ev.end());

    int n = ev.size();
    int maxScore[n];

    maxScore[n - 1] = ev[n - 1][2];
    for (int i = n - 2; i >= 0; i--) {
      maxScore[i] = max(maxScore[i + 1], ev[i][2]);
    }

    int l, r, m, a, ans = 0;

    for (int i = 0; i < n; i++) {
      l = i + 1;
      r = n - 1;
      a = 0;

      while (l <= r) {
        m = l + (r - l) / 2;

        if (ev[m][0] > ev[i][1]) {
          r = m - 1;
          a = maxScore[m];
        } else {
          l = m + 1;
        }
      }

      ans = max(ans, a + ev[i][2]);
    }

    return ans;
  }
};