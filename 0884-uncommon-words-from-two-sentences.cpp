#include<string>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        string temp = "";
        for (auto ch : s1) {
            if (ch == ' ') {
                if (mp.find(temp) != mp.end())
                    mp[temp] = 1;
                else
                    mp[temp] = 0;
                temp = "";
            }
            else temp.push_back(ch);
        }
        if (mp.find(temp) != mp.end())
            mp[temp] = 1;
        else
            mp[temp] = 0;

        temp = "";
        for (auto ch : s2) {
            if (ch == ' ') {
                if (mp.find(temp) != mp.end())
                    mp[temp] = 1;
                else
                    mp[temp] = 0;
                temp = "";
            }
            else temp.push_back(ch);
        }
        if (mp.find(temp) != mp.end())
            mp[temp] = 1;
        else
            mp[temp] = 0;

        vector<string> ans;
        for (auto entry : mp) {

            if (entry.second == 0)
                ans.push_back(entry.first);
        }
        return ans;
    }
};