#include<map>
#include<string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, bool> mp;
        int pairs = 0, singles = 0;
        for (auto ch: s) {
            if (mp.find(ch) == mp.end()) {
                mp[ch] = true;
                singles++;
            } else {
                if (mp[ch]) {
                    pairs++;
                    singles--;
                } else {
                    singles++;
                }
                mp[ch] = !mp[ch];
            }
        }
        return pairs * 2 + (singles > 0 ? 1 : 0);
    }
};