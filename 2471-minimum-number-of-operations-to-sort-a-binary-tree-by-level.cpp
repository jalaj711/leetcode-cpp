#include<cstring>
#include<unordered_map>
#include<algorithm>
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
  int swaps(int *a, int s) {
    int c[s];
    memcpy(c, a, sizeof(int) * s);
    sort(c, c + s);

    unordered_map<int, int> mp;

    for (int i = 0; i < s; i++) {
      mp[a[i]] = i;
    }

    int sw = 0;
    int j = 0;
    while (j < s) {
      if (a[j] != c[j]) {
        int x = mp[c[j]];
        mp[a[j]] = x;
        swap(a[x], a[j]);
        sw++;
      }
      j++;
    }
    return sw;
  }

  int minimumOperations(TreeNode *root) {
    int ans = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      int a[n];
      int s = n;
      while (n--) {
        auto node = q.front();
        q.pop();
        a[s - n - 1] = node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }

      ans += swaps(a, s);
    }

    return ans;
  }
};