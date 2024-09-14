#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target)
                return true;
            if (nums[m] == nums[l] && nums[m] == nums[r]) {
                l++;
                r--;
                continue;
            }
            if (nums[l] <= nums[m])
                if (target < nums[m] && target >= nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            else if (nums[m] < target && nums[r] >= target)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }
};