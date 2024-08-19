#include<vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n/2+1, 0));
        int inf = 1e9+7;
        for (int i = n - 1; i >= 0; i--) {
            for (int c = i/2; c >= 0; c--) {
                if (i + c == n) {
                    memo[i][c] = 1;
                    continue;
                }
                int copy = i * 2 <= n ? memo[i * 2][i]+2 : inf;
                int paste = (i + c < n && c > 0) ? memo[i + c][c]+1 : inf;
                memo[i][c] = min(copy, paste);
            }
        }
        return memo[1][0];
    }
};