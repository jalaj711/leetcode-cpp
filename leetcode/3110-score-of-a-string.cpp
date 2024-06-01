#include<string>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int a = 0;
        for (int i=0;i<s.size()-1;i++) {
            a += abs(s[i] - s[i+1]);
        }
        return a;
    }
};