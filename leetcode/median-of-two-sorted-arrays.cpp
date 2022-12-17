#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged;
        int m = 0, n = 0;
        int i = nums1.size() + nums2.size();
        while (m + n < i && m < nums1.size() && n < nums2.size())
        {
            if (nums1[m] < nums2[n])
            {
                merged.push_back(nums1[m]);
                m++;
            }
            else
            {
                merged.push_back(nums2[n]);
                n++;
            }
        }

        if (m >= nums1.size())
        {
            while (m + n < i)
            {
                merged.push_back(nums2[n]);
                n++;
            }
        }
        if (n >= nums2.size())
        {
            while (m + n < i)
            {
                merged.push_back(nums1[m]);
                m++;
            }
        }
        double median;
        if (i % 2 == 0)
        {
            median = (merged[i / 2 - 1] + merged[i / 2]) / 2.0;
        }
        else
        {
            median = merged[(i + 1) / 2 - 1];
        }
        return median;
    }
};

int main()
{
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums1.push_back(6);
    nums1.push_back(9);

    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(5);
    (new Solution())->findMedianSortedArrays(nums1, nums2);
}
