#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> ans;
    void recur(Node *root) {
        if (root == nullptr) return;
        for (auto child: root->children) {
            recur(child);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        recur(root);
        return ans;
    }
};