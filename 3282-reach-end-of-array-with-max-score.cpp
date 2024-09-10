#include<vector>
using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int prev = 0;
        for (int i=1;i<n;i++) {
            if (nums[i] > nums[prev]) {
                ans += (long long) (i-prev)*(nums[prev]);
                prev = i;
            }
        }
        ans += (long long)(n-1-prev)*(nums[prev]);
        return ans;
    }
};