#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zero = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 && zero == -1)
            {
                zero = i;
            }
            else if (nums[i] != 0 && zero != -1)
            {
                nums[zero] = nums[i];
                nums[i] = 0;
                zero++;
            }
        }
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(0);
    vec.push_back(15);

    (new Solution())->moveZeroes(vec);
    return 0;
}