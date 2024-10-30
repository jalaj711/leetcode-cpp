#include<vector>

using namespace std;

class Solution {
public:
  int dirs[4][2] = {{0,  1},
                    {-1, 0},
                    {1,  0},
                    {0,  -1}};
  int m, n;

  int discoverWater(int r, int c, vector<vector<int>> &grid) {
    int val = grid[r][c];

    grid[r][c] = 0;
    for (const auto &dir: dirs) {
      int nr = r + dir[0];
      int nc = c + dir[1];

      if (
          nr >= 0 &&
          nc >= 0 &&
          nr < m &&
          nc < n &&
          grid[nr][nc] > 0
          ) {
        val += discoverWater(nr, nc, grid);
      }
    }

    return val;
  }

  int findMaxFish(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    int val = 0;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] > 0)
          val = max(val, discoverWater(i, j, grid));

    return val;
  }
};