#include<vector>
#include<queue>
#include<unordered_map>
// mask person_x, person_y, box_x, box_y into a single int
#define MASK(px, py, bx, by) (   \
    (((px) & 31) << 15) | \
    (((py) & 31) << 10) | \
    (((bx) & 31) <<  5) | \
    (((by) & 31)      )   \
)
using namespace std;

class Solution {
public:
  int minPushBox(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int dirs[4][2] = {
        {0,  1},
        {1,  0},
        {-1, 0},
        {0,  -1}
    };

    // {pushes, person_x, person_y, box_s, box_y}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // [bitmask of current pos] = min pushes to reach here
    unordered_map<int, int> dis;
    vector<int> start(5, 0);
    int target_x, target_y;

    // find the starting conditions
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 'S') {
          start[1] = i;
          start[2] = j;
        } else if (grid[i][j] == 'T') {
          target_x = i;
          target_y = j;
        } else if (grid[i][j] == 'B') {
          start[3] = i;
          start[4] = j;
        }
      }
    }

    dis[MASK(start[0], start[1], start[2], start[3])] = 0;
    pq.push(start);

    while (!pq.empty()) {
      int p = pq.top()[0];
      int px = pq.top()[1];
      int py = pq.top()[2];
      int bx = pq.top()[3];
      int by = pq.top()[4];
      pq.pop();

      for (const auto &dir: dirs) {
        int npx = px + dir[0];
        int npy = py + dir[1];
        int nbx = bx;
        int nby = by;
        int np = p;

        // if the new position is inaccessible for the person
        if (
            npx < 0 ||
            npy < 0 ||
            npx >= m ||
            npy >= n ||
            grid[npx][npy] == '#'
            )
          continue;

        // if the box is in the direction of movement, we check
        // if we can push it
        if (npx == bx && npy == by) {
          nbx += dir[0];
          nby += dir[1];
          np += 1;
          if (
              nbx < 0 ||
              nby < 0 ||
              nbx >= m ||
              nby >= n ||
              grid[nbx][nby] == '#'
              )
            continue;
          // target reached
          if (nbx == target_x && nby == target_y) return np;
        }


        // see if this new direction is unvisited, if so, visit it
        int mask = MASK(npx, npy, nbx, nby);
        if (
            dis.find(mask) == dis.end() ||
            dis[mask] > np
            ) {
          pq.push({np, npx, npy, nbx, nby});
          dis[mask] = np;
        }
      }
    }

    return -1;

  }
};