#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    int count = 0;
    unordered_map<string, int> mp;
    int n = matrix[0].size();

    for(const auto &row: matrix) {
      string s = "*";
      for (int i=1;i<n;i++) {
        if (row[i] != row[i-1]) s+='|';
        s+='*';
      }

      if (++mp[s] > count) count = mp[s];
    }

    return count;
  }
};