#include<vector>

using namespace std;

class Solution {
public:
  int inf = 1e9 + 7;
  int ans = 0;
  int m, n;
  int dirs[4][2] = {
      {0,  1},
      {0,  -1},
      {1,  0},
      {-1, 0}
  };

  int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &mem) {
    if (mem[x][y] > -1) return mem[x][y];
    int count = 0;

    for (int i = 0; i < 4; i++) {
      int nx = x + dirs[i][0];
      int ny = y + dirs[i][1];

      if (
          nx < m &&
          ny < n &&
          nx >= 0 &&
          ny >= 0

          ) {
        if (grid[nx][ny] > grid[x][y]) {
          count = (count + 1 + dfs(nx, ny, grid, mem)) % inf;
        }
      }
    }


    ans = (ans + count) % inf;
    return mem[x][y] = count;
  }

  int countPaths(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    vector<vector<int>> mem(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mem[i][j] == -1) dfs(i, j, grid, mem);
      }
    }

    // adding single length paths
    ans = (ans + m * n) % inf;
    return ans;
  }
};
