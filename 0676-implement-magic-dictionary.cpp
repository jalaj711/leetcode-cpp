#include<string>
#include<vector>
using namespace std;
struct Node {
  Node * child[26];
  bool leaf;

  Node() {
    leaf = false;
    for (auto & i : child) {
      i = nullptr;
    }
  }
};

class MagicDictionary {
  Node * root;
  void insert(const string &word) {
    Node * curr = root;
    for (const char &ch: word) {
      if ((curr->child)[ch-'a'] == nullptr) {
        (curr->child)[ch-'a'] = new Node();
      }
      curr = (curr->child)[ch-'a'];
    }
    curr -> leaf = true;
  }

  bool _search(const string &word, Node * curr, int ptr, bool skip) {
    int n = word.size();

    while (ptr < n) {
      char ch = word[ptr];

      if (skip) {
        for (int i=0;i<26;i++)
          if(ch-'a' != i && (curr->child)[i] != nullptr && _search(word, (curr->child)[i], ptr+1, false)) return true;
      }

      if ((curr->child)[ch-'a'] == nullptr) break;
      curr = (curr->child)[ch-'a'];
      ptr++;
    }

    return ptr == n && !skip && curr->leaf;
  }
public:
  MagicDictionary() {
    root = new Node();
  }

  void buildDict(const vector<string> &dictionary) {
    for (const string &word: dictionary) {
      insert(word);
    }
  }

  bool search(const string &searchWord) {
    Node * curr = root;
    return _search(searchWord, curr, 0, true);
  }
};

int main() {
  vector<string> dictionary {"hello","leetcode"};
  MagicDictionary* obj = new MagicDictionary();
  obj->buildDict(dictionary);
  obj->search("hello");
  obj->search("hhllo");
  obj->search("hell");
  obj->search("leetcoded");
}
/**
 * Your MagicDictionary object will be instantiated and called as such:
 *
 */