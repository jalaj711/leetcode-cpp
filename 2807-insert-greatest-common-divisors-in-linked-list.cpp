struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *temp = head;
        while (temp->next != nullptr) {
            auto node = new ListNode(gcd(temp->val, temp->next->val), temp->next);
            temp->next = node;
            temp = node->next;
        }
        return head;
    }
};