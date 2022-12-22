#include <iostream>
#include <stdlib.h>

struct ListNode {
    int elem;
    struct ListNode *next;
};

void traverseLinkedList (struct ListNode *head) {
    int k = 0;
    while (head -> next != NULL) {
        std::cout << k << "=" << head -> elem << " ";
        head = head -> next;
        k++;
    }
    std::cout << std::endl;
}

int getElement (int n, struct ListNode *head) {
    struct ListNode *NextNode;
    NextNode = head;
    for (int i=0;i<n;i++) {
        if (NextNode->next == NULL) {
            break;
        }
        NextNode = NextNode -> next;
    }
    return NextNode -> elem;
}

int insertElement(int element, int n, struct ListNode **head) {
    struct ListNode *NewNode;
    NewNode = (ListNode *) malloc(sizeof(struct ListNode));
    NewNode -> elem = element;
    if (n == 0) {
        NewNode -> next = *head;
        *head = NewNode;
    } else {
        struct ListNode *prevNode, *nextNode;
        nextNode = *head;
        for(int i=0;i<n;i++){
            prevNode = nextNode;
            nextNode = (nextNode -> next);
            if (nextNode == NULL){
                break;
            }
        }
        prevNode -> next = NewNode;
        NewNode -> next = nextNode;
    }
    return n;
}

void deleteElement(int n, struct ListNode **head) {
    if (n == 0) {
        struct ListNode *temp;
        temp = *head;
        *head = (*head) -> next;
        free(temp);
    } else {
        struct ListNode *prevNode, *currentNode;
        currentNode = *head;
        for(int i=0;i<n;i++){
            prevNode = currentNode;
            currentNode = (currentNode -> next);
            if (currentNode == NULL){
                break;
            }
        }
        prevNode -> next = currentNode -> next;
        free(currentNode);
    }
}

int main(){
    struct ListNode **headNode;
    headNode = (ListNode **) malloc(sizeof(ListNode *));
    *headNode = (ListNode *) malloc(sizeof(struct ListNode));
    // std::cout << sizeof (head) << " " << sizeof(*head);
    insertElement(10, 0, headNode);
    insertElement(20, 1, headNode);
    insertElement(30, 2, headNode);
    insertElement(40, 3, headNode);
    traverseLinkedList(*headNode);
    insertElement(50, 2, headNode);
    traverseLinkedList(*headNode);
    deleteElement(0, headNode);
    traverseLinkedList(*headNode);
    deleteElement(1, headNode);
    traverseLinkedList(*headNode);
}