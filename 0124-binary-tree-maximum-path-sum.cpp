#include<climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
    int maxSum;

    int recur(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        int ans = max(root->val, root->val + max(left, right));
        maxSum = max(maxSum, max(ans, root->val + left + right));
        return ans;
    }

public:
    int maxPathSum(TreeNode *root) {
        maxSum = INT_MIN;
        return max(maxSum, recur(root));
    }
};