#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
  int longestSquareStreak(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = -1;
    int l, r, m;

    for (int i = 0; i < n; i++) {
      int num = nums[i];

      // this is to prevent searching from the same element twice
      // without changing the original array
      if (num < 1) {
        nums[i] = -nums[i];
        continue;
      }

      int streak = 0;
      int j = i;

      while (true) {
        // mark the original element so that we don't process
        // the same element again in future
        nums[j] = -nums[j];
        l = j;
        r = n - 1;
        bool found = false;
        // binary search for its square
        while (l <= r) {
          m = (l + r) / 2;
          if (nums[m] == (long long) num * num) {
            found = true;
            break;
          }
          if (nums[m] < (long long) num * num) l = m + 1;
          else r = m - 1;
        }

        if (found) {
          num = nums[m];
          j = m;
          streak++;
        } else break;

      }


      if (streak) count = max(count, streak + 1);
    }

    return count;
  }
};