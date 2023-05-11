#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int count_rows = matrix.size();
        if (count_rows < 1)
            return;
        int count_col = matrix[0].size();
        vector<bool> zero_cols(count_col, false);
        vector<bool> zero_rows(count_rows, false);
        for (int i = 0; i < count_rows; i++)
        {
            for (int j = 0; j < count_col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zero_rows[i] = true;
                    zero_cols[j] = true;
                }
            }
        }
        for (int i = 0; i < count_rows; i++)
        {
            for (int j = 0; j < count_col; j++)
            {
                if (zero_rows[i] || zero_cols[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};

int main()
{
    vector<int> i;
    vector<vector<int>> matrix;
    (new Solution())->setZeroes(matrix);
}
