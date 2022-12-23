#include <vector>
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
        vector<ListNode *> nodes;
        ListNode *nextNode = head;
        while (nextNode != nullptr)
        {
            nodes.push_back(nextNode);
            nextNode = nextNode->next;
        }
        if (nodes.size() > n)
        {
            ListNode *next = nodes[nodes.size() - n]->next;
            nodes[nodes.size() - n - 1]->next = next;
        }
        else
        {
            head = head -> next;
        };
        return head;
    }
};

int main()
{
    // ListNode *a7 = new ListNode(9);
    // ListNode *a6 = new ListNode(8, a7);
    // ListNode *a5 = new ListNode(7, a6);
    // ListNode *a4 = new ListNode(6, a5);
    // ListNode *a3 = new ListNode(5, a4);
    // ListNode *a2 = new ListNode(4, a3);
    ListNode *a1 = new ListNode(3, nullptr);
    (new Solution())->removeNthFromEnd(a1, 1);
}