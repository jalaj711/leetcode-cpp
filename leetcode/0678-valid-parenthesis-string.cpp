#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> opens;
        stack<int> stars;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '(') opens.push(i);
            else if (s[i] == '*') stars.push(i);
            else if (!opens.empty()) opens.pop();
            else if (!stars.empty()) stars.pop();
            else return false;
        }
        while(!opens.empty()) {
            if (stars.empty()) return false;
            if (stars.top() < opens.top()) return false;
            stars.pop();
            opens.pop();
        }
        return true;
    }
};
