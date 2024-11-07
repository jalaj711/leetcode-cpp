#include<vector>
using namespace std;

class Solution {
public:
  int largestCombination(vector<int>& c) {
    int n = c.size();

    int msz = 0;

    for(int i=0;i<24;i++) {
      int sz = 0;

      for(int j=0;j<n;j++) {
        if ((c[j] >> i) & 1) sz++;
      }

      msz = max(sz, msz);
    }

    return msz;
  }
};