#include<vector>
using namespace std;

class Solution {
public:

  int numOfSubarrays(vector<int>& arr) {
    int n = arr.size();
    int inf = 1e9+7;
    // count of evens and odds
    int p[2] = {0,0};

    // convert arr[0] to 0 if its even else 1
    arr[0] = arr[0] & 1;
    p[arr[0]]++;

    int count = arr[0];

    for (int i=1;i<n;i++) {
      // convert arr[i] to 0 if sum till this
      // position is even else 1
      arr[i] = (arr[i] & 1) ^ arr[i-1];

      count = (
                  count
                  // if arr[i] itself is odd then we can make
                  // a singleton with it
                  + arr[i]
                  // we can create a subarray starting from any
                  // index with sum opposite of arr[i]
                  + p[arr[i]^1]
              )%(inf);
      p[arr[i]]++;
    }
    return count;
  }
};