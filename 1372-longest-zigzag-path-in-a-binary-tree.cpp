int max(int a, int b) {
  return a > b ? a : b;
}

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
  int maxPath = 0;

  // this function returns the longest zigzag path
  // including this node, prev_l is true is this node
  // is the left node of its parent, false otherwise.
  int dfs(TreeNode *root, bool prev_l) {
    if (root == nullptr) return 0;

    int l = 1+dfs(root->left, true);
    int r = 1+dfs(root->right, false);

    // this will update maxPath if a path starting from
    // this node has more length than the parent node
    maxPath = max(maxPath, max(l, r));

    if (prev_l) return r;
    return l;
  }

  int longestZigZag(TreeNode* root) {
    dfs(root, false);

    return maxPath-1;
  }
};