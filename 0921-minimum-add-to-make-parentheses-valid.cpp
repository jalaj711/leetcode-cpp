#include<string>
using namespace std;
class Solution {
public:
  int minAddToMakeValid(string s) {
    int ans = 0;
    int b = 0;
    for (char ch:s) {
      if (ch=='(') b++;
      else {
        if (b==0) ans++;
        else b--;
      }
    }
    return ans+b;
  }
};