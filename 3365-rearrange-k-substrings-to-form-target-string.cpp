#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
  bool isPossibleToRearrange(const string &s, const string &t, int k) {
    int n = s.size();
    int sz = n / k;
    if (s.size() % k) return false;

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i += sz) {
      mp[s.substr(i, sz)]++;
    }

    for (int i = 0; i < n; i += sz) {
      if (mp.find(t.substr(i, sz)) == mp.end()) return false;

      if (--mp[t.substr(i, sz)] == 0) mp.erase(t.substr(i, sz));
    }

    return mp.size() == 0;
  }
};