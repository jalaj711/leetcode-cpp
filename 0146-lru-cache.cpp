#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct DLL
{
    int key;
    int val;
    DLL *prev;
    DLL *next;
    DLL() : key(0), val(0), prev(nullptr), next(nullptr){};
    DLL(int k, int v, DLL *p, DLL *n) : key(k), val(v), prev(p), next(n){};
};

class LRUCache
{
public:
    map<int, DLL *> pairs;
    DLL *head;
    DLL *tail;
    int cap;
    LRUCache(int capacity)
    {
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key)
    {
        if (pairs.find(key) != pairs.end())
        {
            DLL *node = pairs[key];
            if (pairs.size() == 1 || node == tail)
                return node->val;
            if (node == head)
            {
                head = node->next;
                (node->next)->prev = nullptr;
            }
            else
            {
                (node->prev)->next = node->next;
                (node->next)->prev = node->prev;
            }
            (tail->next) = node;
            (node->prev) = tail;
            node->next = nullptr;
            tail = node;
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (pairs.size() >= cap)
        {
            DLL *to_be_deleted = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
                if (head->next == nullptr)
                    tail = nullptr;
            }
            pairs.erase(to_be_deleted->key);
        }

        if (pairs.find(key) != pairs.end())
        {
            DLL *node = new DLL(key, value, nullptr, nullptr);
            if (head == nullptr)
            {
                head = node;
                tail = node;
            }
            else if (tail == nullptr)
            {
                head->next = node;
                node->prev = head;
                tail = node;
            }
            else
            {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            pairs.insert({key, node});
        }
        else
        {
            DLL *node = pairs[key];
            if (pairs.size() == 1 || node == tail)
            {
                node->val = value;
                return;
            }
            if (node == head)
            {
                head = node->next;
                (node->next)->prev = nullptr;
            }
            else
            {
                (node->prev)->next = node->next;
                (node->next)->prev = node->prev;
            }
            (tail->next) = node;
            (node->prev) = tail;
            node->next = nullptr;
            tail = node;
            node -> val = value;
        }
    }
};

int main()
{
    int capacity = 5, key = 1, value = 1;
    LRUCache *obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key, value);
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */