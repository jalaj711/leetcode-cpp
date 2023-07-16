#include <vector>
using namespace std;
class Solution
{
private:
    void solve(int index, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (index >= candidates.size())
            return;
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            solve(index, target - candidates[index], candidates, ds, ans);
            ds.pop_back();
        }
        solve(index + 1, target, candidates, ds, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};

int main() {
    vector<int> q {2,3,6,7};
    Solution s;
    s.combinationSum(q, 7);
}
