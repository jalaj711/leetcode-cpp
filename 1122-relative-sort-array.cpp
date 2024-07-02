#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        map<int, int> cnt;
        for (auto j: arr1) cnt[j]++;

        vector<int> res;
        for (auto j: arr2) {
            for (int i = 0; i < cnt[j]; i++) {
                res.push_back(j);
            }
            cnt.erase(j);
        }
        for (auto it: cnt) {
            for (int i = 0; i < it.second; i++) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};