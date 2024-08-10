#include<vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution {
public:
    vector<TreeNode *> recur(int n, int startFrom, unordered_map<string, vector<TreeNode*>> &memo) {
        vector<TreeNode *> ans;
        if (n <= 0){
            ans.push_back(nullptr);
            return ans;
        }
        string key = to_string(n) + "-" + to_string(startFrom);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        for (int i = 0; i < n; i++) {
            auto lefts = recur(i, startFrom, memo);
            auto rights = recur(n - i - 1, startFrom + i + 1, memo);

            for (auto &left: lefts)
                for (auto &right: rights) {
                    auto node = new TreeNode(startFrom + i);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }

        }
        memo[key] = ans;
        return ans;
    }

    vector<TreeNode *> generateTrees(int n) {
        unordered_map<string, vector<TreeNode*>> memo;
        return recur(n, 1, memo);
    }
};

int main() {
    Solution s;
    s.generateTrees(2);
}