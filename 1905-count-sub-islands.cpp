#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> vis;
    vector<pair<int, int>> dirs{{0,  1},
                                {0,  -1},
                                {1,  0},
                                {-1, 0}};
    int m;
    int n;

    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j) {
        vis[i][j] = true;
        bool isSubIsland = grid1[i][j];
        int ni, nj;
        for (auto dir: dirs) {
            ni = i + dir.first;
            nj = j + dir.second;
            if (
                    ni >= 0 && nj >= 0 &&
                    ni < m && nj < n &&
                    grid2[ni][nj] &&
                    !vis[ni][nj]
                    ) {
                isSubIsland = dfs(grid1, grid2, ni, nj) && isSubIsland;
            }
        }


        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        m = grid1.size();
        n = grid1[0].size();

        vis.resize(m, vector<bool>(n, false));

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] && !vis[i][j]) {
                    count += dfs(grid1, grid2, i, j);
                }
            }
        }
        return count;
    }

};

int main() {
    vector<vector<int>> grid1{{1, 1, 1, 0, 0},
                              {0, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0},
                              {1, 1, 0, 1, 1}};
    vector<vector<int>> grid2{{1, 1, 1, 0, 0},
                              {0, 0, 1, 1, 1},
                              {0, 1, 0, 0, 0},
                              {1, 0, 1, 1, 0},
                              {0, 1, 0, 1, 0}};
    Solution s;
    s.countSubIslands(grid1, grid2);
}