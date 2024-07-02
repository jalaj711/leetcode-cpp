#include<string>
#include <math.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for (auto ch: s) {
            if (!ans.empty()&&abs(ans[ans.size()-1]-ch)==32){
                ans = ans.substr(0, ans.size()-1);
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    s.makeGood("leEeetcode");
}
