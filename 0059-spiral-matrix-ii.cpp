#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dirs[4][2] = {{0,  1},
                          {1,  0},
                          {0,  -1},
                          {-1, 0}};
        int x = 0, y = 0, c = 1, d = 0;
        vector<vector<int>> res(n, vector<int>(n, 0));
        while (c < n * n) {
            if (x + dirs[d][0] < 0 || x + dirs[d][0] > n - 1 ||
                y + dirs[d][1] < 0 || y + dirs[d][1] > n - 1 ||
                res[x + dirs[d][0]][y + dirs[d][1]]) {
                d = (d + 1) % 4;
            } else {
                res[x][y] = c++;
                x += dirs[d][0];
                y += dirs[d][1];
            }
        }
        res[x][y] = c;
        return res;
    }
};