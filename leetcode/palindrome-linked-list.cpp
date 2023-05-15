
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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return true;
        ListNode *slow = head, *fast = head;

        while(fast -> next != nullptr && (fast -> next) -> next != nullptr) {
            fast = (fast -> next) -> next;
            slow = slow -> next;
        }

        bool isOdd = fast -> next == nullptr;

        ListNode *lista = head;
        ListNode *listb = slow -> next;

        ListNode *prev = nullptr;
        ListNode *next = head -> next;

        while(isOdd ? lista != slow : prev != slow) {
            lista -> next = prev;
            prev = lista;
            lista = next;
            next = next -> next;
        }
        lista = prev;

        while (lista != nullptr && listb != nullptr) {
            if (lista -> val != listb -> val) return false;
            lista = lista -> next;
            listb = listb -> next;
        }

        return true;
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
    // ListNode *a7 = new ListNode(3);
    ListNode *a6 = new ListNode(3);
    ListNode *a5 = new ListNode(4);
    ListNode *a4 = new ListNode(5);
    ListNode *a3 = new ListNode(5);
    ListNode *a2 = new ListNode(4);
    ListNode *a1 = new ListNode(3);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    // a6->next = a7;
    // a7 -> next = a4;
    traverse(a1);
    cout << endl;
    bool ans = (new Solution())->isPalindrome(a1);
    cout << ans << endl;
}
