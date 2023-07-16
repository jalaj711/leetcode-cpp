#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        int sum = numbers[l] + numbers[r];
        while (sum != target)
        {
            if (sum > target)
                r--;
            else
                l++;
            sum = numbers[l] + numbers[r];
        }
        vector<int> ans;
        ans.push_back(l + 1);
        ans.push_back(r + 1);
        return ans;
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(10);

    (new Solution())->twoSum(vec, 13);
    return 0;
}