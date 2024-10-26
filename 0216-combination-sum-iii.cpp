#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> ans;

  void construct(const int &path) {
    vector<int> p;
    int i = 1;
    while (i <= 9) {
      if ((path >> i) & 1) p.push_back(i);
      i++;
    }
    ans.push_back(p);
  }

  void recur(int k, int n, int l, int path) {
    if (k < 1 || n < 1 || k * 9 < n || l > 9) return;

    for (int i = l; i < 10; i++) {
      if ((path >> i) & 1) continue;
      int p = path | (1 << i);
      if (k == 1) {
        if (i == n) {
          construct(p);
        }
      } else {
        recur(k - 1, n - i, i + 1, p);
      }
    }

  }

  vector<vector<int>> combinationSum3(int k, int n) {
    recur(k, n, 1, 0);

    return ans;
  }
};