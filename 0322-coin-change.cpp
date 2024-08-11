#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> curr(amount + 1, -1);

        for (int idx = n - 1; idx >= 0; idx--)
            if (coins[idx] <= amount) {
                curr[coins[idx]] = 1;
                for (int target = coins[idx] + 1; target <= amount;
                     target++) {
                    int take = 1 + curr[target - coins[idx]];
                    if (take == 0) continue;
                    if (curr[target] == -1) curr[target] = take;
                    else curr[target] = min(curr[target], take);
                }
            }

        return curr[amount];
    }
};

int main() {
    vector<int> que{1, 2, 5};
    int target = 11;
    Solution::coinChange(que, target);
}