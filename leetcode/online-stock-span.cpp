#include <iostream>
#include <map>
#include <vector>
// #include <pair>
using namespace std;

class StockSpanner
{
public:
    vector<pair<int, int>> stack;
    StockSpanner()
    {
    }

    int next(int price)
    {
        if (stack.empty() || stack.back().first > price)
        {
            stack.push_back(make_pair(price, 1));
            return 1;
        }
        int span = 1;
        while (!stack.empty() && stack.back().first <= price) {
            span += stack.back().second;
            stack.pop_back();
        }
        stack.push_back(make_pair(price, span));
        return span;
    }
};

int main()
{
    int prices[] = {31, 41, 48, 59, 79};
    StockSpanner *obj = new StockSpanner();
    for (int i: prices) {
        cout << obj->next(i) << " ";
    }
    cout << endl;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */