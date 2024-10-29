#include<vector>

using namespace std;

class Solution {
public:
  int m, n;
  int dirs[3][2] = {{-1, 1},
                    {0,  1},
                    {1,  1}};

  int solve(int r, int c, vector<vector<int>> &grid) {
    int val = grid[r][c];
    int ans = 0;

    for (const auto &dir: dirs) {
      int nr = r + dir[0];
      int nc = c + dir[1];

      if (
          nr < 0 ||
          nc < 0 ||
          nr >= m ||
          nc >= n ||
          grid[nr][nc] == 0
          )
        continue;

      if (grid[nr][nc] < 0 && val < -grid[nr][nc]) ans = max(ans, 1 - grid[nr][nc]);
      if (val < grid[nr][nc])
        ans = max(ans, solve(nr, nc, grid) + 1);

    }

    grid[r][c] = -ans;
    return ans;
  }

  int maxMoves(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    int j = 0;
    for (int i = 0; i < m; i++)
      j = max(j, solve(i, 0, grid));

    return j;
  }
};