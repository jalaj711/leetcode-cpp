#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<unordered_set<int>> adj(n, unordered_set<int>());
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        int m = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (i != j) {
                    int rank = adj[i].size() + adj[j].size() - (adj[i].find(j) != adj[i].end());
                    m = max(m, rank);
                }
        return m;
    }
};