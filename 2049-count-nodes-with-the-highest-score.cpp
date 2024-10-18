#include<vector>
#include<climits>

using namespace std;


typedef long long ul;

class Solution {
public:
  vector<vector<int>> adj;
  ul highest = INT_MIN;
  int cnt = 0;
  int n;

  int dfs(int idx) {
    ul sz[3] = {0, 0, 0};
    for (int i = 0; i < adj[idx].size(); i++) {
      sz[i] = dfs(adj[idx][i]);
    }

    if (idx != 0) sz[2] = n - 1 - sz[0] - sz[1];

    ul score = (sz[0] == 0 ? 1 : sz[0]) * (sz[1] == 0 ? 1 : sz[1]) * (sz[2] == 0 ? 1 : sz[2]);
    if (score > highest) {
      cnt = 1;
      highest = score;
    } else if (score == highest) cnt++;
    return 1 + sz[0] + sz[1];
  }

  int countHighestScoreNodes(vector<int> &parents) {
    n = parents.size();
    adj.resize(n);

    for (int i = 1; i < n; i++)
      adj[parents[i]].push_back(i);

    dfs(0);
    return cnt;
  }
};