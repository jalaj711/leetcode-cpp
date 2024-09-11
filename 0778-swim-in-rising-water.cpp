#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = grid[0][0];
        int dirs[4][2] = {{0,  1},
                          {1,  0},
                          {0,  -1},
                          {-1, 0}};

        priority_queue<
                pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>
        > pq;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto fr = pq.top();
            pq.pop();

            for (auto dir: dirs) {
                int nx = fr.second.first + dir[0];
                int ny = fr.second.second + dir[1];

                if (nx < n && ny < n && nx >= 0 && ny >= 0) {
                    int t = max(grid[nx][ny], fr.first);
                    if (t < dis[nx][ny]) {
                        dis[nx][ny] = t;
                        pq.push({t, {nx, ny}});
                    }
                }

            }
        }

        return dis[n - 1][n - 1];
    }
};