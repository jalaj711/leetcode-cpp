#include<queue>
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
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode *> q;
    q.push(root);

    while(true) {
      auto fr = q.front();
      q.pop();
      if (fr==nullptr) break;
      q.push(fr->left);
      q.push(fr->right);
    }

    while(!q.empty()) {
      if (q.front() != nullptr) return false;
      q.pop();
    }

    return true;
  }
};