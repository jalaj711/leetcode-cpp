struct Node {
    int val;
    Node * prev;
    Node * next;
    Node(int x): val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node * nxt): val(x), prev(nullptr), next(nxt) {}
    Node(int x, Node * nxt, Node * prv): val(x), prev(prv), next(nxt) {}
};

class MyCircularDeque {
    int cap;
    int sz;
    Node * front;
    Node * back;
public:
    MyCircularDeque(int k) {
        cap = k;
        sz = 0;
        front = nullptr;
        back = nullptr;
    }

    bool insertFront(int value) {
        if (sz==cap) return false;
        auto newNode = new Node(value, front);
        if (front != nullptr) front -> prev = newNode;
        else back = newNode;
        front = newNode;
        sz++;
        return true;
    }

    bool insertLast(int value) {
        if (sz==cap) return false;
        auto newNode = new Node(value, nullptr, back);
        if (back != nullptr) back -> next = newNode;
        else front = newNode;
        back = newNode;
        sz++;
        return true;
    }

    bool deleteFront() {
        if (sz==0) return false;
        auto node = front;
        front = front->next;
        if (front==nullptr) back = nullptr;
        else front -> prev = nullptr;
        delete node;
        sz--;
        return true;
    }

    bool deleteLast() {
        if (sz==0) return false;
        auto node = back;
        back = back->prev;
        if (back==nullptr) front = nullptr;
        else back -> next = nullptr;
        delete node;
        sz--;
        return true;

    }

    int getFront() {
        if (sz == 0) return -1;
        return front->val;
    }

    int getRear() {
        if (sz == 0) return -1;
        return back->val;

    }

    bool isEmpty() {
        return sz==0;
    }

    bool isFull() {
        return sz==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */