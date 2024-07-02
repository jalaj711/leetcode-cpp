#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    void dfs(int curr, int elem, vector<bool> &vis, vector<vector<int>> &adj, vector<vector<int>> &ans) {
        for (auto child: adj[curr]) {
            if (!vis[child]) {
                vis[child] = true;
                ans[child].push_back(elem);
                dfs(child, elem, vis, adj, ans);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>>ans(n);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        for (int i=0;i<n;i++) {
            vector<bool> vis(n, false);
            dfs(i, i, vis, adj, ans);
        }
        for (auto res: ans) {
            sort(res.begin(), res.end());
        }
        return ans;
    }
};