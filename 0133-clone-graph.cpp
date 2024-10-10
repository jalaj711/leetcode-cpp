#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};


class Solution {
public:
  Node *cloneGraph(Node *node) {

    if (node == nullptr) return node;

    unordered_map<Node *, Node *> mp;
    mp[node] = new Node(node->val);

    queue<Node *> q;
    q.push(node);

    while (!q.empty()) {
      Node *oldfr = q.front();
      q.pop();
      Node *newfr = mp[oldfr];
      for (Node *old: oldfr->neighbors) {
        if (mp.find(old) == mp.end()) {
          (newfr->neighbors).push_back(mp[old] = new Node(old->val));
          q.push(old);
        } else {
          (newfr->neighbors).push_back(mp[old]);
        }
      }
    }

    return mp[node];
  }
};