#include<queue>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    // second = 1 for blue edge, 0 for red edge, -1 for visited edge
    vector<vector<pair<int, int>>> adj(n);
    for (const auto &edge: blueEdges) {
      adj[edge[0]].push_back({edge[1], 1});
    }
    for (const auto &edge: redEdges) {
      adj[edge[0]].push_back({edge[1], 0});
    }

    vector<int> dis(n, INT_MAX);
    // [0]: distance, [1]: element, [2]: isBlue
    queue<vector<int>> pq;
    pq.push({0, 0, true});
    pq.push({0, 0, false});
    dis[0] = 0;

    while(!pq.empty()) {
      int dist = pq.front()[0];
      int node = pq.front()[1];
      int blue = pq.front()[2];
      pq.pop();

      for(int i=0;i<adj[node].size();i++) {
        const auto &neigh = adj[node][i];
        if (neigh.second == -1) continue;
        if (neigh.second != blue) {
          if (dis[neigh.first] > dist+1) dis[neigh.first] = dist+1;
          pq.push({dist+1, neigh.first, neigh.second});
          adj[node][i].second = -1;
        }
      }
    }

    for(int i=0;i<n;i++) if(dis[i] == INT_MAX) dis[i] = -1;

    return dis;
  }
};