#include<climits>

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
  int a = 0;

  // vector<int> path;
  void dfs(TreeNode *root, int t, bool s) {
    if (root == nullptr) return;
    if (root->val == t) {
      a++;
      // cout << "match " << root->val << "targ=" << t << "path=";
      // for (int i:path) {
      //     cout << i << ", ";
      // }
      // cout << endl;
    }
    if (s) {
      dfs(root->left, t, true);
      dfs(root->right, t, true);
    }
    // path.push_back(root->val);
    if (root->val < 0 && t > INT_MAX + root->val) return;
    if (root->val > 0 && t < INT_MIN + root->val) return;
    dfs(root->left, t - root->val, false);
    dfs(root->right, t - root->val, false);
    // path.pop_back();
  }

  int pathSum(TreeNode *root, int targetSum) {
    dfs(root, targetSum, true);

    return a;
  }
};