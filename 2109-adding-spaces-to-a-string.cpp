#include<vector>
#include<string>
using namespace std;

class Solution {
public:
  string addSpaces(const string &s, vector<int>& sp) {
    int n = s.size();
    int m = sp.size();
    string a(n+m, ' ');

    int j = 0;
    for (int i=0;i<n;i++) {
      if (j<m && i == sp[j]) {
        j++;
      }
      a[i+j] = s[i];
    }
    return a;
  }
};