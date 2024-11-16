#include<string>
#include<vector>

using namespace std;

//class Solution {
//public:
//  string longestPalindrome(string s) {
//    int n = s.size();
//
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//    int len = 1;
//    int maxi = 0;
//
//    for (int i = n - 1; i >= 0; i--) {
//      dp[i][i] = 1;
//      for (int j = i + 1; j < n; j++) {
//        if (s[i] == s[j]) {
//          // if the inner string is not already a palindrome then it can
//          // be a valid palindrome only if i and j are consecutive.
//          // So in the string "abbca" dp[1][2] should be 2
//          // but dp[0][4] should not be 2, rather it should be 0;
//          if (dp[i + 1][j - 1] == 0 && i != j - 1) continue;
//          dp[i][j] = 2 + dp[i + 1][j - 1];
//          if (dp[i][j] > len) {
//            len = dp[i][j];
//            maxi = j;
//          }
//        }
//      }
//    }
//    return s.substr(maxi - len + 1, len);
//  }
//};

// space optimised tabulation
class Solution {
public:
  string longestPalindrome(const string &s) {
    int n = s.size();

    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);
    int len = 1;
    int maxi = 0;

    for (int i=n-1;i>=0;i--) {
      curr[i] = 1;
      for (int j=i+1;j<n;j++) {
        if (s[i] == s[j] && !(prev[j-1] == 0 && i != j-1)) {
          curr[j] = 2 + prev[j-1];
          if (curr[j] > len) {
            len = curr[j];
            maxi = j;
          }
        } else curr[j] = 0;
      }
      prev = curr;
    }
    return s.substr(maxi-len+1, len);
  }
};

// TODO: Optimise this with Manacher's Algortihm
