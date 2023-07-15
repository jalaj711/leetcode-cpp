#include<vector>
#include<queue>
using namespace std;

class Solution {
    private:
    void dfs(int start, vector<int>adj[], int vis[], vector<int> &ans) {
        vis[start] = 1;
        ans.push_back()
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        queue<int> q;
        
        if (V==0) return dfs;
        return bfs;
    }
};