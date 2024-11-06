#include<vector>

using namespace std;

class Solution {
public:
  int dirs[4][2] = {
      {0,  1},
      {0,  -1},
      {1,  0},
      {-1, 0}
  };
  int m, n;

  int dfs(int i, int j, vector<vector<int>> &grid) {
    grid[i][j] = 2;
    int s = 1;

    for (const auto &dir: dirs) {
      int ni = i + dir[0];
      int nj = j + dir[1];

      if (
          ni < 0 ||
          nj < 0 ||
          ni >= m ||
          nj >= n ||
          grid[ni][nj] != 1
          )
        continue;

      s += dfs(ni, nj, grid);
    }

    return s;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    int maxArea = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          maxArea = max(maxArea, dfs(i, j, grid));
        }
      }
    }

    return maxArea;
  }
};