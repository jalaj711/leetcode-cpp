#include<string>
#include<vector>
#include<iostream>

using namespace std;

class DSU {
private:
    vector<int> parent, size, smallest;
public:
    explicit DSU(int n) {
        parent.resize(n + 1);
        smallest.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
            smallest[i] = i;
        }
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
            smallest[par_v] = min(smallest[par_u], smallest[par_v]);
        } else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
            smallest[par_u] = min(smallest[par_u], smallest[par_v]);
        }
    }

    int getSmallest(int u) {
        return smallest[findPar(u)];
    }
};

class Solution {
public:
    static string smallestEquivalentString(string s1, string s2, const string &baseStr) {
        DSU dsu(25);
        for (int i = 0;i<s1.size();i++) {
            dsu.unionBySize(s1[i] - 'a', s2[i] - 'a');
        }
        string smallest;
        for (const auto &ch: baseStr) {
            smallest += (dsu.getSmallest(ch - 'a') + 'a');
        }
        return smallest;
    }
};

int main() {
//    cout << Solution::smallestEquivalentString("hello", "world", "hold") << endl;
    cout << Solution::smallestEquivalentString("parker", "morris", "parser") << endl;
}