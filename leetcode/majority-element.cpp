#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i=0,j=0, k=0;
        while(k<nums.size()){
            if (nums[k]==j)i++;
            else {
                if (i==0) {j=nums[k];i=1;}
                else i--;
            }
            k++;
        }
        return j;        
    }
};


int main()
{
    vector<int> q = {0,0,1,1,0,0,2,2,2,0,0};
    Solution s;
    s.majorityElement(q);
    return 0;
}
