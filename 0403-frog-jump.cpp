#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
  int n;
  unordered_map<int, bool> dp;
  bool rec(int idx, int k, vector<int> &stones) {
    if (idx == n-1) return true;
    const int key = k << 11 | idx;

    if (dp.find(key) != dp.end()) return dp[key];

    int nxt = idx+1;
    bool canJump = false;

    while(nxt < n && stones[nxt] - stones[idx] <= k+1) {
      if (stones[nxt] - stones[idx] == k-1) canJump |= rec(nxt, k-1, stones);
      if (stones[nxt] - stones[idx] == k) canJump |= rec(nxt, k, stones);
      if (stones[nxt] - stones[idx] == k+1) canJump |= rec(nxt, k+1, stones);
      nxt++;
    }

    return dp[key] = canJump;
  }
  bool canCross(vector<int>& stones) {
    n = stones.size();

    if (stones[1] != 1) return false;
    return rec(1, 1, stones);
  }
};