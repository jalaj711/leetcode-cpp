#include<vector>
#include<cmath>

using namespace std;

class Solution {
private:
  int m;
  int n;
  int dirs[4][2] = {{0,  -1},
                    {-1, 0},
                    {0,  1},
                    {1,  0}};

  void findFrontier(int i, int j, vector<vector<int>> &grid,
                    vector<pair<int, int>> &q) {
    grid[i][j] = 2;

    bool boundary = false;

    for (const auto &dir: dirs) {
      int ni = i + dir[0];
      int nj = j + dir[1];

      if (ni < 0 || nj < 0 || ni >= m || nj >= n)
        continue;
      if (grid[ni][nj] == 0)
        boundary = true;
      if (grid[ni][nj] == 1)
        findFrontier(ni, nj, grid, q);
    }

    if (boundary)
      q.push_back({i, j});
  }

public:
  int shortestBridge(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    bool br = false, firstFound = false;
    vector<pair<int, int>> frontier1, frontier2;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          findFrontier(i, j, grid,
                       firstFound ? frontier2 : frontier1);
          if (firstFound)
            br = true;
          firstFound = true;
        }
      }
      if (br)
        break;
    }

    int ans = 1e9;
    int f1 = frontier1.size();
    int f2 = frontier2.size();
    for (int i = 0; i < f1; i++) {
      for (int j = 0; j < f2; j++) {
        ans = min(ans,
                  abs(frontier1[i].first - frontier2[j].first) +
                  abs(frontier1[i].second - frontier2[j].second));
      }
    }
    return ans - 1;
  }
};
