#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        queue<int> q;
        
        vector<int> bfs;
        if (V==0) return bfs;
        q.push(0);
        while(!q.empty()) {
            int n = q.size();
            while (n--) {
                if(!vis[q.front()]) {
                    bfs.push_back(q.front());
                    vis[q.front()] = 1;
                    for(auto it: adj[q.front()]) {
                        q.push(it);
                    }
                }
                q.pop();
            }
        }
        return bfs;
    }
};