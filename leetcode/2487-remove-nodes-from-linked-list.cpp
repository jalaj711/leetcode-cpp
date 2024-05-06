struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
private:
    ListNode* reverseNodes(ListNode* head) {
        if (head -> next == nullptr) return head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head -> next;
        while (next != nullptr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if (head -> next == nullptr) return head;
        head = reverseNodes(head);
        int _max = head -> val;
        ListNode *curr = head->next;
        ListNode *listptr = head;

        while (curr != nullptr) {
            if (curr -> val >= _max) {
                listptr -> next = curr;
                listptr = listptr -> next;
                _max = curr -> val;
            }
            curr = curr -> next;
        }
        listptr -> next = nullptr;
        return reverseNodes(head);
    }
};