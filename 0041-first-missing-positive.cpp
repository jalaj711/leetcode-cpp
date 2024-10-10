#include<vector>
using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    int i=0;
    for (;i<n;i++)
      if (
          nums[i] > 0 &&              // ignore negative numbers
          nums[i] <= n &&             // ignore numbers out of range
          nums[i] != i+1 &&           // ignore numbers already in place
          nums[i] != nums[nums[i]-1]  // ignore numbers with duplicate entry
          ) {
        int temp = nums[i];
        nums[i] = nums[nums[i]-1];
        nums[temp-1] = temp;
        i--;
      }


    i=0;
    for (;i<n;i++)
      if (nums[i] != i+1)
        return i+1;

    return i+1;
  }
};