#include<vector>

using namespace std;

class Solution {
public:
  vector<int>* adj;
  vector<int> depth;
  int cmin;
  int lcycle = -1;
  int dfs(int i, int d) {
    depth[i] = d;
    // cout << "setting depth[" << i << "] = " << d << endl;
    if ((*adj)[i] == -1) return d;
    if (depth[(*adj)[i]] >= cmin) {
      // cout << "cycle found of length " << d - depth[(*adj)[i]] + 1 << endl;
      lcycle = max(lcycle, d - depth[(*adj)[i]] + 1);
    } else if (depth[(*adj)[i]] == 0) {
      // cout << "going to " << (*adj)[i] << " from  " << i << endl;
      d = max(d, dfs((*adj)[i], d+1));
    }
    return d;
  }
  int longestCycle(vector<int>& edges) {
    adj = &edges;
    int n = edges.size();
    int d = 0;
    depth.resize(n, 0);

    for (int i=0;i<n;i++) {
      if (depth[i] == 0) {
        cmin = ++d;
        d = dfs(i, d);
      }
    }

    return lcycle;

  }
};