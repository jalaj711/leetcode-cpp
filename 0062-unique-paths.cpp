#include<vector>
using namespace std;

class Solution {
private:
    int recur(int m, int n, int i, int j, vector<vector<int>>&dp) {
        if (i==m-1&&j==n-1) return 1;
        dp[i][j] = 0;
        if (i<m-1) dp[i][j] += dp[i+1][j] < 0 ? recur(m, n, i+1, j, dp) : dp[i+1][j];
        if (j<n-1) dp[i][j] += dp[i][j+1] < 0 ? recur(m, n, i, j+1, dp) : dp[i][j+1];
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int>(n, -1));
        return recur(m, n, 0, 0, dp);
    }
};