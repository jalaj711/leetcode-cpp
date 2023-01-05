#include<iostream>
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
    ListNode* swapPairs(ListNode* head) {
	if(head == NULL || head -> next == NULL) return head;
	ListNode *cursor = head;
	head = head -> next;
	ListNode *temp;
	bool swap = true;
	while(cursor != NULL && cursor -> next != NULL){
		if(swap){
			temp = (cursor -> next) -> next;
			(cursor -> next) -> next = cursor;
			cursor -> next = temp;
		} else {
			if(cursor -> next -> next != NULL){
				temp = cursor -> next;
				cursor -> next = cursor -> next -> next;
				cursor = temp;
			} else {
				cursor = cursor -> next;
			}
		}
		swap = !swap;
	}
	return head;
    }
};

void traverse(ListNode *l){
	while(l != NULL){
		cout << l -> val << ",";
		l = l -> next;
	}
	cout << endl;
}

int main(){
	Solution *s = new Solution();
	ListNode *test = new ListNode(1, new ListNode(2, new ListNode(5, new ListNode(8, new ListNode(7)))));
	traverse(test);
	cout << endl;
	ListNode *answer = s -> swapPairs(test);
	traverse(answer);
	cout << endl;
	return 0;
}

