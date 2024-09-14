#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem = 0;
        int cnt = 0;
        int n = nums.size();
        for (int i=0;i<n;) {
            int j=i+1;
            while(j<n&&nums[j]==nums[i]) j++;
            if (nums[i] > maxElem) {
                cnt = j-i;
                maxElem = nums[i];
            } else if (nums[i] == maxElem) cnt = max(cnt, j-i);
            i=j;
        }
        return cnt;
    }
};