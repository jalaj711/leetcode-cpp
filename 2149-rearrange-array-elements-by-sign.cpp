#include "vector"

using namespace std;

class Solution {
private:
    void jumpToNext(bool positive, int &ptr, vector<int> &nums) {
        (ptr)++;
        while ((ptr < nums.size()) &&
               (positive ? (nums[ptr] < 0) : (nums[ptr] > 0)))
            (ptr)++;
    }

public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> ans(nums.size());
        int positivePtr = -1;
        int negativePtr = -1;
        jumpToNext(true, positivePtr, nums);
        jumpToNext(false, negativePtr, nums);
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2) {
                ans[i] = nums[negativePtr];
                jumpToNext(false, negativePtr, nums);
            } else {
                ans[i] = nums[positivePtr];
                jumpToNext(true, positivePtr, nums);
            }
        }
        return ans;
    }
};