#include<vector>
using namespace std;

class Solution {
public:
  int minimizedMaximum(int n, vector<int>& q) {
    int l =      1, // left
        r = 100000, // right
        a =      0, // ans
        m,          // mid
        sum;        // sum at each stage

    // binary search
    while(l <= r) {
      m = l + (r-l)/2;
      sum = 0;
      // try to give m quantities to each shopkeeper
      // and count the number of shopkeepers we can accommodate
      // if that is more than what we have, we should increase
      // the value m, otherwise reduce it
      for(const auto &x: q) {
        sum += (x + m - 1) / m;  // ceil(x/m)
      }
      if(sum <= n) {
        a = m;
        r = m-1;
      } else {
        l = m+1;
      }
    }
    return a;
  }
};