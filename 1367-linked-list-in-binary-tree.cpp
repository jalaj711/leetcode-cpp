struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool match(ListNode *head, TreeNode *root) {
        if (head == nullptr) return true;
        if (root == nullptr || root->val != head->val) return false;
        return match(head->next, root->left) || match(head->next, root->right);
    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        if (root == nullptr || head == nullptr) return false;
        if (head->val == root->val && match(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};