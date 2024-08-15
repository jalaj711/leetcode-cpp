#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
// Solution 1: Using DP LIS: O(n2) time, O(n) space;
//
//class Solution {
//public:
//    int findLongestChain(vector<vector<int>>& pairs) {
//        int n = pairs.size();
//        sort(pairs.begin(), pairs.end());
//        vector<int>memo(n + 1, 0);
//        for (int idx = n - 1; idx >= 0; idx--) {
//            for (int prevMax = idx - 1; prevMax > -2; prevMax--) {
//                if (prevMax == -1 || pairs[idx][0] > pairs[prevMax][1])
//                    memo[prevMax + 1] = max(memo[prevMax+1], 1 + memo[idx+1]);
//            }
//        }
//        return memo[0];
//    }
//};

// Solution 2: Greedy, O(n) time, O(1) space

bool cmp(const vector<int>& p1, const vector<int>& p2)
{
    return p1[1] < p2[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        int ans = 0;
        int cur = INT_MIN;
        for (int idx = 0; idx <n; idx++) {
            if (pairs[idx][0] > cur) {
                cur = pairs[idx][1];
                ans += 1;
            }
        }
        return ans;
    }
};