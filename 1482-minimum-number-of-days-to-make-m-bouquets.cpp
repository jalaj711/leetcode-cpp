#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isCorrect(vector<int> &bloomDay, int m, int k, int d) {
        int a = 0, b=0;
        for (auto day: bloomDay) {
            if (day <= d) b++;
            else b = 0;

            if (b==k) {a++;b=0;}
        }
        return a >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int l=1,r=*max_element(bloomDay.begin(), bloomDay.end()), mid, ans = -1;

        while (l <= r) {
            mid = (l+r)/2;
            if (isCorrect(bloomDay, m, k, mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};