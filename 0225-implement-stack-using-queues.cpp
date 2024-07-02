#include <queue>
#include <iostream>
using namespace std;

class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
        {
            q1.push(x);
            while (q2.size() != 0)
            {
                q1.push(q2.front());
                q2.pop();
            }
            return;
        }
        q2.push(x);
        while (q1.size() != 0)
        {
            q2.push(q1.front());
            q1.pop();
        }
        return;
    }

    int pop()
    {
        int elem;
        if (q1.empty())
        {
            elem = q2.front();
            q2.pop();
        }
        else
        {

            elem = q1.front();
            q1.pop();
        }
        return elem;
    }

    int top()
    {
        if (q1.empty())
            return q2.front();
        return q1.front();
    }

    bool
    empty()
    {
        return q1.empty() && q2.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    bool ans_1 = obj->empty();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->push(6);
    int ans_2 = obj->top();
    int ans_3 = obj->pop();
    int ans_4 = obj->top();
    bool ans_5 = obj->empty();
    cout << ans_1 << endl
         << ans_2 << endl
         << ans_3 << endl
         << ans_4 << endl
         << ans_5 << endl;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */