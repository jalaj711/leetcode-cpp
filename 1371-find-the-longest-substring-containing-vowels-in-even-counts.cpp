#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int charToNum(char c) {
        switch(c) {
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
            default:
                return -1;
        }
    }
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int, int> mp;

        int mask = 0;
        int ans = 0;
        for (int i=0;i<n;i++) {
            int id = charToNum(s[i]);
            mask = mask ^ (id == -1 ? 0 : (1 << id));
            if (mask == 0) ans = i+1;
            else if (mp.find(mask) != mp.end()) {
                ans = max(ans, i-mp[mask]+(charToNum(s[mp[mask]])==-1));
            } else {
                mp[mask] = i;
            }
        }

        return ans;

    }
};