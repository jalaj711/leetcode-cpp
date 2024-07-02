#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> recur(int idx, int n, vector<int>& nums) {
        vector<vector<int>> ans;
        if (idx == n - 1) {
            vector<int> path;
            path.push_back(nums[idx]);
            ans.push_back(path);
            return ans;
        }
        auto prevAns = recur(idx + 1, n, nums);
        for (int i = 0; i < prevAns.size(); i++) {
            for (int j = 0; j <= prevAns[i].size(); j++) {
                vector<int> path(prevAns[i].begin(), prevAns[i].end());
                path.insert(path.begin() + j, nums[idx]);
                ans.push_back(path);
            }
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return recur(0, nums.size(), nums);
    }
};