#include<queue>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (auto &n: nums) {
      pq.push(n);
    }

    long long score = 0;
    while(k--) {
      int fr = pq.top();
      pq.pop();
      score += fr;
      pq.push(ceil((double)fr/3.0));
    }

    return score;
  }
};