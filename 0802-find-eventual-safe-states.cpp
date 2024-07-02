#include <vector>
#include <algorithm>
using namespace std;

enum STATES
{
    UNVISITED,
    IN_PROCESS,
    FINISHED
};
//
//class Solution
//{
//private:
//    void isSafeNode(int node, vector<vector<int>> &graph, vector<STATES> &vis, vector<bool> &safe)
//    {
//        vis[node] = STATES::IN_PROCESS;
//        for (auto it=graph[node].begin();it<graph[node].end();it++)
//        {
//            if (vis[*it] == STATES::IN_PROCESS)
//            {
//
//                safe[node] = false;
//                break;
//            }
//            else if (vis[*it] == STATES::FINISHED)
//            {
//                if (!safe[*it])
//                {
//                    safe[node] = false;
//                    break;
//                }
//            }
//            else
//            {
//                isSafeNode(*it, graph, vis, safe);
//                it--;
//            }
//        }
//        vis[node] = STATES::FINISHED;
//    }
//
//public:
//    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
//    {
//        int n = graph.size();
//        vector<STATES> vis(n, STATES::UNVISITED);
//        vector<bool> safe(n, true);
//
//        for (int i = 0; i < n; i++)
//        {
//            if (!vis[i])
//                isSafeNode(i, graph, vis, safe);
//        }
//
//        vector<int> ans;
//        for (int j = 0; j < n; j++)
//        {
//            if (safe[j])
//                ans.push_back(j);
//        }
//
//        return ans;
//    }
//};

class Solution {
private:
    bool dfs(int i, vector<vector<int>>&graph, vector<bool>&vis,vector<bool>&pathVis, vector<int>&ans) {
        if (pathVis[i]) return false;
        if (vis[i]) return true;
        pathVis[i] = true;
        vis[i] = true;
        for (int j=0;j<graph[i].size();j++) {
            if ((!vis[graph[i][j]]&&!dfs(graph[i][j], graph, vis, pathVis, ans))||pathVis[graph[i][j]]) return false;
        }
        ans.push_back(i);
        pathVis[i] = false;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> pathVis(n, false);
        vector<int> ans;
        for (int i=0;i<n;i++) {
            if (!vis[i]) dfs(i, graph, vis, pathVis, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<vector<int>> q{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution s;
    s.eventualSafeNodes(q);
}
