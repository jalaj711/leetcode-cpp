#include<unordered_map>
#include<vector>

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
    unordered_map<int, TreeNode*> mp;
    void dfs(TreeNode* root) {
        if (root->left != nullptr) {
            dfs(root->left);
            mp.erase((root->left)->val);
        }
        if (root->right != nullptr) {
            dfs(root->right);
            mp.erase((root->right)->val);
        }
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* parent;
        TreeNode* child;
        for (auto desc : descriptions) {
            if (mp.find(desc[0]) != mp.end())
                parent = mp[desc[0]];
            else {
                parent = new TreeNode(desc[0]);
                mp[desc[0]] = parent;
            }
            if (mp.find(desc[1]) != mp.end())
                child = mp[desc[1]];
            else {
                child = new TreeNode(desc[1]);
                mp[desc[1]] = child;
            }
            if (desc[2])
                parent->left = child;
            else
                parent->right = child;
        }
        for (auto i : mp) {
            dfs(i.second);
        }
        TreeNode* root;
        for (auto i : mp) {
            root = i.second;
        }
        return root;
    }
};