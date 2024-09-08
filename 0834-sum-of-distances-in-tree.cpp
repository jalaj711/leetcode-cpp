#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> adj;
    vector<pair<int, int>> dist;

    void dfs(int i) {
        vis[i] = true;
        for (auto node: adj[i]) {
            if (!vis[node]) {
                dfs(node);
                dist[i].first += (dist[node].first + 1);
                dist[i].second +=
                        (dist[node].first + dist[node].second + 1);

            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        adj.resize(n);
        vis.resize(n, false);
        // (count_nodes, distance_sum)
        dist.resize(n, {0, 0});
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        vector<int> ans(n, 0);
        // (node, parent)
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int x = q.size();
            while (x--) {
                auto fr = q.front();
                q.pop();
                if (dist[fr.first].first < (n - 1)) {
                    ans[fr.first] =
                            dist[fr.second].first - 2 * dist[fr.first].first - 1 +
                            dist[fr.second].second;
                    dist[fr.first].first = n - 1;
                    dist[fr.first].second = ans[fr.first];
                } else ans[fr.first] = dist[fr.first].second;

                for (auto node: adj[fr.first])
                    if (node != fr.second) q.push({node, fr.first});

            }
        }
        return ans;
    }
};