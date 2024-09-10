#include<vector>

using namespace std;


class Solution {
public:
    int m, n;
    int dirs[4][2] = {{0,  1},
                      {1,  0},
                      {0,  -1},
                      {-1, 0}};

    int NODE_IN_PROCESS = -2;

    vector<vector<int>> vis;
    int res = 0;

    int dfs(int x, int y, vector<vector<int>> &matrix) {
        if (vis[x][y] > -1)
            return vis[x][y];
        vis[x][y] = NODE_IN_PROCESS;
        int ans = 0;
        for (auto dir: dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (
                    nx >= 0 &&
                    ny >= 0 &&
                    nx < m &&
                    ny < n &&
                    vis[nx][ny] != NODE_IN_PROCESS &&
                    matrix[nx][ny] > matrix[x][y]
                    )
                ans = max(ans, dfs(nx, ny, matrix));


        }

        ans++;
        res = max(res, ans);
        return vis[x][y] = ans;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vis.resize(m, vector<int>(n, -1));
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                if (vis[x][y] == -1)
                    dfs(x, y, matrix);

        return res;
    }
};

int main() {
    vector<vector<int>> m{{9, 9, 4},
                          {6, 6, 8},
                          {2, 1, 1}};
    Solution s;
    s.longestIncreasingPath(m);
}