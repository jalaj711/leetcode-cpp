#include<string>
#include<vector>

using namespace std;

class DSU {
private:
    vector<int> parent, size;
public:
    explicit DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++) parent[i] = i;
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (par_u == par_v) return;
        if (size[par_u] < size[par_v]) {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        } else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        DSU dsu(26);
        for (const auto &equation: equations)
            if (equation[1] == '=')
                dsu.unionBySize(equation[0] - 'a', equation[3] - 'a');
        for (const auto &equation: equations)
            if (equation[1] == '!' && dsu.findPar(equation[0] - 'a') == dsu.findPar(equation[3] - 'a'))
                return false;
        return true;
    }
};