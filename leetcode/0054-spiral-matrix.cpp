#include <vector>
using namespace std;

enum direction
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        direction currDirection = RIGHT;
        vector<int> ans;

        int i = 0, j = 0, cnt = 0, m = matrix.size(), n = matrix[0].size();
        while (cnt < m * n)
        {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = 101;
            cnt++;
            if (cnt < m * n)
            {

                switch (currDirection)
                {
                case RIGHT:
                    j++;
                    if (j>=n || matrix[i][j] == 101) {
                        currDirection = DOWN;
                        i++;
                        j--;
                    }
                    break;
                case DOWN:
                    i++;
                    if (i>=m || matrix[i][j] == 101) {
                        currDirection = LEFT;
                        i--;
                        j--;
                    }
                    break;
                case LEFT:
                    j--;

                    if (j<0 || matrix[i][j] == 101) {
                        currDirection = UP;
                        i--;
                        j++;
                    }
                    break;
                case UP:
                    i--;

                    if (i<0 || matrix[i][j] == 101) {
                        currDirection = RIGHT;
                        i++;
                        j++;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> q {{1,2,3},{8,9,4}, {7,6,5}};
    Solution s;
    s.spiralOrder(q);
}
