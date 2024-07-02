#include<vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        vector<int> rem(k, 0);
        rem[0] = 1;
        int sum = 0;
        int count = 0;
        int re;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]);
            re = sum % k;
            if (re < 0) re += k;
            if (rem[re]) {
                count += rem[re];
            }
            rem[re]++;
        }
        return count;
    }
};