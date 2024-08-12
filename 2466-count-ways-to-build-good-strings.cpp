#include<vector>
using namespace std;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high+1, 0);
        memo[0] = 0;
        int z, o, inf = 1e9+7;
        for (int idx = min(zero, one);idx<=high;idx++) {
            z = o = 0;
            if (idx >= zero) z += memo[idx-zero]+1;
            if (idx >= one) o += memo[idx-one]+1;
            memo[idx] = (z+o) % inf;
        }
        return (memo[high] - memo[low-1] + inf) % inf;
    }
};