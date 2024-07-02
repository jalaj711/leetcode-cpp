#include <string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        if (s == "") return 0;
        int a = 0;
        int r = 0;
        for (auto ch: s) {
            if (ch == '(') r++;
            if (ch == ')') {
                a = a > r ? a : r;
                r--;
            }
        }
        return a;
    }
};

//int main() {
//    vector<vector<char>> q {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
//    Solution s;
//    s.containsCycle(q);
//}//
//// Created by jalaj on 4/4/24.
////
