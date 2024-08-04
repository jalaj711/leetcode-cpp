#include<vector>
using namespace std;

/*
 * Solution 1
 * class Solution {
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
};*/

// Solution 2: Space optimisation
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==1 || n==1) return 1;
        vector<int> dp (n, 1);
        dp[n-1] = 0;
        for (int i = m-2;i>=0;i--) {
            dp[n-1] = 1;
            for (int j = n-2;j>=0;j--)
                dp[j] += dp[j+1];
        }
        return dp[0];
    }
};