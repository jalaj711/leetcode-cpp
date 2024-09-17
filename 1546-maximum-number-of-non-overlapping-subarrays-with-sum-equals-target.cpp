#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        mp[nums[0]] = 0;
        int lastUsedIdx = (nums[0] == target)-1, n = nums.size();
        int ans = nums[0] == target;

        for (int idx = 1;idx<n;idx++) {
            nums[idx] += nums[idx-1];
            if (mp.find(nums[idx]-target) != mp.end() && mp[nums[idx]-target] >= lastUsedIdx) {
                ans++;
                lastUsedIdx = idx;
            }
            mp[nums[idx]] = idx;
        }

        return ans;
    }
};