#include<vector>
#include<string>

using namespace std;

struct Node {
    char val;
    vector<Node *> children;

    Node(char ch) : val(ch) {}
};

class Solution {
public:
    int maxAns = 0;

    int dfs(Node *root) {
        if (root == nullptr)
            return 0;

        int mx1 = 0, // child with max length
        mx2 = 0,  // child with second max length
        n = (root->children).size();

        for (int i = 0; i < n; i++) {
            int v = dfs((root->children)[i]);
            if (
                    (root->children)[i] != nullptr &&
                    (root->children)[i]->val != root->val
                    ) {
                // update max length
                if (v > mx1) {
                    mx2 = mx1;
                    mx1 = v;
                } else if (v > mx2)
                    // update second max length
                    mx2 = v;
            }

        }

        // if the answer subtree is rooted at this node
        maxAns = max(maxAns, 1 + mx1 + mx2);

        // if the answer subtree is rooted at the node above it
        return 1 + mx1;
    }

    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        auto nodes = new vector<Node *>(n, nullptr);
        Node *root = nullptr;

        // generate the tree
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = new Node(s[i]);
                (*nodes)[i] = root;
            } else {
                auto par = (*nodes)[parent[i]];
                if (par == nullptr) {
                    par = new Node(s[parent[i]]);
                    (*nodes)[parent[i]] = par;
                }
                auto self = (*nodes)[i];
                if (self == nullptr) {
                    self = new Node(s[i]);
                    (*nodes)[i] = self;
                }
                (par->children).push_back(self);
            }
        }
        // not needed anymore
        delete nodes;

        dfs(root);
        return maxAns;
    }
};