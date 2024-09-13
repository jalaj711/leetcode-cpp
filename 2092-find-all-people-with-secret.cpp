#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// Solution 1
// Using Djisktra's
// Beats 50%
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {

        // adjacency list
        // adj[i][j] = [node, weight]
        vector<vector<pair<int, int>>> adj(n);

        for (auto meet: meetings) {
            adj[meet[0]].push_back({meet[1], meet[2]});
            adj[meet[1]].push_back({meet[0], meet[2]});
        }

        adj[0].push_back({firstPerson, 0});
        adj[firstPerson].push_back({0, 0});


        // {time, node}
        priority_queue<
                pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>
        > pq;

        pq.push({0, 0});

        // time at which each person gets the secret
        vector<int> dis(n, 1e9);
        vector<int> ans{0};
        dis[0] = 0;
        while (!pq.empty()) {
            auto fr = pq.top();
            int time = fr.first;
            int node = fr.second;
            pq.pop();
            for (auto child: adj[node]) {
                int elem = child.first;
                int weight = child.second;
                if (weight < time) continue;
                if (weight < dis[elem]) {
                    if (dis[elem] == 1e9) ans.push_back(elem);
                    dis[elem] = weight;
                    pq.push({weight, elem});
                }
            }
        }

        return ans;
    }
};

// Solution 2
// Using Union find
// Beats 99%
class DSU {
    vector<int> par;

public:
    DSU(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int u) {
        if (u == par[u])
            return u;
        return par[u] = find(par[u]);
    }

    void join(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu < pv)
            par[pv] = pu;
        else
            par[pu] = pv;
    }

    void reset(int i) {par[i] = i;}
};

class Solution2 {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        int m = meetings.size();
        DSU dsu(n);
        vector<int> ans;
        dsu.join(0, firstPerson);

        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        };

        sort(meetings.begin(), meetings.end(), compare);

        for (int i = 0; i <m;) {
            int j = 0;
            for (;((i+j)<m)&&meetings[i+j][2] == meetings[i][2];j++) {
                dsu.join(meetings[i+j][0], meetings[i+j][1]);
            }
            i += j;
            while(j) {
                if (dsu.find(meetings[i-j][0]) != 0) dsu.reset(meetings[i-j][0]);
                if (dsu.find(meetings[i-j][1]) != 0) dsu.reset(meetings[i-j][1]);
                j--;
            }
        }

        for (int i=0;i<n;i++) if (dsu.find(i) == 0) ans.push_back(i);

        return ans;
    }
};