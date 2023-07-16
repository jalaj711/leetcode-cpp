#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int res = -1;
        int index = (low + high) / 2;
        if(target > nums[high]) {
            return high+1;
        } else if (target < nums[0]) {
            return 0;
        }
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
                if(nums[index-1] < target) {
                    res = index;
                    break;
                }
            }
            else
            {
                low = index + 1;
                if(nums[index+1] > target) {
                    res = index+1;
                    break;
                }
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

    int res = (new Solution())->searchInsert(vec, 1);
    res = (new Solution())->searchInsert(vec, -7);
    res = (new Solution())->searchInsert(vec, 3);
    res = (new Solution())->searchInsert(vec, 9);
    res = (new Solution())->searchInsert(vec, 10);
}