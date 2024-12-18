#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
  vector<int> finalPrices(vector<int>& p) {
    stack<int> s;

    int n = p.size();
    for (int i=n-1;i>=0;i--) {
      int v = p[i];
      while(!s.empty() && s.top() > v) s.pop();
      if (!s.empty()) v = p[i] - s.top();
      s.push(p[i]);

      p[i] = v;
    }

    return p;
  }
};