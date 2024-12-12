#include<vector>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
  long long pickGifts(vector<int>& g, int k) {
    priority_queue<int> pq (g.begin(), g.end());

    long long a = 0;
    for (const int &n: g) a += n;

    while(k--) {
      int b = pq.top();
      pq.pop();
      int x = sqrt(b);
      a -= (b-x);
      pq.push(x);
    }

    return a;
  }
};