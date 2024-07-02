#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int k) {
        long long m = *max_element(nums.begin(), nums.end());
        long long l = 0, r = 0, c = 0, a = 0, n = nums.size();
        for (r = 0; r < n; r++) {
            if (nums[r] == m) {
                c++;
                while (c == k && l <= r) {
                    a += n - r;
                    if (nums[l] == m) {
                        c--;
                    }
                    l++;
                }
            }
        }
        return a;
    }
};