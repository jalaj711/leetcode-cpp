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

//BFS Solution
//class Solution {
//public:
//  int goodNodes(TreeNode *root) {
//    int count = 0;
//    queue<pair<TreeNode *, int>> q;
//    q.push({root, root->val});
//    while (!q.empty()) {
//      int n = q.size();
//      while (n--) {
//        auto fr = q.front();
//        q.pop();
//
//        if (fr.first->val >= fr.second) count++;
//        if (fr.first->left) q.push({fr.first->left, max(fr.second, fr.first->val)});
//        if (fr.first->right) q.push({fr.first->right, max(fr.second, fr.first->val)});
//      }
//    }
//    return count;
//  }
//};

// DFS Solution
class Solution {
public:
  int count(TreeNode* root, int mval) {
    if (root == nullptr) return 0;
    return (mval <= root->val) + count(root->left, max(mval, root->val)) + count(root->right, max(mval, root->val));
  }
  int goodNodes(TreeNode* root) {
    return count(root, root->val);
  }
};