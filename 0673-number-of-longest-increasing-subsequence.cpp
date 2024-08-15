#include<vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<pair<int, int>> curr(n + 1, {0, 1});

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevMax = idx - 1; prevMax >= 0; prevMax--) {
                if (nums[idx] > nums[prevMax]) {
                    if (curr[prevMax + 1].first == curr[idx + 1].first + 1) {
                        curr[prevMax + 1] = {curr[prevMax + 1].first,
                                             curr[prevMax + 1].second +
                                             curr[idx + 1].second};
                    } else if (curr[prevMax + 1].first <
                               curr[idx + 1].first + 1) {
                        curr[prevMax + 1] = {curr[idx + 1].first + 1,
                                             curr[idx + 1].second};
                    }
                }
            }
            if (curr[0].first == curr[idx + 1].first + 1) {
                curr[0] = {curr[0].first,
                           curr[0].second + curr[idx + 1].second};
            } else if (curr[0].first < curr[idx + 1].first + 1) {
                curr[0] = {curr[idx + 1].first + 1, curr[idx + 1].second};
            }
        }

        return curr[0].second;
    }
};

int main() {
    Solution s;
    vector<int> q{5, 4, 7};
    s.findNumberOfLIS(q);
}