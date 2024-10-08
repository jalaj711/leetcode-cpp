#include<vector>
#include<algorithm>
using namespace std;

// This is an O(n^2 log(n)) solution
// A better solution that works in n^2 exists
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int l,
        r,
        m,
        k,
        ans = 0,
        n = nums.size();
    for (int i=0;i<n-2;i++) {
      for (int j=i+1;j<n-1;j++) {
        l = j+1;
        r = n-1;
        k = j;
        while(l<=r) {
          m = (l+r)/2;
          if (nums[m] >= nums[i]+nums[j]) {
            r = m-1;
          } else {
            k = m;
            l = m+1;
          }
        }
        // cout << "making triangles k=" << k << "j=" << j << endl;
        ans += (k-j);
      }
    }
    return ans;
  }
};