#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
  bool closeStrings(const string &word1, const string &word2) {
    if (word1.size() != word2.size()) return false;
    int w1[26] = {0},
        w2[26] = {0};
    unordered_map<int, int> mp1, mp2;
    int b1 = 0, b2 = 0, n = word1.size();

    for (int i=0;i<n;i++) {
      w1[word1[i]-'a']++;
      w2[word2[i]-'a']++;

      // these bit masks make sure that both the words have
      // the same set of characters in them
      b1 |= 1 << (word1[i]-'a');
      b2 |= 1 << (word2[i]-'a');
    }

    if (b1 != b2) return false;

    for (int i=0;i<26;i++) {
      mp1[w1[i]]++;
      mp2[w2[i]]++;
    }

    for(const auto &it: mp1) {
      if (it.second != mp2[it.first]) return false;
      mp2.erase(it.first);
    }

    if (mp2.size()) return false;
    return true;

  }
};