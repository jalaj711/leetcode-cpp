#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i % n] >= st.top())
            {
                st.pop();
            }

            if (!st.empty() && i < n)
            {
                ans[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
int main()
{
    vector<int> ques{1, 4, 2, 6, 9, 0, 3};
    vector<int> ans = (new Solution())->nextGreaterElements(ques);
    for (auto elem : ans)
        cout << elem << endl;
}
