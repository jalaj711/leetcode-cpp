#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // element wise adj list
        // only elements of same group are connected
        // adj[i].first = indegree
        // adj[i].second = connected elements
        vector<pair<int, vector<int>>> elemWiseAdj(n, {0, {}});

        // stores the children of ith group for each 0 <= i < m
        vector<vector<int>> groupWise(m);

        // group wise adj list
        // adj[i].first = indegree
        // adj[i].second = connected elements
        unordered_map<int, pair<int,vector<int>>> groupWiseAdj;

        for (int i=0;i<n;i++) {

            // if element has no group, we create its own group
            if (group[i] == -1) group[i] = -i-2;
            else if(group[i] > -1) groupWise[group[i]].push_back(i);

            // ensure group exists in groupWiseAdj
            if (groupWiseAdj.find(group[i]) == groupWiseAdj.end()) {
                groupWiseAdj[group[i]] = {0, vector<int>()};
            }

            // create connections based on beforeItems
            for (auto j: beforeItems[i]) {
                if (group[j] == -1) group[j] = -j-2;

                if (group[i] == group[j]) {
                    // they belong to the same group
                    // so use the elemWiseAdj
                    elemWiseAdj[j].second.push_back(i);
                    elemWiseAdj[i].first += 1;
                } else {

                    // diff groups
                    // connect the groups
                    if (groupWiseAdj.find(group[j]) == groupWiseAdj.end()) {
                        groupWiseAdj[group[j]] = {0, vector<int>()};
                    }

                    groupWiseAdj[group[j]].second.push_back(group[i]);
                    groupWiseAdj[group[i]].first += 1;
                }
            }
        }


        // topological sort on groups
        vector<int> sortedGroups;
        queue<int> q;
        for (auto grp: groupWiseAdj) if (grp.second.first == 0) q.push(grp.first);
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            sortedGroups.push_back(fr);

            for (auto child: groupWiseAdj[fr].second)
                if (--groupWiseAdj[child].first == 0) q.push(child);
        }

        // cyclic dependency among the groups
        if (sortedGroups.size() != groupWiseAdj.size()) return {};

        vector<int> ans;
        for (auto item: sortedGroups) {
            // recover item if it belonged to no group
            if (item < 0) ans.push_back(-item-2);
            else {
                int init = ans.size();

                // use the same queue for topological sort
                // inside the group
                for (auto elem: groupWise[item])
                    if (elemWiseAdj[elem].first == 0) q.push(elem);

                while(!q.empty()) {
                    int fr = q.front();
                    q.pop();
                    ans.push_back(fr);
                    for (auto child: elemWiseAdj[fr].second) {
                        if (--elemWiseAdj[child].first == 0) q.push(child);
                    }
                }
                // cyclical dependency inside the group
                if (ans.size() - init != groupWise[item].size()) return {};
            }
        }

        return ans;

    }
};