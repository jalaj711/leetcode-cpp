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

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        bool flag1 = false, flag2 = false;
        ListNode *a = headA;
        ListNode *b = headB;
        while (!flag1 || !flag2)
        {
            if (a == nullptr)
            {
                flag1 = true;
                a = headB;
            }
            else
            {
                a = a->next;
            }
            if (b == nullptr)
            {
                flag2 = true;
                b = headA;
            }
            else
            {
                b = b->next;
            }
        }
        while (a != nullptr && b != nullptr) {
            if (a == b) {
                return a;
            }
            a = a -> next;
            b = b -> next;
        }
        return nullptr;
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
    ListNode *a2 = new ListNode(1);
    ListNode *a1 = new ListNode(4);
    a1->next = a2;

    ListNode *b3 = new ListNode(1);
    ListNode *b2 = new ListNode(6);
    ListNode *b1 = new ListNode(5);
    b1 -> next = b2;
    b2 -> next = b3;


    ListNode *c3 = new ListNode(5);
    ListNode *c2 = new ListNode(4);
    ListNode *c1 = new ListNode(8);
    c1 -> next = c2;
    c2 -> next = c3;

    a2 -> next = c1;
    b3 -> next = c1;

    ListNode *ans = (new Solution())->getIntersectionNode(a1, b1);

    traverse(a1);
    cout << endl;
    traverse(b1);
    cout << endl;
    traverse(ans);
    cout << endl;
}
