#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode *> nodes;
        while(head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        return nodes[nodes.size() / 2];
    }
};

class Solution2 {
    public:
    ListNode* middleNode(ListNode* head) {
        ListNode* elem = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next !== NULL && ((fast -> next) -> next) != NULL) {
            elem = elem -> next;
            fast = ((fast -> next) -> next);
        }
        return elem;
    }
};
