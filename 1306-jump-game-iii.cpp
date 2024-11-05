#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
      int fr = q.front();
      q.pop();
      if (arr[fr] == 0) return true;
      if (arr[fr] == -1) continue;

      if (fr+arr[fr] < n) q.push(fr+arr[fr]);
      if (fr-arr[fr] >= 0) q.push(fr-arr[fr]);

      arr[fr] = -1;
    }

    return false;
  }
};