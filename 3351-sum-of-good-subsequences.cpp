#include<vector>
#include<unordered_map>

using namespace std;

// Solution 1: DP Tabulation
// Time: O(n^2) Space O(n)
// Gives TLE
//  class Solution {
//  public:
//    int inf = 1e9+7;
//    int sumOfGoodSubsequences(vector<int>& nums) {
//      int n = nums.size();
//      vector<pair<int,int>> prev(n+2, {0,0});
//      vector<pair<int,int>> curr(n+2, {0,0});
//      for(int idx=n-1;idx>=0;idx--) {
//        for(int prevPick=idx-1;prevPick>=-1;prevPick--) {
//          int pick = 0;
//          int ns = 0;
//          if (prevPick == -1 || abs(nums[idx] - nums[prevPick]) == 1) {
//            ns++;
//            auto res = prev[idx+1];
//            pick = (res.first + ((long)nums[idx] * (res.second+1))%inf)%inf;
//            ns += res.second;
//          }
//
//          auto notpick = prev[prevPick+1];
//          ns += notpick.second;
//
//          curr[prevPick+1] = {(pick+notpick.first)%inf, ns%inf};
//        }
//        prev = curr;
//      }
//
//      return prev[0].first;
//    }
//  };

// Solution 2: Using Hash Table
// Time: O(n) Space O(n)
// 235ms, beats 100%
class Solution {
public:
  int inf = 1e9+7;
  int sumOfGoodSubsequences(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    // mp[i] = {sum of all good seq ending at number i, number of such seq}
    unordered_map<int, pair<int, int>> mp;
    for (int i=0;i<n;i++) {
      int sum = nums[i];
      mp[nums[i]].second++;

      // the idea is that if there are n sequences which have
      // a total sum of sum, and we want to add the current number
      // to each of these sequences then the final sum will be
      // n * current_number + sum
      if (mp.find(nums[i]-1) != mp.end()) {
        sum = (sum+(mp[nums[i]-1].first + ((long long)mp[nums[i]-1].second * nums[i])%inf)%inf)%inf;
        mp[nums[i]].second = (mp[nums[i]].second+mp[nums[i]-1].second)%inf;
      }
      if (mp.find(nums[i]+1) != mp.end()) {
        sum = (sum+(mp[nums[i]+1].first + ((long long)mp[nums[i]+1].second * nums[i])%inf)%inf)%inf;
        mp[nums[i]].second = (mp[nums[i]].second+mp[nums[i]+1].second)%inf;
      }

      result = (result+sum)%inf;
      mp[nums[i]].first = (mp[nums[i]].first+sum)%inf;
    }

    return result;
  }
};