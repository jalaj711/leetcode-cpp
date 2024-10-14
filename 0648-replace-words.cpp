#include<string>
#include<vector>
using namespace std;

struct Node {
  Node * child[26];
  bool leaf;

  Node() {
    leaf = false;
    for (int i=0;i<26;i++) {
      child[i] = nullptr;
    }
  }
};

class Solution {
  Node * root;
  void _insert(const string &word) {
    Node * curr = root;
    for (const char &ch: word) {
      if (curr->child[ch-'a'] == nullptr) {
        curr->child[ch-'a'] = new Node();
      }

      curr = curr->child[ch-'a'];
    }
    curr->leaf = true;
  }


  string _search(const string &word) {
    string ans = "";
    Node * curr = root;
    for (const char &ch: word) {
      if (curr->leaf || curr->child[ch-'a'] == nullptr) {
        break;
      }
      ans += ch;
      curr = curr->child[ch-'a'];
    }
    if (curr->leaf) {
      return ans;
    }
    return word;
  }
public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    root = new Node();
    string  ans = "",
        temp = "";

    for (const string &w: dictionary) {
      _insert(w);
    }

    for (const char &ch: sentence) {
      if (ch == ' ') {
        ans += _search(temp);
        ans += ' ';
        temp = "";
      } else {
        temp += ch;
      }
    }
    ans += _search(temp);

    return ans;
  }
};