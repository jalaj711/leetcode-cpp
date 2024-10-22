#include<vector>

#include<queue>

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
  long long kthLargestLevelSum(TreeNode *root, int k) {
    queue<TreeNode *> q;
    priority_queue<long long, vector<long long>, greater<>> pq;

    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      long long sum = 0;
      while (n--) {
        TreeNode *fr = q.front();
        q.pop();
        sum += fr->val;
        if (fr->left) q.push(fr->left);
        if (fr->right) q.push(fr->right);
      }
      // cout << "sum=" << sum << endl;
      pq.push(sum);

      if (pq.size() > k) pq.pop();
    }

    if (pq.size() < k) return -1;

    return pq.top();
  }
};