#include<climits>
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
    int maxSum = LONG_MIN;

    pair<long, pair<int, int>> isBST(TreeNode *root) {
        if (root == nullptr) return {LONG_MIN, {0, 0}};
        if ((root->left == nullptr) && (root->right == nullptr)) {
            maxSum = max(maxSum, root->val);
            return {root->val, {root->val, root->val}};
        }
        auto left = isBST(root->left);
        auto right = isBST(root->right);
        if (root->left == nullptr) {
            if (right.first == LONG_MIN || right.second.first <= root->val) return {LONG_MIN, {0, 0}};
            maxSum = max(maxSum, root->val + (int) right.first);
            return {root->val + (int) right.first, {root->val, right.second.second}};
        }
        if (root->right == nullptr) {
            if (left.first == LONG_MIN || left.second.second >= root->val) return {LONG_MIN, {0, 0}};
            maxSum = max(maxSum, root->val + (int) left.first);
            return {root->val + (int) left.first, {left.second.first, root->val}};
        }
        if (
                left.first == LONG_MIN ||
                right.first == LONG_MIN ||
                left.second.second >= root->val ||
                right.second.first <= root->val
                )
            return {LONG_MIN, {0, 0}};

        maxSum = max(maxSum, root->val + (int) left.first + (int) right.first);
        return {root->val + (int) left.first + (int) right.first, {left.second.first, right.second.second}};
    }

public:
    int maxSumBST(TreeNode *root) {
        isBST(root);
        return maxSum;
    }
};