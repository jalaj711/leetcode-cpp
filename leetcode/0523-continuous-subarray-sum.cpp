#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        if (nums.size() < 2)
            return false;
        map<int, int> rem;
        int currsum = 0;
        int r;
        for (int i = 0; i < nums.size(); i++) {
            currsum += nums[i];
            r = currsum % k;
            if (i != 0 && r == 0) return true;
            if (rem.find(r) != rem.end()) {

                if ((i - rem[r]) > 1)
                    return true;

            } else {
                rem[r] = i;
            }
        }
        return false;
    }
};