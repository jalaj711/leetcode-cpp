int max(int a, int b) {
  if (a > b) return a;
  return b;
}

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode *head) {
    ListNode *slowPrev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    // find the middle of the linked list
    while (fast != nullptr && fast->next != nullptr) {
      slowPrev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = slow;
    slow = slow->next;
    fast = slow ? slow->next : slow;
    prev->next = nullptr;

    // reverse the second half of linked list
    while (slow != nullptr) {
      slow->next = prev;
      prev = slow;
      slow = fast;
      if (fast)
        fast = fast->next;
    }

    // this step along with line 28
    // changes the linked list from 5-4-3-2-null
    // to 5-4-2-3-null
    slowPrev->next = slow;
    slow = head;
    int sum = slow->val + prev->val;

    // process the twins
    while (slow != nullptr) {
      sum = max(sum, slow->val + prev->val);
      slow = slow->next;
      prev = prev->next;
    }

    return sum;
  }
};