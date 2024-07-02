
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

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        int steps = 0;
        while (steps < k)
        {
            fast = fast->next;
            steps++;
            if (fast == nullptr)
            {
                fast = head;
                k = k % steps;
                steps = 0;
            }
        }
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (slow != fast) {
            fast -> next = head;
            head = slow -> next;
            slow -> next = nullptr;
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
    ListNode *ans = (new Solution())->rotateRight(a1, 17);
    traverse(ans);
    cout << endl;
}
