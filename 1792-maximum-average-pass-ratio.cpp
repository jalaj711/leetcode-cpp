#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
  double maxAverageRatio(vector<vector<int>>& c, int e) {
    priority_queue<pair<float, int>> pq;
    int n = c.size();
    for(int i=0;i<n;i++) {
      float change = (float)(c[i][0]+1)/(c[i][1]+1) - (float)c[i][0] / c[i][1];
      pq.push({change, i});
    }

    while(e--) {
      int i = pq.top().second;
      pq.pop();
      c[i][0]++;
      c[i][1]++;
      float change = (float)(c[i][0]+1)/(c[i][1]+1) - (float)c[i][0] / c[i][1];
      pq.push({change, i});
    }

    double avg = 0;
    for (const auto &a: c) avg += (double)a[0]/a[1];
    return avg / n;
  }
};
