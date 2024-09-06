#include<vector>
#include<unordered_map>
#include<climits>

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
    unordered_map<TreeNode *, vector<int>> mp;
    int recur(TreeNode *root, bool skip, bool hasCover) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return (!skip || !hasCover);

        if (mp.find(root) == mp.end()) mp[root] = {-1, -1, -1};
        if (mp[root][skip+hasCover] != -1) return mp[root][skip+hasCover];

        int pick = 1 + recur(root->left, true, true) + recur(root->right, true, true);
        int notPick = INT_MAX;
        if (skip) {
            if (root->left) notPick = min(notPick, recur(root->left, hasCover, false) + recur(root->right, true, false));
            if (root->right) notPick = min(notPick, recur(root->left, true, false) + recur(root->right, hasCover, false));
        }
        return mp[root][skip+hasCover] = min(pick, notPick);
    }

    int minCameraCover(TreeNode *root) {
        return recur(root, true, false);
    }
};