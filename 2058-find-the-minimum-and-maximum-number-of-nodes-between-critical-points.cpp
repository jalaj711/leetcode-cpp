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
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *next = curr->next;

        vector<int> ans{100001, -1};

        int idx = 2;
        int lastCriticalPointIdx = -1;
        int firstCriticalPointIdx = -1;

        while (next != nullptr) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                if (firstCriticalPointIdx == -1)
                    firstCriticalPointIdx = idx;
                if (lastCriticalPointIdx != -1)
                    ans[0] = min(ans[0], idx - lastCriticalPointIdx);
                lastCriticalPointIdx = idx;
            }
            prev = curr;
            curr = next;
            next = next->next;
            idx++;
        }
        if (lastCriticalPointIdx != -1 && firstCriticalPointIdx != -1 &&
            firstCriticalPointIdx != lastCriticalPointIdx) {
            ans[1] = lastCriticalPointIdx - firstCriticalPointIdx;
            return ans;
        }
        return {-1, -1};
    }
};