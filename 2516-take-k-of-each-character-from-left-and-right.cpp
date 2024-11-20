#include<string>
using namespace std;

class Solution {
public:
  int takeCharacters(const string &s, int k) {
    if (k == 0) return 0;
    int n = s.size();
    int la = 0, lb = 0, lc = 0, ra = 0, rb = 0, rc = 0;

    for(int i=0;i<n;i++) {
      la += (s[i] == 'a');
      lb += (s[i] == 'b');
      lc += (s[i] == 'c');
    }

    if (la < k || lb < k || lc < k) return -1;

    int a = n, r = n-1, l = 0;
    la = s[0] == 'a';
    lb = s[0] == 'b';
    lc = s[0] == 'c';
    ra = s[n-1] == 'a';
    rb = s[n-1] == 'b';
    rc = s[n-1] == 'c';

    while ((la+ra < k) || (lb+rb<k) || (lc+rc < k)) {
      r--;
      ra += s[r] == 'a';
      rb += s[r] == 'b';
      rc += s[r] == 'c';
      // cout << l << " " << r << endl;
    }

    a = l+n-r+1;

    l = 1;
    while (l < n && r < n) {
      la += s[l] == 'a';
      lb += s[l] == 'b';
      lc += s[l] == 'c';
      // cout << l << " " << r << endl;


      while (((la+ra >= k) && (lb+rb >= k) && (lc+rc >= k)) && r < n) {
        ra -= s[r] == 'a';
        rb -= s[r] == 'b';
        rc -= s[r] == 'c';
        a = min(a, l+n-r+1);
        r++;

        // cout << l << " " << r << endl;
      }
      if (r >= n && la>=k && lb >= k && lc >= k) a = min(a, l+1);
      // cout << l << " " << r << " " << a << endl;
      // cout << "l=" << la << " " << lb << " " << lc << endl;
      // cout << "r=" << ra << " " << rb << " " << rc << endl;
      l++;
    }

    return a;
  }
};
// TODO: Add the two pointer approach (optimised solution)