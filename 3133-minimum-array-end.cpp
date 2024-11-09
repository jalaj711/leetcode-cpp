class Solution {
public:
  long long minEnd(int n, int x) {
    long long num = x;
    int i=0;
    n--;
    while(n != 0) {
      if (((num >> i) & 1) == 0) {
        num |= (((long long)(n&1))<<i);
        n = n >> 1;
      }
      i++;
    }

    return num;
  }
};