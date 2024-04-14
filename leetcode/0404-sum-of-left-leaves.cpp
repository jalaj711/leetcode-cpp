struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void dfs(TreeNode *leaf, int *ans, bool isLeft) {
        if (leaf->right == nullptr && leaf->left == nullptr && isLeft) {
            *ans = *ans + leaf->val;
        }
        if (leaf->left != nullptr) dfs(leaf->left, ans, true);
        if (leaf->right != nullptr) dfs(leaf->right, ans, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root) {
        int ans = 0;
        dfs(root, &ans, false);
        return ans;
    }
};