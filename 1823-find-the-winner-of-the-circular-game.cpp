#include <vector>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> st(n);
        for (int i = 1; i <= n; i++) st[i - 1] = i;
        int idx = 0;
        while (st.size() != 1) {
            idx = (idx + k - 1) % st.size();
            st.erase(st.begin() + idx);
        }
        return st[0];
    }
};