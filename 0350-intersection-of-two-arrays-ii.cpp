#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    vector<int> common(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) j++;
            else i++;
        }
        return ans;
    }

public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if (nums1.size() > nums2.size()) return common(nums1, nums2);
        return common(nums2, nums1);
    }
};