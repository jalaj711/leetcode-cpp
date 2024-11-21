#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    char grid[m][n];
    memset(grid, 0, m*n);

    int c = m * n - walls.size() - guards.size();

    for (const auto& w : walls)
      grid[w[0]][w[1]] = 1;
    for (const auto& g : guards)
      grid[g[0]][g[1]] = 1;
    for (const auto& g : guards) {
      for (int i = g[0] + 1; i < m; i++) {
        if (grid[i][g[1]] == 1)
          break;
        if (grid[i][g[1]] == 0) {
          c--;
          grid[i][g[1]] = 2;
        }
      }
      for (int i = g[0] - 1; i >= 0; i--) {
        if (grid[i][g[1]] == 1)
          break;
        if (grid[i][g[1]] == 0) {
          c--;
          grid[i][g[1]] = 2;
        }
      }
      for (int i = g[1] + 1; i < n; i++) {
        if (grid[g[0]][i] == 1)
          break;
        if (grid[g[0]][i] == 0) {
          c--;
          grid[g[0]][i] = 2;
        }
      }
      for (int i = g[1] - 1; i >= 0; i--) {
        if (grid[g[0]][i] == 1)
          break;
        if (grid[g[0]][i] == 0) {
          c--;
          grid[g[0]][i] = 2;
        }
      }
    }
    return c;
  }
};