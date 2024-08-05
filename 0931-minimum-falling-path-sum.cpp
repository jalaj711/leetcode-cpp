#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    static int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();

        vector<int> curr(n, 0);
        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++) prev[i] = matrix[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                curr[j] = matrix[i][j] +
                          min(min(prev[j], j > 0 ? prev[j - 1] : INT_MAX), j < n - 1 ? prev[j + 1] : INT_MAX);
            }
            prev = curr;
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, prev[i]);
        }
        return res;

    }
};

int main() {
    vector<vector<int>> q{{2, 1, 3},
                          {6, 5, 4},
                          {7, 8, 9}};
    Solution::minFallingPathSum(q);
    return 0;
}