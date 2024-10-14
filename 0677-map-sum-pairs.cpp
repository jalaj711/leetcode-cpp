#include<string>
using namespace std;

struct Trie {
  Trie* child[26];
  int v;

  Trie(int val) {
    v = val;
    for (int i=0;i<26;i++) {
      child[i] = nullptr;
    }
  }
};

class MapSum {
  Trie * root;
  int _sum_helper(Trie * node) {
    int s = node -> v;
    for (const auto &t: node -> child){
      if (t != nullptr) s += _sum_helper(t);
    }
    return s;
  }
public:
  MapSum() {
    root = new Trie(0);
  }

  void insert(string key, int val) {
    Trie * curr = root;
    for (const char &ch: key ) {
      if (curr->child[ch-'a'] == nullptr) {
        curr->child[ch-'a'] = new Trie(0);
      }

      curr = curr->child[ch-'a'];
    }

    curr->v= val;
  }

  int sum(string prefix) {
    Trie * curr = root;
    for (const char &ch: prefix) {
      if (curr->child[ch-'a'] == nullptr) {
        return 0;
      }

      curr = curr->child[ch-'a'];
    }
    return _sum_helper(curr);
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */