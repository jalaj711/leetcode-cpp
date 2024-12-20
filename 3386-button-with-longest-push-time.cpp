#include<vector>
using namespace std;

class Solution {
public:
  int buttonWithLongestTime(vector<vector<int>>& ev) {
    int p = 0, m = 0, a = 1e6;
    for (const auto &e: ev) {
      if (e[1] - p > m) {
        m = e[1] - p;
        a = e[0];
      } else if (e[1] - p == m) {
        a = min(a, e[0]);
      }
      p = e[1];
    }

    return a;
  }
};