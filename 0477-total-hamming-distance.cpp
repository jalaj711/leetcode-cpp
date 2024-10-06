#include<vector>

using namespace std;

class Solution {
public:
  int totalHammingDistance(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();

    vector<int> bits(32, 0);
    int j;
    for (int i = 0; i < n; i++) {
      j = 0;
      while (nums[i]) {
        bits[j++] += nums[i] & 1;
        nums[i] >>= 1;
      }
    }

    for (auto i: bits) {
      ans += i * (n - i);
    }

    return ans;
  }
};