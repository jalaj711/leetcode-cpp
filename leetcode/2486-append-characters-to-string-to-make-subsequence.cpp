#include<string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = 0, r = 0, ss = s.size(), ts = t.size();
        while(l<ss&&r<ts) {
            if (s[l] == t[r]) {
                r++;
            }
            l++;
        }
        return ts-r;
    }
};