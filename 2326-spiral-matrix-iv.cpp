#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        int dirs[4][2] = {{0,  1},
                          {1,  0},
                          {0,  -1},
                          {-1, 0}};
        int dir = 0;
        int ni, nj;
        while (i < m && j < n && head) {
            ans[i][j] = head->val;
            head = head->next;
            ni = i + dirs[dir][0];
            nj = j + dirs[dir][1];
            if (
                    ni > m - 1 ||
                    nj > n - 1 ||
                    ni < 0 ||
                    nj < 0 ||
                    ans[ni][nj] > -1
                    ) {
                dir = (dir + 1) % 4;
                ni = i + dirs[dir][0];
                nj = j + dirs[dir][1];
            }
            i = ni;
            j = nj;
        }
        return ans;
    }
};