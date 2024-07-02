#include <queue>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root == nullptr)
            return root;
        root->next = nullptr;
        if (root->left != nullptr)
        {
            q.push((root->left));
            q.push((root->right));
        }
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *curr = q.front();
                q.pop();
                if (!q.empty() && n)
                    curr->next = q.front();
                else
                    curr->next = nullptr;
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};