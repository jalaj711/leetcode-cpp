#include<unordered_set>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
  unordered_set<int> st;

  void _recover(TreeNode *root, int x) {
    if (root->left) {
      _recover(root->left, 2 * x + 1);
    }
    if (root->right) {
      _recover(root->right, 2 * x + 2);
    }
    st.insert(x);
  }

  FindElements(TreeNode *root) {
    _recover(root, 0);
  }

  bool find(int target) {
    return st.find(target) != st.end();
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */