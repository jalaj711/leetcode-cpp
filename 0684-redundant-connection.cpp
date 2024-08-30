#include<vector>
using namespace std;

class DSU {
public:
    vector<int> size;
    vector<int> par;
    DSU(int n) {
        size.resize(n, 1);
        par.resize(n);
        for (int i=0;i<n;i++) par[i] = i;
    }
    int findPar(int u) {
        if (par[u] == u) return u;
        return par[u] = findPar(par[u]);
    }

    void join(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) return;
        if (size[pu] > size[pv]) {
            par[pv] = pu;
            size[pu] += size[pv];
        }else{
            par[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU ds(n+1);

        for (auto edge : edges) {
            if (ds.findPar(edge[0]) == ds.findPar(edge[1])) return edge;
            ds.join(edge[0], edge[1]);
        }
        return vector<int>{0, 0};
    }
};