#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int a = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int z = 0;
        pair<int, int> fr;
        bool incrA;
        while (!q.empty()) {
            z = q.size();
            incrA = false;
            while (z--) {
                fr = q.front();
                q.pop();
                if (fr.first > 0 && grid[fr.first - 1][fr.second] == 1) {
                    grid[fr.first - 1][fr.second] = 2;
                    q.push({fr.first - 1, fr.second});
                    incrA=true;
                }
                if (fr.first < m - 1 && grid[fr.first + 1][fr.second] == 1) {
                    grid[fr.first + 1][fr.second] = 2;
                    q.push({fr.first + 1, fr.second});
                    incrA=true;
                }
                if (fr.second > 0 && grid[fr.first][fr.second - 1] == 1) {
                    grid[fr.first][fr.second - 1] = 2;
                    q.push({fr.first, fr.second - 1});
                    incrA=true;
                }
                if (fr.second < n - 1 && grid[fr.first][fr.second + 1] == 1) {
                    grid[fr.first][fr.second + 1] = 2;
                    q.push({fr.first, fr.second + 1});
                    incrA=true;
                }
            }
            incrA && a++;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return a;
    }
};