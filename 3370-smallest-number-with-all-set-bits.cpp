class Solution {
public:
  int smallestNumber(int n) {
    int c = 0;
    while(n) {
      c++;
      n >>= 1;
    }

    return (1 << c) - 1;
  }
};