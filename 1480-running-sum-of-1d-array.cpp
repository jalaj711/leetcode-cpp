#include<vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> ans;
        for (int n: nums) {
            sum += n;
            ans.push_back(sum);
        }
        return ans;
    }
};