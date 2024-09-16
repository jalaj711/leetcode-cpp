#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m-1, mid;
        int row = -1;
        while (l<=r) {
            mid = (l+r)/2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] < target) {
                row = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        if (row == -1) return false;

        l = 0, r = n-1;
        while (l <= r) {
            mid = (l+r)/2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] < target) l = mid +1;
            else r = mid - 1;
        }

        return false;
    }
};