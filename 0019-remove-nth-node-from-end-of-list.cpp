#include <vector>
#include <iostream>
using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = new ListNode(0, head);
        ListNode *slow = new ListNode(0, head);
        for(int i=0;i<n;i++) {
            if (fast -> next != nullptr) {
                fast = fast -> next;
            } else {
                break;
            }
        }
        while (fast -> next != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }
        if(slow == nullptr || slow -> next == nullptr) {
            return nullptr;
        }
        slow -> next = (slow -> next) -> next;
        if (slow -> next == head -> next && slow != head) {
            return slow -> next;
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
    ListNode *a6 = new ListNode(8, a7);
    ListNode *a5 = new ListNode(7, a6);
    ListNode *a4 = new ListNode(6, a5);
    ListNode *a3 = new ListNode(5, a4);
    ListNode *a2 = new ListNode(4, a3);
    ListNode *a1 = new ListNode(3, a2);
    ListNode *ans = (new Solution())->removeNthFromEnd(a1, 2);
    traverse(ans);
    cout << endl;
}