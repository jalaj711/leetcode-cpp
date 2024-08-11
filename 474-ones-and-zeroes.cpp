#include<vector>
#include<string>

using namespace std;


// Solution 1: Recursion
//class Solution {
//public:
//    int recur(vector<pair<int, int>> &strs, int idx, int m, int n) {
//        if (idx >= strs.size() || m < 0 || n < 0) return 0;
//
//        int pick = INT_MIN;
//        if (m >= strs[idx].first && n >= strs[idx].second) pick = 1 + recur(strs, idx+1, m-strs[idx].first, n-strs[idx].second);
//        int notpick = recur(strs, idx+1, m, n);
//        return max(pick, notpick);
//    }
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector<pair<int, int>> que;
//        for (auto str: strs) {
//            pair<int, int> p{0, 0};
//            for (auto ch: str) {
//                p.first += ch == '0';
//                p.second += ch == '1';
//            }
//            que.push_back(p);
//        }
//        return recur(que, 0, m, n);
//    }
//};

// Solution 2: Tabulation
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        int sz = strs.size();
//        vector<pair<int, int>> que;
//
//        for (auto str: strs) {
//            pair<int, int> p{0, 0};
//            for (auto ch: str) {
//                p.first += ch == '0';
//                p.second += ch == '1';
//            }
//            que.push_back(p);
//        }
//
//        vector<vector<vector<int>>> memo(sz, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
//
//        for (int _m = que[sz-1].first;_m<=m;_m++) {
//            for (int _n = que[sz-1].second;_n<=n;_n++) {
//                memo[sz-1][_m][_n] = 1;
//            }
//        }
//
//        for (int idx = sz-2;idx >=0;idx--) {
//            for (int _m = 0;_m<=m;_m++) {
//                for (int _n = 0;_n<=n;_n++) {
//                    int pick = INT_MIN;
//                    if (_m >= que[idx].first && _n >= que[idx].second) pick = 1 + memo[idx+1][_m-que[idx].first][_n-que[idx].second];
//                    int notpick = memo[idx+1][_m][_n];
//                    memo[idx][_m][_n] = max(pick, notpick);
//                }
//            }
//        }
//
//        return memo[0][m][n];
//    }
//};


// Solution 3: Slightly better memory in tabulation
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        int sz = strs.size();
//        vector<pair<int, int>> que;
//
//        for (auto str: strs) {
//            pair<int, int> p{0, 0};
//            for (auto ch: str) {
//                p.first += ch == '0';
//                p.second += ch == '1';
//            }
//            que.push_back(p);
//        }
//
//        vector<vector<int>> curr(m+1, vector<int>(n+1, 0));
//        vector<vector<int>> prev(m+1, vector<int>(n+1, 0));
//
//        for (int _m = que[sz-1].first;_m<=m;_m++) {
//            for (int _n = que[sz-1].second;_n<=n;_n++) {
//                prev[_m][_n] = 1;
//            }
//        }
//
//        for (int idx = sz-2;idx >=0;idx--) {
//            for (int _m = 0;_m<=m;_m++) {
//                for (int _n = 0;_n<=n;_n++) {
//                    int pick = INT_MIN;
//                    if (_m >= que[idx].first && _n >= que[idx].second) pick = 1 + prev[_m-que[idx].first][_n-que[idx].second];
//                    int notpick = prev[_m][_n];
//                    curr[_m][_n] = max(pick, notpick);
//                }
//            }
//            prev = curr;
//        }
//
//        return prev[m][n];
//    }
//};

// Solution 4: Optimised Tabulation
class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        int sz = strs.size();
        vector<pair<int, int>> que;

        for (auto str: strs) {
            pair<int, int> p{0, 0};
            for (auto ch: str) {
                p.first += ch == '0';
                p.second += ch == '1';
            }
            que.push_back(p);
        }

        vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));

        for (int idx = sz - 1; idx >= 0; idx--)
            for (int _m = m; _m >= que[idx].first; _m--)
                for (int _n = n; _n >= que[idx].second; _n--)
                    curr[_m][_n] = max(curr[_m][_n], 1 + curr[_m - que[idx].first][_n - que[idx].second]);

        return curr[m][n];
    }
};