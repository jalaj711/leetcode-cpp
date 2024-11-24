#include<string>
#include<vector>

using namespace std;

class Solution {
public:
  long long shiftDistance(const string &s, const string &t, vector<int> &next, vector<int> &prev) {
    long long ans = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      int init = s[i] - 'a';
      int targ = t[i] - 'a';

      int fd = (targ - init + 26) % 26;
      int bd = (init - targ + 26) % 26;
      long long f = 0;
      for (int j = 0; j < fd; ++j) {
        f += next[(init + j) % 26];
      }

      long long b = 0;
      for (int j = 0; j < bd; ++j) {
        b += prev[(init - j + 26) % 26];
      }

      ans += min(f, b);
    }

    return ans;
  }
};