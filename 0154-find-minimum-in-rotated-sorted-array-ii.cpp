#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1, m;
        int ans = INT_MAX;
        while (l <= r) {
            m = (l+r)/2;
            if (nums[m] == nums[l] && nums[m] == nums[r]) {
                ans = min(ans, nums[m]);
                l++;
                r--;
            } else if (nums[l] <= nums[m]) {
                ans = min(ans, nums[l]);
                l = m+1;
            } else {
                ans = min(ans, nums[m]);
                r = m-1;
            }
        }
        return ans;
    }
};