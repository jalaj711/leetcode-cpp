#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

//class Solution {
//    int recur(TreeNode *root, bool canRob) {
//        if (root == nullptr) return 0;
//        if (canRob) {
//            int skip = recur(root->left, canRob) + recur(root->right, canRob);
//            int rob = root->val + recur(root->left, false) + recur(root->right,false);
//            return max(skip, rob);
//        }
//        return recur(root->left, true) + recur(root->right, true);
//    }
//public:
//    int rob(TreeNode* root) {
//        return recur(root, true);
//    }
//};


//class Solution {
//    int recur(TreeNode *root, bool canRob, unordered_map<TreeNode*, pair<int, int>> &memo) {
//        if (root == nullptr) return 0;
//        pair<int, int> p {-1, -1};
//        if (memo.find(root) != memo.end()){
//            if (canRob ? memo[root].first != -1 : memo[root].second != -1)
//                return (canRob ? memo[root].first : memo[root].second);
//            else if (canRob) {
//                p.second = memo[root].second;
//            } else {
//                p.first = memo[root].first;
//            }
//        }
//        if (canRob) {
//            int skip = recur(root->left, canRob, memo) + recur(root->right, canRob, memo);
//            int rob = root -> val + recur(root->left, false, memo) + recur(root->right, false, memo);
//            p.first = max(skip, rob);
//            memo[root] = p;
//            return p.first;
//        }
//        p.second =  recur(root->left, true, memo) + recur(root->right, true, memo);;
//        memo[root] = p;
//        return p.second;
//    }
//public:
//    int rob(TreeNode* root) {
//        unordered_map<TreeNode*, pair<int, int>> memo;
//        return recur(root, true, memo);
//    }
//};


class Solution {
    pair<int, int> recur(TreeNode* root) {
        pair<int, int> p{0, 0};
        if (root == nullptr)
            return p;
        auto left = recur(root->left);
        auto right = recur(root->right);
        p.first = root->val + left.second + right.second;
        p.second =
                max(left.first, left.second) + max(right.first, right.second);
        return p;
    }

public:
    int rob(TreeNode* root) {
        auto ans = recur(root);
        return max(ans.first, ans.second);
    }
};