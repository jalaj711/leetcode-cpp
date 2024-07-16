#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
private:
    string srcPath = "";
    string dstPath = "";
    bool srcFound = false;
    bool dstFound = false;
    int src = 0;
    int dst = 0;

    void dfs(TreeNode *root) {
        if (root->val == src)
            srcFound = true;
        if (root->val == dst)
            dstFound = true;

        if (root->left != nullptr) {
            if (!srcFound)
                srcPath += "L";
            if (!dstFound)
                dstPath += "L";
            if (!srcFound || !dstFound)
                dfs(root->left);
            if (!srcFound)
                srcPath.pop_back();
            if (!dstFound)
                dstPath.pop_back();
        }
        if (root->right != nullptr) {

            if (!srcFound)
                srcPath += "R";
            if (!dstFound)
                dstPath += "R";
            if (!srcFound || !dstFound)
                dfs(root->right);
            if (!srcFound)
                srcPath.pop_back();
            if (!dstFound)
                dstPath.pop_back();
        }
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue) {
        src = startValue;
        dst = destValue;
        dfs(root);
        int i = 0;
        while (i < srcPath.size() && i < dstPath.size() &&
               srcPath[i] == dstPath[i])
            i++;
        string ans = "";
        for (int j = i; j < srcPath.size(); j++) {
            ans += "U";
        }
        for (int j = i; j < dstPath.size(); j++) {
            ans += dstPath[j];
        }
        return ans;
    }
};