#include <vector>
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *elem = head;
        ListNode *next = head->next;
        while (next != NULL)
        {
            next = elem->next;
            elem->next = prev;
            prev = elem;
            elem = next;
        }
        return prev;
    };
};

int main()
{
    ListNode *test1 = new ListNode(1, new ListNode(2, new ListNode(5, new ListNode(8))));
    Solution *s = new Solution();
    ListNode *answer = s->reverseList(test1);
}
