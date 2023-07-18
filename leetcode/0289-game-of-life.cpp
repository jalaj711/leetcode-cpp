#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class Solution
{
private:
    int countNeighours(int i, int j, int m, int n, vector<vector<int>> &board)
    {
        int cnt = 0;
        bool checkUp = i != 0, checkDown = i != m - 1, checkLeft = j != 0, checkRight = j != n - 1;
        if (checkUp)
            cnt += board[i - 1][j];
        if (checkDown)
            cnt += board[i + 1][j];
        if (checkLeft)
            cnt += board[i][j - 1];
        if (checkRight)
            cnt += board[i][j + 1];
        if (checkLeft && checkUp)
            cnt += board[i - 1][j - 1];
        if (checkLeft && checkDown)
            cnt += board[i + 1][j - 1];
        if (checkRight && checkUp)
            cnt += board[i - 1][j + 1];
        if (checkRight && checkDown)
            cnt += board[i + 1][j + 1];
        return cnt;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        int nc;
        vector<vector<int>> nboard = board;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nc = countNeighours(i, j, m, n, board);
                if (board[i][j] && (nc < 2 || nc > 3))
                    nboard[i][j] = 0;
                else if (nc == 3)
                    nboard[i][j] = 1;
            }
        }
        board = nboard;
        return;
    }
};

int main()
{
    vector<vector<int>> q{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution s;
    s.gameOfLife(q);
    // cout << ~0b1 << " " << ~0;
}
