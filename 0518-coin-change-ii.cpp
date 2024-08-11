#include<vector>
#include <algorithm>

using namespace std;
// Solution 1: memoized recursion
//class Solution {
//public:
//    int recur (int target, int idx, vector<int> &coins, vector<vector<int>> &memo ) {
//        if (idx >= coins.size() || target < 0) return 0;
//        if (target == coins[idx]) return 1;
//        if (memo[idx][target-1] > -1) return memo[idx][target-1];
//
//        int take = recur(target - coins[idx], idx, coins, memo);
//        int skip = recur(target, idx + 1, coins, memo);
//
//        return memo[idx][target-1] = take + skip;
//    }
//    int change(int amount, vector<int>& coins) {
//        if (amount == 0) return 1;
//        sort(coins.begin(), coins.end());
//        vector<vector<int>> memo (coins.size(), vector<int>(amount, -1));
//        return recur(amount, 0, coins, memo);
//    }
//};

// Solution 2: Tabulation
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        if (amount == 0) return 1;
//        int n = coins.size();
//        sort(coins.begin(), coins.end());
//        vector<vector<int>> memo (n, vector<int>(amount+1, 0));
//
//        for (int target=coins[n-1];target<=amount;target++)
//            if (target == coins[n-1]) memo[n-1][target] = 1;
//            else if (target > coins[n-1]) memo[n-1][target] += memo[n-1][target - coins[n-1]];
//
//        for (int i=0;i<n;i++)
//            memo[i][0] = 1;
//
//
//        for (int idx = n-2;idx>=0;idx--) {
//            for (int target=coins[idx];target<=amount;target++) {
//                if (target == coins[idx]) {
//                    memo[idx][target] = 1;
//                    continue;
//                }
//                memo[idx][target] += target > coins[idx] ? memo[idx][target - coins[idx]] : 0;
//                memo[idx][target] += memo[idx+1][target];
//            }
//        }
//
//        return memo[0][amount];
//    }
//};

// Solution 3: Space optimised tabulation
class Solution {
public:
    static int change(int amount, vector<int> &coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> memo(amount + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            memo[0] = 1;
            if (coins[idx] <= amount) memo[coins[idx]] = 1;
            for (int target = coins[idx] + 1; target <= amount; target++)
                memo[target] += memo[target - coins[idx]];
        }

        return memo[amount];
    }
};

int main() {
    vector<int> coins{5, 3, 2};
    int target = 5;
    Solution::change(target, coins);
}