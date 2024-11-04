#include<vector>
#include<queue>
#include<climits>
#define vi vector<int>

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

    // {distance, x coord, y coord, addition}
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    vector<vector<int>> dis (m, vector<int> (n, INT_MAX));
    dis[0][0] = 0;

    pq.push({0,0,0,1});
    while(!pq.empty()) {
      int d = pq.top()[0];
      int x = pq.top()[1];
      int y = pq.top()[2];
      int a = pq.top()[3];
      pq.pop();

      for(const auto &dir: dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];

        if (
            nx >= 0 &&
            ny >= 0 &&
            nx < m  &&
            ny < n  &&
            max(d, moveTime[nx][ny])+a < dis[nx][ny]
            ) {
          dis[nx][ny] = max(d, moveTime[nx][ny])+a;
          pq.push({dis[nx][ny],nx, ny,a==1?2:1});
        }
      }
    }
    return dis[m-1][n-1];
  }
};