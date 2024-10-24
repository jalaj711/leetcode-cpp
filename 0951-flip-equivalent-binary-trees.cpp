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
  bool solve(TreeNode *root1, TreeNode *root2) {
    if ((root1 == nullptr) ^ (root2 == nullptr)) return false;
    if ((root1 == nullptr) & (root2 == nullptr)) return true;
    if (root1->val != root2->val) return false;

    bool doSwap = false;

    if ((root1->left == nullptr) ^ (root2->left == nullptr)) doSwap = true;
    else if (root1->left == root2->left) doSwap = false;
    else if (root1->left->val != root2->left->val) doSwap = true;

    if (doSwap) return solve(root1->left, root2->right) && solve(root1->right, root2->left);
    return solve(root1->left, root2->left) && solve(root1->right, root2->right);
  }

  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    return solve(root1, root2);
  }
};