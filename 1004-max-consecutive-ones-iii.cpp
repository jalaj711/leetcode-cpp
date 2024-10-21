#include<vector>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int a = 0, // answer
        l = 0, // start of window
        r = 0, // end of window
        c = 0, // number of zeroes in window
        n = nums.size();
    while(r < n) {
      // if nums[r] is 1 then greedily include it in window
      if (nums[r]) {
        r++;
      }
      // if it's a zero and c is less than k then greedily
      // convert this zero to one
      else if (c < k) {
        c++;
        r++;
      }
      // if we reach here it means that our limit of zeroes
      // has approached, so we must evict a member
      else if (nums[l]) {
        l++;
      } else {
        l++;
        c--;
      }
      a = max(a, r-l);
    }
    return a;
  }
};