#include<string>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node* prev;
    Node(string v) : val(v), next(nullptr), prev(nullptr){};
    Node(string v, Node* nxt) : val(v), next(nxt), prev(nullptr){};
    Node(string v, Node* nxt, Node* prv) : val(v), next(nxt), prev(prv){};
};

class BrowserHistory {
    Node* base;
    Node* ptr;

public:
    BrowserHistory(string homepage) {
        base = new Node(homepage);
        ptr = base;
    }

    void visit(string url) {
        if (ptr->next) {
            ptr = ptr->next;
            ptr->val = url;
            ptr->next = nullptr;
        } else {
            auto node = new Node(url, nullptr, ptr);
            ptr->next = node;
            ptr = node;
        }
    }

    string back(int steps) {
        while (steps-- && ptr != base) {
            ptr = ptr->prev;
        }
        return ptr->val;
    }

    string forward(int steps) {
        while (steps-- && ptr->next != nullptr) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */