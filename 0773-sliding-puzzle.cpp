#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
  // hash a board to an integer
  int hash(vector<vector<int>> &b) {
    int h = 0;
    h |= (b[0][0] & 7) << 0;
    h |= (b[0][1] & 7) << 3;
    h |= (b[0][2] & 7) << 6;
    h |= (b[1][0] & 7) << 9;
    h |= (b[1][1] & 7) << 12;
    h |= (b[1][2] & 7) << 15;
    return h;
  }

  // swap indices a and b in the board
  int swap(int board, int a, int b) {
    a *= 3;
    b *= 3;

    // extract
    int x = (board >> a) & 7;
    int y = (board >> b) & 7;

    // set to 0
    board = board & (~(7 << a));
    board = board & (~(7 << b));

    // set to required val
    board = board | (x << b);
    board = board | (y << a);

    return board;
  }

  // void printBoard(int b) {
  //     cout << ((b>>0)&7) << " " << ((b>>3)&7) << " " << ((b>>6)&7) << endl;
  //     cout << ((b>>9)&7) << " " << ((b>>12)&7) << " " << ((b>>15)&7) << endl;
  // }
  int slidingPuzzle(vector<vector<int>> &board) {
    unordered_set<int> v;
    // hash of target board
    int t = 0b000101100011010001;
    int swaps[4] = {-1, 1, -3, 3};

    // {hash, location of zero}
    queue<pair<int, int>> q;

    // find the zero and push it to queue and set for bfs
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0) {
          int b = hash(board);
          q.push({b, i * 3 + j});
          v.insert(b);
        }
      }
    }

    int l = 0;
    // standard bfs traversal where we go from the starting state
    // to each possible state
    while (!q.empty()) {
      int n = q.size();
      while (n--) {
        int b = q.front().first;
        int z = q.front().second;
        q.pop();
        if (b == t) return l;
        // cout << "process" << endl;
        // printBoard(b);

        for (const int &s: swaps) {
          int nz = z + s;
          if (
              nz > 5 ||
              nz < 0 ||
              (z == 3 && nz == 2) ||  // can't do a -1 from [1][0] to go to [0][2]
              (z == 2 && nz == 3)     // can't do a +1 from [0][2] to go to [1][0]
              )
            continue;

          int nb = swap(b, z, nz);
          // cout << z << " " << nz << endl;
          // printBoard(nb);
          if (v.find(nb) == v.end()) {
            q.push({nb, nz});
            v.insert(nb);
          }
        }
      }
      l++;
    }

    return -1;
  }
};