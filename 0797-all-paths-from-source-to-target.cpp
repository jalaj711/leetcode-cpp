#include<vector>

using namespace std;

class Solution {
private:
    void dfs(int start, vector<vector<int>> &graph, vector<vector<vector<int>>> &paths, vector<bool> &vis) {
        int n = graph.size();
        for (auto it: graph[start]) {
            if (!vis[it]) { dfs(it, graph, paths, vis); }
            if (it == n - 1) {
                vector<int> nPath{start, n - 1};
                paths[start].push_back(nPath);
            }
            for (auto path: paths[it]) {
                vector<int> nPath;
                nPath.push_back(start);
                nPath.insert(nPath.end(), path.begin(), path.end());
                paths[start].push_back(nPath);
            }
        }
        vis[start] = true;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<vector<int>>> paths(graph.size(), vector<vector<int>>());
        vector<bool> vis(graph.size(), false);
        dfs(0, graph, paths, vis);
        return paths[0];
    }
};