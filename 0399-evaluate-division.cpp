#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
  unordered_map<string, vector<pair<string, double>>> adj;
  // save the variables currently in progress
  unordered_set<string> proc;

  double solve(const string &start, const string &target) {
    if (start == target) return 1.0;
    proc.insert(start);

    double ans = -1.0;

    for(const auto &child: adj[start]) {
      if (proc.find(child.first) != proc.end()) continue;
      if (child.first == target) {
        ans = child.second;
        break;
      }

      // dfs
      if ((ans = solve(child.first, target)) != -1.0) {
        ans *= child.second;
        break;
      }
    }

    proc.erase(start);
    return ans;
  }

  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int n = equations.size();

    // form the graph using the hash map
    for (int i=0;i<n;i++) {
      adj[equations[i][0]].push_back({equations[i][1], values[i]});
      adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
    }

    vector<double> ans;

    for (const auto &query: queries) {

      // if any one variable doesn't exist, then answer is -1
      if (adj.find(query[0]) == adj.end() || adj.find(query[1]) == adj.end()) {
        ans.push_back(-1.0);
        continue;
      }

      ans.push_back(solve(query[0], query[1]));
    }

    return ans;
  }
};