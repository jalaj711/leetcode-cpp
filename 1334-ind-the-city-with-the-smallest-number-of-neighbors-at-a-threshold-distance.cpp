#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                greater<pair<int, int>>>
        q;
        int ans = INT_MIN;
        int minCnx = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> vis(n, false);
            int cnx = 0;
            q.push({0, i});
            // cout << "starting city " << i << endl;
            while (!q.empty()) {
                int n = q.size();
                while (n--) {
                    pair<int, int> fr = q.top();
                    q.pop();
                    if (vis[fr.second])
                        continue;
                    vis[fr.second] = true;
                    cnx++;
                    // cout << "visit" << fr.second << endl;
                    for (pair<int, int> path : adj[fr.second]) {
                        if (fr.first + path.second <= distanceThreshold &&
                            !vis[path.first]) {
                            q.push({fr.first + path.second, path.first});
                            // cout << "add to list " << path.first << endl;
                        }
                    }
                }
            }
            // cout << "city=" << i << " cnx=" << cnx << endl;
            if (cnx <= minCnx) {
                minCnx = cnx;
                ans = max(ans, i);
            }
        }
        return ans;
    }
};