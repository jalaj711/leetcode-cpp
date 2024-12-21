typedef long long ll;

#include<vector>

using namespace std;

class Solution {
public:

  int count = 0;

  ll solve(int node, int par, vector<vector<int>> &adj, vector<int> &v, int k) {
    ll sum = v[node];

    for (const auto &n: adj[node]) {
      if (n != par) {
        sum += solve(n, node, adj, v, k);
      }
    }

    if (sum % k == 0) {
      count++;
      return 0;
    }

    return sum;
  }

  int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
    vector<vector<int>> adj(n);

    for (const auto &e: edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    solve(0, -1, adj, values, k);

    return count;
  }
};