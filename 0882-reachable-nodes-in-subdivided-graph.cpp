#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // adj[i] = [{node, cnt}]
        vector<vector<pair<int, int>>> adj (n);

        for (const vector<int> &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<unsigned int> dis(n, UINT_MAX);
        dis[0] = 0;
        int ans = 1;
        pq.push({0,0});

        while(!pq.empty()) {
            int d = pq.top().first, node = pq.top().second;
            pq.pop();
            for (const pair<int, int> &child: adj[node]) {
                int newDist = d+child.second+1;
                if (newDist > maxMoves) continue;
                if (newDist < dis[child.first]) {
                    ans += (dis[child.first] == UINT_MAX);
                    dis[child.first] = newDist;
                    pq.push({newDist, child.first});
                }
            }
        }

        for (const vector<int> &edge: edges) {
            int t = 0;
            if (dis[edge[0]] < maxMoves) t += maxMoves - dis[edge[0]];
            if (dis[edge[1]] < maxMoves) t += maxMoves - dis[edge[1]];
            ans += min(t, edge[2]);
        }

        return ans;
    }
};