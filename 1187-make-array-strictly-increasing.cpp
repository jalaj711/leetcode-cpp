#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
  // binary search for the smallest element in arr2 which is
  // strictly greater than a
  int findReplacement(int a, vector<int> &arr2) {
    int l = 0,
        r = arr2.size() - 1,
        m, n = -1;
    while(l <= r) {
      m = (l+r)/2;
      if (arr2[m] > a) {
        n = m;
        r = m-1;
      } else l = m+1;
    }

    return n;
  }
  int solve(int idx, int prev, vector<int> &arr1, vector<int> &arr2, vector<unordered_map<int, int>> &dp) {
    if (idx >= arr1.size()) return 0;

    if (dp[idx].find(prev) != dp[idx].end()) return dp[idx][prev];
    int replace = -1, temp;

    // replace current element
    if ((temp=findReplacement(prev, arr2)) > -1) {
      replace = solve(idx + 1, arr2[temp], arr1, arr2, dp);
      if (replace != -1) replace++;
    }

    // skip replacing the current element
    if (arr1[idx] > prev) {
      int notreplace = solve(idx+1, arr1[idx], arr1, arr2, dp);
      if (replace == -1) replace = notreplace;
      else if(notreplace != -1) replace = min(replace, notreplace);
    }

    return dp[idx][prev] = replace;
  }
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end());
    vector<unordered_map<int, int>> dp(arr1.size());
    return solve(0, INT_MIN, arr1, arr2, dp);

  }
};