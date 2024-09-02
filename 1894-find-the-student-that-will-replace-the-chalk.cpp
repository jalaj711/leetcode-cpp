#include<vector>
using namespace std;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        int n = chalk.size();
        int sum = 0;
        while (sum<=k&&i<n) {
            sum += chalk[i];
            i++;
        }
        if (sum > k) return i-1;
        k = k%sum;
        i=0;
        while (k>=chalk[i]) {
            k -= chalk[i];
            i = (i+1)%n;
        }
        return i;
    }
};