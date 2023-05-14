
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLinkedListTillN(ListNode *head, int n) {
    if (head == NULL || head -> next == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *elem = head;
        ListNode *next = head->next;
        int count = 0;
        while (next != NULL && count < n)
        {
            next = elem->next;
            elem->next = prev;
            prev = elem;
            elem = next;
            count++;
        }
        return prev;
}

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *kth_ptr = head->next;
        ListNode *zero_ptr = head;
        ListNode *zero_prev = nullptr;
        int covered = 1;
        while (kth_ptr != nullptr)
        {
            kth_ptr = kth_ptr->next;
            covered++;
            if (covered == k)
            {
                ListNode *group_head = reverseLinkedListTillN(zero_ptr, k);
                if (zero_prev == nullptr) {
                    head = group_head;
                } else {
                    zero_prev -> next = group_head;
                }
                zero_ptr -> next = kth_ptr;

                zero_prev = zero_ptr;
                zero_ptr = kth_ptr;
                covered = 0;
            }
        }
        return head;
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
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    a6->next = a7;
    // a7 -> next = a4;
    traverse(a1);
    cout << endl;
    ListNode *ans = (new Solution())->reverseKGroup(a1, 3);
    traverse(ans);
    cout << endl;
}
