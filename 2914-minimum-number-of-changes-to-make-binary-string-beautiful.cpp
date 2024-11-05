#include<string>
using namespace std;

class Solution {
public:
  int minChanges(const string& s) {
    int n = s.size();
    int c = 0;
    for (int i = 0; i < n - 1; i += 2)
      if (s[i] != s[i + 1])
        c++;
    return c;
  }
};