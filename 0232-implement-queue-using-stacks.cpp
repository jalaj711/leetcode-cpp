#include <vector>
#include <iostream>
using namespace std;

class MyQueue
{
public:
    vector<int> stack1;
    vector<int> stack2;

    MyQueue()
    {
    }

    void push(int x)
    {
        if (empty())
        {
            stack1.push_back(x);
            return;
        }
        for (int i = stack1.size() - 1; i >= 0; i--)
        {
            stack2.push_back(stack1[i]);
        }
        stack1.clear();
        stack1.push_back(x);
        for (int i = stack2.size() - 1; i >= 0; i--)
        {
            stack1.push_back(stack2[i]);
        }
        stack2.clear();
    }

    int pop()
    {
        int elem = stack1[stack1.size() - 1];
        stack1.pop_back();
        return elem;
    }

    int peek()
    {
        return stack1[stack1.size() - 1];
    }

    bool empty()
    {
        return stack1.size() == 0;
    }
};

int main()
{
    MyQueue *obj = new MyQueue();
    bool ans_1 = obj->empty();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->push(6);
    int ans_2 = obj->peek();
    int ans_3 = obj->pop();
    int ans_4 = obj->peek();
    bool ans_5 = obj->empty();
    cout << ans_1 << endl << ans_2 << endl << ans_3 << endl << ans_4 << endl << ans_5 << endl;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */