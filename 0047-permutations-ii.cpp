#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void recur(int i, vector<int>&nums, vector<vector<int>> &ans) {
        if (i >= nums.size()) {
            vector<int> path(nums.begin(), nums.end());
            ans.push_back(path);
            return;
        }
        unordered_set<int> st;
        for (int j=i;j<nums.size();j++) {
            if (st.find(nums[j]) != st.end()) continue;
            st.insert(nums[j]);
            swap(nums[i], nums[j]);
            recur(i+1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(0, nums, ans);
        return ans;
    }
};