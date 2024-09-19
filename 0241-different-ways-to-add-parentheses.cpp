#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    int eval(int x, int y, int op) {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        return x * y;
    }

    vector<int> rec(int i, int j, const string &expr, vector<vector<vector<int>>> &dp) {
        if (dp[i][j].size() > 0) return dp[i][j];
        bool num = true;

        for (int k = i; k < j; k++) {
            if (!isdigit(expr[k])) {
                num = false;
                // calculate all possibilities on left and right part
                auto l = rec(i, k, expr, dp);
                auto r = rec(k + 1, j, expr, dp);

                // do a cross join of those possibilities
                for (auto x: l)
                    for (auto y: r)
                        dp[i][j].push_back(eval(x, y, expr[k]));
            }
        }

        // if this string is a pure number
        if (num) {
            int n = 0, k = i;
            while (k < j) {
                n = n * 10 + (expr[k++] - '0');
            }
            dp[i][j].push_back(n);
        }
        return dp[i][j];
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        // dp array
        // dp[i][j] = array of all possible answers of the substring expr[i] to expr[j]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>()));
        return rec(0, expression.size(), expression, dp);
    }
};