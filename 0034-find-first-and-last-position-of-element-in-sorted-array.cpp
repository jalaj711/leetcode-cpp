#include<vector>
using namespace std;

class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int n = nums.size();
        int ans = n;
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] >= target) {
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
    int upper_bound(vector<int> &nums, int target) {
        int n = nums.size();
        int ans = n;
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] > target) {
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums, target);
        int ub = upper_bound(nums, target)-1;

        if (lb >= n || nums[lb] != target) lb = -1;
        if (ub >= n || ub < 0 || nums[ub] != target) ub = -1;
        return vector<int> {lb, ub};
    }
};