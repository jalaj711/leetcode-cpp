#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 2;
            }
            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                grid[i][n - 1] = 2;
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 2;
            }
            if (grid[m - 1][j] == 1) {
                q.push({m - 1, j});
                grid[m - 1][j] = 2;
            }
        }
        int z;
        pair<int, int> fr;
        while (!q.empty()) {
            z = q.size();
            while (z--) {
                fr = q.front();
                q.pop();
                if (fr.first > 0 && grid[fr.first - 1][fr.second] == 1) {
                    q.push({fr.first - 1, fr.second});
                    grid[fr.first - 1][fr.second] = 2;
                }
                if (fr.first < m - 1 && grid[fr.first + 1][fr.second] == 1) {
                    q.push({fr.first + 1, fr.second});
                    grid[fr.first + 1][fr.second] = 2;
                }
                if (fr.second > 0 && grid[fr.first][fr.second - 1] == 1) {
                    q.push({fr.first, fr.second - 1});
                    grid[fr.first][fr.second - 1] = 2;
                }
                if (fr.second < n - 1 && grid[fr.first][fr.second + 1] == 1) {
                    q.push({fr.first, fr.second + 1});
                    grid[fr.first][fr.second + 1] = 2;
                }
            }
        }
        z = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1) z++;
            }
        }
        return z;
    }
};

int main() {
    vector<vector<int>> grid{{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                             {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                             {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                             {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
                             {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                             {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                             {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                             {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                             {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};
    Solution s;
    s.numEnclaves(grid);
}
