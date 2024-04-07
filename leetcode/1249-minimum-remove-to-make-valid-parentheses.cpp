#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string answer;
        stack<int> stk;
        for(auto ch: s) {
            answer.push_back(ch);
            if (ch == '(') {
                stk.push(answer.size()-1);
            } else if (ch == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    answer.pop_back();
                }
            }
        }
        while(!stk.empty()) {
            answer = answer.substr(0, stk.top()) + answer.substr(stk.top()+1, answer.size());
            stk.pop();
        }
        return answer;
    }
};

int main(){
    Solution s;
    s.minRemoveToMakeValid("test(()");
    s.minRemoveToMakeValid("lee(t(c)o)de)");
    s.minRemoveToMakeValid("a)b(c)d");
    s.minRemoveToMakeValid("))((");
}