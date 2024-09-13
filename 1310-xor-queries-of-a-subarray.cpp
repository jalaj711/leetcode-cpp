#include<vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] ^ arr[i];
        }

        vector<int> ans;
        for (auto query: queries) {
            if (query[0] == 0) ans.push_back(arr[query[1]]);
            else ans.push_back(arr[query[0] - 1] ^ arr[query[1]]);
        }

        return ans;
    }
};