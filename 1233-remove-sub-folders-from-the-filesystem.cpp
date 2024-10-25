#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;

// Solution 1: Tries
//struct Node {
//  Node * children[27];
//  bool leaf;
//
//  Node() {
//    for(int i=0;i<27;i++) children[i] = nullptr;
//    leaf = false;
//  }
//};
//
//class Solution {
//  Node * root;
//  void _insert(const string &s) {
//    Node *curr = root;
//    char ch;
//    for (int i=0;i<s.size();i++) {
//      ch = s[i];
//      if (ch == '/') ch = '{';
//      ch -= 'a';
//      if (curr->children[ch] == nullptr) {
//        curr->children[ch] = new Node();
//      }
//      curr = curr->children[ch];
//    }
//    curr->leaf = true;
//  }
//  void dfs(const Node* curr, string path, vector<string> &ans) {
//    if (curr->leaf) {
//      path.pop_back();
//      ans.push_back(path);
//      return;
//    }
//    for (int i=0;i<27;i++) {
//      char ch = 'a'+i;
//      if (ch == '{') ch = '/';
//
//      if (curr->children[i] != nullptr) {
//        dfs(curr->children[i], path+ch, ans);
//      }
//    }
//  }
//public:
//  vector<string> removeSubfolders(vector<string>& folder) {
//    root = new Node();
//
//    for (const auto &str: folder) {
//      _insert(str+'/');
//    }
//
//    vector<string> ans;
//    dfs(root, "", ans);
//
//    return ans;
//  }
//};

// Solution 2: Set
class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    unordered_set<string> folders;
    sort(folder.begin(), folder.end(), [](const string &a, const string &b) {
      return a.size() < b.size();
    });

    for (const auto &str: folder) {
      string copy = string(str);
      int i = copy.size() - 1;
      while (i >= 0) {
        if (copy[i] == '/') {

          copy.pop_back();
          if (copy.size() != 0 && folders.find(copy) != folders.end()) {
            break;
          }
        } else copy.pop_back();
        i--;
      }
      if (i == -1) folders.insert(str);
    }

    return vector<string>(folders.begin(), folders.end());
  }
};
