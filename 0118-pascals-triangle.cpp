#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i=0;i<numRows;i++) {
            vector<int> row;
            for (int j=0;j<i+1;j++) {
                int elem;
                if(j==0||j==i) {
                    elem = 1;
                } else {
                    elem = ans[i-1][j-1] + ans[i-1][j];
                }
                row.push_back(elem);
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main()
{
    vector<int> i;
    vector<vector<int>> matrix;
    matrix = (new Solution())->generate(5);
}
