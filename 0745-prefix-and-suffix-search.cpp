#include<string>
#include<vector>

using namespace std;

struct Trie {
  Trie * child[27];
  int idx;
  Trie() {
    idx = -1;
    for (int i=0;i<27;i++) {
      child[i] = nullptr;
    }
  };
};


class WordFilter {
  Trie * root;

  void _insert(const string &s, int idx) {
    // cout << "inserting" << s << "at index" << idx << endl;
    Trie * curr = root;
    for(const char &ch: s) {
      if (curr->child[ch-'a'] == nullptr) {
        curr->child[ch-'a'] = new Trie();
      }
      curr = curr -> child[ch-'a'];
      curr->idx = idx;
    }
    curr->idx = idx;
  }

  int _search(const string &suff) {
    // cout << "searching " << suff << endl;
    Trie * curr = root;
    for (const char &ch: suff) {
      if (curr->child[ch-'a'] == nullptr) {
        return -1;
      }
      curr = curr->child[ch-'a'];
    }
    return curr->idx;
  }

public:
  WordFilter(const vector<string>& words) {
    root = new Trie();
    int n = words.size();
    for (int i=0;i<n;i++) {
      for (int j=0;j<words[i].size();j++) {
        _insert(words[i].substr(j) + "{" + words[i], i);
      }
    }
  }

  int f(const string &pref, const string &suff) {

    return _search(suff + "{" + pref);
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */