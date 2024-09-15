#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end()), m;
        int ans = r;
        unsigned long long t;
        while (l <= r) {
            m = (l+r)/2;
            t = 0;
            for (const int &pile: piles) {
                t +=  (pile + m -1) / m;
                if (t>h) break;
            }
            if (t<=h) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};