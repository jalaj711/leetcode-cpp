#include <vector>
using namespace std;

class Solution
{
    private:
    void dfs(int city, vector<vector<int>> &matrix, vector<int> &vis, int n) {
        vis[city] = 1;
        for(int i=0;i<n;i++) {
            if (matrix[city][i] == 1 && !vis[i]) {
                dfs(i, matrix, vis, n);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> vis (n, 0);
        int cnt = 0;

        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                dfs(i, isConnected, vis, n);
                cnt++;
            }
        }

        return cnt;
    }
};

int main(){
    vector<vector<int>> q {{1,1,0},{1,1,0},{0,0,1}};
    Solution s;
    s.findCircleNum(q);
}
