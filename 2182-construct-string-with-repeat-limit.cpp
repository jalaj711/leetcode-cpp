#include<string>
using namespace std;

class Solution {
public:
  string repeatLimitedString(const string &s, int rl) {
    int f[26] = {0};

    for(const char &ch: s) f[ch-'a']++;

    string ans = "";

    auto find = [&](int i) {
      int j = i-1;
      for(;j>=0;j--) {
        if (f[j] > 0) break;
      }
      if (j < 0) return 0;
      f[j]--;
      return j+'a';
    };

    for(int i=25;i>=0;i--) {
      bool brk = false;
      while(f[i] >= rl) {
        // cout << i << " f=" << f[i] << " ans=" << ans << endl;
        for(int j=0;j<rl;j++) ans.push_back(i+'a');

        f[i] -= rl;
        if (f[i] > 0) {
          char x = find(i);
          // cout << "find= " << x << endl;
          if (x != 0)
            ans.push_back(x);
          else {
            brk = true;
            break;
          }
        }
      }

      if (brk) break;

      for(int j=0;j<f[i];j++) ans.push_back(i+'a');
    }

    return ans;
  }
};