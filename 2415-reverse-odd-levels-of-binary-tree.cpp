#include<queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

class Solution {
public:
  TreeNode *reverseOddLevels(TreeNode *root) {
    int ptr = 0;
    int lvl = 0;

    TreeNode *level[1LL << 13];
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      while (n--) {
        TreeNode *fr = q.front();
        q.pop();
        if (fr->left) {
          q.push(fr->left);
          q.push(fr->right);
        }
        if (lvl % 2) {
          level[ptr++] = fr;
        }
      }

      if (lvl % 2) {
        for (int i = 0; i < ptr / 2; i++) {
          swap(level[i]->val, level[ptr - i - 1]->val);
        }
      }

      lvl++;
      ptr = 0;
    }

    return root;
  }
};
