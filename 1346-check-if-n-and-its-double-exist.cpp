#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    unordered_set<int> st;

    for (const int &a: arr) {
      if (st.find(a * 2) != st.end()) return true;
      if (a % 2 == 0 && st.find(a / 2) != st.end()) return true;

      st.insert(a);
    }

    return false;
  }
};