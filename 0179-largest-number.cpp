#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool customSort(const int &a, const int &b) {
        if (a==0) return false;
        if (b==0) return true;
        int x = log10(a);
        int y = log10(b);
        unsigned long long p=a, q=b;
        p = p * (unsigned long long)pow(10, y+1) + b;
        q = q * (unsigned long long)pow(10, x+1) + a;
        // cout << "input = " << a << " " << b << endl;
        // cout << "comp = " << p << " " << q << endl;
        return p > q;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), customSort);
        string ans = "";
        int x, p;
        for (int n:nums) {
            if (n==0) {
                if (ans.size()) ans += '0';
                continue;
            }
            x = log10(n)+1;
            while(x--) {
                p = (int)pow(10, x);
                ans += (n/p) + '0';
                n = n % p;
            }
        }
        return ans.size() ? ans:"0";
    }
};