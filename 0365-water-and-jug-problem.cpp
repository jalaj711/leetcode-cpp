#include<unordered_map>
using namespace std;

class Solution {
public:
  int t, cx, cy;
  unordered_map<int, int> vis;
  bool dfs(int x, int y) {
    if (x + y == t)
      return true;
    const int k = x * 1000 + y;
    if (vis.find(k) != vis.end()) {
      if (vis[k] == -1)
        return false;
      return vis[k];
    }

    vis[k] = -1;

    // cout << "called x=" << x << "y=" << y << endl;

    // fill x completely
    if (dfs(cx, y))
      return vis[k] = 1;
    // fill y completely
    if (dfs(x, cy))
      return vis[k] = 1;
    // empty x
    if (dfs(0, y))
      return vis[k] = 1;
    // empty y
    if (dfs(x, 0))
      return vis[k] = 1;
    // transfer from x to y
    int nx, ny;
    if (cy - y > x) {
      nx = 0;
      ny = y + x;
    } else {
      ny = cy;
      nx = x - cy + y;
    }
    if (dfs(nx, ny))
      return vis[k] = 1;

    // transfer from y to x
    if (cx - x > y) {
      ny = 0;
      nx = y + x;
    } else {
      nx = cx;
      ny = y - cx + x;
    }
    if (dfs(nx, ny))
      return vis[k] = 1;

    return vis[k] = 0;
  }
  bool canMeasureWater(int x, int y, int target) {
    cx = x;
    cy = y;
    t = target;

    return dfs(0, 0);
  }
};