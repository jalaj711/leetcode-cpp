#include<vector>

using namespace std;


class Solution {
public:
  int m, n;
  int dirs[4][2] = {
      {0,  1},
      {0,  -1},
      {1,  0},
      {-1, 0}
  };

  bool dfs(int i, int j, vector<vector<int>> &grid) {
    grid[i][j] = 2;

    bool closed = true;

    for (const auto &dir: dirs) {
      int ni = i + dir[0];
      int nj = j + dir[1];

      if (
          ni < 0 ||
          nj < 0 ||
          ni >= m ||
          nj >= n
          ) {
        closed = false;
        continue;
      }

      if (
          grid[ni][nj] == 0
          )
        closed = closed & dfs(ni, nj, grid);
    }

    return closed;
  }

  int closedIsland(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          count += dfs(i, j, grid);
        }
      }
    }

    return count;
  }
};