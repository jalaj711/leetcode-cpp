#include<vector>

using namespace std;

class Solution {
private:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &indegrees) {
        indegrees[i] = -1;
        for (auto j: adj[i]) {
            if (indegrees[j]>0&&(--indegrees[j] == 0)) {
                dfs(j, adj, indegrees);
            }
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>{});
        vector<int> indegrees(numCourses, 0);
        for (auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegrees[it[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                dfs(i, adj, indegrees);
            }
        }
        for (auto i: indegrees) {
            if (i > 0)return false;
        }
        return true;
    }
};

int main() {
//    vector<vector<int>> q {{1,0},{2,1}};
    vector<vector<int>> q{{1, 4},
                          {2, 4},
                          {3, 1},
                          {3, 2}};
    Solution s;
    s.canFinish(5, q);
}
