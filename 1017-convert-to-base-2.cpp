#include<string>
using namespace std;

class Solution {
public:
  string baseNeg2(int n) {
    if (n==0) return "0";
    string ans = "";
    while(n != 0) {
      int d = n % (-2);
      n = n/(-2);
      if (d<0) {
        d += 2;
        n++;
      }
      ans += '0'+d;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};