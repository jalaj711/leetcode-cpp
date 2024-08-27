#include<vector>
#include<queue>
#include<math.h>
using namespace std;
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto edge: connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(-edge[0]);
        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        int count = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int fr = q.front();
                q.pop();
                for(auto node: adj[fr]) {
                    if (!vis[abs(node)]) {
                        if (node > 0) count++;
                        node = abs(node);
                        vis[node] = true;
                        q.push(node);
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> q {{0,1},{1,3},{2,3},{4,0},{4,5}};
    Solution s;
    s.minReorder(6, q);
}