#include<string>
#include<cstring>

using namespace std;

class Solution {
public:
  int maximumLength(const string &s) {
    int counts[26];
    int n = s.size(),
        l = 1,
        r = n - 2,
        a = -1,
        m;

    while (l <= r) {
      m = l + (r - l) / 2;

      memset(counts, 0, sizeof(int) * 26);
      bool pos = false;
      // cout << "check for" << m << endl;
      for (int i = 0; i < n;) {
        char ch = s[i];
        int c = 0;
        while (i < n && s[i] == ch) {
          c++;
          i++;
        }
        if (c >= m) counts[ch - 'a'] += c - m + 1;
        // cout << "ch=" << ch << " c=" << c << " count=" << counts[ch-'a'] << endl;
        if (c >= m && counts[ch - 'a'] >= 3) {
          pos = true;
          break;
        }
      }

      if (pos) {
        l = m + 1;
        a = m;
      } else {
        r = m - 1;
      }
    }

    return a;
  }
};