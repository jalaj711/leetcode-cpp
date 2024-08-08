#include<vector>

using namespace std;

// solution 1: pure recursion
//class Solution {
//public:
//    int recur(const vector<int> &prices, const int &fee, int idx, int bought_at) {
//        if (idx >= prices.size()) return 0;
//        if (idx == prices.size()-1) return bought_at == -1 ? 0 : max(prices[idx]-prices[bought_at]-fee, 0);
//        int skip = recur(prices, fee, idx+1, bought_at);
//        int transact;
//        if (bought_at == -1) {
//            transact = recur(prices, fee, idx+1, idx);
//        } else {
//            transact = prices[idx]-prices[bought_at]-fee + recur(prices, fee, idx+1, -1);
//        }
//        return max(skip, transact);
//    }
//    int maxProfit(vector<int>& prices, int fee) {
//        return recur(prices, fee, 0, -1);
//    }
//};

// solution 2: memoized recursion
//class Solution {
//public:
//    int recur(const vector<int> &prices, const int &fee, int idx, int bought_at, vector<vector<int>> &memo) {
//        if (idx >= prices.size()) return 0;
//        if (memo[idx][bought_at+1] > -1) return memo[idx][bought_at+1] ;
//        int skip = recur(prices, fee, idx+1, bought_at, memo);
//        int transact;
//        if (bought_at == -1) {
//            transact = recur(prices, fee, idx+1, idx, memo);
//        } else {
//            transact = prices[idx]-prices[bought_at]-fee + recur(prices, fee, idx+1, -1, memo);
//        }
//        return memo[idx][bought_at+1] = max(skip, transact);
//    }
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        vector<vector<int>> memo(n, vector<int>(n+1, -1));
//        return recur(prices, fee, 0, -1, memo);
//    }
//};

// solution 3: slightly better memoized recursion
//class Solution {
//public:
//    int recur(const vector<int> &prices, const int &fee, int idx, bool buy, vector<vector<int>> &memo) {
//        if (idx >= prices.size()) return 0;
//        if (memo[idx][buy] > -1) return memo[idx][buy] ;
//        int skip = recur(prices, fee, idx+1, buy, memo);
//        int transact;
//        if (buy) {
//            transact = -prices[idx] + recur(prices, fee, idx+1, false, memo);
//        } else {
//            transact = prices[idx]-fee + recur(prices, fee, idx+1, true, memo);
//        }
//        return memo[idx][buy] = max(skip, transact);
//    }
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        vector<vector<int>> memo(n, vector<int>(2, -1));
//        return recur(prices, fee, 0, true, memo);
//    }
//};

// solution 4: tabulated
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        vector<vector<int>> memo(n, vector<int>(2, -1));
//        memo[n-1][1] = 0;
//        memo[n-1][0] = max(prices[n-1]-fee, 0);
//        for (int idx=n-2;idx>=0;idx--) {
//            for (int buy=1;buy>=0;buy--) {
//                int skip = memo[idx+1][buy] ;
//                int transact;
//                if (buy) {
//                    transact = -prices[idx] + memo[idx+1][false];
//                } else {
//                    transact = prices[idx]-fee + memo[idx+1][true];
//                }
//                memo[idx][buy] = max(skip, transact);
//            }
//        }
//        return memo[0][1];
//    }
//};

// solution 5: optimised tabulation
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        vector<int> prev(2, -1);
//        vector<int> curr(2, -1);
//        prev[1] = 0;
//        prev[0] = max(prices[n-1]-fee, 0);
//        for (int idx=n-2;idx>=0;idx--) {
//            for (int buy=1;buy>=0;buy--) {
//                int transact;
//                if (buy) {
//                    transact = -prices[idx] + prev[false];
//                } else {
//                    transact = prices[idx]-fee + prev[true];
//                }
//                curr[buy] = max(prev[buy], transact);
//            }
//            prev = curr;
//        }
//        return prev[1];
//    }
//};

// solution 6: alternate version of optimised tabulation
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        int plus_one_buy = 0, plus_one_not_buy = max(prices[n - 1] - fee, 0), curr_buy, curr_not_buy;
        for (int idx = n - 2; idx >= 0; idx--) {
            curr_buy = max(plus_one_buy, -prices[idx] + plus_one_not_buy);
            curr_not_buy = max(plus_one_not_buy, prices[idx] - fee + plus_one_buy);
            plus_one_buy = curr_buy;
            plus_one_not_buy = curr_not_buy;
        }
        return plus_one_buy;
    }
};