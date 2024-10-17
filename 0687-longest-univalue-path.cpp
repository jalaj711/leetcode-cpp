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
  int ans = 0;

  int dfs(TreeNode *root) {
    if (root == nullptr) return 0;
    int a = 1;
    int l = dfs(root->left);
    int r = dfs(root->right);
    int ret = a;

    if (root->left && root->left->val == root->val) {
      a += l;
      ret = a;
    }
    if (root->right && root->right->val == root->val) {
      ret = max(a, 1 + r);
      a += r;
    }

    ans = max(ans, a);
    return ret;
  }

  int longestUnivaluePath(TreeNode *root) {
    if (root == nullptr) return 0;
    dfs(root);
    return ans - 1;
  }
};