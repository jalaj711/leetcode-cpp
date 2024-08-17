#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_sz = s.size();
        int p_sz = p.size();
        vector<bool> prev(p_sz + 1, false);
        vector<bool> curr(p_sz + 1, false);

        bool flag = true;
        for (int idx_p = p_sz - 1; idx_p >= 0; idx_p--) {
            if (p[idx_p] != '*')
                flag = false;
            prev[idx_p] = flag;
        }
        prev[p_sz] = true;

        for (int idx_s = s_sz - 1; idx_s >= 0; idx_s--) {
            for (int idx_p = p_sz - 1; idx_p >= 0; idx_p--) {
                if (p[idx_p] == '?')
                    curr[idx_p] = prev[idx_p + 1];
                else if (p[idx_p] == '*')
                    curr[idx_p] =
                            prev[idx_p] || curr[idx_p + 1];
                else
                    curr[idx_p] =
                            (s[idx_s] == p[idx_p] && prev[idx_p + 1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};