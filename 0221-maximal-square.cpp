#include<vector>

using namespace std;

class Solution {
public:
    static int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> curr(n, 0);
        int maxSq = 0;
        for (int i = 0; i < n; i++)
            maxSq = max(curr[i] = matrix[0][i] - '0', maxSq);

        int prev, temp;
        for (int i = 1; i < m; i++) {
            prev = curr[0];
            curr[0] = matrix[i][0] - '0';
            maxSq = max(maxSq, curr[0]);
            for (int j = 1; j < n; j++) {
                temp = curr[j];
                if (matrix[i][j] - '0') {
                    curr[j] = min(prev, min(curr[j], curr[j - 1])) + 1;
                    maxSq = max(maxSq, curr[j]);
                } else {
                    curr[j] = 0;
                }
                prev = temp;
            }
        }
        return maxSq * maxSq;
    }
};

int main() {
    vector<vector<char>> q{{'0', '0', '1', '0'},
                           {'1', '1', '1', '1'},
                           {'1', '1', '1', '1'},
                           {'1', '1', '1', '0'},
                           {'1', '1', '0', '0'},
                           {'1', '1', '1', '1'},
                           {'1', '1', '1', '0'}};
    Solution::maximalSquare(q);
}