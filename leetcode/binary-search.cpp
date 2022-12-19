#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int res = -1;
        int index = (low + high) / 2;
        while (low <= high)
        {
            if (nums[index] == target)
            {
                res = index;
                break;
            }
            else if (nums[index] > target)
            {
                high = index - 1;
            }
            else
            {
                low = index + 1;
            }
            index = low + (high - low) / 2;
        }
        return res;
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

    int res = (new Solution())->search(vec, 1);
    res = (new Solution())->search(vec, -5);
    res = (new Solution())->search(vec, 3);
    res = (new Solution())->search(vec, 9);
    res = (new Solution())->search(vec, 15);
}