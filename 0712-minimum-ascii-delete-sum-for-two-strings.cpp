#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<int> curr(n+1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                curr[i] += s2[j];
            }
        }

        int prev, temp;
        for (int idx1 = m - 1; idx1 >= 0; idx1--) {
            temp = curr[n];
            curr[n] = 0;
            for (int j = idx1; j < m; j++) {
                curr[n] += s1[j];
            }
            for (int idx2 = n - 1; idx2 >= 0; idx2--) {
                int delOne = s1[idx1] + curr[idx2];
                int delTwo = s2[idx2] + curr[idx2 + 1];

                prev = temp;
                temp = curr[idx2];
                curr[idx2] = min(delOne, delTwo);
                if (s1[idx1] == s2[idx2])
                    curr[idx2] = min(curr[idx2], prev);

            }
        }

        return curr[0];
    }
};