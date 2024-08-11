#include<vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> memo(n, 0);
        memo[n - 1] = questions[n - 1][0];
        long long solve;
        for (int i = n - 2; i >= 0; i--) {
            solve = questions[i][0] + ((i + questions[i][1] + 1) < n ? memo[i + questions[i][1] + 1]:0);
            memo[i] = max(memo[i + 1], solve);
        }
        return memo[0];
    }
};