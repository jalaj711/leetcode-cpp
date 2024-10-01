#include<vector>
#include<string>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int lp = 0,
        rp = 0,
        n1 = s1.size(),
        n2 = s2.size();

    if (n1 > n2) return false;

    vector<int> o (26, 0);
    vector<int> r (26, 0);

    for (auto ch: s1) o[ch-'a']++;

    while (rp < n1) {
      r[s2[rp] - 'a']++;
      rp++;

    }

    auto cmp = [&r, &o]() {
      for (int i=0;i<26;i++) {
        if (r[i] != o[i]) return false;
      }
      return true;
    };

    while (rp < n2) {
      if (cmp()) return true;

      // cout << "rp=" << rp << "r=";
      // for (int i=0;i<26;i++) {
      //     cout  << r[i] <<  "-";
      // }
      // cout << endl;

      r[s2[rp] - 'a']++;
      r[s2[lp] - 'a']--;
      rp++;
      lp++;
    }

    return cmp();
  }
};