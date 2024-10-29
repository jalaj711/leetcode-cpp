#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  // binary search to find the next job that starts after endTime
  int findNextJob(int endTime, vector<int> &pos,  vector<int> &startTime) {
    int l = 0,
        r = pos.size() - 1,
        m, a = -1;
    while(l <= r) {
      m = (l+r)/2;
      if (startTime[pos[m]] >= endTime) {
        a = m;
        r = m-1;
      } else l = m+1;
    }
    return a;
  }
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<int> pos(n);
    vector<int> dp(n+1, 0);
    for (int i=0;i<n;i++) pos[i] = i;

    // sort pos according to startTime
    sort(pos.begin(), pos.end(), [&startTime, &endTime, &profit](int a, int b) {
      if (startTime[a] != startTime[b]) return startTime[a] < startTime[b];
      if (endTime[a] != endTime[b]) return endTime[a] < endTime[b];
      return profit[a] < profit[b];
    });

    // bottom-up dp
    for(int idx=n-1;idx>=0;idx--) {

      // check if there is another job after this one
      int perform = findNextJob(endTime[pos[idx]], pos, startTime);

      // doing this job gets us profit[pos[idx]] and depending
      // on whether there is a job after this, we can perform that
      if (perform == -1) perform = profit[pos[idx]];
      else perform = profit[pos[idx]] + dp[perform];

      // dp[idx+1] is the profit that we earn when we skip
      // this job to perform the next earliest job
      dp[idx] = max(perform, dp[idx+1]);
    }

    return dp[0];
  }
};