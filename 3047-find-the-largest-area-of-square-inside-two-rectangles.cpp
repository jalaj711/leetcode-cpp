#include<vector>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0, s;
        int l, b;

        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                b = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                l = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);

                // cout << "i=" << i << "j=" << j << "l=" << l << "b=" << b << endl;

                s = min(l, b);
                if (s>0) ans = max(ans, s*s);
            }
        }
        return ans;
    }
};