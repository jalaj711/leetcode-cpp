#include<vector>
#include<queue>
using namespace std;

class Solution {
    private:
    void dfs(int start, vector<int>adj[], int vis[], vector<int> &ans) {
        vis[start] = 1;
        ans.push_back(start);
        for(auto it: adj[start]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ans);
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vector<int> ans;
        
        if (V==0) return ans;
        dfs(0, adj, vis, ans);
        return ans;
    }
};