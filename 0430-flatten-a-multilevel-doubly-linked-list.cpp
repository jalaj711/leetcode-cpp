class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node * flattenUtil (Node *head) {
        if (head == nullptr) return head;
        Node * curr = head;
        Node * next;
        do {
            next = curr -> next;
            if (curr -> child != nullptr) {
                auto tail = flattenUtil(curr->child);
                curr -> next = curr -> child;
                curr -> next -> prev = curr;
                curr -> child = nullptr;
                tail -> next = next;
                if (next) next -> prev = tail;
                else curr=tail;
            }
            if (next) curr = next;
        } while (next != nullptr);
        return curr;
    }
    Node* flatten(Node* head) {
        flattenUtil(head);
        return head;
    }
};