#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    long long cost = 0;

    int n = costs.size();
    int l = -1, r = n;
    int sel = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<>
    > left_pq, right_pq;

    // fill the priority queues
    while ((right_pq.size() + left_pq.size()) < min(2 * candidates, n)) {
      l++;
      left_pq.push({costs[l], l});
      if (l < r - 1) {
        r--;
        right_pq.push({costs[r], r});
      }
    }

    while (sel < k) {
      // best from both halves
      int lhire = left_pq.empty() ? INT_MAX : left_pq.top().first;
      int rhire = right_pq.empty() ? INT_MAX : right_pq.top().first;

      if (lhire <= rhire) {
        cost += lhire;
        left_pq.pop();
        sel++;
        // if we have new candidates for the next round, then include them
        if ((right_pq.size() + left_pq.size()) < min(2 * candidates, n - sel)) {
          l++;
          left_pq.push({costs[l], l});
        }
      } else {
        cost += rhire;
        right_pq.pop();
        sel++;
        if ((right_pq.size() + left_pq.size()) < min(2 * candidates, n - sel)) {
          r--;
          right_pq.push({costs[r], r});
        }
      }
    }

    return cost;
  }
};