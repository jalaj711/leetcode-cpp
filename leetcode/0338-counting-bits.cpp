#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        if (n == 0) return ans;
        ans[1] = 1;
        if (n == 1) return ans;
        int less = 1;
        int max = 2;
        for (int i = 2; i <= n; i++) {
            if (i == max) {
                less = max;
                max <<= 1;
            }
            ans[i] = ans[i - less] + 1;
        }
        return ans;
    }
};