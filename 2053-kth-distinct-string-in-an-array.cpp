#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string> &arr, int k) {
        unordered_set<string> st;
        unordered_set<string> rep;
        for (int i = 0; i < arr.size(); i++) {
            if (st.find(arr[i]) != st.end()) {
                rep.insert(arr[i]);
            } else {
                st.insert(arr[i]);
            }
        }
        if (k > (st.size() - rep.size())) return "";
        st.clear();
        int j = 0, i = 0;
        for (; i < arr.size() && j < k; i++) {
            if (rep.find(arr[i]) == rep.end()) {
                j++;
            }
        }
        return arr[i - 1];
    }
};