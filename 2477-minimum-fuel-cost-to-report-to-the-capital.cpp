#include<vector>

using namespace std;

class Solution {
public:
  long long ans = 0;
  int dfs(int idx, int par, int s, vector<vector<int>> &adj) {
    int child = 1;

    for (auto &node: adj[idx])
      if (node != par)
        child += dfs(node, idx, s, adj);

    ans += child / s;
    if (child % s) ans++;
    return child;
  }
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size() + 1;
    vector<vector<int>> adj(n);

    for (int i = 0;i<n-1;i++) {
      adj[roads[i][0]].push_back(roads[i][1]);
      adj[roads[i][1]].push_back(roads[i][0]);
    }

    for (auto &node: adj[0])
      dfs(node, 0, seats, adj);


    return ans;
  }
};