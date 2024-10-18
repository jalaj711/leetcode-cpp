#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int z = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1)
          q.push({i, j});
        else
          z++;

    if (z == 0 || z == m * n)
      return -1;

    int d = 0;
    int dirs[4][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};

    while (!q.empty() && z != 0) {
      int s = q.size();
      while (s--) {
        pair<int, int> fr = q.front();
        q.pop();
        for (auto dir: dirs) {
          int ni = fr.first + dir[0];
          int nj = fr.second + dir[1];

          if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
              grid[ni][nj] == 0) {
            grid[ni][nj] = 1;
            z--;
            q.push({ni, nj});
          }
        }
      }
      d++;
    }

    return d;
  }
};