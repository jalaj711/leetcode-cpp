#include<vector>
using namespace std;

class Solution {
public:
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    if (k==1) return true;
    int a = 0;
    int b = a+k;
    int lastA = nums[a];
    int lastB = nums[b];
    int l = 1;

    while(b<nums.size()-1) {
      if ((nums[++a] <= lastA) | (nums[++b] <= lastB)) l = 1;
      else if (++l == k) return true;
      lastA = nums[a];
      lastB = nums[b];
    }
    return false;
  }
};