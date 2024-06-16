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
    int sum = 0;

    void traverse(TreeNode *root) {
        if (root == nullptr) return;
        if (root->right != nullptr) traverse(root->right);
        sum += root->val;
        root->val = sum;
        if (root->left != nullptr) traverse(root->left);
    }

public:
    TreeNode *bstToGst(TreeNode *root) {
        traverse(root);
        return root;
    }
};