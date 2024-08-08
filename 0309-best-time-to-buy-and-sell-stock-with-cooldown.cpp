#include<vector>
using namespace std;

//class Solution {
//public:
//    int recur(vector<int> &prices, int idx, int bought_at, vector<vector<int>> &memo) {
//        if (idx >= prices.size()) return 0;
//        if (memo[idx+1][bought_at+1] > -1) return memo[idx+1][bought_at+1];
//        if (idx == prices.size()-1) {
//            if (bought_at > -1) return memo[idx+1][bought_at+1] = prices[idx]-prices[bought_at];
//            else return memo[idx+1][bought_at+1] = 0;
//        }
//        int skip = recur(prices, idx+1, bought_at, memo);
//        int transact = INT_MIN;
//        if (bought_at > -1) {
//            transact = prices[idx] - prices[bought_at] + recur(prices, idx+2, -1, memo);
//        } else {
//            transact = recur(prices, idx+1, idx, memo);
//        }
//        return memo[idx+1][bought_at+1] = max(skip, transact);
//    }
//    int maxProfit(vector<int>& prices) {
//        vector<vector<int>> memo(prices.size()+1, vector<int> (prices.size()+1, -1));
//        int a =  recur(prices, 0, -1, memo);
//        return a;
//    }
//};


//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        vector<vector<int>> memo(n, vector<int> (n+1, -1));
//        memo[n-1][0] = 0;
//        for (int i=0;i<n-1;i++) {
//            memo[n-1][i+1] = prices[n-1] - prices[i];
//        }
//        for (int idx=n-2;idx>=0;idx--) {
//            for (int bought_at=idx-1;bought_at>=-1;bought_at--) {
//                int skip = memo[idx+1][bought_at+1];
//                int transact = INT_MIN;
//                if (bought_at > -1) {
//                    transact = prices[idx] - prices[bought_at] + (idx + 2 < n ? memo[idx+2][0] : 0);
//                } else {
//                    transact = memo[idx+1][idx+1];
//                }
//                memo[idx][bought_at+1] = max(skip, transact);
//            }
//        }
//        return memo[0][0];
//    }
//};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> plus_two(n+1, 0);
        vector<int> plus_one(n+1, 0);
        vector<int> curr(n+1, 0);
        plus_two[0] = 0;
        for (int i=0;i<n-1;i++) {
            plus_two[i+1] = prices[n-1] - prices[i];
        }
        int skip, transact;
        for (int bought_at=n-3;bought_at>-1;bought_at--) {
            skip = plus_two[bought_at+1];
            transact = prices[n-2] - prices[bought_at];
            plus_one[bought_at+1] = max(skip, transact);
        }
        plus_one[0] = max(plus_two[0], plus_two[n-1]);

        for (int idx=n-3;idx>=0;idx--) {
            for (int bought_at=idx-1;bought_at>-1;bought_at--) {
                skip = plus_one[bought_at+1];
                transact = prices[idx] - prices[bought_at] + plus_two[0];
                curr[bought_at+1] = max(skip, transact);

            }
            curr[0] = max(plus_one[0], plus_one[idx+1]);
            plus_two = plus_one;
            plus_one = curr;
        }
        return curr[0];
    }
};

int main() {
    vector<int> q {1,2,3,0,2};
    Solution s;
    s.maxProfit(q);
}