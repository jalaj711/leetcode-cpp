#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto convert = [mapping](int n) -> int {
            int newN = 0;
            int mult = 1;
            do {
                newN = mapping[n%10] * mult + newN;
                mult *= 10;
                n /= 10;
            } while (n);
            return newN;
        };
        unordered_map<int, int> mp;
        for (auto n: nums) {
            mp[n] = convert(n);
        }
        sort(nums.begin(), nums.end(), [&mp](int a, int b) -> bool {
            return mp[a] < mp[b];
        });
        return nums;
    }
};