#include<vector>
#include<climits>
using namespace std;

// Solution 1: O(n^2)
//class Solution {
//public:
//  int count(int n) {
//    int a = 0;
//    while(n != 0) {
//      a += n&1;
//      n >>= 1;
//    }
//
//    return a;
//  }
//  bool canSortArray(vector<int>& nums) {
//    int n = nums.size();
//
//    for(int i=0;i<n;i++) {
//      for(int j=i+1;j<n;j++) {
//        if (nums[i] > nums[j] && count(nums[i]) != count(nums[j])) {
//          return false;
//        }
//      }
//    }
//
//    return true;
//  }
//};

// Solution 2: O(n)
class Solution {
public:
  int count(int n) {
    int a = 0;
    while(n != 0) {
      a += n&1;
      n >>= 1;
    }

    return a;
  }
  // intuition: if array is divided into segments of consecutive
  // numbers with same number of set bits, then the max of
  // prev segment should nto be more than the min of this segment
  bool canSortArray(vector<int>& nums) {
    int n = nums.size();

    int prevSegMax = INT_MIN,
        currSegMin = INT_MAX,
        currSegMax = INT_MIN,
        bits = count(nums[0]);

    for(int i=0;i<n;i++) {
      if (count(nums[i]) == bits) {
        currSegMin = min(currSegMin, nums[i]);
        currSegMax = max(currSegMax, nums[i]);
      } else {
        bits = count(nums[i]);
        prevSegMax = currSegMax;
        currSegMin = nums[i];
        currSegMax = nums[i];
      }


      if (prevSegMax > currSegMin) return false;
    }

    return true;
  }
};