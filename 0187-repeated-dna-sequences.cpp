#include "unordered_set"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
  int mask = (1 << 20) - 1;
  int charToInt(char ch) {
    switch (ch) {
      case 'A':
        return 0;
      case 'C':
        return 1;
      case 'G':
        return 2;
      case 'T':
        return 3;
    }
    return 0;
  }
  string hashToStr(int hash) {
    int initial = 3 << 18;
    int shift = 18;
    string s = "";
    for (int i = 0; i < 10; i++) {
      switch ((hash & initial) >> shift) {
        case 0:
          s += 'A';
          break;
        case 1:
          s += 'C';
          break;
        case 2:
          s += 'G';
          break;
        default:
          s += 'T';
          break;
      }
      initial = initial >> 2;
      shift -= 2;
    }
    return s;
  }
  vector<string> findRepeatedDnaSequences(string s) {
    int hash = 0;
    unordered_set<int> st;
    unordered_set<int> ans;

    vector<string> arr;

    int j = 0, n = s.size();
    while (j < 10 && j < n) {
      hash = (hash << 2) | charToInt(s[j]);
      j++;
    }
    st.insert(hash);

    while (j < n) {
      hash = (hash << 2) | charToInt(s[j]);
      hash = hash & mask;
      if (st.count(hash)) {

        ans.insert(hash);
      }

      st.insert(hash);
      j++;
    }

    for (auto it : ans)
      arr.push_back(hashToStr(it));

    return arr;
  }
};
