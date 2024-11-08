#include<vector>
using namespace std;

// O(n*maximumBit)
//class Solution {
//public:
//  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//    int n = nums.size();
//    int x = nums[0];
//
//    for(int i=1;i<n;i++) x ^= nums[i];
//
//    vector<int> ans(n);
//
//    for(int i=n-1;i>=0;i--) {
//      int num = 0;
//      for(int j=maximumBit-1;j>=0;j--) {
//        num |= (((x >> j) & 1) ^ 1) << j;
//      }
//      ans[n-i-1] = num;
//      x ^= nums[i];
//    }
//
//    return ans;
//  }
//};

// O(n)
// Possible due to the constraint that nums[i] < 2^maximumBit
class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    int x = nums[0];
    int m = (1 << maximumBit) - 1; // maximum possible xor

    for(int i=1;i<n;i++) x ^= nums[i];

    vector<int> ans(n);

    for(int i=n-1;i>=0;i--) {
      ans[n-i-1] = x ^ m;
      x ^= nums[i];
    }

    return ans;
  }
};