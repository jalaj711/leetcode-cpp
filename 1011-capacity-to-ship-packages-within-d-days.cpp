#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    bool isCorrect(vector<int> &weights, int days, int cap) {
        int a = 0, b = 0;
        for (const int &w: weights) {
            b += w;
            if (b > cap) {
                if (++a > days) return false;
                b=w;
            }
        }
        // cout << cap << " " << a << " " << b << endl;
        return (a+(b>0)) <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0, m=INT_MIN;
        for (auto w: weights) {
            s += w;
            m = max(w, m);
        }
        int l = m, r = s, ans;
        // cout <<"l=" << l<< "r=" << r << endl;
        while(l <= r) {
            m = (l+r)/2;
            if (isCorrect(weights, days, m)) {
                ans = m;
                r = m-1;
            } else {l = m + 1;}
        }
        return ans;
    }
};