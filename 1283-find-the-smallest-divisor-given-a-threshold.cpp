#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isCorrect(vector<int> &nums, int t, int d) {
        long long r = 0;
        for (auto num: nums) {
            r += (num+d-1)/d;
            if (r>t) return false;
        }
        return r <= t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(begin(nums), end(nums)), m, ans;
        while (l <= r) {
            m = (l+r)/2;

            if (isCorrect(nums, threshold, m)) {
                ans = m;
                r = m-1;
            } else l = m+1;
        }
        return ans;
    }
};