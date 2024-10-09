#include <algorithm>

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
  TreeNode *ans;
  int maxDepth;

  int dfs(TreeNode *root, int d) {
    int l = d;
    if (root->left) l = dfs(root->left, d + 1);
    int r = d;
    if (root->right) r = dfs(root->right, d + 1);

    if ((l == r && l >= maxDepth) || (l == d && r > maxDepth) || (r == d && l > maxDepth)) ans = root;
    maxDepth = max(maxDepth, max(l, r));
    return max(l, r);
  }

  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    maxDepth = 0;
    ans = root;
    dfs(root, 0);
    return ans;
  }
};