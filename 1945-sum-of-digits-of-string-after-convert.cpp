#include<string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int a = 0;
        for (auto ch: s)
            a += (ch-'a'+1)/10 + (ch-'a'+1)%10;
        k--;
        int temp=a;
        while(k--) {
            temp = 0;
            while(a) {
                temp += a%10;
                a = a/10;
            }
            a = temp;
        }
        return a;
    }
};
