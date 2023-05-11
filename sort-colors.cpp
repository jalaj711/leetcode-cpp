#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0, cnt1, cnt2;
        if(nums.size() <= 1)
            return;
        cnt0 = cnt1 = cnt2 = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0){
                cnt0++;
            } else if(nums[i] == 1){
                cnt1++;
            } else if(nums[i] == 2){
                cnt2++;
            }
        }
        for(int j=0;j<cnt0;j++) {
            nums[j] = 0;
        }
        for(int j=0;j<cnt1;j++) {
            nums[j+cnt0] = 1;
        }
        for(int j=0;j<cnt2;j++) {
            nums[j+cnt0+cnt1] = 2;
        }
    }
};


int main()
{
    vector<int> i;
    (new Solution())->sortColors(i);
}
