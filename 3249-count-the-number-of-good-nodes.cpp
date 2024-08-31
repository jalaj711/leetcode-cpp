#include<vector>
using namespace std;

class Solution {
    int count;
    vector<vector<int>> adj;

public:
    int dfs(int node, int parent) {
        if (adj[node].size() == 1 && adj[node][0] == parent) {
            count++;
            return 1;
        }
        int size = 1;
        int firstSize = -1;
        bool flg = true;
        for (int i = 0; i < adj[node].size(); i++) {
            if (adj[node][i] == parent)
                continue;
            int sz = dfs(adj[node][i], node);
            if (firstSize == -1)
                firstSize = sz;
            flg = (flg) && (sz == firstSize);
            size += sz;
        }
        count += flg;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        count = 0;
        int n = edges.size() + 1;
        adj.resize(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        return count;
    }
};