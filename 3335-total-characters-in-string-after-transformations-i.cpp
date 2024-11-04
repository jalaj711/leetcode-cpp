#include<string>
using namespace std;

class Solution {
public:
  int lengthAfterTransformations(const string &s, int t) {
    int freq[26] = {0};

    for (const char &ch: s) freq[ch-'a']++;

    int count = s.size();
    int inf = 1e9+7;
    for(int i=0;i<t;i++) {
      int p = freq[25]%inf;
      for (int j=25;j>0;j--) freq[j] = freq[j-1];
      freq[1] += p;
      freq[0] = p;
      count = (count+p) % inf;
    }

    return count;
  }
};