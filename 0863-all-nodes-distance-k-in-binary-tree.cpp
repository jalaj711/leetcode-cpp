#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

  // return 0 if target not found, 1 if found
  int dfs(TreeNode *root, TreeNode *target, vector<TreeNode *> &path) {
    if (root == nullptr) return 0;

    path.push_back(root);
    if (root == target) return 1;

    int l = dfs(root->left, target, path);
    int r = dfs(root->right, target, path);
    if (l || r) return 1;
    path.pop_back();
    return 0;
  }

  void handleBelow(TreeNode *root, int l, int k, vector<int> &path) {
    if (root == nullptr) return;

    if (l == k) {
      path.push_back(root->val);
      return;
    }

    handleBelow(root->left, l + 1, k, path);
    handleBelow(root->right, l + 1, k, path);
  }

  void handleAbove(int idx, int l, int k, vector<TreeNode *> &parents, vector<int> &path) {
    if (idx < 0) return;
    if (l == k) {
      path.push_back(parents[idx]->val);
      return;
    }

    if (parents[idx]->left == parents[idx + 1]) {
      handleBelow(parents[idx]->right, l + 1, k, path);
    } else {
      handleBelow(parents[idx]->left, l + 1, k, path);
    }

    handleAbove(idx - 1, l + 1, k, parents, path);
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    vector<TreeNode *> parents;

    // search for the parents of target
    dfs(root, target, parents);

    vector<int> path;

    // handle the nodes that are chldren of target
    handleBelow(target, 0, k, path);

    // handle the nodes that are parents of target
    if (parents.size() >= 2)
      handleAbove(parents.size() - 2, 1, k, parents, path);

    return path;
  }
};