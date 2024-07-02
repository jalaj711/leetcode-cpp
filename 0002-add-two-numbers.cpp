#include <stdlib.h>
#include <iostream>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *ans = new ListNode();
        ListNode *currentNode = ans;
        ListNode *nextNode;
        while (l1 != nullptr && l2 != nullptr)
        {
            // add the numbers
            int sum;
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            currentNode->val = sum;
            if (l1->next != nullptr || l2->next != nullptr)
            {
                // insert next node in ans
                nextNode = new ListNode();
                currentNode->next = nextNode;

                // move to next digit
                currentNode = nextNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            // add the numbers
            int sum;
            sum = carry + l1->val;
            carry = sum / 10;
            sum = sum % 10;
            currentNode->val = sum;
            if (l1->next != nullptr)
            {
                // insert next node in ans
                nextNode = new ListNode();
                currentNode->next = nextNode;

                // move to next digit
                currentNode = nextNode;
            }
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            // add the numbers
            int sum;
            sum = carry + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            currentNode->val = sum;
            if (l2->next != nullptr)
            {
                // insert next node in ans
                nextNode = new ListNode();
                currentNode->next = nextNode;

                // move to next digit
                currentNode = nextNode;
            }
            l2 = l2->next;
        }
        if (carry != 0)
        {
            nextNode = new ListNode(carry, nullptr);
            currentNode->next = nextNode;
            currentNode = nextNode;
        }
        currentNode->next = nullptr;
        return ans;
    }
};

void traverse(ListNode *lst)
{
    while (lst != nullptr)
    {
        cout << lst->val;
        lst = lst->next;
    }
}

int main()
{
    ListNode *a7 = new ListNode(9);
    ListNode *a6 = new ListNode(9, a7);
    ListNode *a5 = new ListNode(9, a6);
    ListNode *a4 = new ListNode(9, a5);
    ListNode *a3 = new ListNode(9, a4);
    ListNode *a2 = new ListNode(9, a3);
    ListNode *a1 = new ListNode(9, a2);

    ListNode *b4 = new ListNode(9);
    ListNode *b3 = new ListNode(9, b4);
    ListNode *b2 = new ListNode(9, b3);
    ListNode *b1 = new ListNode(9, b2);
    traverse((new Solution())->addTwoNumbers(a1, b1));
}