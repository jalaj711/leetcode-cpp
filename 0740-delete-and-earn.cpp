#include<vector>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int sums[10001] = {0};
        for (auto i: nums) sums[i]++;

        int take_1 = 0, skip = 0;
        int take;
        for (int i = 1;i<10001;i++) {
            take = skip + i * sums[i];
            skip = max(take_1, skip);
            take_1 = take;
        }
        return max(skip, take);
    }
};