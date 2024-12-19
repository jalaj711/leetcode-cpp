#include<vector>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& a) {
    int n = a.size(),
        c = 0,
        k = 0,
        m;

    while(k < n) {
      m = a[k];
      while(k <= m) {
        m = max(m, a[k]);
        k++;
      }
      c++;
    }
    return c;
  }
};