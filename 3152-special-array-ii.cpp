#include<vector>

using namespace std;

class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    int mem[n + 1];

    mem[0] = 0;
    for (int i = 0; i < n - 1; i++) {
      mem[i + 1] = ((nums[i] & 1) ^ (nums[i + 1] & 1)) + mem[i];
      // cout << "i=" << i << " nums[i]=" << nums[i] << " mem[i+1]=" << mem[i+1] << endl;
    }

    vector<bool> ans;
    ans.reserve(queries.size());

    for (const auto &q: queries) {
      ans.push_back(mem[q[1]] - mem[q[0]] == q[1] - q[0]);
    }

    return ans;
  }
};