#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    int m = box.size();
    int n = box[0].size();

    vector<vector<char>> rot(n, vector<char>(m, '.'));


    for (int i = 0; i < m; i++) {
      int f = n - 1;
      for (int j = n - 1; j >= 0; j--) {
        if (box[i][j] == '*') {
          rot[j][m - i - 1] = '*';
          f = j - 1;
        } else if (box[i][j] == '#') {
          rot[f][m - i - 1] = '#';
          f--;
        }
      }
    }

    return rot;
  }
};