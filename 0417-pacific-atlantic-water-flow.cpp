#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
  int dirs[4][2] = {
      {0,  1},
      {1,  0},
      {-1, 0},
      {0,  -1}
  };
  int m, n;

  void discoverPacific(vector<vector<bool>> &pacific, vector<vector<int>> &heights) {
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vis[0][0] = true;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto fr = q.front();
      q.pop();
      // cout << "pushing " << fr.first << " " <<  fr.second << " to pacific" << endl;
      pacific[fr.first][fr.second] = true;

      for (const auto &dir: dirs) {
        int ni = fr.first + dir[0];
        int nj = fr.second + dir[1];

        if (
            ni < 0 ||
            nj < 0 ||
            ni >= m ||
            nj >= n ||
            vis[ni][nj]
            )
          continue;

        if (ni == 0 || nj == 0 || heights[ni][nj] >= heights[fr.first][fr.second]) {
          vis[ni][nj] = true;
          q.push({ni, nj});
        }
      }
    }
  }

  void discoverAtlantic(vector<vector<bool>> &pacific, vector<vector<int>> &heights, vector<vector<int>> &ans) {
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    queue<pair<int, int>> q;
    q.push({m - 1, n - 1});
    vis[m - 1][n - 1] = true;

    while (!q.empty()) {
      auto fr = q.front();
      q.pop();
      // cout << "pushing " << fr.first << " " <<  fr.second << " to atlantic" << endl;
      if (pacific[fr.first][fr.second]) {
        ans.push_back({fr.first, fr.second});
      }

      for (const auto &dir: dirs) {
        int ni = fr.first + dir[0];
        int nj = fr.second + dir[1];

        if (
            ni < 0 ||
            nj < 0 ||
            ni >= m ||
            nj >= n ||
            vis[ni][nj]
            )
          continue;

        if (ni == m - 1 || nj == n - 1 || heights[ni][nj] >= heights[fr.first][fr.second]) {
          vis[ni][nj] = true;
          q.push({ni, nj});
        }
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    m = heights.size();
    n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<int>> ans;

    discoverPacific(pacific, heights);
    discoverAtlantic(pacific, heights, ans);

    return ans;
  }
};