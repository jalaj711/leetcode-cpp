#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    int targ;

    double dfs(int idx, int parent, int t) {
        if (t == 0 || adj[idx].size() == (parent != -1)) return (double) targ == idx;

        double initial = 0;
        double level = 1.0 / (double) (adj[idx].size() - (parent != -1));

        for (int i = 0; i < adj[idx].size() && initial == 0; i++) {
            if (adj[idx][i] != parent) initial = level * dfs(adj[idx][i], idx, t - 1);
        }
        return initial;
    }

    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        adj.resize(n);
        for (auto edge: edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        targ = target - 1;

        return dfs(0, -1, t);
    }
};