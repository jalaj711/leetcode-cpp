#include<vector>

using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    int n = asteroids.size();
    vector<int> st;

    for (int i = 0; i < n; i++) {
      if (
          !st.empty() &&
          st.back() >= 0 &&
          asteroids[i] <= 0
          ) {
        int tp = st.back();
        if (tp < -asteroids[i]) {
          st.pop_back();
          i--;
        } else if (tp == -asteroids[i]) {
          st.pop_back();
        }
      } else {
        st.push_back(asteroids[i]);
      }
    }

    return st;
  }
};