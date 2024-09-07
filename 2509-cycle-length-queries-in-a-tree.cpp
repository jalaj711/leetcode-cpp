#include<vector>
using namespace std;
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> a;
        int d;
        for (auto q: queries) {
            d = 0;
            while(q[0] >= 1 && q[1] >= 1 && q[0] != q[1]) {
                if (q[0] > q[1]) q[0] /= 2;
                else q[1] /= 2;
                d++;
            }
            a.push_back(d + 1);
        }
        return a;
    }
};