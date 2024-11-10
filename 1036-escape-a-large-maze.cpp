#include<vector>
#include<queue>
#include<unordered_set>
#include<cmath>
using namespace std;

class Solution {
public:
  // returns whether source is blocked such that it can't
  // reach target. 1 = can reach, 0 = can't
  int isLocked(vector<int>& source, vector<int>& target, unordered_set<long>& blocked) {
    int mdis = 0; // max distance yet
    int limit = 1e6;
    int dirs[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    queue<pair<int, int>> q;
    q.push({source[0], source[1]});

    unordered_set<long> vis;
    // with a maximum of 200 blocking squares, if we are able to move
    // to a distance more than 280 in cartesian plane, then there's
    // no possible way to block
    //
    // and also, if at any point, we have more elements in our queue
    // than the number of blocks then the blockade can't stop the
    // wave front.
    while(!q.empty() && mdis <= 280 && q.size() <= blocked.size()) {
      int sz = q.size();
      while(sz--) {
        const auto fr = q.front();
        q.pop();

        int dis = sqrt(pow(source[0]-fr.first, 2) + pow(source[1] - fr.second, 2));
        mdis = max(mdis, dis);

        for(const auto &dir: dirs) {
          int nx = fr.first + dir[0];
          int ny = fr.second + dir[1];

          if (
              nx < 0 ||
              ny < 0 ||
              nx >= limit ||
              ny >= limit
              ) continue;

          // early return if target is found
          if (nx == target[0] && ny == target[1]) return 1;

          long hash = ((long)nx << 20) | ny;
          if (blocked.find(hash) != blocked.end() || vis.find(hash) != vis.end()) continue;

          vis.insert(hash);
          q.push({nx, ny});
        }
      }
    }

    if (q.size() > blocked.size()) return 1;
    return mdis > 280;
  }
  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    unordered_set<long> bl;

    for(const auto &pt: blocked) {
      bl.insert(((long)pt[0]<<20) | pt[1]);
    }
    // for blocked to stop a path from source to target,
    // it must either form a loop around source or target
    return isLocked(target, source, bl) && isLocked(source, target, bl);
  }
};