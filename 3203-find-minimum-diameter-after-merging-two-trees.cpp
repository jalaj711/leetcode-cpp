#include<vector>

using namespace std;

class Solution {
public:

  // dfs 1: calculate the second biggest and biggest paths from each node and also
  // calculate the diameter of the tree from this node

  // dia = max diameter till now
  // maxEdge = pointer to array of pair<edge of max distance, second-biggest distance> for each node
  int dfs(vector<int> *adj, int node, int par, int *dia, pair<int, int> *maxEdge) {

    int maxD = 0, sMaxD = 0, maxE = -1;

    for (const auto &n: adj[node]) {
      if (n != par) {
        int dis = dfs(adj, n, node, dia, maxEdge) + 1;

        if (dis >= maxD) {
          sMaxD = maxD;
          maxD = dis;
          maxE = n;
        } else if (dis >= sMaxD) {
          sMaxD = dis;
        }
      }
    }

    (*dia) = max(*dia, maxD + sMaxD);
    maxEdge[node] = {maxE, sMaxD};

    return maxD;
  }

  // dfs 2: find the node which can be the center for our join and the distance of this
  // node with the farthest node. minimise this farthest distance. takes into account the
  // nodes along the parent edge.

  // parD = distance to farthest edge from the parent side
  // minD = pointer to minimum maximum distance from any node
  int dfs2(vector<int> *adj, int node, int parD, int *minD, pair<int, int> *maxEdge) {

    int maxDis = 0;
    if (maxEdge[node].first != -1) {
      maxDis = max(
          // the furthest distance on parent side for our child can either be the distance from
          // our parent side (parD) or some other child which has more length (this is given by maxEdge)
          dfs2(adj, maxEdge[node].first, max(parD, maxEdge[node].second) + 1, minD, maxEdge) + 1,
          maxDis
      );
    }

    // maxDis counts the max distance towards children. max distance towards parents is parD
    // so combine them.
    (*minD) = min(*minD, max(maxDis, parD));

    return maxDis;
  }

  // performs two dfs to find out two values:
  // 1. the node to which the edge should be connected for merger. this node is such
  //    that this node minimises the maximum distance to any node in the tree.
  // 2. the diameter of the tree.
  pair<int, int> solve(vector<vector<int>> &edges) {
    int n = edges.size() + 1;
    vector<int> adj[n];

    for (const auto &e: edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int maxD = 0, sMaxD = 0, maxE = -1, dia = 0;
    int *diaP = &dia;

    pair<int, int> maxEdge[n];

    for (const auto &node: adj[0]) {
      int dis = dfs(adj, node, 0, diaP, maxEdge) + 1;
      if (dis >= maxD) {
        sMaxD = maxD;
        maxD = dis;
        maxE = node;
      } else if (dis >= sMaxD) {
        sMaxD = dis;
      }
    }

    maxEdge[0] = {maxE, sMaxD};

    dia = max(dia, maxD + sMaxD);
    int ans = maxD;
    int *ansP = &ans;

    if (maxE != -1)
      dfs2(adj, maxE, sMaxD + 1, ansP, maxEdge);

    return {ans, dia};
  }

  int minimumDiameterAfterMerge(vector<vector<int>> &e1, vector<vector<int>> &e2) {
    auto d1 = solve(e1);
    auto d2 = solve(e2);

    // answer is either:
    // 1. the furthest node from connection point in tree 1 +
    //    furthest node from connection point in tree 2 +
    //    1
    // 2. Diameter of tree 1
    // 3. Diameter of tree 2
    int ans = d1.first + d2.first + 1;
    ans = max(ans, d1.second);
    ans = max(ans, d2.second);

    return ans;
  }
};