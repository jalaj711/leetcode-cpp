#include<string>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:
  int numWays(vector<string> &words, string target) {
    int n = words.size();

    int w_len = words[0].size();
    int t_len = target.size();
    int inf = 1e9 + 7;

    int prev[t_len + 1];
    int curr[t_len + 1];
    int charc[26][w_len];
    memset(curr, 0, sizeof(int) * (t_len + 1));
    memset(prev, 0, sizeof(int) * (t_len + 1));
    memset(charc, 0, sizeof(int) * (w_len) * (26));

    prev[t_len] = 1;
    curr[t_len] = 1;

    for (int i = 0; i < w_len; i++) {
      for (int k = 0; k < n; k++) {
        charc[words[k][i] - 'a'][i]++;
      }
    }

    int pval;
    for (int j = w_len - 1; j >= 0; j--) {
      pval = 1;
      for (int i = t_len - 1; i >= 0; i--) {
        int ways = charc[target[i] - 'a'][j];

        int pick = (int) (((long) ways * (long) pval) % inf);
        int notpick = prev[i];

        // cout << "i=" << i << " j=" << j << " p=" << pick << " np=" << notpick << " w=" << ways << endl;
        prev[i + 1] = pval;
        pval = prev[i];
        prev[i] = (pick + notpick) % inf;
      }
      // memcpy(prev, curr, sizeof(int)*(t_len+1));

    }

    return prev[0];
  }
};