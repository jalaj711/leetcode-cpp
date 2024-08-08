#include<vector>

using namespace std;

/*
 * solution 1: Simple recursion
 *
 * class Solution {
 * public:
 *     int recur(vector<int> &prices, int idx, bool buy, int transactions) {
 *         if (idx >= prices.size()) return 0;
 *         if (transactions==0) return 0;
 *         if (idx == prices.size()-1) {
 *             if (buy) return 0;
 *             return prices[idx];
 *         }
 *
 *         int skip = recur(prices, idx+1, buy, transactions);
 *         int transact;
 *         if (buy){
 *             transact = -prices[idx] + recur(prices, idx+1, false, transactions);
 *         } else {
 *             transact = prices[idx] + recur(prices, idx+1, true, transactions-1);
 *         }
 *         return max(skip, transact);
 *     }
 *     int maxProfit(vector<int>& prices) {
 *         return recur(prices, 0, true, 2);
 *     }
 * };
 */

/*
 * solution 2: recursion with memoization
 *
 * class Solution {
 * public:
 *     int recur(vector<int> &prices, int idx, bool buy, int transactions, vector<vector<vector<int>>> &memo) {
 *         if (idx >= prices.size() || transactions==0) return 0;
 *         if (memo[idx][buy][transactions-1] > -1) return memo[idx][buy][transactions-1];
 *         if (idx == prices.size()-1) {
 *             if (buy) return memo[idx][buy][transactions-1] = 0;
 *             return memo[idx][buy][transactions-1] = prices[idx];
 *         }
 *
 *         int skip = recur(prices, idx+1, buy, transactions, memo);
 *         int transact;
 *         if (buy){
 *             transact = -prices[idx] + recur(prices, idx+1, false, transactions, memo);
 *         } else {
 *             transact = prices[idx] + recur(prices, idx+1, true, transactions-1, memo);
 *         }
 *         return memo[idx][buy][transactions-1] = max(skip, transact);
 *     }
 *     int maxProfit(vector<int>& prices) {
 *         int n = prices.size();
 *         int transactions = 2;
 *         vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(transactions, -1)));
 *         return recur(prices, 0, true, transactions, memo);
 *     }
 * };
 */

/*
 * Solution 3: Tabulation
 * class Solution {
 * public:
 *     int maxProfit(vector<int>& prices) {
 *         int n = prices.size();
 *         vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
 *
 *         for (int idx = n-1;idx >= 0;idx--) {
 *             for (int buy = 0;buy <= 1; buy++) {
 *                 for (int trx = 1;trx<=2;trx++) {
 *                     if (buy){
 *                         memo[idx][buy][trx] = max(memo[idx+1][1][trx], -prices[idx] + memo[idx+1][false][trx]);
 *                     } else {
 *                         memo[idx][buy][trx] = max(memo[idx+1][0][trx], prices[idx] + memo[idx+1][true][trx-1]);
 *                     }
 *                 }
 *             }
 *         }
 *         return memo[0][1][2];
 *     }
 * };
 */

/*
 * Solution 4: Better tabulation
 *
 * class Solution {
 * public:
 *     int maxProfit(vector<int>& prices) {
 *         int n = prices.size();
 *         vector<vector<int>> prev(2, vector<int>(3, 0));
 *         vector<vector<int>> curr(2, vector<int>(3, 0));
 *
 *         for (int idx = n-1;idx >= 0;idx--) {
 *             for (int buy = 0;buy <= 1; buy++) {
 *                 for (int trx = 1;trx<=2;trx++) {
 *                     if (buy){
 *                         curr[buy][trx] = max(prev[1][trx], -prices[idx] + prev[false][trx]);
 *                     } else {
 *                         curr[buy][trx] = max(prev[0][trx], prices[idx] + prev[true][trx-1]);
 *                     }
 *                 }
 *             }
 *             prev = curr;
 *         }
 *         return prev[1][2];
 *     }
 * };
 */

/*
 * Solution 5: Optimised tabulation
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(2, 0));
        vector<vector<int>> curr(2, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            curr[1][0] = max(prev[1][0], -prices[idx] + prev[0][0]);
            curr[0][0] = max(prev[0][0], prices[idx]);
            curr[1][1] = max(prev[1][1], -prices[idx] + prev[0][1]);
            curr[0][1] = max(prev[0][1], prices[idx] + prev[1][0]);
            prev = curr;
        }
        return prev[1][1];
    }
};

int main() {
    vector<int> q{3, 3, 5, 0, 0, 3, 1, 4};
    Solution s;
    q[896] = 6;
    s.maxProfit(q);
}