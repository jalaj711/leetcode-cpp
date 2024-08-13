
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
 public:
     ListNode* oddEvenList(ListNode* head) {
         if (head == nullptr) return nullptr;
         auto oddTail = head;
         auto evenHead = head->next;
         auto evenTail = evenHead;

         int n = 3;
         auto temp = evenTail;
         if (temp != nullptr) temp = temp->next;
         while (temp != nullptr) {
             if (n&1) {
                 oddTail -> next = temp;
                 oddTail = temp;
             } else {
                 evenTail -> next = temp;
                 evenTail = temp;
             }
             temp = temp -> next;
             n++;
         }
         oddTail -> next = evenHead;
         if (evenTail != nullptr) evenTail -> next = nullptr;
         return head;
     }
 };

int main() {
    ListNode n1(5);
    ListNode n2(4, &n1);
    ListNode n3(3, &n2);
    ListNode n4(2, &n3);
    ListNode n5(1, &n4);
    Solution s;
    s.oddEvenList(&n5);
}