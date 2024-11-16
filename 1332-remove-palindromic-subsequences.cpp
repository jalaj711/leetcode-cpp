#include<string>

class Solution {
public:
  int removePalindromeSub(const std::string &s) {
    int l = 0,
        r = s.size() - 1;
    while(l <= r) {
      if (s[l] != s[r]) return 2;
      l++;
      r--;
    }
    return 1;
  }
};