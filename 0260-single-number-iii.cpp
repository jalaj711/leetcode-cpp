#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) return nums;
        int x = nums[0];
        int n=nums.size();
        for (int i=1;i<n;i++) {
            x ^= nums[i];
        }
        int c = 1;
        while((x&1) != 1) {
            x>>=1;
            c <<= 1;
        }
        vector<int> ans {0, 0};
        bool f1 = false, f2 = false;
        for (int j=0;j<n;j++) {
            if (nums[j]&c) {
                if (f1) ans[0] ^= nums[j];
                else {
                    f1 = true;
                    ans[0] = nums[j];
                }
            } else {
                if (f2) ans[1] ^= nums[j];
                else {
                    f2 = true;
                    ans[1] = nums[j];
                }
            }
        }
        return ans;
    }
};