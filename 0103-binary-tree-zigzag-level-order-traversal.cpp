#include<vector>
#include<queue>
using namespace  std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        q.push(root);
        bool left = true;
        while(!q.empty()) {
            int n = q.size();
            vector<int> row (n);
            for (int i=0;i<n;i++) {
                TreeNode * front = q.front();
                q.pop();
                if (left) {
                    row[i] = front -> val;
                } else {
                    row[n-i-1] = front->val;
                }
                if (front->left != nullptr) {
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
            ans.push_back(row);
            left = !left;
        }
        return ans;
    }
};