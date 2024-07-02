/**
 * Definition for singly-linked list.*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow != nullptr && fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = (fast -> next) -> next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

void traverse(ListNode *l)
{
    while (l != NULL)
    {
        cout << l->val;
        l = l->next;
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
    a1 -> next = a2;
    a2 -> next = a3;
    a3 -> next = a4;
    a4 -> next = a5;
    a5 -> next = a6;
    a6 -> next = a7;
    //a7 -> next = a4;

    bool ans = (new Solution())->hasCycle(a1);
}
