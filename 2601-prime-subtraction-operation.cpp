#include<vector>
using namespace std;

static vector<int> primes;
static bool generated = false;

class Solution {
public:
  void primeSieve(int begin, vector<int> &input) {
    primes.push_back(begin);
    int nextBegin = -1;
    vector<int> nextInput;

    for(const int &in: input) {
      if (in%begin != 0) {
        if (nextBegin == -1) nextBegin = in;
        else nextInput.push_back(in);
      }
    }

    if (nextBegin != -1) primeSieve(nextBegin, nextInput);
  }

  // fing the largest prime smaller than n
  int findPrime(int n) {
    int l = 0;
    int r = primes.size() - 1;
    int m, a = -1;
    while( l <= r) {
      m = (l+r)/2;
      if (primes[m] >= n) {
        r = m-1;
      } else {
        a = m;
        l = m+1;
      }
    }
    return a;
  }
  bool primeSubOperation(vector<int>& nums) {
    if (!generated) {
      vector<int> all(999);
      for(int i=2;i<=1000;i++) all[i-2] = i;
      generated = true;
      primeSieve(2, all);
    }

    int lastNum = 0;
    for (const auto &n: nums) {
      if(n <= lastNum) return false;

      // apply the given operation greedily
      int prime = findPrime(n-lastNum);
      if (prime == -1) lastNum = n;
      else lastNum = n-primes[prime];
    }

    return true;
  }
};