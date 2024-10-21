#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
  string removeStars(const string &s) {
    stack<char> st;
    for (const char &ch: s) {
      if (ch == '*')
        st.pop();
      else
        st.push(ch);
    }
    string ans = "";
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};