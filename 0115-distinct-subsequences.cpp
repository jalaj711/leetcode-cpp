#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int s_sz = s.size();
        int t_sz = t.size();
        vector<unsigned int>curr(t_sz+1, 0);
        int temp, prev;
        for (int idx = s_sz-1;idx>=0;idx--) {
            curr[t_sz] = prev = 1;
            for (int target=t_sz-1;target>=0;target--) {
                temp = curr[target];
                curr[target] += (s[idx] == t[target])*prev;
                prev = temp;
            }
        }

        return curr[0];
    }
};