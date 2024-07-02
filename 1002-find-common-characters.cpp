#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> count(const string &s) {
        vector<int> ans (26, 0);
        for(auto ch: s) {
            ans[ch-'a']++;
        }
        return ans;
    }
    vector<int> intersect(const vector<int> &a, const vector<int> &b) {
        vector<int> ab (26, 0);
        for (int i=0;i<a.size();i++) {
            ab[i] = min(a[i], b[i]);
        }
        return ab;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<int> cur = count(words[0]);
        for(int j=1;j<words.size();j++) {
            cur = intersect(cur, count(words[j]));
        }
        vector<string> ans;
        for (int i=0;i<26;i++) {
            while(cur[i]--) {
                ans.push_back(string(1, i+'a'));
            }
        }
        return ans;
    }
};