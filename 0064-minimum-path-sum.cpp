#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        dp[n - 1] = grid[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1) {
                    if (j == n - 1) continue;
                    dp[j] = grid[i][j] + dp[j + 1];
                }
                if (j == n - 1) dp[j] += grid[i][j];
                else {
                    dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};

int main() {
    vector<vector<int>> q{{1, 3, 1},
                          {1, 5, 1},
                          {4, 2, 1}};

    Solution s;
    s.minPathSum(q);
}