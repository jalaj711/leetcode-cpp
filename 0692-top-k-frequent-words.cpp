#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;
    for (const auto &w: words) {
      mp[w]++;
    }

    vector<pair<string, int>> vec (mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), [](const pair<string, int> &a, const pair<string, int> &b){
      if (a.second == b.second) return a.first < b.first;
      return a.second > b.second;
    });

    vector<string> ans;
    for (int i=0;i<k;i++) {
      ans.push_back(vec[i].first);
    }

    return ans;
  }
};