#include <queue>
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
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> ans;
        vector<int> row;

        if (root == nullptr)
            return ans;
        q.push(root);
        int n;
        TreeNode *front;
        while (!q.empty())
        {
            n = q.size();
            while (n--)
            {
                front = q.front();
                row.push_back(front->val);
                if (front->left != nullptr)
                    q.push(front->left);
                if (front->right != nullptr)
                    q.push(front->right);
                q.pop();
            }
            if (!row.empty())
            {
                ans.push_back(row[row.size() - 1]);
                row.clear();
            }
        }

        return ans;
    }
};