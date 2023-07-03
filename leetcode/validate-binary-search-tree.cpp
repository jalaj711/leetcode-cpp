struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long int MIN = -2147483649;
long long int MAX = -MIN-1;

class Solution
{
public:
    bool validateSubTree(TreeNode *root, long long int ll, long long int ul)
    {

        if (root == nullptr)
            return true;
        if (
            root->left != nullptr && (
                (root->left)->val >= root->val ||
                (root->left)->val <= ll ||
                (root->left)->val >= ul || 
                !validateSubTree(root->left, ll, root->val)
            )
        )
            return false;
        if (
            root->right != nullptr && (
                (root->right)->val <= root->val ||
                (root->right)->val <= ll ||
                (root->right)->val >= ul ||
                !validateSubTree(root->right, root->val, ul)
            )
        )
            return false;
        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (
            root->left != nullptr && (
                (root->left)->val >= root->val ||
                !validateSubTree(root->left, MIN, root->val)
            )
        )
            return false;
        if (
            root->right != nullptr && (
                (root->right)->val <= root->val ||
                !validateSubTree(root->right, root->val, MAX)
            )
        )
            return false;
        return true;
    }
};

int main() {
    TreeNode rl(3);
    TreeNode rr(78);
    TreeNode r(49, nullptr, &rr);
    TreeNode l(1);
    TreeNode root(-59, nullptr, &r);
    Solution s;
    s.isValidBST(&root);
}
