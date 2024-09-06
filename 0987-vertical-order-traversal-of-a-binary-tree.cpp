#include<map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<int, map<int, vector<int>>> mp;

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int row = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto fr = q.front();
                q.pop();
                if (mp.find(fr.second) == mp.end()) mp[fr.second] = {{row, vector<int>{(fr.first)->val}}};
                else if (mp[fr.second].find(row) == mp[fr.second].end())
                    mp[fr.second][row] = vector<int>{(fr.first)->val};
                else mp[fr.second][row].push_back((fr.first)->val);

                if ((fr.first)->left)
                    q.push({(fr.first)->left, fr.second - 1});
                if ((fr.first)->right)
                    q.push({(fr.first)->right, fr.second + 1});

            }
            row++;
        }
        int sz = 0;
        for (auto inner: mp) {
            ans.push_back(vector<int>());
            for (auto values: inner.second) {
                auto vec = values.second;
                sort(vec.begin(), vec.end());
                for (auto val: vec) ans[sz].push_back(val);
            }
            sz++;
        }
        return ans;
    }
};