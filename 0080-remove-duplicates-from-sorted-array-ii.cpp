#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        int prevVal = -10001;
        int prevCount = 0;
        int p = 0, q = 0;
        while(p<nums.size()){
            if(nums[p] == prevVal) prevCount++;
            else prevCount = 0;
            prevVal=nums[p];

            if (p != q) {
                swap(nums[p], nums[q]);
                prevCount < 2 && q++;
            } else if (prevCount < 2) q++;
            p++;
        }
        return q;
    }
};

int main()
{
    vector<int> q = {0,0,1,2,2,2,3,3,4,4,4,5};
    Solution s;
    s.removeDuplicates(q);
    return 0;
}
