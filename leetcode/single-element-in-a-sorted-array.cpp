#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int low = 0, high = n;
        int mid;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            // cout << mid << " low=" << low << " high=" << high << " elem=" << nums[mid] << endl;
            if (mid==0 || mid==n || (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]))
            {
                return nums[mid];
            }
            else if (mid % 2)
            {
                if (nums[mid] == nums[mid - 1])
                {
                    // cout << "c" << endl;
                    low = mid + 1;
                }
                else
                {
                    // cout << "d" << endl;
                    high = mid - 1;
                }
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                {
                    // cout << "a" << endl;
                    low = mid + 1;
                }
                else
                {
                    // cout << "b" << endl;
                    high = mid - 1;
                }
            }
        }
        return nums[low];
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans1 = s.singleNonDuplicate(arr);
    cout << ans1 << endl;
}
