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
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
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
        } else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }

    int countGroups() {
        int count = 0;
        for (int i = 0; i < parent.size(); i++) {
            count += (i == parent[i]);
        }
        return count;
    }

};

class Solution {
public:

    static bool checkSimilar(const string &s1, const string &s2) {
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
                if (diff.size() > 2) return false;
            }
        }
        if (
                diff.empty() ||
                (
                        diff.size() == 2 &&
                        s1[diff[0]] == s2[diff[1]] &&
                        s2[diff[0]] == s1[diff[1]]
                )
                )
            return true;
        return false;
    }

    static int numSimilarGroups(vector<string> &strs) {
        int n = strs.size();

        DSU dsu(n - 1);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dsu.findPar(i) == dsu.findPar(j)) continue;
                if (checkSimilar(strs[i], strs[j])) dsu.unionBySize(i, j);
            }
        }
        return dsu.countGroups();

    }
};

int main() {
    vector<string> q{"tars", "rats", "arts", "star"};
    Solution::numSimilarGroups(q);
}
