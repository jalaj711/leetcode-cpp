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
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (root == nullptr || depth == 1) {
            TreeNode *newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        queue<TreeNode *> q;
        q.push(root);
        int d = 2;
        int sz;
        TreeNode *fr;
        while (!q.empty() && d < depth) {
            sz = q.size();
            while (sz--) {
                fr = q.front();
                q.pop();
                if (fr->left != nullptr) q.push(fr->left);
                if (fr->right != nullptr) q.push(fr->right);
            }
            d++;
        }
        while (!q.empty()) {
            fr = q.front();
            q.pop();
            TreeNode *left = new TreeNode(val, fr->left, nullptr);
            fr->left = left;
            TreeNode *right = new TreeNode(val, nullptr, fr->right);
            fr->right = right;
        }

        return root;
    }
};

int main() {
    auto ll = new TreeNode(3);
    auto lr = new TreeNode(1);
    auto rl = new TreeNode(5);
    auto l = new TreeNode(2, ll, lr);
    auto r = new TreeNode(6, rl, nullptr);
    auto root = new TreeNode(4, l, r);

    Solution s;
    s.addOneRow(root, 1, 4);
    delete ll;
    delete lr;
    delete rl;
    delete l;
    delete r;

}
