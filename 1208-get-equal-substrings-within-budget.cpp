#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0;
        int maxlen = 0;
        int cost = 0;
        int l = 0, r = 0;
        int z = s.size();
        while (r < z) {
            if (cost + abs(t[r] - s[r]) <= maxCost) {
                len++;
                cost += abs(t[r] - s[r]);
                maxlen = max(len, maxlen);
                r++;
            } else {
                if (l == r) r++;
                else {
                    cost -= abs(t[l] - s[l]);
                    len--;
                }
                l++;
            }
        }
        return maxlen;
    }
};