
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> ans;

    void recur(int j, int n) {
        if (j > n || ans.size() > n) return;
        int k = j + 10;
        j += (j == 0);
        while (j < k && j <= n) {
            ans.push_back(j);
            if (j * 10 <= n) recur(j * 10, n);
            j++;
        }
    }

    vector<int> lexicalOrder(int n) {
        recur(0, n);
        return ans;
    }
};