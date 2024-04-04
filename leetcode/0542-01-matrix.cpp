#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        int z = 0, a = 0;
        pair<int, int> fr;
        bool dcrA = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        a = -1;
        while (!q.empty()) {
            z = q.size();
            dcrA = false;
            while (z--) {
                fr = q.front();
                q.pop();

                if (fr.first > 0 && mat[fr.first - 1][fr.second] == 1) {
                    mat[fr.first - 1][fr.second] = a;
                    q.push({fr.first - 1, fr.second});
                    dcrA = true;
                }
                if (fr.first < m - 1 &&
                    mat[fr.first + 1][fr.second] == 1) {
                    mat[fr.first + 1][fr.second] = a;
                    q.push({fr.first + 1, fr.second});
                    dcrA = true;
                }
                if (fr.second > 0 &&
                    mat[fr.first][fr.second - 1] == 1) {
                    mat[fr.first][fr.second - 1] = a;
                    q.push({fr.first, fr.second - 1});
                    dcrA = true;
                }
                if (fr.second < n - 1 &&
                    mat[fr.first][fr.second + 1] == 1) {
                    mat[fr.first][fr.second + 1] = a;
                    q.push({fr.first, fr.second + 1});
                    dcrA = true;
                }
            }
            if (dcrA)
                a--;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] < 0) {
                    mat[i][j] = -mat[i][j];
                }
            }
        }
        return mat;
    }
};

int main() {
//    vector<vector<int>> q{{0, 1, 0, 1, 1},
//                          {1, 1, 0, 0, 1},
//                          {0, 0, 0, 1, 0},
//                          {1, 0, 1, 1, 1},
//                          {1, 0, 0, 0, 1}};
    vector<vector<int>> q{{0, 0, 0},
                          {0, 1, 0},
                          {1, 1, 1}};
    Solution s;
    s.updateMatrix(q);
}
