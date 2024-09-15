#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int charToNum(char c) {
        switch (c) {
            case 'a':
                return 1;
            case 'e':
                return 2;
            case 'i':
                return 4;
            case 'o':
                return 8;
            case 'u':
                return 16;
            default:
                return -1;
        }
    }
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> bitmp(32, -1);

        int mask = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int id = charToNum(s[i]);
            if (id != -1)
                mask = mask ^ id;

            if (bitmp[mask] == -1 && mask != 0)
                bitmp[mask] = i;

            ans = max(ans, i - bitmp[mask]);
        }

        return ans;
    }
};