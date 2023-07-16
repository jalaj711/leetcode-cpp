#include<vector>
#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sliceToBst(vector<int>&nums, int low, int high, int n) {
        if (low>high || low<0 || high<0) return nullptr;
        int mid = (low+high+n)/2;
        cout << low << " " << mid << " " << high << endl;
        TreeNode *root = new TreeNode(nums[mid]);
        if (mid != low) root->left = sliceToBst(nums, low, mid-1, 1);
        if(mid != high) root->right = sliceToBst(nums, mid+1, high, 0);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = sliceToBst(nums, 0, nums.size()-1, 0);
        return root;
    }
};

int main(){
    Solution s;
    vector<int> nums({-10,-3,0,5,9});
    s.sortedArrayToBST(nums);
}
