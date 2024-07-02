
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        bool loop = false;
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = (fast -> next) -> next;
            if(slow == fast) {
                loop = true;
                break;
            }
        }

        if (!loop) return nullptr;

        ListNode *ptr = head;
        while (slow != ptr) {
            slow = slow -> next;
            ptr = ptr -> next;
        }
        return ptr;
    }
};

void traversetillMaxLen(ListNode *l, int max)
{
    int c = 0;
    while (l != NULL && c < max)
    {
        cout << l->val;
        l = l->next;
        c++;
    }
}

int main()
{
    ListNode *a7 = new ListNode(9);
    ListNode *a6 = new ListNode(8);
    ListNode *a5 = new ListNode(7);
    ListNode *a4 = new ListNode(6);
    ListNode *a3 = new ListNode(5);
    ListNode *a2 = new ListNode(4);
    ListNode *a1 = new ListNode(3);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    a6->next = a7;
    a7 -> next = a4;
    traversetillMaxLen(a1, 8);
    cout << endl;
    ListNode *ans = (new Solution())->detectCycle(a1);
    traversetillMaxLen(ans, 5);
    cout << endl;
}
