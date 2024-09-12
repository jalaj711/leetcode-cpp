#include<vector>

using namespace std;

class DSU {
    vector<int> par;
    vector<int> size;
public:
    DSU(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
        size.resize(n, -1);
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void join(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (size[pu] > size[pv]) {
            par[pv] = pu;
            size[pu] += size[pu];
        } else {
            par[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
    int dirs[4][2] = {{0,  1},
                      {1,  0},
                      {0,  -1},
                      {-1, 0}};
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int mn = row * col;
        DSU ds(mn + 2);

        int n = 0;
        for (auto it = cells.rbegin(); it != cells.rend(); it++) {
            int x = (*it)[0] - 1;
            int y = (*it)[1] - 1;
            grid[x][y] = 1;
            for (auto dir: dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx < row && ny < col && nx >= 0 && ny >= 0 && grid[nx][ny]) {
                    ds.join(x * col + y, nx * col + ny);
                }
            }
            if (x == 0) ds.join(x * col + y, mn);
            if (x == row - 1) ds.join(x * col + y, mn + 1);

            if (ds.find(mn) == ds.find(mn + 1)) break;
            n++;
        }

        return cells.size() - n - 1;
    }
};