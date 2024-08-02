#include<vector>

class Solution {
public:
    int minSwaps(std::vector<int> &nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i]) total++;

        int i = 0;
        int count = 0;
        int maxCount = 0;
        int j = 0;
        for (; j < total - 1; j++) {
            count += nums[j];
        }
        count += nums[j];

        while (i < n) {
            if (nums[i++]) count--;
            if (nums[++j % n]) count++;
            maxCount = std::max(maxCount, count);
        }
        return total - maxCount;
    }
};