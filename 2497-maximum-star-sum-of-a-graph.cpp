#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
  int ans = INT_MIN;

  void dfs(int i, vector<int> &vals, vector<vector<int>> &adj, vector<bool> &vis, int k) {
    vis[i] = true;
    int score = vals[i];
    int x = k;
    ans = max(ans, score);

    for (const auto &it: adj[i]) {
      if (x-- > 0) {
        score += vals[it];
        ans = max(ans, score);
      }

      if (!vis[it]) {
        dfs(it, vals, adj, vis, k);
      }
    }


    return;
  }

  int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
    int n = vals.size();
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);

    for (const auto &edge: edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < n; i++) {
      sort(adj[i].begin(), adj[i].end(), [&vals](int a, int b) {
        return vals[a] > vals[b];
      });
    }

    for (int i = 0; i < n; i++) {
      dfs(i, vals, adj, vis, k);
    }

    return ans;
  }
};