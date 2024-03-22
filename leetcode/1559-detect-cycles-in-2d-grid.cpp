#include<vector>

using namespace std;

class Solution {
private:
    bool dfs(int i, int j, int m, int n, int xdir, int ydir, char target, vector<vector<char>> &grid) {
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1) return false;
        if (grid[i][j] == target-'a') return true;
        if (grid[i][j] != target) return false;

        grid[i][j] = target-'a';

        return (xdir != 1 && dfs(i - 1, j, m, n, -1, 0, target, grid)) ||
               (xdir != -1 && dfs(i + 1, j, m, n, 1, 0, target, grid)) ||
               (ydir != 1 && dfs(i, j - 1, m, n, 0, -1, target, grid)) ||
               (ydir != -1 && dfs(i, j + 1, m, n, 0, 1, target, grid));
    }

public:
    bool containsCycle(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] >= 'a') {
                    if (dfs(i, j, m, n, 0, 0, grid[i][j], grid)) return true;
                }
            }
        }
        return false;
   }
};

int main() {
    vector<vector<char>> q {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    Solution s;
    s.containsCycle(q);
}