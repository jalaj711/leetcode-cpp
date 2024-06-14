#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                cnt += nums[i - 1] - nums[i] + 1;
                nums[i] += nums[i - 1] - nums[i] + 1;
            }
        }

        return cnt;
    }
};