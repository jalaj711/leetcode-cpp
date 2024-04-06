#include<vector>
#include<queue>

using namespace std;

class Solution {
private:
    bool bfs(int start, vector<int> &colors, vector<vector<int>> &graph) {
        bool currColor = false;
        queue<int> q;
        q.push(start);
        int fr, sz;
        while (!q.empty()) {
            sz = q.size();
            while (sz--) {
                fr = q.front();
                q.pop();
                if (colors[fr] == -1) {
                    colors[fr] = currColor;
                    for (auto it: graph[fr]) {
                        q.push(it);
                    }
                } else if (colors[fr] != currColor) {
                    return false;
                }
            }
            currColor = !currColor;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1 && !bfs(i, colors, graph)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph{{1, 3},
                              {0, 2},
                              {1, 3},
                              {0, 2}};
    Solution s;
    s.isBipartite(graph);
}
