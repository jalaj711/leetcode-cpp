class Solution {
public:
  int integerBreak(int n) {
    if (n <= 2) return 1;
    if (n == 3) return 2;

    int ans = 1;
    bool s = n%3 != 2;

    while (s ? n/3!=1 : n/3!=0) {
      ans *= 3;
      n -= 3;
    }
    if (n) ans *= n;
    return ans;
  }
};