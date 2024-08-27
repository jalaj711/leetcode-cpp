#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj (n);
        for (int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> probability (n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        while(!pq.empty()) {
            pair<double, int> front = pq.top();
            pq.pop();
            for (auto edge: adj[front.second]) {
                if (front.first * edge.second > probability[edge.first]) {
                    probability[edge.first] = front.first * edge.second;
                    pq.push({probability[edge.first], edge.first});
                }
            }
        }
        return probability[end_node];
    }
};