#include<string>

using namespace std;
class Solution {

public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        if (num.size() == 1) return num;

        string ans = "";
        for (auto ch: num) {
            while(!ans.empty() && ans.back()>ch && k) {
                ans.pop_back();
                k--;
            }
            if (!ans.empty()||ch!='0') ans.push_back(ch);
        }
        while (k--&&!ans.empty()) {
            ans.pop_back();
        }
        if (ans.empty()) return "0";
        return ans;
    }
};

int main() {
    Solution s;
//    s.removeKdigits("1234567890", 9); // 0
//    s.removeKdigits("1432219", 3);    // 1219
//    s.removeKdigits("10", 2);         // 0
//    s.removeKdigits("4321", 2);       // 21
    s.removeKdigits("10001", 4);
}