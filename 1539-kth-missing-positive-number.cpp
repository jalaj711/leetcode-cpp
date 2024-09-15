#include<vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = n-1, m, x;

        while(l <= r) {
            m = (l+r)/2;
            x = arr[m] - m - 1;
            if (x < k) l = m+1;
            else {
                r = m-1;
            }
        }
        return k+l;
    }
};