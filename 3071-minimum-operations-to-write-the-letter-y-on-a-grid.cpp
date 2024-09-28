#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    bool belongsToY(int x, int y, int n) {
        if (x >= n / 2)
            return y == n / 2;
        if (y < n / 2)
            return x == y;
        return x == (n - y - 1);
    }

    int minimumOperationsToWriteY(vector<vector<int>> &grid) {
        int yCount[3] = {0, 0, 0};
        int notYCount[3] = {0, 0, 0};

        int n = grid.size(), ySum = 0, notYSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (belongsToY(i, j, n)) {
                    yCount[grid[i][j]]++;
                    ySum++;
                } else {
                    notYCount[grid[i][j]]++;
                    notYSum++;
                }
            }
        }

        int minAns = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j)
                    continue;
                minAns = min(minAns, ySum - yCount[i] + notYSum - notYCount[j]);
            }
        }

        return minAns;
    }
};