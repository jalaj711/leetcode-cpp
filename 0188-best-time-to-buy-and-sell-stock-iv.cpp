#include<vector>

using namespace std;

// This solution is simply an extension to the solution of 0123-best-time-to-buy-and-sell-stock-iii
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int trx = 1; trx <= k; trx++) {
                curr[1][trx] = max(prev[1][trx], -prices[idx] + prev[false][trx]);
                curr[0][trx] = max(prev[0][trx], prices[idx] + prev[true][trx - 1]);
            }
            prev = curr;
        }
        return prev[1][k];
    }
};