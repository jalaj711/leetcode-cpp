#include<vector>
using namespace std;

// Solution 1: 279ms beats 5%
//class Solution {
//public:
//  int countSquares(vector<vector<int>>& matrix) {
//    int m = matrix.size();
//    int n = matrix[0].size();
//
//    for (int i=1;i<m;i++) matrix[i][0] += matrix[i-1][0];
//    for (int j=1;j<n;j++) matrix[0][j] += matrix[0][j-1];
//
//    for (int i=1;i<m;i++) {
//      for(int j=1;j<n;j++) {
//        matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
//      }
//    }
//
//    int count = 0;
//    for (int s=0;s<min(m,n);s++) {
//      for (int i=0;i+s<m;i++) {
//        for (int j=0;j+s<n;j++) {
//          int sum = matrix[i+s][j+s];
//          if (i > 0) sum -= matrix[i-1][j+s];
//          if (j > 0) sum -= matrix[i+s][j-1];
//          if (i > 0 && j > 0) sum += matrix[i-1][j-1];
//
//          if (sqrt(sum) == s+1) {
//            count++;
//          }
//        }
//      }
//    }
//    return count;
//  }
//};

// Solution 2: 0ms beats 100%
class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int count = 0;
    for (int i=0;i<m;i++) {
      for (int j=0;j<n;j++) {
        if (i > 0 && j > 0 && matrix[i][j]) {
          int s = matrix[i-1][j-1];
          int k=1;
          while(k <= s) {
            if (matrix[i-k][j] == 0 || matrix[i][j-k] == 0) break;
            k++;
          }
          matrix[i][j] = k;
          count += k;
        } else {
          count += matrix[i][j];
        }
      }
    }

    return count;
  }
};