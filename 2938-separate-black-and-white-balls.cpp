#include<string>

using namespace std;

class Solution {
public:
  long long minimumSteps(string s) {
    long long ans = 0;
    int ptr = 0,
        zPtr = 0,
        n = s.size();

    while (ptr < n) {
      if (s[ptr] == '0') {
        ans += ptr - zPtr;
        zPtr++;
      }
      ptr++;
    }

    return ans;
  }
};