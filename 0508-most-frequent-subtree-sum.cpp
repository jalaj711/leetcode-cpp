#include<unordered_map>
#include<climits>
#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  unordered_map<int, int> mp;

  int dfs(TreeNode *root) {
    if (root == nullptr) return 0;

    int s = root->val;
    s += dfs(root->left);
    s += dfs(root->right);

    mp[s]++;
    return s;
  }

  vector<int> findFrequentTreeSum(TreeNode *root) {
    dfs(root);

    int m = INT_MIN;
    vector<int> ans;

    for (const auto &it: mp) {
      // cout << "sum=" << it.first << "freq=" << it.second << endl;
      if (it.second > m) {
        ans.clear();
        ans.push_back(it.first);
        m = it.second;
      } else if (it.second == m)
        ans.push_back(it.first);
    }

    return ans;
  }
};