#include<vector>

using namespace std;

class Solution {
public:
  // binary search for largest value in arr smaller than or
  // equal to val, between the indices l and r
  int findLower(int val, int l, int r, vector<int> &arr) {
    int m, a = -1;

    while (l <= r) {
      m = l + (r - l) / 2;
      if (arr[m] <= val) {
        a = m;
        l = m + 1;
      } else r = m - 1;
    }

    return a;
  }

  int findLengthOfShortestSubarray(vector<int> &arr) {
    int n = arr.size();
    int fr = 0;
    int bk = n - 1;

    // largest non-decreasing subarray starting from the
    // beginning of the arr
    for (int i = 1; i < n; i++) {
      if (arr[i] >= arr[fr]) fr++;
      else break;
    }
    // already sorted
    if (fr == n - 1) return 0;

    // largest non-decreasing sub array ending at the end of arr
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] <= arr[bk]) bk--;
      else break;
    }

    // initialise the ans with either deleting everything except
    // the beginning sorted subarray or the ending subarray
    int ans = min(n - fr - 1, bk);
    int l = -1;

    // for each element in the ending subarray, find the largest
    // elem in starting subarray which can form a valid prefix to
    // make a sorted array and update the answer accordingly
    for (int i = bk; i < n; i++) {
      l = findLower(arr[i], l + 1, fr, arr);
      if (l == -1) ans = min(ans, i);
      else ans = min(ans, i - l - 1);

      // if the largest smallest element is fr, then break because
      // smaller distance than this is not possible
      if (l == fr) break;
    }

    return ans;
  }
};