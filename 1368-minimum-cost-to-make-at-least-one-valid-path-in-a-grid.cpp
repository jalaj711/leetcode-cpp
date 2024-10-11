#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dis(m, vector<int>(n, 1e9));
    dis[0][0] = 0;

    // distance, {m, n}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > q;

    q.push({0, {0, 0}});
    int dirs[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
    };

    while (!q.empty()) {
      auto fr = q.top();
      q.pop();
      int d = fr.first;
      int x = fr.second.first;
      int y = fr.second.second;

      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        int cost = 1;

        if (i + 1 == grid[x][y]) cost = 0;

        if (
            nx < m &&
            ny < n &&
            nx >= 0 &&
            ny >= 0 &&
            dis[nx][ny] > d + cost
            ) {
          dis[nx][ny] = d + cost;
          q.push({d + cost, {nx, ny}});
        }
      }
    }

    return dis[m - 1][n - 1];
  }
};