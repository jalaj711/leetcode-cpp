#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long total = 0;
        int n = nums.size();
        for (auto i: nums) total += i;

        long ans = INT_MAX;
        int idx = 0;
        long left_sum = 0;
        long left, right, temp;
        for (int i=0;i<n;i++) {
            left_sum += nums[i];
            left = left_sum / (i+1);
            if (i == n-1) right = 0;
            else right = (total - left_sum) / (n-i-1);
            temp = abs(left-right);
            if (temp < ans) {
                idx = i;
                ans = temp;
            }
        }
        return idx;
    }
};