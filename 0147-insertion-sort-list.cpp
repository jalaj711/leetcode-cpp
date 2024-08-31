struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *nxt      = head->next,
                 *crr      = head,
                 *prev     = nullptr,
                 *curr     = nullptr,
                 *sortHead = nullptr,
                 *sortTail = nullptr;

        // crr is the pointer of the current element being inserted
        while (crr != nullptr) {

            // either the element is the first one or the smallest one
            if (sortHead == nullptr || sortTail == nullptr || crr->val < sortHead->val) {
                crr->next = sortHead;
                sortHead = crr;
                if (sortTail == nullptr) sortTail = crr;
            }

                // insert to tail
            else if (crr->val >= sortTail->val) {
                sortTail->next = crr;
                crr->next = nullptr;
                sortTail = crr;
            }

                // insert in the middle
            else {

                // start searching linked list from the sorted part
                prev = sortHead;
                curr = sortHead->next;
                while (curr != sortTail->next && curr) {

                    // insert into correct position if a match is found
                    if (crr->val <= curr->val) {
                        prev->next = crr;
                        crr->next = curr;
                        break;
                    }
                    prev = curr;
                    curr = curr->next;
                }
            }

            // move to the next element;
            crr = nxt;
            if (crr) nxt = crr->next;
        }
        return sortHead;
    }
};