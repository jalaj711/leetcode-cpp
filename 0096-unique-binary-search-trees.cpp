#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n+1, 0);
        memo[0] = 1;
        memo[1] = 1;
        for (int i=2;i<=n;i++) {
            for (int j=i/2;j<i;j++) memo[i] += 2 * memo[j] * memo[i-j-1];
            if (i%2) memo[i] -= memo[i/2] * memo[i/2];
        }
        return memo[n];
    }
};