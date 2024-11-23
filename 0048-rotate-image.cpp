#include<vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(), x, y, t;

    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n - 2 * i - 1; j++) {
        x = i;
        y = j + i;
        for (int k = 0; k < 3; k++) {
          t = matrix[x][y];
          matrix[x][y] = matrix[n - y - 1][x];
          matrix[n - y - 1][x] = t;
          t = x;
          x = n - y - 1;
          y = t;
        }

      }
    }
  }
};