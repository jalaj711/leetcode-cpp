#include<string>
using namespace std;

class Solution {
public:
  int isPrefixOfWord(string &s, string &w) {
    int n = s.size();
    int m = w.size();
    int wi = 1;
    for (int i=0;i<n;i++) {
      int j = 0;
      while(j < m && i < n) {
        if (s[i] != w[j]) break;
        i++;
        j++;
      }
      if (j == m) return wi;
      while(i < n && s[i] !=  ' ') i++;
      wi++;
    }

    return -1;
  }
};