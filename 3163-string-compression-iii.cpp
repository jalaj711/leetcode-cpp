#include<string>
using namespace std;

class Solution {
public:
  string compressedString(string word) {
    string ans = "";
    int n = word.size(),
        i = 0,
        cnt;

    while (i < n) {
      cnt = 0;
      while(cnt+i<n && word[cnt+i] == word[i] && cnt<9) cnt++;
      ans += '0'+cnt;
      ans += word[i];
      i += cnt;
    }

    return ans;
  }
};