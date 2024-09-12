#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allow[26] = {0};
        for (auto ch: allowed) allow[ch-'a'] = true;

        int cnt = 0;
        for (string word: words) {
            bool flag = true;
            for (auto ch: word) if (!(flag = allow[ch-'a'])) break;
            cnt += flag;
        }

        return cnt;
    }
};