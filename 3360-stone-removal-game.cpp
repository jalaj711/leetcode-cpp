class Solution {
public:
  bool canAliceWin(int n) {
    bool alice = false;
    int r = 10;

    while(n >= r) {
      n -= r;
      r--;
      alice = !alice;
    }
    return alice;
  }
};