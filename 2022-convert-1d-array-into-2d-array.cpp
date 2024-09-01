#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m*n) return vector<vector<int>>{};
        vector<vector<int>> arr(m, vector<int>(n));
        int i=0,j=0;
        while (i!=m) {
            j=0;
            while(j!=n) {
                arr[i][j] = original[i*n+j];
                j++;

            }
            i++;
        }
        return arr;
    }
};