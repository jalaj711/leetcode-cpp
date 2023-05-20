#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr) return ans;
        vector<int> left = inorderTraversal(root -> left);
        vector<int> right = inorderTraversal(root -> right);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};

int main() {
    Solution s;
    TreeNode left1(6);
    TreeNode right2(5);
    TreeNode right1(4, nullptr, &right2);
    TreeNode root(0, &left1, &right1);

    s.inorderTraversal(&root);
}
