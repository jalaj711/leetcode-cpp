#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<unsigned long> dp (n, 0);
        dp[n-1] = (obstacleGrid[m-1][n-1]==0);
        for (int i = m-1;i>=0;i--) {
            for (int j = n-1;j>=0;j--) {
                if (i==m-1&&j==n-1) continue;
                if (obstacleGrid[i][j]) dp[j] = 0;
                else if (i==m-1) dp[j] = dp[j+1];
                else if (j != n-1) dp[j] += dp[j+1];
            }
        }
        return dp[0];
    }
};