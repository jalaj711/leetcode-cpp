#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int _n;
    vector<vector<string>> ans;
    vector<vector<bool>> curr;
    vector<bool> col;
    int dirs[4][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    void saveAns() {
        vector<string> vec(_n, "");
        for (int i = 0; i < _n; i++) {
            for (auto val : curr[i])
                vec[i] += val ? "Q" : ".";
        }
        ans.push_back(vec);
    }
    void recur(int row) {
        for (int i = 0; i < _n; i++) {
            if (col[i])
                continue;
            bool isSafe = true;
            for (int j = 1; j < _n; j++) {
                for (auto dir : dirs) {
                    int nrow = row + j * dir[0];
                    int ncol = i + j * dir[1];
                    if (nrow < 0 || ncol < 0 || nrow >= _n || ncol >= _n)
                        continue;
                    if (curr[nrow][ncol]) {
                        isSafe = false;
                        break;
                    }
                }
                if (!isSafe)
                    break;
            }
            if (isSafe) {
                curr[row][i] = true;
                col[i] = true;
                if (row == _n - 1)
                    saveAns();
                else
                    recur(row + 1);
                curr[row][i] = false;
                col[i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        curr.resize(n, vector<bool>(n, false));
        col.resize(n, false);
        recur(0);
        return ans;
    }
};