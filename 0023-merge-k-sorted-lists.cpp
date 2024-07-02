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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res_head = nullptr;
        ListNode *res_tail = res_head;
        int i, min_index, n = lists.size();
        bool all_null = true;
        while (true)
        {
            all_null = true;
            i = 0;
            min_index = -1;
            while (i < n)
            {
                if (lists[i] != nullptr)
                {
                    all_null = false;
                    if (min_index == -1 || lists[min_index]->val > lists[i]->val)
                        min_index = i;
                }
                i++;
            }
            if (all_null)
                break;
            // if all_null is false then min_index is guaranteed to have a value >= 0
            if (res_head == nullptr)
            {
                res_head = res_tail = new ListNode(lists[min_index]->val);
            }
            else
            {
                res_tail->next = new ListNode(lists[min_index]->val);
                res_tail = res_tail->next;
            }
            lists[min_index] = lists[min_index]->next;
        }
        return res_head;
    }
};