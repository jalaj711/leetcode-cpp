#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevMax = idx - 1; prevMax > -2; prevMax--) {
                if (prevMax == -1 || nums[idx] > nums[prevMax])
                    memo[prevMax + 1] = max(memo[prevMax+1], 1 + memo[idx+1]);
            }
        }
        return memo[0];
    }
};