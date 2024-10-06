#include<cmath>
#include<climits>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    if (x==0||x==INT_MIN) return 0;

    bool neg = x < 0;
    x = abs(x);

    int digit;
    int reverse = 0;
    int temp;
    int count = log10(x);

    if (count>9 || count==9&&((x%10)>2)) return 0;

    while(x!=0) {
      digit  = x%10;
      x = x/10;
      temp= digit * pow(10, count--);
      if (INT_MAX-reverse < temp) return 0;
      reverse += temp;
    }

    return reverse * (neg?-1:1);
  }
};