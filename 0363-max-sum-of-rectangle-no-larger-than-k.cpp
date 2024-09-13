#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=1;i<n;i++) matrix[0][i] += matrix[0][i-1];
        for (int i=1;i<m;i++) matrix[i][0] += matrix[i-1][0];
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }

        int ans = INT_MIN;

        for (int t=0;t<m;t++) {
            for (int b=t;b<m;b++) {
                for (int l=0;l<n;l++) {
                    for (int r=l;r<n;r++) {
                        // cout << "l=" << l << "r=" << r << "t=" << t << "b=" << b;
                        int area = matrix[b][r];
                        if (t>0) area -= matrix[t-1][r];
                        if (l>0) area -= matrix[b][l-1];
                        if (t>0 && l>0) area += matrix[t-1][l-1];
                        // cout << "area=" << area << endl;

                        if (area <= k) ans = max(ans, area);
                    }
                }
            }
        }

        return ans;

    }
};