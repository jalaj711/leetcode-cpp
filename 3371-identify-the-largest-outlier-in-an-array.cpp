#include<unordered_set>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
  int getLargestOutlier(vector<int>& nums) {
    int sum = 0;
    unordered_multiset<int> st;
    for (const auto &n: nums) {
      sum+=n;
      st.insert(n);
    }
    int  n = nums.size();
    int outlier = INT_MIN;

    for (int i=0;i<n;i++) {
      int pot = sum - 2*nums[i];
      if (st.count(pot) > ((pot==nums[i]))) {
        outlier = max(outlier, pot);
      }
    }

    return outlier;

  }
};