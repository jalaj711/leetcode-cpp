#include<string>
#include<vector>
#include<queue>
using namespace std;
// Solution 1: Topological sort + DFS
//
// The idea is that first we create a topological sort of the graph,
// then we traverse through this ordering calling dfs on each
// unvisited node. The dfs function takes a state matrix dp. dp[i][c]
// stores the maximum number of times the color c appears from any
// path starting from node i. The base case of the recursion in dfs is
// when we reach the element with zero out-degree. This element will
// have dp[i][c] = 1 where c is it's color and every other value in dp[i]
// will be zero. When the dfs call backtracks from here, we can build the
// max number of colors for each node, finally reaching the top node.
//
//class Solution {
//public:
//  int dfs(int i, vector<vector<int>> &dp, const string &colors, vector<bool> &vis, vector<vector<int>> &adj) {
//    vis[i] = true;
//
//    for(const auto &node: adj[i]) {
//      if (!vis[node]) {
//        dfs(node, dp, colors, vis, adj);
//      }
//
//      for(int j=0;j<26;j++) dp[i][j] = max(dp[i][j], dp[node][j]);
//    }
//    dp[i][colors[i] - 'a']++;
//
//    return *max_element(dp[i].begin(), dp[i].end());;
//  }
//  int largestPathValue(const string &colors, vector<vector<int>>& edges) {
//    int n = colors.size();
//    vector<vector<int>> adj(n);
//    vector<int> indeg(n, 0);
//
//    for(const auto &edge: edges) {
//      adj[edge[0]].push_back(edge[1]);
//      indeg[edge[1]]++;
//    }
//
//    queue<int> q;
//    vector<int> topo;
//
//    for(int i=0;i<n;i++) if (indeg[i] == 0) q.push(i);
//
//    while(!q.empty()) {
//      int node = q.front();
//      q.pop();
//      // cout << "process " << node << endl;
//      topo.push_back(node);
//      for(const auto &child: adj[node]) {
//        if (--indeg[child] == 0) q.push(child);
//      }
//    }
//
//    if (topo.size() != n) return -1;
//    vector<bool> vis (n, false);
//    vector<vector<int>> dp(n, vector<int>(26, 0));
//
//    int lsize = INT_MIN;
//    for(int i=0;i<n;i++) {
//      if (!vis[topo[i]]) {
//        lsize = max(lsize, dfs(topo[i], dp, colors, vis, adj));
//      }
//    }
//
//    return lsize;
//  }
//};

// Solution 2: Modified Topological sort
//
// The idea here is similar to the previous solution. Start from the end node
// and count the maximum number of times a color appears for any path starting
// from each node. However, we use an optimisation to completely eliminate the
// need of a DFS. To do this, we reverse the graph. The adj matrix is now
// reversed and the indeg array stores the in-degrees of the reversed matrix
// now we apply topological sort again and this time while adding each element
// we update the count of colors in it's dp[i] array.
//
class Solution {
public:
  int largestPathValue(const string &colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    // create a reversed adj
    for(const auto &edge: edges) {
      adj[edge[1]].push_back(edge[0]);
      indeg[edge[0]]++;
    }

    queue<int> q;
    vector<vector<int>> dp(n, vector<int>(26, 0));

    for(int i=0;i<n;i++) if (indeg[i] == 0) q.push(i);

    int lsize = 0;
    while(!q.empty()) {
      int node = q.front();
      q.pop();
      dp[node][colors[node]-'a']++;
      // check if we have a max size
      for(int j=0;j<26;j++) {
        lsize = max(lsize, dp[node][j]);
      }

      for(const auto &child: adj[node]) {
        if (--indeg[child] == 0) q.push(child);
        // update colors while doing topological sort
        for(int j=0;j<26;j++) {
          dp[child][j] = max(dp[child][j], dp[node][j]);
        }
      }
    }

    // if any element still as some in degree then we have a
    // cycle in the graph
    for(int i=0;i<n;i++) if(indeg[i] > 0) return -1;

    return lsize;
  }
};