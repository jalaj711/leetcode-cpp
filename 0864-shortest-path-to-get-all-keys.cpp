#include<string>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
  int shortestPathAllKeys(vector<string> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count_k = 0;

    int dirs[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
    };

    pair<int, int> start;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '@') {
          start.first = i;
          start.second = j;
        } else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') count_k++;
      }

    // {dist, i, j, no_of_keys, key_bitmask}
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    // min distance from start for each set of keys we might have
    vector<vector<vector<int>>> dis(m, vector<vector<int>>(n, vector<int>(1 << count_k, INT_MAX)));

    dis[start.first][start.second][0] = 0;
    pq.push({0, start.first, start.second, 0, 0});

    while (!pq.empty()) {
      const auto fr = pq.top();
      pq.pop();

      int d = fr[0];
      int i = fr[1];
      int j = fr[2];
      int k = fr[3];
      int b = fr[4];

      for (const auto &dir: dirs) {
        int ni = i + dir[0];
        int nj = j + dir[1];

        // out of border
        if (
            ni < 0 ||
            nj < 0 ||
            ni >= m ||
            nj >= n
            )
          continue;

        // found a lock whose key is not there
        if (
            grid[ni][nj] >= 'A' &&
            grid[ni][nj] <= 'Z' &&
            ((b >> (grid[ni][nj] - 'A')) & 1) == 0
            )
          continue;

        // found a wall
        if (
            grid[ni][nj] == '#'
            )
          continue;

        bool is_key = grid[ni][nj] >= 'a' && grid[ni][nj] <= 'z';
        // if it's a key we don't already have, then pick it up
        int nk = k + (is_key && (((b >> (grid[ni][nj] - 'a')) & 1) == 0));
        // adjust bitmask according to new key
        int nb = b | (is_key ? (1 << (grid[ni][nj] - 'a')) : 0);

        // found all keys
        if (nk == count_k) return d + 1;

        // distance is less
        if (
            d + 1 < dis[ni][nj][nb]
            ) {
          dis[ni][nj][nb] = d + 1;
          pq.push({d + 1, ni, nj, nk, nb});
        }
      }
    }

    return -1;
  }
};