#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> adj;

  // finds the path from start to end and updates the frequency
  // array accordingly
  bool find(int start, int end, int par, vector<int> &freq) {
    if (start == end)
      return true;

    for (const auto &next: adj[start]) {
      if (next == par) continue;

      if (find(next, end, start, freq)) {
        freq[next]++;
        return true;
      }
    }

    return false;
  }

  // pick the indexes to be halved such that the total price is minimised
  int _minimise(int idx, int par, bool canPick, vector<int> &freq, vector<int> &price, vector<vector<int>> &dp) {
    if (idx >= freq.size()) return 0;
    if (dp[idx][canPick] > -1) return dp[idx][canPick];

    int notpick = 0;
    int pick = 0;
    for (const auto &node: adj[idx]) {
      if (node == par) continue;
      notpick += _minimise(node, idx, true, freq, price, dp);
      if (canPick) pick += _minimise(node, idx, false, freq, price, dp);
    }

    notpick += freq[idx] * price[idx];
    if (canPick) pick += freq[idx] * price[idx] / 2;
    else pick = 2e9;

    return dp[idx][canPick] = min(notpick, pick);
  }

  int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
    adj.resize(n);

    // form the graph
    for (const auto &edge: edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    // find all frequencies
    vector<int> freq(n, 0);
    for (const auto &trip: trips) {
      freq[trip[0]]++;
      find(trip[0], trip[1], -1, freq);
    }

    // minimise the price with dynamic programming
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return _minimise(0, -1, true, freq, price, dp);
  }
};