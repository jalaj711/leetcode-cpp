struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        head = head->next;
        ListNode *curr = head->next;
        ListNode *ptr = head;
        while (curr != nullptr) {
            if (curr->val != 0) ptr->val += curr->val;
            else if (curr->next == nullptr) ptr->next = nullptr;
            else {
                ptr = ptr->next;
                ptr->val = 0;
            }
            curr = curr->next;
        }
        return head;
    }
};