#include<queue>

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
  int maxLevelSum(TreeNode *root) {
    int ls = 0,
        mx = INT_MIN,
        mi = 0,
        lv = 1;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      ls = 0;
      while (n--) {
        TreeNode *fr = q.front();
        q.pop();

        ls += fr->val;
        if (fr->left) q.push(fr->left);
        if (fr->right) q.push(fr->right);
      }
      if (ls > mx) {
        mx = ls;
        mi = lv;
      }
      lv++;
    }
    return mi;
  }
};