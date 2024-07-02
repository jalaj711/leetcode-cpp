
#include<vector>
#include<map>

using namespace std;

class Solution {
private:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &indegrees, map<int, int>&order) {
        indegrees[i] = -1;
        order[i] = order.size();
        for (auto j: adj[i]) {
            if (indegrees[j]>0&&(--indegrees[j] == 0)) {
                dfs(j, adj, indegrees, order);
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses, vector<int>{});
        vector<int> indegrees(numCourses, 0);
        for (auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegrees[it[0]]++;
        }
        map<int, int> order;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                dfs(i, adj, indegrees, order);
            }
        }
        vector<bool> ans;
        for (auto it: queries) {
            if (order[it[0]]>order[it[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};


int main() {
//    vector<vector<int>> q {{1,0},{2,1}};
    vector<vector<int>> q{{1, 4},
                          {2, 4},
                          {3, 1},
                          {3, 2}};
    Solution s;
//    s.checkIfPrerequisite(5, q);
}
