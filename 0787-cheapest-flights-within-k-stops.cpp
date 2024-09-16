#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adjacency list. adj[from] = Array<{to, weight}>
        vector<vector<pair<int, int>>> adj(n);

        for (const vector<int> &flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> cost (n, 1e9);
        cost[src] = 0;

        // {cost, {node, k}}
        queue<pair<int, pair<int, int>>> pq;

        pq.push({0, {src, k}});
        while(!pq.empty()) {
            auto fr = pq.front();
            int c = fr.first,
                    x = fr.second.first,
                    eff_k = fr.second.second;
            pq.pop();
            for(const pair<int, int> &flight: adj[x]) {
                int node = flight.first, price = flight.second;
                if (cost[node] > c + price && (node==dst ? eff_k>=0:eff_k>=1)) {
                    pq.push({c+price, {node, eff_k-1}});
                    cost[node] = c+price;
                }
            }
        }
        return cost[dst]==1e9?-1:cost[dst];
    }
};