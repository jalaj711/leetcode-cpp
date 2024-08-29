#include<vector>
#include<unordered_map>

using namespace std;

class DSU {
public:
    vector<int> par;
    vector<int> size;

    DSU(int n) {
        par.resize(n);
        size.resize(n, 1);
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
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        DSU ds(n / 2);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            if (mp.find(row[i] % 2 ? row[i] - 1 : row[i] + 1) != mp.end())
                ds.join(mp[row[i] % 2 ? row[i] - 1 : row[i] + 1], i / 2);
            else
                mp[row[i]] = i / 2;


        int swaps = 0;
        for (int i = 0; i < n / 2; i++)
            if (ds.findPar(i) == i) swaps += ds.size[i] - 1;

        return swaps;
    }
};