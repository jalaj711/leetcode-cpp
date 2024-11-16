#include<vector>
using namespace std;

class Solution {
public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    if (k == 1)
      return nums;

    int i = 1;
    // length of consecutive numbers ending at the current index
    int consec = 1;
    int lastElem = nums[0];
    int n = nums.size();

    // find consecutive elements in first k-1 elements
    for (; i < k - 1; i++) {
      if (nums[i] - lastElem == 1)
        consec++;
      else
        consec = 1;

      lastElem = nums[i];
    }

    vector<int> results(n - k + 1);

    // handle the rest of elems
    for (; i < n; i++) {
      if (nums[i] - lastElem == 1)
        consec++;
      else
        consec = 1;

      if (consec >= k)
        results[i - k + 1] = nums[i];
      else
        results[i - k + 1] = -1;

      lastElem = nums[i];
    }

    return results;
  }
};