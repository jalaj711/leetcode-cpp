#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        vector<int> count (26, 0);
        int c=0;
        for (auto ch: s) count[ch-'a']++;
        for (auto i: count) c += i ? (i%2?1:2):0;
        return c;
    }
};