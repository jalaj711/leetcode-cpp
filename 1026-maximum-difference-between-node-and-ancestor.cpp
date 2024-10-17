#include<algorithm>

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
  int ans;
  void dfs(TreeNode *root, int ma, int mi) {
    if (root == nullptr) return;

    ans = max(ans, abs(ma-root->val));
    ans = max(ans, abs(mi-root->val));

    ma = max(ma, root->val);
    mi = min(mi, root->val);

    dfs(root->left, ma, mi);
    dfs(root->right, ma, mi);
  }
  int maxAncestorDiff(TreeNode* root) {
    if (root->left) {
      dfs(root->left, max(root->val, root->left->val), min(root->val, root->left->val));
    }
    if (root->right) {
      dfs(root->right, max(root->val, root->right->val), min(root->val, root->right->val));
    }
    return ans;
  }
};