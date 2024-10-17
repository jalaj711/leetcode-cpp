
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  bool dfs(TreeNode * root, int limit) {
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right==nullptr) return limit > root->val;

    limit -= root->val;

    bool l = dfs(root->left, limit);
    if (l) root->left = nullptr;

    bool r = dfs(root->right, limit);
    if (r) root->right = nullptr;

    return l && r;
  }
public:
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    if (dfs(root, limit)) return nullptr;
    return root;
  }
};