#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    char deg[n];
    memset(deg, 0, n);
    int cnt = n;
    for (const auto &e: edges) {
      if (deg[e[1]] == 0) {
        deg[e[1]] = 1;
        cnt--;
      }
    }

    if (cnt == 1)
      for (int i = 0; i < n; i++)
        if (deg[i] == 0) return i;
    return -1;
  }
};