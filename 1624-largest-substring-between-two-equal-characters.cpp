#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, int> mp;
        int maxlen = -1;
        for (int i=0;i<s.size();i++) {
            if (mp.find(s[i]) != mp.end()) {
                maxlen = max(maxlen, abs(i-mp[s[i]]-1));
            } else {
                mp[s[i]] = i;
            }
        }
        return maxlen;
    }
};