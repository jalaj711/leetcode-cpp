#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int index_of_smallest = 0;
        int smallestSquare = nums[index_of_smallest] * nums[index_of_smallest];
        for (int i = 0; i < nums.size(); ++i)
        {
            int sq = nums[i] * nums[i];
            if (sq < smallestSquare)
            {
                smallestSquare = sq;
                index_of_smallest = i;
            }
        }
        vector<int> ans;
        int a = index_of_smallest + 1;
        int b = index_of_smallest - 1;
        int sq_a, sq_b;
        ans.push_back(smallestSquare);
        while (a < nums.size() && b > -1)
        {
            sq_a = nums[a] * nums[a];
            sq_b = nums[b] * nums[b];
            if (sq_a > sq_b)
            {
                ans.push_back(sq_b);
                b--;
            }
            else
            {
                ans.push_back(sq_a);
                a++;
            }
        }
        while (a < nums.size())
        {
            sq_a = nums[a] * nums[a];
            ans.push_back(sq_a);
            a++;
        }
        while (b > -1)
        {
            sq_b = nums[b] * nums[b];
            ans.push_back(sq_b);
            b--;
        }
        return ans;
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(-5);
    vec.push_back(-2);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(15);

    (new Solution())->sortedSquares(vec);
}