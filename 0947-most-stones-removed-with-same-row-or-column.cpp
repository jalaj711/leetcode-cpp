#include<vector>
#include<unordered_map>

using namespace std;


class DSU {
    vector<int> size;
    vector<int> par;
public:
    DSU(int n) {
        size.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int findPar(int u) {
        if (par[u] == u) return u;
        return par[u] = findPar(par[u]);
    }

    void join(int u, int v) {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (par_u == par_v) return;
        if (size[par_u] > size[par_v]) {
            par[par_v] = par_u;
            size[par_u] += size[par_v];
        } else {
            par[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        DSU dsu(n);
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int i = 0; i < n; i++) {
            if (mp1.find(stones[i][0]) == mp1.end()) {
                mp1[stones[i][0]] = i;
            }
            if (mp2.find(stones[i][1]) == mp2.end()) {
                mp2[stones[i][1]] = i;
            }
            dsu.join(i, mp1[stones[i][0]]);
            dsu.join(i, mp2[stones[i][1]]);
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            if (dsu.findPar(i) == i) ans--;
        }
        return ans;
    }
};