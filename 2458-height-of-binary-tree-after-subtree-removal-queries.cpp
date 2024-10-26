#include<unordered_map>

#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  // mp[i] = level of tree node with val i
  unordered_map<int, int> mp;
  // levels[i] = {max_height_in_level_i, element_with_max_height, second_max_height}
  vector<vector<int>> levels;

  // populates mp and levels in a dfs fashion, returns the height of tree
  // below the given node
  int dfs(TreeNode *root, int level) {
    if (root == nullptr) return -1;

    mp[root->val] = level;
    if (levels.size() <= level) levels.push_back({-1, -1, -1});

    int l = dfs(root->left, level + 1);
    int r = dfs(root->right, level + 1);
    int h = 1 + max(l, r);

    // this is max height
    if (levels[level][0] < h) {
      levels[level][2] = levels[level][0];
      levels[level][0] = h;
      levels[level][1] = root->val;
    } else // this is second max height
    if (levels[level][2] < h) levels[level][2] = h;

    return h;
  }

  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    vector<int> ans(queries.size());
    dfs(root, 0);
    for (int i = 0; i < queries.size(); i++) {
      int level = mp[queries[i]];

      // if this element is the one with max height in its level
      if (levels[level][1] == queries[i])
        // the possibility that there are no neighbours
        /**
         * this part can be skipped
         *  if (levels[level][2] == -1)
         *     ans[i] = level - 1;
         *   else
         */
        ans[i] = level + levels[level][2];
        // this is some other element, so max height remains the same
      else
        ans[i] = level + levels[level][0];

    }
    return ans;
  }
};