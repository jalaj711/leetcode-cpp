#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = 0, ans = INT_MAX, s = 0;
        while (r < n) {
            s += nums[r++];
            while (s >= target) {
                ans = min(ans, r - l);
                s -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};