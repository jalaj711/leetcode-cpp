#include<string>
#include<vector>
#include<map>
#include<algorithm>

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
    static vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DSU dsu(n);

        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) != mp.end()) {
                    if (mp[accounts[i][j]] != i) {
                        dsu.unionBySize(mp[accounts[i][j]], i);
                    }
                } else {
                    mp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> merged(n);
        for (const auto &account: mp) {
            int par = dsu.findPar(account.second);
            if (merged[par].empty()) merged[par].push_back(accounts[par][0]);
            merged[par].push_back(account.first);
        }

        for (auto j: merged) if (j.size() > 1) sort(j.begin() + 1, j.end());

        for (int i = 0; i < merged.size();) {
            if (merged[i].empty()) merged.erase(merged.begin() + i);
            else i++;
        }

        return merged;
    }
};
