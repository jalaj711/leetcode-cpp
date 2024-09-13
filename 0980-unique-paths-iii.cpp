#include<vector>
using namespace std;

class Solution {
public:
    int m, n, walkable, ways;
    vector<vector<bool>> vis;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void solve(int i, int j, int covered, vector<vector<int>>& grid) {
        if (grid[i][j] == 2) {
            ways += covered == walkable;
            return;
        }

        vis[i][j] = true;
        for (auto dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == -1 ||
                vis[ni][nj])
                continue;
            solve(ni, nj, covered + 1, grid);
        }
        vis[i][j] = false;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        walkable = 0;
        ways = 0;

        vis.resize(m, vector<bool>(n, 0));

        int si, sj;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                walkable += grid[i][j] == 0;
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        solve(si, sj, -1, grid);
        return ways;
    }
};