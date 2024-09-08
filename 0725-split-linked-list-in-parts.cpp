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
    int count(ListNode *head) {
        int c = 0;
        while (head != nullptr) {
            c++;
            head = head->next;
        }
        return c;
    }

    vector<ListNode *> ans;

    ListNode *insert(ListNode *head, int count) {
        ans.push_back(head);
        while (head && --count) head = head->next;
        ListNode *temp = head;
        if (head) {
            temp = head->next;
            head->next = nullptr;
        }
        return temp;
    }

    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = count(head);
        int parts = n / k;
        int rem = n % k;
        // cout << parts << " " << rem << endl;
        for (int i = 0; i < k; i++) {
            head = insert(head, parts + (rem > 0 ? 1 : 0));
            if (rem) rem--;
        }
        return ans;
    }
};