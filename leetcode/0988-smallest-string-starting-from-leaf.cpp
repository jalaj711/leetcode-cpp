#include<vector>
#include<string>
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
private:
    string best_path;

    void dfs(TreeNode *root, string path) {
        path.push_back('a'+root->val);
        if (root->left == nullptr && root->right == nullptr) {
            reverse(path.begin(), path.end());
            if (best_path.empty() || path < best_path) {
                string nPath = path;
                best_path = nPath;
            }
            reverse(path.begin(), path.end());
        }
        if (root->left != nullptr) dfs(root->left, path);
        if (root->right != nullptr) dfs(root->right, path);
    }

public:
    string smallestFromLeaf(TreeNode *root) {
        if (root == nullptr) return "";
        dfs(root, "");
        return best_path;
    }
};

int main() {
    auto rr = new TreeNode(2);
    auto ll = new TreeNode(0);
    auto rl = new TreeNode(1, rr, nullptr);
    auto lr = new TreeNode(0);
    auto l = new TreeNode(1, nullptr, lr);
    auto r = new TreeNode(2, rl, nullptr);
    auto root = new TreeNode(2, l, r);

    Solution s;
    s.smallestFromLeaf(root);
    delete ll;
    delete lr;
    delete rl;
    delete rr;
    delete l;
    delete r;
    delete root;
}
