#include<string>
using namespace std;

class Solution {
public:
  bool canMakeSubsequence(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    int j = 0;
    for (int i=0;i<m;i++) {
      if (s1[i] == s2[j] || ((s2[j]-'a') == ((s1[i]-'a'+1)%26))) {
        if (++j == n) return true;
      }
    }
    return false;
  }
};