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
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        queue<TreeNode *> q;
        if (root != nullptr)
            q.push(root);
        int n;
        TreeNode *front;
        while (!q.empty())
        {
            n = q.size();
            while (n--)
            {
                front = q.front();
                if (front->left != nullptr)
                    q.push(front->left);
                if (front->right != nullptr)
                    q.push(front->right);
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};

int main()
{
    auto root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    Solution s;
    s.maxDepth(root);
}