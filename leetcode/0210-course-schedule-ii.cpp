#include<vector>

using namespace std;

class Solution {
private:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &indegrees, vector<int>&ans) {
        indegrees[i] = -1;
        ans.push_back(i);
        for (auto j: adj[i]) {
            if (indegrees[j]>0&&(--indegrees[j] == 0)) {
                dfs(j, adj, indegrees, ans);
            }
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>{});
        vector<int> indegrees(numCourses, 0);
        for (auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegrees[it[0]]++;
        }
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                dfs(i, adj, indegrees, ans);
            }
        }
        if (ans.size()==adj.size())
            return ans;
        return {};
    }
};


int main() {
//    vector<vector<int>> q {{1,0},{2,1}};
    vector<vector<int>> q{{1, 4},
                          {2, 4},
                          {3, 1},
                          {3, 2}};
    Solution s;
    s.findOrder(5, q);
}
