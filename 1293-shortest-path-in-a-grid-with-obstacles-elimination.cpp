#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // possible directions
        int dirs[4][2] = {{0,  1},
                          {1,  0},
                          {0,  -1},
                          {-1, 0}};

        // stores min distance at each index
        vector<vector<int>> dis(m, vector<int>(n, 1e9));

        // stores max k at each index
        vector<vector<int>> obs(m, vector<int>(n, 0));

        // initial values
        dis[0][0] = 0;
        obs[0][0] = k;

        // {distance, {x, y, k}}
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                greater<pair<int, vector<int>>>>
                pq;
        pq.push({0, {0, 0, k}});

        while (!pq.empty()) {
            auto fr = pq.top();
            int d = fr.first,
                    x = fr.second[0],
                    y = fr.second[1],
                    eff_k = fr.second[2];
            pq.pop();

            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (
                        // to cross this cell, effective k must be greater
                        // than equal to cell value
                        eff_k >= grid[nx][ny] &&
                        (
                                // we update only if either the distance is
                                // better than earlier
                                d + 1 < dis[nx][ny] ||

                                // or we have more k, i.e. ability to cross
                                // more walls later
                                eff_k - grid[nx][ny] > obs[nx][ny]
                        )
                        ) {

                    // save for further processing
                    pq.push({d + 1, {nx, ny, eff_k - grid[nx][ny]}});

                    // update the values
                    if (d + 1 < dis[nx][ny])
                        dis[nx][ny] = d + 1;
                    else
                        obs[nx][ny] = eff_k - grid[nx][ny];

                }
            }
        }

        return dis[m - 1][n - 1] == 1e9 ? -1 : dis[m - 1][n - 1];
    }
};