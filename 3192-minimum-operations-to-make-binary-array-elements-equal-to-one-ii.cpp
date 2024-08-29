#include<vector>

using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int ops = 0;
        bool flipped = false;
        for (auto num : nums)
            if (!(flipped || num) || (flipped && num)) {
                flipped = !flipped;
                ops++;
            }
        return ops;
    }
};