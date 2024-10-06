#include<vector>

using namespace std;

class Solution {
public:
  int dirs[8][2] = {{0,  1},
                    {0,  -1},
                    {1,  0},
                    {-1, 0},
                    {-1, -1},
                    {-1, 1},
                    {1,  -1},
                    {1,  1}};
  int m, n;

  void reveal(int x, int y, vector<vector<char>> &board) {
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
      return;
    } else if (board[x][y] != 'E') return;

    int mines = 0;
    vector<pair<int, int>> toReveal;
    board[x][y] = 'B';

    for (const auto &dir: dirs) {
      int nx = x + dir[0];
      int ny = y + dir[1];
      if (
          nx >= 0 &&
          ny >= 0 &&
          nx < m &&
          ny < n
          ) {
        if (board[nx][ny] == 'E') toReveal.push_back({nx, ny});
        else if (board[nx][ny] == 'M') mines++;
      }
    }

    if (mines) board[x][y] = '0' + mines;
    else
      for (const auto &coord: toReveal)
        reveal(coord.first, coord.second, board);
  }

  vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
    m = board.size();
    n = board[0].size();

    reveal(click[0], click[1], board);

    return board;
  }
};