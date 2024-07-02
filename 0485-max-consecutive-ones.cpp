#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_count = 0, count = 0;
        for (auto i: nums) {
            if (i)
                count++;
            else {
                if (count > max_count) max_count = count;
                count = 0;
            }
        }

        if (count > max_count) max_count = count;
        return max_count;
    }
};

int main()
{
    vector<int> ques{1, 0, 1, 1, 0, 1};
    int ans = (new Solution())->findMaxConsecutiveOnes(ques);
    cout << ans << endl;
}