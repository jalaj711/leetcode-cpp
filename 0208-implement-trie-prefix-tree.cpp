#include<string>
using namespace std;

struct Node {
  Node * children[26];
  bool leaf;

  Node(): leaf(false) {
    for (int i=0;i<26;i++) {
      children[i] = nullptr;
    }
  };
};

class Trie {
  Node * root;
public:
  Trie() {
    root = new Node();
  }

  void insert(string word) {
    Node * curr = root;
    for (const char &ch: word) {
      if ((curr -> children)[ch-'a'] == nullptr) {
        (curr->children)[ch-'a'] = new Node();
      }
      curr = (curr->children)[ch-'a'];
    }
    curr -> leaf = true;
  }

  bool search(string word) {
    Node * curr = root;
    for (const char &ch: word) {
      if ((curr -> children)[ch-'a'] == nullptr) {
        return false;
      }
      curr = (curr->children)[ch-'a'];
    }
    return curr -> leaf;
  }

  bool startsWith(string prefix) {
    Node * curr = root;
    for (const char &ch: prefix) {
      if ((curr -> children)[ch-'a'] == nullptr) {
        return false;
      }
      curr = (curr->children)[ch-'a'];
    }
    for (const auto &n: curr->children) {
      if (n != nullptr) {
        return true;
      }
    }
    return curr -> leaf;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */