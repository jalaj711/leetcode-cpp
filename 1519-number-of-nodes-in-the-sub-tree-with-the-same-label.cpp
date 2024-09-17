#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    string *l;
    vector<int> dfs(int idx, int par) {
        if (adj[idx].size() == 1 && par != -1) {
            vector<int> a(26, 0);
            a[(*l)[idx] - 'a'] = 1;
            ans[idx] = 1;
            return a;
        }

        int j = adj[idx][0] == par;
        vector<int> init = dfs(adj[idx][j++], idx);
        while (j < adj[idx].size()) {
            vector<int> temp = dfs(adj[idx][j++], idx);
            for (int k=0;k<26;k++) init[k] += temp[k];
        }
        ans[idx] = ++init[(*l)[idx] - 'a'];
        return init;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        if (n==1) {
            ans.push_back(1);
            return ans;
        }
        adj.resize(n);
        ans.resize(n, 0);
        l = &labels;
        for (const auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);

        return ans;
    }
};