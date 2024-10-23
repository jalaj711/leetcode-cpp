#include<utility>
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
  TreeNode* replaceValueInTree(TreeNode* root) {
    queue<pair<TreeNode *, int>> q;
    int levelSum = root->val,
        nextLevelSum = 0;

    q.push({root, root->val});
    while(!q.empty()) {
      int n = q.size();
      nextLevelSum = 0;
      while(n--) {
        TreeNode *node = q.front().first;
        int groupSum = q.front().second;
        q.pop();

        node -> val = levelSum - groupSum;

        int sum = 0;
        if (node->left) {
          nextLevelSum += node->left->val;
          sum += node->left->val;
        }
        if (node->right) {
          nextLevelSum += node->right->val;
          sum += node->right->val;
        }

        if (node->left) q.push({node->left, sum});
        if (node->right) q.push({node->right, sum});
      }
      levelSum = nextLevelSum;
    }

    return root;
  }
};