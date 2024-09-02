#include<vector>

using namespace std;

class Solution {
public:
    vector<int> par;

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries) {
        vector<bool> ans;


        if (threshold == 0) {
            ans.resize(queries.size(), true);
            return ans;
        }

        par.resize(n + 1);

        for (int i = 0; i <= n; i++) par[i] = i;

        int m;
        // Construct the graph
        for (int i = threshold + 1; i <= n; i++) {
            m = i * 2;
            // iterate through all multiples of i
            while (m <= n) {
                // perform union
                par[find(i)] = find(m);
                m += i;
            }
        }
        for (auto query: queries) {
            // check if both are connected
            ans.push_back(find(query[0]) == find(query[1]));
        }
        return ans;
    }
};