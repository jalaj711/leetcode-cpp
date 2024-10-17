#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
  int maximumSwap(int num) {
    if (num == 0)
      return 0;

    int i = log10(num);
    int n = i+1;

    vector<int> digits(n);
    vector<int> maxRight(n);

    maxRight[i] = -1;

    // populate digits and maxRight
    while (num > 0) {
      digits[i] = num % 10;
      if (i < n-1) {
        if (maxRight[i+1] == -1 || digits[i+1] > digits[maxRight[i+1]]) {
          maxRight[i] = i+1;
        } else {
          maxRight[i] = maxRight[i+1];
        }
      }
      i--;
      num /= 10;
    }

    // build the number back
    i = 0;
    while (i < n && (maxRight[i] == -1 || digits[i] >= digits[maxRight[i]])) {
      num = num * 10 + digits[i];
      i++;
    }
    // number is already max possible
    if (i==n) return num;

    // swap
    swap(digits[i], digits[maxRight[i]]);
    while(i < n) {
      num = num * 10 + digits[i];
      i++;
    }
    return num;
  }
};