#include<string>
using namespace std;

//Solution 1: Recursion
//class Solution {
//public:
//    int recur(string &s, int idx, int n, vector<int> &memo) {
//        if (idx >= n) return 1;
//        if (s[idx] == '0') return 0;
//        if (idx == n-1) return 1;
//        if (memo[idx] > -1) return memo[idx];
//
//        int sng = recur(s, idx+1, n, memo);
//        int one = 0;
//        if (s[idx] == '1')
//            one = (recur(s, idx+2,n, memo));
//        int two = 0;
//        if(s[idx] == '2' && idx < n-1 && s[idx+1] <= '6')
//            two = (recur(s, idx+2, n, memo));
//        return memo[idx] = sng+one+two;
//    }
//    int numDecodings(string s) {
//        vector<int> memo (s.size(), -1);
//        return recur(s, 0, s.size(), memo);
//    }
//};

//Solution 2: Tabulation
//class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.size();
//        vector<int> memo (n, 0);
//        memo[n-1] = s[n-1] != '0';
//        if (n>1) memo[n-2] = s[n-2]=='0'?0:((s[n-2] == '1' ? 1:0) + (s[n-2] == '2' && s[n-1] < '7' ? 1:0) + memo[n-1]);
//        for (int i=n-3;i>=0;i--) {
//            if (s[i] == '0') {
//                memo[i] = 0;
//                continue;
//            }
//            int sng = memo[i+1];
//            int one = 0;
//            if (s[i] == '1')
//                one = memo[i+2];
//            int two = 0;
//            if(s[i] == '2' && i < n-1 && s[i+1] <= '6')
//                two = (memo[i+2]);
//            memo[i] = sng+one+two;
//        }
//        return memo[0];
//    }
//};

//Solution 3: Optimised tabulation
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int plus_two = s[n - 1] != '0';

        if (n == 1)
            return plus_two;

        int plus_one =
                s[n - 2] == '0'
                ? 0
                : ((s[n - 2] == '1' ? 1 : 0) +
                   (s[n - 2] == '2' && s[n - 1] < '7' ? 1 : 0) + plus_two);
        int curr;
        for (int i = n - 3; i >= 0; i--) {
            if (s[i] == '0') curr = 0;
            else {
                curr = plus_one;
                if (s[i] == '1')
                    curr += plus_two;
                if (s[i] == '2' && i < n - 1 && s[i + 1] <= '6')
                    curr += (plus_two);
            }
            plus_two = plus_one;
            plus_one = curr;
        }
        return plus_one;
    }
};