#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; i++) {
            if (i != headID) {
                adj[manager[i]].push_back(i);
            }
        }
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({headID, 0});
        int sz;
        pair<int, int> fr;
        int tme;
        while (!q.empty()) {
            sz = q.size();
            while (sz--) {
                fr = q.front();
                q.pop();
                tme = fr.second + informTime[fr.first];
                for (auto i: adj[fr.first]) {
                    q.push({i, tme});
                }
                if (adj[fr.first].empty()) {
                    ans = max(ans, tme);
                }
            }
        }
        return ans;
    }
};