#include<unordered_set>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        auto st = unordered_set<int>(nums.begin(), nums.end());
        auto curr = head;
        ListNode *prev = nullptr;
        while (curr) {
            if (st.find(curr->val) != st.end()) {
                if (curr == head) {
                    head = head->next;
                } else {
                    prev->next = curr->next;
                    curr = prev;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};