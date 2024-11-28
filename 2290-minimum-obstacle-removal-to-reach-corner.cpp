#include<vector>
#include<deque>
#include<cstring>
#include<tuple>

using namespace std;

class Solution {
public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    unsigned int dis[m][n];
    memset(dis, 255, m*n*4);
    int dirs[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

    deque<tuple<int, int, int>> pq;

    pq.push_front({0,0,0});
    dis[0][0] = 0;

    while(!pq.empty()) {
      auto [d, x, y] = pq.front();
      pq.pop_front();

      if (x == m-1  && y == n-1) return d;

      for (const auto &dir: dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];

        if (
            nx >= m ||
            ny >= n ||
            nx < 0  ||
            ny < 0
            ) continue;

        int nd = d + grid[nx][ny];
        if (nd < dis[nx][ny]) {
          dis[nx][ny] = nd;
          if (nd == d)
            pq.push_front({nd, nx, ny});
          else
            pq.push_back({nd, nx, ny});
        }
      }
    }

    return dis[m-1][n-1];
  }
};