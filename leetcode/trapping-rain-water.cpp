#include <vector>
#include <iostream>
using namespace std;

// Although this solution gives the right answer it gives TLE on leetcode :)
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         if (height.size() <= 2)
//             return 0;
//         int ans = 0;
//         int ptr_1 = 0;
//         int ptr_2 = 1;
//         while (ptr_1 < height.size())
//         {
//             int max_height = ptr_2;
//             while (ptr_2 < height.size() && height[ptr_2] < height[ptr_1])
//                 max_height = height[ptr_2++] > height[max_height] ? ptr_2 - 1 : max_height;
//             if (ptr_2 - ptr_1 > 1)
//             {
//                 int water_level;
//                 if (ptr_2 < height.size())
//                     water_level = min(height[ptr_1], height[ptr_2]);
//                 else
//                 {
//                     water_level = height[max_height];
//                     ptr_2 = max_height;
//                 }
//                 for (int i = ptr_1 + 1; i < ptr_2; i++)
//                 {
//                     ans += water_level - height[i];
//                 }
//                 ptr_1 = ptr_2;
//                 ptr_2++;
//             }
//             else
//             {
//                 ptr_1++;
//                 ptr_2 = ptr_1 + 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() <= 2)
            return 0;
        int ans = 0,
            left = 0,
            right = height.size() - 1,
            leftMax = 0,
            rightMax = 0;
        while (left < right)
        {
            if (height[left] > leftMax) leftMax = height[left];
            if (height[right] > rightMax) rightMax = height[right];

            if (height[left] <= height[right]) {
                ans += leftMax - height[left];
                left++;
            }
            else if (height[right] <= height[left]) {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> ques{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // expected: 6
    // vector <int> ques{4,2,3}; // expected: 1
    // vector<int> ques{4, 2, 0, 3, 2, 5}; // expected: 9
    // vector<int> ques{4, 9, 4, 5, 3, 2}; // expected: 1
    int ans = (new Solution())->trap(ques);
    cout << ans << endl;
}