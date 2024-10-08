#include<cmath>
using namespace std;

class Solution {
public:
  // returns the number of digits to the left of n (including n)
  unsigned long digitsOnLeft(unsigned long n) {
    if (n <= 0) return 0;
    int l = log10(n);
    return (n-pow(10,l)+1)*(l+1) + digitsOnLeft(pow(10,l)-1);
  }

  int findNthDigit(int n) {
    int l = 0,
        r = n,
        m;

    // this is the number which contains our required digit
    int ans = n;

    // binary search for the number with required digit
    while(l <= r) {
      m = (l+r)/2;
      if (digitsOnLeft(m) >= n) {
        ans = m;
        r = m-1;
      } else {
        l = m+1;
      }
    }

    // extract the nth digit from the final number
    n -= digitsOnLeft(ans-1);
    n = log10(ans)-n+1;
    ans = ans/pow(10, n);

    return ans%10;
  }
};