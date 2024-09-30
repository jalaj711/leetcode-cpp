#include<vector>
using namespace std;

class CustomStack {
    int sz, cap;
    // {item, incr}
    vector<pair<int, int>*> items;

public:
    CustomStack(int maxSize) {
        cap = maxSize;
        sz = 0;
    }

    void push(int x) {
        if (sz==cap) return;
        auto node = new pair<int, int> {x, 0};
        items.push_back(node);
        sz++;
    }

    int pop() {

        if (sz==0) return -1;
        auto node = items[--sz];
        int v = node->first, i = node->second;
        delete node;

        items.pop_back();

        if (sz != 0) items[sz-1] -> second += i;

        return v+i;
    }

    void increment(int k, int val) {
        if (sz==0) return;
        if (k>=sz) k = sz;
        items[k-1] -> second += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */