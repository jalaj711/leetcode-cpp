#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        m--;
        n--;
        while (m >= 0 && n >= 0)
        {
            if (nums1[m] > nums2[n])
            {
                nums1[m + n+1] = nums1[m];
                m--;
            }
            else
            {
                nums1[m + n+1] = nums2[n];
                n--;
            }
        }
        while (n >= 0)
        {
            nums1[n] = nums2[n];
            n--;
        }
    }
};

int main(){
    vector<int> q1 = {1, 3, 5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> q2 = {-1, 0, 2, 4, 6, 8, 10, 12, 13};
    Solution s;
    s.merge(q1, 4, q2, 9);
    return 0;
}
