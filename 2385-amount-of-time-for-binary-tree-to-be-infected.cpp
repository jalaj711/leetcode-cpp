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
  int maxT = -1;

  int dfs(TreeNode *root, int start, int t) {
    if (root == nullptr) return 0;

    int l = dfs(root->left, start, t + 1);
    int r = dfs(root->right, start, t + 1);

    if (root->val == start) {
      maxT = max(maxT, max(l, r) - t);
      return -1;
    }

    int neg = 0, oth;
    if (l < 0) {
      neg = l;
      oth = r;
    }
    else if (r < 0) {
      neg = r;
      oth = l;
    }

    if (neg) {
      maxT = max(maxT, -neg);
      maxT = max(maxT, oth - t - neg);
      return neg - 1;
    }

    if (r == 0 && l == 0) return t;

    return max(l, r);
  }

  int amountOfTime(TreeNode *root, int start) {
    dfs(root, start, 0);
    return maxT;
  }
};