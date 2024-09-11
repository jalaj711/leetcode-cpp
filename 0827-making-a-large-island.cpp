#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
private:
    // for dsu
    vector<int> par;
    vector<int> sz;

    // graph size
    int n;

    // max island size
    int maxS = 0;

    // possible directions
    int dirs[4][2] = {{0,  1},
                      {1,  0},
                      {0,  -1},
                      {-1, 0}};

    // dsu find
    int find(int u) {
        if (par[u] == -1)
            return u;
        return par[u] = find(par[u]);
    }

    // dsu union
    void join(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (sz[pu] > sz[pv]) {
            par[pv] = pu;
            sz[pu] += sz[pv];
        } else {
            par[pu] = pv;
            sz[pv] += sz[pu];
        }
    }

public:

    // dfs for island discovery
    void dfs(vector<vector<int>> &grid, int i, int j) {
        grid[i][j] = 2;
        for (auto dir: dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                join(i * n + j, ni * n + nj);
                dfs(grid, ni, nj);
            }
        }
        maxS = max(maxS, sz[find(i * n + j)]);
    }

    int largestIsland(vector<vector<int>> &grid) {
        n = grid.size();
        par.resize(n * n, -1);
        sz.resize(n * n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                // island has not been covered
                if (grid[i][j] == 1)
                    dfs(grid, i, j);

                // try flipping this zero
                else if (grid[i][j] == 0) {

                    // flipping adds 1 to the size
                    int island = 1;

                    // to make sure that we don't count the size
                    // of same island multiple times when the zero
                    // is surrounded by multiple 1 from the same
                    // island
                    unordered_set<int> st;

                    // try all directions
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirs[k][0];
                        int nj = j + dirs[k][1];

                        if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                            grid[ni][nj] != 0) {

                            // if the island at this 1 is not discovered yet then do so
                            if (grid[ni][nj] == 1) dfs(grid, ni, nj);
                            // this one is from an already counted island
                            else if (st.find(find(ni * n + nj)) != st.end()) continue;

                            // increment the size of this island
                            island += sz[find(ni * n + nj)];
                            st.insert(find(ni * n + nj));
                        }
                    }
                    maxS = max(maxS, island);
                }
        return maxS;
    }
};