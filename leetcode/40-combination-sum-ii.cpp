#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    void solve(int index, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if(i != index && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] <= target)
            {
                ds.push_back(candidates[i]);
                solve(i + 1, target - candidates[i], candidates, ds, ans);
                ds.pop_back();
            } else {
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};

int main()
{
    vector<int> q{10, 1, 2, 7, 6, 1, 5};
    Solution s;
    s.combinationSum2(q, 8);
}
