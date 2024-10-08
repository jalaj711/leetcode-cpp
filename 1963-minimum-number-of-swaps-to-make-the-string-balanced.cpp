#include<string>
using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int n = s.size();
    int b = 0;
    int p1 = 0;
    int p2 = n-1;
    int ans = 0;

    while(p1 < p2) {
      if (s[p1] == '[') b++;
      else b--;

      if (b < 0) {
        while(s[p2--] != '['){};
        ans++;
        s[p2] = ']';
        s[p1] = '[';
        b+=2;
      }
      p1++;
    }
    return ans;
  }
};