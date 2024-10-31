#include<vector>
#include<algorithm>
using namespace std;

// Solution 1: Recursion + Memoization
// Gives TLE
//  class Solution {
//  public:
//    long long solve(int r, int f, vector<int>& robot, vector<int>& factory, vector<vector<long long>> &dp) {
//      if (r >= robot.size()) return 0;
//      if (f >= factory.size()) return -1;
//
//      if (dp[r][f] > -2) return dp[r][f];
//
//      long long pick = solve(r+1, f+1, robot, factory, dp);
//      if (pick != -1) pick += abs(robot[r] - factory[f]);
//      long long skip = solve(r, f+1, robot, factory, dp);
//
//      if (pick == -1) return skip;
//      if (skip == -1) return pick;
//
//      return dp[r][f] = min(skip, pick);
//    }
//    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//      sort(robot.begin(), robot.end());
//      sort(factory.begin(), factory.end(), [](const vector<int> &a, const vector<int> &b) {
//        return a[0] < b[0];
//      });
//
//      vector<int> unpacked;
//      for (const auto &fact: factory) {
//        for(int i=0;i<fact[1];i++) unpacked.push_back(fact[0]);
//      }
//
//      int nr = robot.size();
//      int nf = unpacked.size();
//
//      vector<vector<long long>> dp (nr+1, vector<long long> (nf+1, -2));
//
//      return solve(0, 0, robot, unpacked, dp);
//    }
//  };

// Solution 2: Tabulation
// 59ms, beats 65.52%
// 67.5MB, beats 33.13%
//  class Solution {
//  public:
//    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//      sort(robot.begin(), robot.end());
//      sort(factory.begin(), factory.end(), [](const vector<int> &a, const vector<int> &b) {
//        return a[0] < b[0];
//      });
//
//      vector<int> unpacked;
//      for (const auto &fact: factory) {
//        for(int i=0;i<fact[1];i++) unpacked.push_back(fact[0]);
//      }
//
//      int nr = robot.size();
//      int nf = unpacked.size();
//
//      vector<vector<long long>> dp (nr+1, vector<long long> (nf+1, 0));
//      for (int i=0;i<nr;i++) {
//        dp[i][nf] = -1;
//      }
//
//      for(int r=nr-1;r>=0;r--) {
//        for(int f=nf-1;f>=0;f--) {
//          long long pick = dp[r+1][f+1];
//          if (pick != -1) pick += abs(robot[r] - unpacked[f]);
//          long long skip = dp[r][f+1];
//
//          if (pick == -1) dp[r][f] = skip;
//          else if (skip == -1) dp[r][f] = pick;
//          else dp[r][f] = min(skip, pick);
//        }
//      }
//
//      return dp[0][0];
//    }
//  };

// Solution 3: Tabulation with better space
// 43ms, beats 82%
// 13.06MB, beats 61%
//  class Solution {
//  public:
//    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//      sort(robot.begin(), robot.end());
//      sort(factory.begin(), factory.end(), [](const vector<int> &a, const vector<int> &b) {
//        return a[0] < b[0];
//      });
//
//      vector<int> unpacked;
//      for (const auto &fact: factory) {
//        for(int i=0;i<fact[1];i++) unpacked.push_back(fact[0]);
//      }
//
//      int nr = robot.size();
//      int nf = unpacked.size();
//
//      vector<long long> prev (nf+1, 0);
//      vector<long long> curr (nf+1, 0);
//      curr[nf] = -1;
//
//      for(int r=nr-1;r>=0;r--) {
//        for(int f=nf-1;f>=0;f--) {
//          long long pick = prev[f+1];
//          if (pick != -1) pick += abs(robot[r] - unpacked[f]);
//          long long skip = curr[f+1];
//
//          if (pick == -1) curr[f] = skip;
//          else if (skip == -1) curr[f] = pick;
//          else curr[f] = min(skip, pick);
//        }
//        prev = curr;
//      }
//
//      return prev[0];
//    }
//  };

// Solution 4: Space optimised tabulation
// 27ms, beats 93%
// 12MB, beats 84%
class Solution {
public:
  long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    });

    vector<int> unpacked;
    for (const auto &fact: factory) {
      for(int i=0;i<fact[1];i++) unpacked.push_back(fact[0]);
    }

    int nr = robot.size();
    int nf = unpacked.size();

    vector<long long> curr (nf+1, 0);
    long long f1 = -1;

    for(int r=nr-1;r>=0;r--) {
      f1 = -1;
      for(int f=nf-1;f>=0;f--) {
        long long pick = curr[f+1];
        curr[f+1] = f1;
        if (pick != -1) pick += abs(robot[r] - unpacked[f]);
        long long skip = curr[f+1];

        if (pick == -1) f1 = skip;
        else if (skip == -1) f1 = pick;
        else f1 = min(skip, pick);
      }
      curr[0] = f1;
    }

    return f1;
  }
};