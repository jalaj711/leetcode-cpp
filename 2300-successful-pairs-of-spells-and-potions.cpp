#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int ns = spells.size(),
        nm = potions.size(),
        l, r, a, m;
    vector<int> ans (ns);

    sort(potions.begin(), potions.end());
    for (int i=0;i<ns;i++) {
      l = 0;
      r = nm-1;
      a = 0;
      while(l <= r) {
        m = (l+r)/2;
        if ((long long)spells[i] * potions[m] >= success) {
          a = nm - m;
          r = m-1;
        } else {
          l = m+1;
        }
      }
      ans[i] = a;
    }
    return ans;
  }
};