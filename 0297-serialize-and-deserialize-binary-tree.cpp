#include<string>

#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ans = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front == nullptr)
                ans += "x";
            else {
                ans += to_string(front->val) + ";";
                q.push(front->left);
                q.push(front->right);
            }
        }
        return ans;
    }

    TreeNode * convert(const string &data, int &i) {
        int temp = 0;
        bool isNegative = data[i] == '-';
        i += isNegative;
        for (; data[i] != ';'; i++)
            temp = temp * 10 + (data[i] - '0');
        i++;
        return new TreeNode(temp * (isNegative ? -1 : 1));
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        TreeNode *root = nullptr;
        if (data == "x")
            return root;
        int i = 0;
        root = convert(data, i);
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty() && i < data.size()) {
            auto fr = q.front();
            q.pop();
            if (data[i] == 'x') {
                fr->left = nullptr;
                i++;
            } else {
                fr->left = convert(data, i);
                q.push(fr->left);
            }
            if (data[i] == 'x') {
                fr->right = nullptr;
                i++;
            } else {
                fr->right = convert(data, i);
                q.push(fr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));