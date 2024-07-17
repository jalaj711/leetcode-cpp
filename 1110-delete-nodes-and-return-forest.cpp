#include "vector"

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
    vector<TreeNode *> forest;

    bool handleDelete(TreeNode *root, int target) {
        bool flag = false;
        if (root->left != nullptr) {
            if ((root->left)->val == target) {
                if ((root->left)->left != nullptr)
                    forest.push_back((root->left)->left);
                if ((root->left)->right != nullptr)
                    forest.push_back((root->left)->right);
                root->left = nullptr;
            } else {
                flag = handleDelete(root->left, target);
            }
        }

        if (!flag && root->right != nullptr) {
            if ((root->right)->val == target) {
                if ((root->right)->left != nullptr)
                    forest.push_back((root->right)->left);
                if ((root->right)->right != nullptr)
                    forest.push_back((root->right)->right);
                root->right = nullptr;
            } else {
                flag = handleDelete(root->right, target);
            }
        }

        return flag;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        forest.push_back(root);
        for (auto target: to_delete) {
            for (int i = 0; i < forest.size(); i++) {
                if (forest[i]->val == target) {
                    if (forest[i]->left != nullptr)
                        forest.push_back(forest[i]->left);
                    if (forest[i]->right != nullptr)
                        forest.push_back(forest[i]->right);
                    forest.erase(forest.begin() + i);
                } else if (handleDelete(forest[i], target))
                    break;
            }
        }
        return forest;
    }
};