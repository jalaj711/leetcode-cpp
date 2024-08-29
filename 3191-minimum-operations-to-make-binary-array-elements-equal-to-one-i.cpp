#include<vector>

using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();
        for (int i=0;i<n-2;i++) {
            if (nums[i] == 0) {
                ops++;
                nums[i+1] = nums[i+1] ? 0 : 1;
                nums[i+2] = nums[i+2] ? 0 : 1;
            }
        }
        if (nums[n-2] == 0 || nums[n-1] == 0) return -1;
        return ops;
    }
};