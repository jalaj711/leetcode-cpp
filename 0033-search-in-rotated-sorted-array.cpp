#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            // cout << "l=" << l << "r=" << r << "m=" << m << endl;
            if (nums[m] == target)
                return m;
            bool l_sorted = nums[l] <= nums[m];
            if (l_sorted)
                if (target < nums[m] && target >= nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            else if (nums[m] < target && nums[r] >= target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};