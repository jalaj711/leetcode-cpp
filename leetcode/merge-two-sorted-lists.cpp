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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode *head = new ListNode();
	ListNode *ans = head;
	while(list1 != NULL && list2 != NULL){
		if(list1 -> val <= list2 -> val){
			ans -> next = new ListNode(list1 -> val, NULL);
			ans = ans -> next;
			list1 = list1 -> next;
		} else {
			ans -> next = new ListNode(list2 -> val, NULL);
			ans = ans -> next;
			list2 = list2 -> next;
		}
	}

	while(list1 != NULL){
		ans -> next = new ListNode(list1 -> val, NULL);
		ans = ans -> next;
		list1 = list1 -> next;
	}
	while(list2 != NULL){
		ans -> next = new ListNode(list2 -> val, NULL);
		ans = ans -> next;
		list2 = list2 -> next;
	}
	return head -> next;
    }
};

void traverse(ListNode *l){
	while(l != NULL){
		cout << l -> val;
		l = l -> next;
	}
}

int main(){
	Solution *s = new Solution();
	ListNode *test1 = new ListNode(1, new ListNode(2, new ListNode(5, new ListNode(8))));
	ListNode *test2 = new ListNode(3, new ListNode(4, new ListNode(6)));
	ListNode *answer = s -> mergeTwoLists(test1, test2);
	traverse(test1);
	cout << endl;
	traverse(test2);
	cout << endl;
	traverse(answer);
	cout << endl;
	return 0;
}
