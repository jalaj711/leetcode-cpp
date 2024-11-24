#include<vector>
using namespace std;
class Solution {
public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long sum = 0;
    int neg = 0;
    int minEl = 2e9;
    for (const auto &row: matrix) {
      for (const auto &num: row) {
        sum += abs(num);
        if (num < 0) neg++;
        minEl = min(minEl, abs(num));
      }
    }

    if (neg & 1) return sum - 2*minEl;

    return sum;
  }
};