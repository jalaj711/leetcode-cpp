#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& t) {
    stack<pair<int, int>> st;

    int n = t.size();
    vector<int> ans(n, 0);
    for(int i=n-1;i>=0;i--) {
      while(!st.empty() && st.top().first <= t[i]) {
        st.pop();
      }
      ans[i] = st.empty() ? 0 : (st.top().second - i);
      st.push({t[i], i});
    }
    return ans;
  }
};