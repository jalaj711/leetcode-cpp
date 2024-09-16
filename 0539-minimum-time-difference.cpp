#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> tp;
        vector<bool> mem(1440, false);
        for (const string  &t : timePoints) {
            int x = ((t[0] - '0') * 10 + (t[1] - '0')) * 60 +
                    (t[3] - '0') * 10 + (t[4] - '0');
            if (!mem[x]) {
                tp.push_back(x);
                mem[x] = true;
            } else return 0;
        }

        sort(tp.begin(), tp.end());
        int ans = tp[0] + 1440 - tp.back();
        for (int i = 1; i < tp.size(); i++)
            ans = min(ans, (tp[i] - tp[i - 1]));

        return ans;
    }
};