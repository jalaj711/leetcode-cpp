#include<vector>
#include<string>

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
    vector<TreeNode *> depth;

    void insert(int val, int d) {
        auto node = new TreeNode(val);
        auto parent = depth[d - 1];
        if (parent->left != nullptr) parent->right = node;
        else parent->left = node;
        if (depth.size() <= d) depth.push_back(node);
        else depth[d] = node;
    }

    int convert(const string &traversal, int &i) {
        int temp = 0;
        while (i < traversal.size() && traversal[i] != '-') {
            temp = temp * 10 + (traversal[i] - '0');
            i++;
        }
        return temp;
    }

    TreeNode *recoverFromPreorder(string traversal) {
        int i = 0;
        auto root = new TreeNode(convert(traversal, i));
        depth.push_back(root);
        int d;
        while (i < traversal.size()) {
            d = 0;
            while (traversal[i] == '-') {
                d++;
                i++;
            }
            insert(convert(traversal, i), d);
        }
        return root;
    }
};