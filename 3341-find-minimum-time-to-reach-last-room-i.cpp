#include<vector>
#include<queue>
#include<climits>
#define pii pair<int, int>
#define ppi pair<int, pii>

using namespace std;

class Solution {
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int m = moveTime.size();
    int n = moveTime[0].size();

    int dirs[4][2] = {
        {0,1},
        {0,-1},
        {1, 0},
        {-1, 0}
    };

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    vector<vector<int>> dis (m, vector<int> (n, INT_MAX));
    dis[0][0] = 0;

    pq.push({0, {0, 0}});
    while(!pq.empty()) {
      int x = pq.top().second.first;
      int y = pq.top().second.second;
      int d = pq.top().first;
      pq.pop();

      for(const auto &dir: dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];

        if (
            nx >= 0 &&
            ny >= 0 &&
            nx < m  &&
            ny < n  &&
            max(d, moveTime[nx][ny])+1 < dis[nx][ny]
            ) {
          dis[nx][ny] = max(d, moveTime[nx][ny])+1;
          pq.push({dis[nx][ny], {nx, ny}});
        }
      }
    }
    return dis[m-1][n-1];
  }
};