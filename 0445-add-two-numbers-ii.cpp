
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
private:
    ListNode *reverseLinkedList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *prev = nullptr;
        ListNode *next = head->next;
        while (next != nullptr)
        {
            head->next = prev;
            prev = head;
            head = next;
            next = next->next;
        }
        head->next = prev;
        return head;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);
        ListNode *ans = nullptr;
        ListNode *ansCurrDigit = nullptr;
        int carry = 0, sum;
        while (l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ansCurrDigit = new ListNode(sum);
            if (ans == nullptr)
                ans = ansCurrDigit;
            else
            {
                ansCurrDigit->next = ans;
                ans = ansCurrDigit;
            };

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            sum = l1->val + carry;
            carry = sum / 10;
            sum %= 10;
            ansCurrDigit = new ListNode(sum);
            if (ans == nullptr)
                ans = ansCurrDigit;
            else
            {
                ansCurrDigit->next = ans;
                ans = ansCurrDigit;
            };

            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            sum = l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ansCurrDigit = new ListNode(sum);
            if (ans == nullptr)
                ans = ansCurrDigit;
            else
            {
                ansCurrDigit->next = ans;
                ans = ansCurrDigit;
            };

            l2 = l2->next;
        }

        if (carry)
        {

            ansCurrDigit = new ListNode(carry);
            if (ans == nullptr)
                ans = ansCurrDigit;
            else
            {
                ansCurrDigit->next = ans;
                ans = ansCurrDigit;
            };
        }

        return ans;
    }
};

int main()
{
    ListNode *l1 = new ListNode(6, new ListNode(5)); //, new ListNode(2)));
    ListNode *l2 = new ListNode(1, new ListNode(4, new ListNode(7)));
    Solution s;
    s.addTwoNumbers(l1, l2);
}
