#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid[0][0] != 0) return -1;

    int n = grid.size();
    int dirs[8][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0},
        {1,  1},
        {1,  -1},
        {-1, 1},
        {-1, -1},
    };

    int dis = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = -1;

    while (!q.empty()) {
      int s = q.size();
      dis++;
      while (s--) {
        pair<int, int> fr = q.front();
        q.pop();
        if (fr.first == n - 1 && fr.second == n - 1) return dis;

        for (const auto &dir: dirs) {
          int nx = fr.first + dir[0];
          int ny = fr.second + dir[1];

          if (
              nx >= 0 &&
              ny >= 0 &&
              nx < n &&
              ny < n &&
              grid[nx][ny] == 0
              ) {
            q.push({nx, ny});
            grid[nx][ny] = -1;
          }
        }
      }
    }

    return -1;
  }
};