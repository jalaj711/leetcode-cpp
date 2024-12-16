#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
  vector<int> getFinalState(vector<int>& nums, int k, int mu) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = nums.size();

    for(int i=0;i<n;i++) {
      pq.push({nums[i], i});
    }

    while(k--) {
      int idx = pq.top().second;
      pq.pop();
      nums[idx] *= mu;

      pq.push({nums[idx], idx});
    }

    return nums;
  }
};